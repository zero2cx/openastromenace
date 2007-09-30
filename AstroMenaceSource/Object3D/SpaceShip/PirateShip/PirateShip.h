/******************************************************************************

	This source file is part of AstroMenace game
	(Hardcore 3D space shooter with spaceship upgrade possibilities.)
	For the latest info, see http://www.viewizard.com/

	File name: PirateShip.h

	Copyright (c) 2006-2007 Michael Kurinnoy, Viewizard
	All Rights Reserved.

	File Version: 1.2

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


#ifndef PIRATESHIP_H
#define PIRATESHIP_H


#include "../SpaceShip.h"



//-----------------------------------------------------------------------------
// Класс CPirateShip
//-----------------------------------------------------------------------------
class CPirateShip : public CSpaceShip
{
public:

	virtual ~CPirateShip(){};

	// Создание нужного объекта
	virtual void	Create(int	PirateShipNum);

};




//-----------------------------------------------------------------------------
// Дополнительные функции для CPirateShip
//-----------------------------------------------------------------------------

// Создание двигателя
void SetPirateShipEngine(eParticleSystem *ParticleSystem, int EngineType);




#endif // PIRATESHIP_H
