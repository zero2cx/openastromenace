/******************************************************************************

	This source file is part of AstroMenace game
	(Hardcore 3D space shooter with spaceship upgrade possibilities.)
	For the latest info, see http://www.viewizard.com/

	File name: Defines.h

	Copyright (c) 2006-2012 Michael Kurinnoy, Viewizard
	All Rights Reserved.

	File Version: 1.3

******************************************************************************

	AstroMenace game source code available under "dual licensing" model.
	The licensing options available are:

	* Commercial Licensing. This is the appropriate option if you are
	  creating proprietary applications and you are not prepared to
	  distribute and share the source code of your application.
	  Contact us for pricing at viewizard@viewizard.com

	* Open Source Licensing. This is the appropriate option if you want
	  to share the source code of your application with everyone you
	  distribute it to, and you also want to give them the right to share
	  who uses it. You should have received a copy of the GNU General Public
	  License version 3 with this source codes.
	  If not, see <http://www.gnu.org/licenses/>.

******************************************************************************/


#ifndef DEFINES_H
#define DEFINES_H


// язык интерфейса
#if !defined(EN) && !defined(DE) && !defined(RU)

#define EN
//#define DE
//#define RU

#endif

#define GAME_VERSION_ID	 	1.3f
#define GAME_VERSION_BUILD 	120925
#define GAME_COPYRIGHT		"Copyright 2007-2012, Viewizard"



// для разных видов билдов.
// без определений - нормальный, однопоточный билд
// Если билд мульти потоковый (под многоядерный процессоры, или многопроцессорные машины)
// - отдельный поток музыки при загрузке
#define MULTI_THREAD_VERSION





// данные для определения папки пользователя
#ifdef WIN32
#include <windows.h>

#define SD_APPDATA                   0x001a
#define SD_DESKTOPDIRECTORY          0x0010        // <user name>\Desktop
typedef BOOL (WINAPI *SHGETSPECIALFOLDERPATH)(HWND hwndOwner, LPTSTR lpszPath, int nFolder, BOOL fCreate);
extern SHGETSPECIALFOLDERPATH pSHGetSpecialFolderPath;
#endif // WIN32



#endif // DEFINES_H
