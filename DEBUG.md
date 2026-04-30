To debug a Meson-built C project directly from the terminal, you follow a "Build, Launch, Break" workflow.
## 1. Build with Debug Symbols
Ensure your project is compiled for debugging so GDB can "see" your source code.

# Set build type to debug and compile
meson setup builddir --buildtype=debug --reconfigure
meson compile -C builddebug

## 2. Launch GDB
Start GDB and point it to your compiled executable:

gdb builddir/hobby_c

## 3. Set Breakpoints and Run
Once inside the GDB prompt ((gdb)), use these commands:

* Set a breakpoint by function name:

break main

* Set a breakpoint by filename and line number:

break main.c:25

* Start the program:

run

If your program needs arguments, provide them here: run --input file.txt

## 4. Basic Navigation once paused
When GDB hits your breakpoint, the program stops. Use these shorthand commands:

* n (next): Execute the next line (step over).
* s (step): Step into a function call.
* p variable_name (print): Show the current value of a variable.
* c (continue): Resume execution until the next breakpoint.
* q (quit): Exit GDB.

## Shortcut: Meson Test Debugging
If you want to debug a specific test case defined in your meson.build, Meson provides a shortcut that handles the paths for you:

meson test --gdb name_of_test

This will automatically launch GDB and pause at the start of the test.
Do you need to pass specific command-line arguments or environment variables to your program while running it in GDB?

