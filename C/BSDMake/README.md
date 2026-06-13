# Playground for BSD Makefile creator 

There's an old article from Adam de Boor of Berkeley:

https://docs-archive.freebsd.org/44doc/psd/12.make/paper.pdf


## de Boor’s First Rule of writing makefiles:

Anything that needs to be written more than once should be placed in a variable.

## de Boor’s Second Rule of writing makefiles:

Any flags or programs used inside a makefile should be placed in a variable so they may be changed, temporarily or permanently, with the greatest ease.

## de Boor’s First Corollary:

Variables are your friends.

## Debugging

```make -d m``` causes PMake to tell you as it examines each target in the makefile and indicate why it is deciding whatever it is deciding.


