# Halcyon Plains
Relaxing, Idle farming game made using SDL2

## Windows Setup
1. Download [MinGW](https://osdn.net/projects/mingw/releases/) *mingw-get-setup.exe*
    * At the second installation window:
        * mingw-developer-toolkit-bin
        * mingw32-base-bin
        * mingw32-gcc-g++-bin
        * msys-base-bin
        * Installation -> Apply Changes
2. Add the MinGW bin folder to path (i.e. C:\MinGW\bin)
3. Download [SDL2](http://libsdl.org/) *SDL Version 2.0.12*
    * Make sure you download the MinGW version, not the VS Version. (If you want to set up the project with VS, you're on your own)
4. Extract SDL to a convenient location (i.e. C:/SDL2)
5. Copy the folder SDL2\i686-w64-mingw32\include\SDL2 and paste the entire folder to MinGW\include\
6. Copy all the .a and .la files from SDL2\i686-w64-mingw32\lib\ and paste them into MinGW\lib\
7. Finally, copy the SDL2.dll from SDL2\i686-w64-mingw32\bin\ and paste it into MinGW\bin\

## Building
1. An example Makefile is included in the src/ folder. The CCFLAGS -I and -L will need to be changed to point to your SDL2 Installation
2. Use `mingw32-make main` to build the executable and `mingw32-make clean` to remove the object files
3. `mingw32-make clean-all` to remove object files and the executable
