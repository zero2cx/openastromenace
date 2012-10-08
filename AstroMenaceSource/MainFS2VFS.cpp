/******************************************************************************

	This source file is part of AstroMenace game
	(Hardcore 3D space shooter with spaceship upgrade possibilities.)
	For the latest info, see http://www.viewizard.com/

	File name: MainFS2VFS.cpp

	Copyright (c) 2012 Michael Kurinnoy, Viewizard
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


#include "Game.h"

// для генерации используем (или как удобно)
// find ./ -type f | grep -v ".svn" > list.txt

const int	ConvertListCount = 592;
const char *ConvertList[ConvertListCount] =
{"DATA_RU/VOICE/EngineMalfunction.wav",
"DATA_RU/VOICE/WeaponDamaged.wav",
"DATA_RU/VOICE/MissileDetected.wav",
"DATA_RU/VOICE/PrepareForAction.wav",
"DATA_RU/VOICE/Attention.wav",
"DATA_RU/VOICE/WeaponDestroyed.wav",
"DATA_RU/VOICE/WeaponMalfunction.wav",
"DATA_RU/VOICE/CeaseFire.wav",
"DATA_RU/VOICE/PowerSupplyReestablished.wav",
"DATA_RU/VOICE/ReactorMalfunction.wav",
"DATA_RU/VOICE/Warning.wav",
"DATA_RU/MENU/system_protect_empty.tga",
"DATA_RU/MENU/weapon_empty2_icon.tga",
"DATA_RU/MENU/system_protect1.tga",
"DATA_RU/MENU/system_target2.tga",
"DATA_RU/MENU/weapon_empty3_icon.tga",
"DATA_RU/MENU/button_weaponry_in.tga",
"DATA_RU/MENU/system_power2.tga",
"DATA_RU/MENU/system_engine2.tga",
"DATA_RU/MENU/system_target_empty.tga",
"DATA_RU/MENU/system_engine4.tga",
"DATA_RU/MENU/system_target1.tga",
"DATA_RU/MENU/system_mechan3.tga",
"DATA_RU/MENU/weapon_empty4_icon.tga",
"DATA_RU/MENU/button_weaponry_out.tga",
"DATA_RU/MENU/system_mechan1.tga",
"DATA_RU/MENU/weapon_empty1_icon.tga",
"DATA_RU/MENU/system_mechan4.tga",
"DATA_RU/MENU/system_power3.tga",
"DATA_RU/MENU/system_protect3.tga",
"DATA_RU/MENU/system_engine3.tga",
"DATA_RU/MENU/system_protect4.tga",
"DATA_RU/MENU/weapon_empty5_icon.tga",
"DATA_RU/MENU/system_target4.tga",
"DATA_RU/MENU/system_target3.tga",
"DATA_RU/MENU/system_mechan2.tga",
"DATA_RU/MENU/system_mechan_empty.tga",
"DATA_RU/MENU/system_engine_empty.tga",
"DATA_RU/MENU/system_protect2.tga",
"DATA_RU/MENU/weapon_empty_icon.tga",
"DATA_RU/MENU/system_engine1.tga",
"DATA_RU/MENU/system_power1.tga",
"DATA_RU/MENU/system_power_empty.tga",
"DATA_RU/MENU/system_power4.tga",
"DATA_RU/GAME/pause.tga",
"DATA_RU/GAME/mission.tga",
"DATA_RU/GAME/missionfailed.tga",
"DATA_RU/LOADING/loading_back.tga",
"DATA_RU/SCRIPT/text.xml",
"GLSL/light.vert",
"GLSL/light_track.vert",
"GLSL/light12.frag",
"GLSL/light20.frag",
"GLSL/light21.frag",
"GLSL/light14.frag",
"GLSL/light16.frag",
"GLSL/particle.frag",
"GLSL/light11.frag",
"GLSL/light10.frag",
"GLSL/light23.frag",
"GLSL/particle_stars.vert",
"GLSL/light24.frag",
"GLSL/light_explosion.vert",
"GLSL/particle.vert",
"GLSL/light15.frag",
"GLSL/light22.frag",
"GLSL/light13.frag",
"GLSL/light25.frag",
"GLSL/light26.frag",
"CREDITS/gentoo.tga",
"CREDITS/sdl.tga",
"CREDITS/opengl.tga",
"CREDITS/gnugcc.tga",
"CREDITS/tinyxml.tga",
"CREDITS/codeblocks.tga",
"CREDITS/openal.tga",
"CREDITS/svn.tga",
"cursor.tga",
"DATA_EN/VOICE/EngineMalfunction.wav",
"DATA_EN/VOICE/WeaponDamaged.wav",
"DATA_EN/VOICE/MissileDetected.wav",
"DATA_EN/VOICE/PrepareForAction.wav",
"DATA_EN/VOICE/Attention.wav",
"DATA_EN/VOICE/WeaponDestroyed.wav",
"DATA_EN/VOICE/WeaponMalfunction.wav",
"DATA_EN/VOICE/CeaseFire.wav",
"DATA_EN/VOICE/PowerSupplyReestablished.wav",
"DATA_EN/VOICE/ReactorMalfunction.wav",
"DATA_EN/VOICE/Warning.wav",
"DATA_EN/MENU/system_protect_empty.tga",
"DATA_EN/MENU/weapon_empty2_icon.tga",
"DATA_EN/MENU/system_protect1.tga",
"DATA_EN/MENU/system_target2.tga",
"DATA_EN/MENU/weapon_empty3_icon.tga",
"DATA_EN/MENU/button_weaponry_in.tga",
"DATA_EN/MENU/system_power2.tga",
"DATA_EN/MENU/system_engine2.tga",
"DATA_EN/MENU/system_target_empty.tga",
"DATA_EN/MENU/system_engine4.tga",
"DATA_EN/MENU/system_target1.tga",
"DATA_EN/MENU/system_mechan3.tga",
"DATA_EN/MENU/weapon_empty4_icon.tga",
"DATA_EN/MENU/button_weaponry_out.tga",
"DATA_EN/MENU/system_mechan1.tga",
"DATA_EN/MENU/weapon_empty1_icon.tga",
"DATA_EN/MENU/system_mechan4.tga",
"DATA_EN/MENU/system_power3.tga",
"DATA_EN/MENU/system_protect3.tga",
"DATA_EN/MENU/system_engine3.tga",
"DATA_EN/MENU/system_protect4.tga",
"DATA_EN/MENU/weapon_empty5_icon.tga",
"DATA_EN/MENU/system_target4.tga",
"DATA_EN/MENU/system_target3.tga",
"DATA_EN/MENU/system_mechan2.tga",
"DATA_EN/MENU/system_mechan_empty.tga",
"DATA_EN/MENU/system_engine_empty.tga",
"DATA_EN/MENU/system_protect2.tga",
"DATA_EN/MENU/weapon_empty_icon.tga",
"DATA_EN/MENU/system_engine1.tga",
"DATA_EN/MENU/system_power1.tga",
"DATA_EN/MENU/system_power_empty.tga",
"DATA_EN/MENU/system_power4.tga",
"DATA_EN/GAME/pause.tga",
"DATA_EN/GAME/mission.tga",
"DATA_EN/GAME/missionfailed.tga",
"DATA_EN/LOADING/loading_back.tga",
"DATA_EN/SCRIPT/text.xml",
"SFX/weaponfire12.wav",
"SFX/drag_offslot.wav",
"SFX/menu_click.wav",
"SFX/drag_error.wav",
"SFX/menu_onbutton.wav",
"SFX/weapon1probl.wav",
"SFX/weaponfire3.wav",
"SFX/gausshit.wav",
"SFX/menu_online.wav",
"SFX/weaponfire5.wav",
"SFX/weapon4probl.wav",
"SFX/drag_release.wav",
"SFX/menu_selectline.wav",
"SFX/weaponfire1.wav",
"SFX/weaponfire14.wav",
"SFX/weaponfire13.wav",
"SFX/weaponfire16.wav",
"SFX/weaponfire17.wav",
"SFX/explosion4.wav",
"SFX/weapon3probl.wav",
"SFX/plasmahit.wav",
"SFX/weaponfire19.wav",
"SFX/menu_nclick.wav",
"SFX/drag_onslot.wav",
"SFX/weaponfire10.wav",
"SFX/ionhit.wav",
"SFX/weaponfire6.wav",
"SFX/weaponfire7.wav",
"SFX/weaponfire15.wav",
"SFX/explosion2.wav",
"SFX/weaponfire8.wav",
"SFX/weaponfire2.wav",
"SFX/menu_onbutton2.wav",
"SFX/weaponfire18.wav",
"SFX/menu_new.wav",
"SFX/weaponfire4.wav",
"SFX/antimaterhit.wav",
"SFX/weapon5probl.wav",
"SFX/explosion3.wav",
"SFX/kinetichit.wav",
"SFX/weaponfire9.wav",
"SFX/menu_taping.wav",
"SFX/game_showmenu.wav",
"SFX/game_hidemenu.wav",
"SFX/weaponfire11.wav",
"SFX/weapon2probl.wav",
"SFX/explosion1.wav",
"SFX/lowlife.wav",
"MODELS/MILITARYBUILDING/artiler-gun-01.VW3D",
"MODELS/MILITARYBUILDING/aa-gun-03.VW3D",
"MODELS/MILITARYBUILDING/aa-gun-04.VW3D",
"MODELS/MILITARYBUILDING/aa-gun-05.VW3D",
"MODELS/MILITARYBUILDING/aa-gun-02.VW3D",
"MODELS/MILITARYBUILDING/aa-gun-01.VW3D",
"MODELS/MILITARYBUILDING/artiler-gun-02.VW3D",
"MODELS/track.jpg",
"MODELS/WHEELED/apc-04.VW3D",
"MODELS/WHEELED/jeep-01.VW3D",
"MODELS/WHEELED/apc-02.VW3D",
"MODELS/WHEELED/jeep-03.VW3D",
"MODELS/WHEELED/jeep-02.VW3D",
"MODELS/WHEELED/jeep-05.VW3D",
"MODELS/WHEELED/jeep-04.VW3D",
"MODELS/WHEELED/r-launcher-01.VW3D",
"MODELS/gr-04.jpg",
"MODELS/gr-07.jpg",
"MODELS/MINE/mine2i.jpg",
"MODELS/MINE/mine1.jpg",
"MODELS/MINE/mine3i.jpg",
"MODELS/MINE/mine3.jpg",
"MODELS/MINE/mine-04.VW3D",
"MODELS/MINE/mine-01.VW3D",
"MODELS/MINE/mine2.jpg",
"MODELS/MINE/mine-03.VW3D",
"MODELS/MINE/mine1i.jpg",
"MODELS/MINE/mine-02.VW3D",
"MODELS/MINE/mine4i.jpg",
"MODELS/MINE/mine4.jpg",
"MODELS/gr-01.jpg",
"MODELS/gr-06.jpg",
"MODELS/PLANET/planet5.VW3D",
"MODELS/PLANET/aplanet.VW3D",
"MODELS/PLANET/dplanet.VW3D",
"MODELS/PLANET/planet1.jpg",
"MODELS/PLANET/p5base.jpg",
"MODELS/PLANET/p5i.tga",
"MODELS/PLANET/planet3.jpg",
"MODELS/PLANET/planet6.VW3D",
"MODELS/PLANET/moon.tga",
"MODELS/PLANET/gplanet.VW3D",
"MODELS/PLANET/moon.VW3D",
"MODELS/PLANET/clouds.tga",
"MODELS/PLANET/asteroid.tga",
"MODELS/gr-03.jpg",
"MODELS/gr-05.jpg",
"MODELS/EARTHFIGHTER/sf-07.VW3D",
"MODELS/EARTHFIGHTER/sf-16.VW3D",
"MODELS/EARTHFIGHTER/sf-06.VW3D",
"MODELS/EARTHFIGHTER/swarm.VW3D",
"MODELS/EARTHFIGHTER/sf-09.VW3D",
"MODELS/EARTHFIGHTER/sf-01.VW3D",
"MODELS/EARTHFIGHTER/sf-text05.jpg",
"MODELS/EARTHFIGHTER/lnch34.jpg",
"MODELS/EARTHFIGHTER/sf-text09.jpg",
"MODELS/EARTHFIGHTER/sf-19.VW3D",
"MODELS/EARTHFIGHTER/lnch1.VW3D",
"MODELS/EARTHFIGHTER/lnch2.VW3D",
"MODELS/EARTHFIGHTER/sf-illum01.tga",
"MODELS/EARTHFIGHTER/sf-text00.jpg",
"MODELS/EARTHFIGHTER/sf-text10.jpg",
"MODELS/EARTHFIGHTER/sf-05.VW3D",
"MODELS/EARTHFIGHTER/sf-14.VW3D",
"MODELS/EARTHFIGHTER/sf-illum02.tga",
"MODELS/EARTHFIGHTER/sf-illum03.tga",
"MODELS/EARTHFIGHTER/sf-17.VW3D",
"MODELS/EARTHFIGHTER/rockets.jpg",
"MODELS/EARTHFIGHTER/sf-12.VW3D",
"MODELS/EARTHFIGHTER/sf-13.VW3D",
"MODELS/EARTHFIGHTER/lnch3.VW3D",
"MODELS/EARTHFIGHTER/sf-text08.jpg",
"MODELS/EARTHFIGHTER/sf-03.VW3D",
"MODELS/EARTHFIGHTER/sf-15.VW3D",
"MODELS/EARTHFIGHTER/sf-04.VW3D",
"MODELS/EARTHFIGHTER/sf-text07.jpg",
"MODELS/EARTHFIGHTER/torpedo.VW3D",
"MODELS/EARTHFIGHTER/sf-20.VW3D",
"MODELS/EARTHFIGHTER/missile.VW3D",
"MODELS/EARTHFIGHTER/lnch4.VW3D",
"MODELS/EARTHFIGHTER/sf-10.VW3D",
"MODELS/EARTHFIGHTER/sf-11.VW3D",
"MODELS/EARTHFIGHTER/nuke.VW3D",
"MODELS/EARTHFIGHTER/sf-22.VW3D",
"MODELS/EARTHFIGHTER/lnch12.jpg",
"MODELS/EARTHFIGHTER/sf-21.VW3D",
"MODELS/EARTHFIGHTER/sf-text06.jpg",
"MODELS/EARTHFIGHTER/sf-18.VW3D",
"MODELS/EARTHFIGHTER/sf-08.VW3D",
"MODELS/EARTHFIGHTER/sf-illum04.tga",
"MODELS/EARTHFIGHTER/weapons.VW3D",
"MODELS/EARTHFIGHTER/sf-text04.jpg",
"MODELS/EARTHFIGHTER/sf-02.VW3D",
"MODELS/ALIENMOTHERSHIP/alm-01.VW3D",
"MODELS/ALIENMOTHERSHIP/alm-04.VW3D",
"MODELS/ALIENMOTHERSHIP/alm-text04.jpg",
"MODELS/ALIENMOTHERSHIP/alm-text03.jpg",
"MODELS/ALIENMOTHERSHIP/alm-05.VW3D",
"MODELS/ALIENMOTHERSHIP/alm-illum04.tga",
"MODELS/ALIENMOTHERSHIP/alm-02.VW3D",
"MODELS/ALIENMOTHERSHIP/alm-03.VW3D",
"MODELS/ALIENMOTHERSHIP/alm-illum08.tga",
"MODELS/ALIENMOTHERSHIP/alm-illum03.tga",
"MODELS/ALIENMOTHERSHIP/alm-06.VW3D",
"MODELS/ALIENMOTHERSHIP/alm-07.VW3D",
"MODELS/ALIENMOTHERSHIP/alm-text02.jpg",
"MODELS/ALIENMOTHERSHIP/alm-text08.jpg",
"MODELS/ALIENMOTHERSHIP/alm-illum02.tga",
"MODELS/ALIENMOTHERSHIP/alm-08.VW3D",
"MODELS/TRACKED/apc-03.VW3D",
"MODELS/TRACKED/apc-01.VW3D",
"MODELS/TRACKED/tank-03.VW3D",
"MODELS/TRACKED/tank-09.VW3D",
"MODELS/TRACKED/tank-08.VW3D",
"MODELS/TRACKED/tank-07.VW3D",
"MODELS/TRACKED/tank-05.VW3D",
"MODELS/TRACKED/apc-aa-01.VW3D",
"MODELS/TRACKED/tank-01.VW3D",
"MODELS/TRACKED/engineering-01.VW3D",
"MODELS/TRACKED/tank-10.VW3D",
"MODELS/TRACKED/apc-aa-02.VW3D",
"MODELS/TRACKED/tank-06.VW3D",
"MODELS/TRACKED/tank-11.VW3D",
"MODELS/gr-02.jpg",
"MODELS/ALIENFIGHTER/al-04.VW3D",
"MODELS/ALIENFIGHTER/al-06.VW3D",
"MODELS/ALIENFIGHTER/al-12.VW3D",
"MODELS/ALIENFIGHTER/al-10.VW3D",
"MODELS/ALIENFIGHTER/al-16.VW3D",
"MODELS/ALIENFIGHTER/al-illum04.tga",
"MODELS/ALIENFIGHTER/al-13.VW3D",
"MODELS/ALIENFIGHTER/al-07.VW3D",
"MODELS/ALIENFIGHTER/al-02.VW3D",
"MODELS/ALIENFIGHTER/al-15.VW3D",
"MODELS/ALIENFIGHTER/al-03.VW3D",
"MODELS/ALIENFIGHTER/al-01.VW3D",
"MODELS/ALIENFIGHTER/al-14.VW3D",
"MODELS/ALIENFIGHTER/al-text04.jpg",
"MODELS/ALIENFIGHTER/al-08.VW3D",
"MODELS/ALIENFIGHTER/al-11.VW3D",
"MODELS/ALIENFIGHTER/al-17.VW3D",
"MODELS/ALIENFIGHTER/al-05.VW3D",
"MODELS/ALIENFIGHTER/al-09.VW3D",
"MODELS/BUILDING/bld-08.VW3D",
"MODELS/BUILDING/bld-06.VW3D",
"MODELS/BUILDING/bld-07.VW3D",
"MODELS/BUILDING/bld-02.VW3D",
"MODELS/BUILDING/bld.jpg",
"MODELS/BUILDING/bld-03.VW3D",
"MODELS/BUILDING/bld-09.VW3D",
"MODELS/BUILDING/bld-04.VW3D",
"MODELS/BUILDING/bld-05.VW3D",
"MODELS/BUILDING/bld_illum.tga",
"MODELS/BUILDING/bld-10.VW3D",
"MODELS/BUILDING/bld-01.VW3D",
"MODELS/BUILDING/bld-11.VW3D",
"MODELS/SPACEBASE/4/1.VW3D",
"MODELS/SPACEBASE/3/1.VW3D",
"MODELS/SPACEBASE/7/1.VW3D",
"MODELS/SPACEBASE/1/2.VW3D",
"MODELS/SPACEBASE/1/4.VW3D",
"MODELS/SPACEBASE/1/3.VW3D",
"MODELS/SPACEBASE/1/1.VW3D",
"MODELS/SPACEBASE/1/5.VW3D",
"MODELS/SPACEBASE/aster.jpg",
"MODELS/SPACEBASE/metal.jpg",
"MODELS/SPACEBASE/5/1.VW3D",
"MODELS/SPACEBASE/6/2.VW3D",
"MODELS/SPACEBASE/6/4.VW3D",
"MODELS/SPACEBASE/6/3.VW3D",
"MODELS/SPACEBASE/6/1.VW3D",
"MODELS/SPACEBASE/6/5.VW3D",
"MODELS/SPACEBASE/8/2.VW3D",
"MODELS/SPACEBASE/8/4.VW3D",
"MODELS/SPACEBASE/8/3.VW3D",
"MODELS/SPACEBASE/8/1.VW3D",
"MODELS/SPACEBASE/8/5.VW3D",
"MODELS/SPACEBASE/allalpha.tga",
"MODELS/SPACEBASE/2/2.VW3D",
"MODELS/SPACEBASE/2/4.VW3D",
"MODELS/SPACEBASE/2/3.VW3D",
"MODELS/SPACEBASE/2/1.VW3D",
"MODELS/SPACEBASE/2/5.VW3D",
"MODELS/PIRATESHIP/bomber-06.VW3D",
"MODELS/PIRATESHIP/gunship-01.VW3D",
"MODELS/PIRATESHIP/gunship-04.VW3D",
"MODELS/PIRATESHIP/gunship-03.VW3D",
"MODELS/PIRATESHIP/gunship-02.VW3D",
"MODELS/PIRATESHIP/bomber-04.VW3D",
"MODELS/PIRATESHIP/bomber-03.VW3D",
"MODELS/PIRATESHIP/bomber-05.VW3D",
"MODELS/PIRATESHIP/bomber-07.VW3D",
"MODELS/PIRATESHIP/bomber-02.VW3D",
"MODELS/TURRET/turret-02.VW3D",
"MODELS/TURRET/turret-01.VW3D",
"MODELS/TURRET/turrets.jpg",
"MODELS/SPACE/asteroid-0118.VW3D",
"MODELS/SPACE/asteroid-0116.VW3D",
"MODELS/SPACE/asteroid-011.VW3D",
"MODELS/SPACE/bigasteroid-03.VW3D",
"MODELS/SPACE/asteroid-018.VW3D",
"MODELS/SPACE/asteroid-017.VW3D",
"MODELS/SPACE/bigasteroid.jpg",
"MODELS/SPACE/asteroid-016.VW3D",
"MODELS/SPACE/bigasteroid-02.VW3D",
"MODELS/SPACE/bigasteroid-05.VW3D",
"MODELS/SPACE/asteroid-01.jpg",
"MODELS/SPACE/asteroid-0110.VW3D",
"MODELS/SPACE/asteroid-0115.VW3D",
"MODELS/SPACE/asteroid-0112.VW3D",
"MODELS/SPACE/asteroid-0117.VW3D",
"MODELS/SPACE/asteroid-012.VW3D",
"MODELS/SPACE/asteroid-019.VW3D",
"MODELS/SPACE/bigasteroid-01.VW3D",
"MODELS/SPACE/asteroid-013.VW3D",
"MODELS/SPACE/asteroid-0119.VW3D",
"MODELS/SPACE/asteroid-0114.VW3D",
"MODELS/SPACE/asteroid-014.VW3D",
"MODELS/SPACE/asteroid-0113.VW3D",
"MODELS/SPACE/asteroid-015.VW3D",
"MODELS/SPACE/bigasteroid-04.VW3D",
"MODELS/SPACE/asteroid-010.VW3D",
"MODELS/SPACE/asteroid-0111.VW3D",
"MENU/weapon4_icon.tga",
"MENU/ammo.tga",
"MENU/weapon17_icon.tga",
"MENU/workshop_panel1.tga",
"MENU/weapon18_icon.tga",
"MENU/weapon14_icon.tga",
"MENU/weapon19_icon.tga",
"MENU/weapon13_icon.tga",
"MENU/panel800_444_back.tga",
"MENU/button384_back.tga",
"MENU/panel444_333_back.tga",
"MENU/weapon2_icon.tga",
"MENU/button_dialog128_in.tga",
"MENU/weapon6_icon.tga",
"MENU/arrows_off.tga",
"MENU/workshop_panel5.tga",
"MENU/workshop_panel3.tga",
"MENU/dialog768_600.tga",
"MENU/dialog512_256.tga",
"MENU/perc_none.tga",
"MENU/weapon5_icon.tga",
"MENU/panel444_333_border.tga",
"MENU/button_dialog200_out.tga",
"MENU/workshop_panel4.tga",
"MENU/weapon12_icon.tga",
"MENU/whitepoint.tga",
"MENU/weapon16_icon.tga",
"MENU/weapon11_icon.tga",
"MENU/back_spot2.tga",
"MENU/button256_off.tga",
"MENU/blackpoint.tga",
"MENU/checkbox_main.tga",
"MENU/button_dialog200_off.tga",
"MENU/workshop_panel1+.tga",
"MENU/weapon10_icon.tga",
"MENU/perc.tga",
"MENU/workshop_panel2.tga",
"MENU/dialog512_512.tga",
"MENU/button_dialog200_in.tga",
"MENU/button384_out.tga",
"MENU/button384_in.tga",
"MENU/weapon15_icon.tga",
"MENU/workshop_panel2+.tga",
"MENU/line.tga",
"MENU/button256_out.tga",
"MENU/weapon3_icon.tga",
"MENU/button256_in.tga",
"MENU/back_spot.tga",
"MENU/button256_back.tga",
"MENU/weapon_on_icon.tga",
"MENU/system_onoff.tga",
"MENU/weapon8_icon.tga",
"MENU/arrows_on.tga",
"MENU/astromenace.tga",
"MENU/weapon9_icon.tga",
"MENU/weapon1_icon.tga",
"MENU/checkbox_in.tga",
"MENU/weapon7_icon.tga",
"MENU/button_dialog128_out.tga",
"MENU/button_dialog128_off.tga",
"GAME/ammo.tga",
"GAME/weapon_panel_left.tga",
"GAME/game_panel.tga",
"GAME/weapon_ammo.tga",
"GAME/game_panel2.tga",
"GAME/energy.tga",
"GAME/nums.tga",
"GAME/game_num.tga",
"GAME/weapon_panel_right.tga",
"GAME/game_panel_el.tga",
"GAME/weapon_energy.tga",
"GFX/flare2.tga",
"GFX/flare.tga",
"GFX/flare1.tga",
"GFX/flare3.tga",
"LOADING/viewizardlogo.jpg",
"LOADING/loading03.jpg",
"LOADING/loading_line.tga",
"LOADING/loading01.jpg",
"LOADING/loading02.jpg",
"LOADING/loading04.jpg",
"DATA_DE/VOICE/EngineMalfunction.wav",
"DATA_DE/VOICE/WeaponDamaged.wav",
"DATA_DE/VOICE/MissileDetected.wav",
"DATA_DE/VOICE/PrepareForAction.wav",
"DATA_DE/VOICE/Attention.wav",
"DATA_DE/VOICE/WeaponDestroyed.wav",
"DATA_DE/VOICE/WeaponMalfunction.wav",
"DATA_DE/VOICE/CeaseFire.wav",
"DATA_DE/VOICE/PowerSupplyReestablished.wav",
"DATA_DE/VOICE/ReactorMalfunction.wav",
"DATA_DE/VOICE/Warning.wav",
"DATA_DE/MENU/system_protect_empty.tga",
"DATA_DE/MENU/weapon_empty2_icon.tga",
"DATA_DE/MENU/system_protect1.tga",
"DATA_DE/MENU/system_target2.tga",
"DATA_DE/MENU/weapon_empty3_icon.tga",
"DATA_DE/MENU/button_weaponry_in.tga",
"DATA_DE/MENU/system_power2.tga",
"DATA_DE/MENU/system_engine2.tga",
"DATA_DE/MENU/system_target_empty.tga",
"DATA_DE/MENU/system_engine4.tga",
"DATA_DE/MENU/system_target1.tga",
"DATA_DE/MENU/system_mechan3.tga",
"DATA_DE/MENU/weapon_empty4_icon.tga",
"DATA_DE/MENU/button_weaponry_out.tga",
"DATA_DE/MENU/system_mechan1.tga",
"DATA_DE/MENU/weapon_empty1_icon.tga",
"DATA_DE/MENU/system_mechan4.tga",
"DATA_DE/MENU/system_power3.tga",
"DATA_DE/MENU/system_protect3.tga",
"DATA_DE/MENU/system_engine3.tga",
"DATA_DE/MENU/system_protect4.tga",
"DATA_DE/MENU/weapon_empty5_icon.tga",
"DATA_DE/MENU/system_target4.tga",
"DATA_DE/MENU/system_target3.tga",
"DATA_DE/MENU/system_mechan2.tga",
"DATA_DE/MENU/system_mechan_empty.tga",
"DATA_DE/MENU/system_engine_empty.tga",
"DATA_DE/MENU/system_protect2.tga",
"DATA_DE/MENU/weapon_empty_icon.tga",
"DATA_DE/MENU/system_engine1.tga",
"DATA_DE/MENU/system_power1.tga",
"DATA_DE/MENU/system_power_empty.tga",
"DATA_DE/MENU/system_power4.tga",
"DATA_DE/GAME/pause.tga",
"DATA_DE/GAME/mission.tga",
"DATA_DE/GAME/missionfailed.tga",
"DATA_DE/LOADING/loading_back.tga",
"DATA_DE/SCRIPT/text.xml",
"cursor_shadow.tga",
"MUSIC/boss-intro.ogg",
"MUSIC/menu.ogg",
"MUSIC/boss-loop.ogg",
"MUSIC/game.ogg",
"MUSIC/missionfailed.ogg",
"MUSIC/intro.ogg",
"SCRIPT/mission6.xml",
"SCRIPT/list.xml",
"SCRIPT/mission14.xml",
"SCRIPT/mission8.xml",
"SCRIPT/mission9_icon.tga",
"SCRIPT/mission15_icon.tga",
"SCRIPT/mission3.xml",
"SCRIPT/mission7.xml",
"SCRIPT/mission12.xml",
"SCRIPT/mission5.xml",
"SCRIPT/mission1.xml",
"SCRIPT/mission10_icon.tga",
"SCRIPT/mission13_icon.tga",
"SCRIPT/menu3.xml",
"SCRIPT/mission5_icon.tga",
"SCRIPT/mission13.xml",
"SCRIPT/mission14_icon.tga",
"SCRIPT/mission6_icon.tga",
"SCRIPT/mission3_icon.tga",
"SCRIPT/mission11.xml",
"SCRIPT/mission4.xml",
"SCRIPT/mission2.xml",
"SCRIPT/mission11_icon.tga",
"SCRIPT/mission4_icon.tga",
"SCRIPT/mission8_icon.tga",
"SCRIPT/mission7_icon.tga",
"SCRIPT/aimode.xml",
"SCRIPT/mission10.xml",
"SCRIPT/mission2_icon.tga",
"SCRIPT/mission12_icon.tga",
"SCRIPT/menu2.xml",
"SCRIPT/mission15.xml",
"SCRIPT/mission1_icon.tga",
"SCRIPT/mission9.xml",
"SCRIPT/menu1.xml",
"SKYBOX/3/skybox_FR.jpg",
"SKYBOX/3/skybox_LF.jpg",
"SKYBOX/3/skybox_RT.jpg",
"SKYBOX/3/skybox_BK.jpg",
"SKYBOX/3/skybox_DN.jpg",
"SKYBOX/3/skybox_UP.jpg",
"SKYBOX/1/skybox_FR.jpg",
"SKYBOX/1/skybox_LF.jpg",
"SKYBOX/1/skybox_RT.jpg",
"SKYBOX/1/skybox_BK.jpg",
"SKYBOX/1/skybox_DN.jpg",
"SKYBOX/1/skybox_UP.jpg",
"SKYBOX/tile_14.jpg",
"SKYBOX/2/skybox_FR.jpg",
"SKYBOX/2/skybox_LF.jpg",
"SKYBOX/2/skybox_RT.jpg",
"SKYBOX/2/skybox_BK.jpg",
"SKYBOX/2/skybox_DN.jpg",
"SKYBOX/2/skybox_UP.jpg",
"FONT/LiberationMono-Bold.ttf",
"CREDITS/freetype.tga",
"CREDITS/oggvorbis.tga"};




//------------------------------------------------------------------------------------
// конвертирование данных в VFS файл
//------------------------------------------------------------------------------------
int ConvertFS2VFS(char RawDataDir[MAX_PATH])
{
	// создаем новый файл VFS
	vw_CreateVFS(VFSFileNamePath);


	// используем не авто поиск по дирректориям, как было, а заранее сформированный список
	// 1) файлы очень редко удаляются/добавляются
	// 2) нужно обязательно проверить "целостность" всей сборки на наличие всех файлов
	// 3) будет работать на любой платформе где работает libSDL


	char SrcFileName[MAX_PATH];
	char DstFileName[MAX_PATH];


	for (int i=0; i<ConvertListCount; i++)
	{

		strcpy(SrcFileName, RawDataDir);
		strcat(SrcFileName, ConvertList[i]);

		// все наши файлы внутри VFS лежат в директории DATA
		strcpy(DstFileName, "DATA/");
		strcat(DstFileName, ConvertList[i]);


		// читаем данные файла в буфер
		SDL_RWops *Ftmp = SDL_RWFromFile(SrcFileName, "rb");
		// Если файл не найден - выходим
		if (Ftmp == NULL)
    	{
			fprintf(stderr, "Can't find file %s !!!\n", SrcFileName);
			fprintf(stderr, "VFS compilation process aborted!\n");
        	return -1;
    	}

		// получаем размер файла
		SDL_RWseek(Ftmp, 0, SEEK_END);
		int tmpLength = SDL_RWtell(Ftmp);
		SDL_RWseek(Ftmp, 0, SEEK_SET);

		// копируем все данные файла в массив
		BYTE *tmp = 0;
		tmp = new BYTE[tmpLength];
		SDL_RWread(Ftmp, tmp, tmpLength, 1);
		SDL_RWclose(Ftmp);

		// запись в VFS
		if (0 != vw_WriteIntoVFSfromMemory(DstFileName, tmp, tmpLength))
		{
			// какая-то ошибка, не можем записать в VFS
			delete [] tmp; tmp = 0;
			fprintf(stderr, "Can't write into VFS from memory %s !!!\n", DstFileName);
			fprintf(stderr, "VFS compilation process aborted!\n");
			return -1;
		}

		// Освобождаем память
		delete [] tmp; tmp = 0;
	}


	// закрываем VFS файл
	vw_CloseVFS();

	return 0;
}




