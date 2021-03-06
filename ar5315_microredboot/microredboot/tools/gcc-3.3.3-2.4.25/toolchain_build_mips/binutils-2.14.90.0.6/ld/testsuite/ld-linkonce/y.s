;# Library file y.s has linkonce entries for fn and fn2.  Note
;# that this version of fn has different code, as if compiled
;# with different optimization flags than the one in x.s (not
;# important for this test, though).  The reference from
;# .eh_frame to the linkonce-excluded fn2 must be zero, or g++
;# EH will not work.

 .section .gnu.linkonce.t.fn2,"ax",@progbits
 .weak fn2
 .type fn2,@function
fn2:
.Lc:
 .long 3
.Ld:
 .size fn2,.Ld-.Lc

 .section .gnu.linkonce.t.fn,"ax",@progbits
 .weak fn
 .type fn,@function
fn:
.Le:
 .long 4
.Lf:
 .size fn,.Lf-.Le

 .section .eh_frame,"aw",@progbits
 .long 7
 .long .Lc
 .long .Ld-.Lc

 .long 0x6066
 .long .Le
 .long .Lf-.Le
