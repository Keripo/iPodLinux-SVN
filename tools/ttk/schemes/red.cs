\name Red
# Red color scheme (for m:robe look)
#  brought in from pz0 by bleullama
#  originally conceived for the m-robe color scheme by Stuart Clark (Decipher)

\def black #000000
\def red   #ff0000
\def blue  #000044
\def ltred #aa0000
\def dkred #550000
\def orange #ff5500
\def yellow #ffff00
\def white #ffffff

  header: bg => dkred, fg => black, line => red -1, accent => red
	  gradient.top => red,
	  gradient.middle => yellow,
	  gradient.bottom => red,
	  gradient.bar => white -1 

 battery: border => red, bg => black, fill.normal => red +1, 
		fill.low => orange +1, fill.charge => orange +1,
		bg.low => blue, bg.charging => blue

    lock: border => red, fill => black

 loadavg: bg => dkred, fg => ltred, spike => red

  window: bg => black, fg => red, border => dkred -3

  dialog: bg => black, fg => red, line => black,
          title.fg => red,	
          button.bg => black, button.fg => red, button.border => dkred,
	  button.sel.bg => dkred, button.sel.fg => red, button.sel.border => black, button.sel.inner => black +1

   error: bg => dkred, fg => red, line => black,
          title.fg => red,
          button.bg => dkred, button.fg => red, button.border => black,
          button.sel.bg => ltred, button.sel.fg => black, button.sel.border => red, button.sel.inner => dkred +1

  scroll: box => red, bg => black +1, bar => ltred +2

   input: bg => black, fg => red, selbg => red, selfg => black, border => dkred, cursor => red


    menu: bg => black, fg => red, choice => red, icon => red,
          selbg => red, selfg => black, selchoice => dkred,
          icon0 => red, icon1 => ltred, icon2 => dkred, icon3 => black

  slider: border => red, bg => black, full => black

textarea: bg => black, fg => red