# libbill

'Tis just a little old utility library I wrote.

Licensed under WTFPL.  Do with it what you will.

# About libbill

This lib did some things I needed in graphics class in college, like vector
math, the clamp function, and text-file processing.  It's not terribly
pretty, nor will it win the elegance sweeps, but it worked in COSC 456
at UTK and I'm sure it'll work again when I need it.

# Caveats

The real documentation is in the source code; use `doxygen` to extract
it.

Parts of this library, namely uniformops.c, require the use of the OpenGL
development libraries.  (We used Mesa at UTK, and I'm using Mesa in my
Bearded Axe project.)  If you don't want or need to use uniformops.c,
just remove it from the makefile.

If it breaks, you keep the pieces.

I'm not responsible if this program eats all the cheese in your fridge,
beams your cat into space, or causes segfaults.

# History

- Commit b0e1de9: Libbill now compiles without warnings on Linux.
- Commit 616ad58: Added bstring, a string-with-length struct.
- Commit ace40ae: Added this readme.
- Commit a32bc01: First real commit.  This is the code as it was when I finished at UT.
