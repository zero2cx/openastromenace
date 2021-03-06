/************************************************************************************

	AstroMenace (Hardcore 3D space shooter with spaceship upgrade possibilities)
	Copyright (c) 2006-2016 Mikhail Kurinnoi, Viewizard


	AstroMenace is free software: you can redistribute it and/or modify
	it under the terms of the GNU General Public License as published by
	the Free Software Foundation, either version 3 of the License, or
	(at your option) any later version.

	AstroMenace is distributed in the hope that it will be useful,
	but WITHOUT ANY WARRANTY; without even the implied warranty of
	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
	GNU General Public License for more details.

	You should have received a copy of the GNU General Public License
	along with AstroMenace. If not, see <http://www.gnu.org/licenses/>.


	Web Site: http://www.viewizard.com/
	Project: http://sourceforge.net/projects/openastromenace/
	E-mail: viewizard@viewizard.com

*************************************************************************************/


#ifndef CONFIG_H
#define CONFIG_H

#define GAME_VERSION	 	"1.3.3 svn"
#define GAME_BUILD			160125




// libSDL2 implementation. Work in progress.
// #define use_SDL2
// Note:
// - Make sure, that you have libSDL2 development package installed.
// - No need direct access to libXinerama in code. libSDL2 have multiple displays support.





// You can disable some OpenGL features during compilation to avoid some drivers issues.
// OpenGL 4.2+
#define use_Texture_Storage
#define use_BPTC_Texture_Compression
// OpenGL 3.0+
#define use_Vertex_Array_Objects
#define use_Framebuffer_Objects
// OpenGL 2.0+
#define use_Shading_Language
#define use_NPOT_Texture
// OpenGL 1.5+
#define use_Query_Objects
#define use_Vertex_Buffer_Objects
// OpenGL 1.4+
#define use_Automatic_Mipmap_Generation

// xinerama support, required libXinerama (* need for libSDL only, libSDL2 have internal implementation)
#ifdef xinerama_detected_by_cmake // do not comment this line, unless you are sure what are you doing
	#define xinerama
#endif // xinerama_detected_by_cmake

// joystick support, required SDL compilled with "joystick" flag
#define joystick

// separate thread for music during data loading (based on SDL multithread implementation)
// #define multithread

// compression during gamedata.vfs creation, game will take more time for loading in exchange of size reducing (about 30 MB)
// #define compression

// define DATADIR with gamedata.vfs file location if you don't put it together in the same directory with binary file.
// Use cmake with DATADIR flag OR uncomment line below
// #define DATADIR "/usr/share/astromenace"

// game configuration file will be stored with game binary file
// #define portable

// fontconfig support.
// With fontconfig you don't need fonts bundled with game, system TrueType, Type 1 or CFF fonts will be used instead.
// Make sure, that you have at least one installed bold style TrueType, Type 1 or CFF font with en, de and ru languages support.
// RAW_VFS_DATA/FONT/ folder can be removed in case of fontconfig use.
#ifdef fontconfig_detected_by_cmake // do not comment this line, unless you are sure what are you doing
//	#define fontconfig
#endif // fontconfig_detected_by_cmake

// Default font family for game text rendering in case of fontconfig use.
// Please note, font family name could be vary in different distros.
// Recomended fonts as dafault game font (were tested for correct ingame text rendering):
// 1) Linux Libertine/Linux Biolinum
#define default_font_family "Linux Biolinum O"
//#define default_font_family "Linux Libertine O"
// 2) Liberation Fonts
//#define default_font_family "Liberation Mono"
//#define default_font_family "Liberation Sans"
//#define default_font_family "Liberation Serif"
// 3) GNU FreeFont
//#define default_font_family "FreeMono"
//#define default_font_family "FreeSans"
//#define default_font_family "FreeSerif"








// You can create standalone AstroMenaceFS2VFS util for gamedata.vfs file creation.
// Use cmake with FS2VFS flag OR
// Use CodeBlocks.cbp project file (you will need Code::Blocks IDE) with "FS2VFS Linux GCC" as Build target OR
// 1) Uncomment "#define vfs_pack_standalone" line
// 2) Make sure, that your compilation list consist only 4 source files:
//			MainFS2VFS.cpp
//			Core/VirtualFileSystem/VFS.cpp
//			Core/VirtualFileSystem/Haff.cpp
//			Core/VirtualFileSystem/RLE.cpp
//    and you have 2 header files - config.h and Core/VirtualFileSystem/VFS.h close to them.
//
// #define vfs_pack_standalone





// more actions and text outputs with debug information for bug hunting
// #define gamedebug

// PNG image format support via libpng.
// #define png

// JPEG image format support via libjpeg.
// #define jpeg

#endif // CONFIG_H
