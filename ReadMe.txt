AstroMenace

Runtime dependencies:
libSDL (ver 1.2.10+), libopenal (ver 1.0+), libalut (ver 1.0+), libogg (ver 1.1+), 
libvorbis (ver 1.1+), freetype (ver 2.1.6+), GLU, libXinerama (optional), 
fontconfig (optional), Linux Libertine/Biolinum fonts (optional)


The easy way to get up to date AstroMenace on your computer:

1) Make sure all necessary packages with development headers
   installed in your system: 

   gcc (with g++), cmake, make, subversion, libsdl, libogg, libvorbis, openal, 
   alut (freealut), libXinerama, GLU, freetype2, fontconfig

For Ubuntu/Mint/Debian:
$ sudo apt-get install g++ cmake make subversion libsdl1.2-dev
  libogg-dev libvorbis-dev libopenal-dev libXinerama-dev libalut-dev
  libfreetype6-dev libfontconfig1-dev fonts-linuxlibertine

For Mageia:
$ sudo urpmi gcc-c++ cmake make subversion libSDL-devel libogg-devel
  libvorbis-devel libopenal-devel libxinerama-devel libfreealut-devel
  freetype2-devel libfontconfig-devel fonts-ttf-libertine

For OpenSuse:
$ sudo zypper install gcc-c++ cmake make subversion libSDL-devel
  libogg-devel libvorbis-devel openal-soft-devel libXinerama-devel
  freealut-devel freetype2-devel fontconfig-devel linux-libertine-fonts

For Fedora:
$ sudo yum install gcc-c++ cmake make subversion SDL-devel libogg-devel
  libvorbis-devel openal-soft-devel libXinerama-devel freealut-devel 
  freetype-devel fontconfig-devel linux-libertine-fonts
  linux-libertine-biolinum-fonts

For FreeBSD:
$ sudo pkg_add -r -v gcc cmake subversion sdl libogg libvorbis openal
  libXinerama freealut freetype2 fontconfig linuxlibertine

For MacOSX 10.5+:
  Download and install "Command Line Tools for Xcode" or "Xcode".
  Install HomeBrew package manager: http://mxcl.github.com/homebrew/
$ brew install cmake sdl subversion libogg libvorbis freealut freetype

2) Checkout svn with latest source files
$ cd ~/
$ svn checkout http://svn.code.sf.net/p/openastromenace/code/ AstroMenace

3) Compile game binary
$ cd ~/AstroMenace
$ cmake ./
$ make

4) Create game VFS data file
$ ./AstroMenace --pack --rawdata=./RAW_VFS_DATA

5) Create desktop shortcut or start AstroMenace
$ ~/AstroMenace/AstroMenace



Game launch options:
   /game/bin/folder/AstroMenace [optional parameters]
   where,   
   /game/bin/folder/AstroMenace - the game executable file
   optional parameters:
    --dir=/game/data/folder/ - folder with gamedata.vfs file
    --mouse - launch the game without system cursor hiding.
    --safe-mode - reset all settings not connected to Pilots Profiles at the game start.
    --pack - pack raw game data to gamedata.vfs file.
    --rawdata=/game/rawdata/folder/ - folder with game raw data for gamedata.vfs.
    --help - info about all launch options.

For Xinerama/TwinView, use SDL_VIDEO_FULLSCREEN_DISPLAY environment variable if need. 
The SDL_VIDEO_FULLSCREEN_DISPLAY environment variable set to 0 to place 
fullscreen/windowed SDL windows on the first Xinerama/TwinView screen by default.
