This project uses the FREEGLUT library to create simple 2D Pixel Graphics in C++.
It was designed for beginners like me who don't really understand how OpenGL works.
It is intended to be used in beginner emulator development for old gaming consoles by drawing pixels to the screen and reacting to keyboard input.

The code was created by looking at and learning from many code snippets across the internet.
It is my hope that others don't have to go through the same "freeglut journey" as I did, spending 3 days 
with freeglut and OpenGL code, just to draw pixels to the screen.

Using MinGW (and having never heard of MAKE), compile using:
g++ -o Example Example.cpp -lfreeglut -lopengl32

