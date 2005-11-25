#include "bootloader.h"

#include "ata2.h"
#include "fb.h"
#include "console.h"
#include "keypad.h"
#include "minilibc.h"
#include "ipodhw.h"
#include "vfs.h"
#include "menu.h"

#define PP5020_IDE_PRIMARY_BASE    0xC30001E0
#define PP5020_IDE_PRIMARY_CONTROL 0xC30003f8

uint16 *buff;

void *loader(void) {
    void *entry;
    int fd,menuPos,done,redraw;
    uint32 ret;
    uint8 *buffer;

    /* Backlight ON */
    switch( ipod_get_hwrev() >> 16 ) {
    case 0xc:
      /* set port B03 */
      outl(((0x100 | 1) << 3), 0x6000d824);
      /* set port L07 */
      outl(((0x100 | 1) << 7), 0x6000d12c);
      break;
    case 0x6:
      outl(0x80000000 | (0xFF << 16),0x7000A010);
      outl( ((0x100 | 1) << 3),0x6000D824 );
      break;
    }

    keypad_init();

    /* Make sure malloc() is initialized */
    mlc_malloc_init();
    buff   = (uint16*)mlc_malloc( 320*240*2 ); /* Room for the biggest display */
    buffer = (uint8 *)mlc_malloc( 512 );

    fb_init( ipod_get_hwrev() );

    fb_cls(buff,0x1F);

    console_init(buff, ipod_get_hwrev() );

    console_puts("iPL Bootloader 2.0\n");

    //return(

    /*for(;;) {
      mlc_printf("ScanCore: %u \r",keypad_getstate());
      fb_update(buff);
      //ipod_wait_usec(1000);
      }*/

    ret = ata_init(PP5020_IDE_PRIMARY_BASE);
    if( ret ) {
      mlc_printf("ATAinit: %i\n",ret);
      for(;;);
    }

    ata_identify();

    vfs_init();
    fd = vfs_open("NOTES/KERNEL.BIN");
    vfs_seek(fd,0,VFS_SEEK_END);
    ret = vfs_tell(fd);
    vfs_seek(fd,0,VFS_SEEK_SET);

    mlc_printf("FD=%i (Len %u)\n",fd,ret);

    //console_puts("Trying to load kernel\n");
    //fb_update(buff);


    menu_init();
    menu_additem("Retail OS");
    menu_additem("uCLinux");
    menu_additem("Disk mode");

    menuPos = 0;
    done    = 0;
    redraw  = 1;
    while(!done ) {
      int key;

      key = keypad_getstate();
      if( key == 0x10 ) { // Up
	if(menuPos>0)
	  menuPos--;
	redraw = 1;
      } else if( key == 0x8 ) { // Down
	if(menuPos<2)
	  menuPos++;
	redraw = 1;
      } else if( key == 0x1 ) { // Center
	done = 1;
      }

      if(redraw) {
	menu_redraw(buff,menuPos);
	fb_update(buff);
	redraw = 0;
      }
    }

    entry = (void*)0x10000000;

    if( menuPos == 0 ) return( entry ); // RetailOS
    if( menuPos == 2 ) { // Diskmode
      unsigned char * storage_ptr = (unsigned char *)0x40017F00;
      char * diskmode = "diskmode\0";
      char * hotstuff = "hotstuff\0";
      
      mlc_memcpy(storage_ptr, diskmode, 9);
      storage_ptr = (unsigned char *)0x40017f08;
      mlc_memcpy(storage_ptr, hotstuff, 9);
      outl(1, 0x40017F10);
      outl(inl(0x60006004) | 0x4, 0x60006004);
    } else { // Linux kernel

      vfs_read( entry, ret, 1, fd );
      
      mlc_printf("Trying to start.\n");
      fb_update(buff);
    }

    return entry;
}

