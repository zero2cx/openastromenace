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


#include "Math.h"



//------------------------------------------------------------------------------------
// Cosine Tab
//------------------------------------------------------------------------------------
double Cos[360] = {1.000000,0.999848,0.999391,0.998630,0.997564,0.996195,0.994522,
	0.992546,0.990268,0.987688,0.984808,0.981627,0.978148,0.974370,
	0.970296,0.965926,0.961262,0.956305,0.951057,0.945519,0.939693,
	0.933580,0.927184,0.920505,0.913545,0.906308,0.898794,0.891007,
	0.882948,0.874620,0.866025,0.857167,0.848048,0.838671,0.829038,
	0.819152,0.809017,0.798636,0.788011,0.777146,0.766044,0.754710,
	0.743145,0.731354,0.719340,0.707107,0.694658,0.681998,0.669131,
	0.656059,0.642788,0.629320,0.615661,0.601815,0.587785,0.573576,
	0.559193,0.544639,0.529919,0.515038,0.500000,0.484810,0.469472,
	0.453990,0.438371,0.422618,0.406737,0.390731,0.374607,0.358368,
	0.342020,0.325568,0.309017,0.292372,0.275637,0.258819,0.241922,
	0.224951,0.207912,0.190809,0.173648,0.156434,0.139173,0.121869,
	0.104528,0.087156,0.069756,0.052336,0.034899,0.017452,0.000000,
	-0.017452,-0.034899,-0.052336,-0.069756,-0.087156,-0.104528,
	-0.121869,-0.139173,-0.156434,-0.173648,-0.190809,-0.207912,
	-0.224951,-0.241922,-0.258819,-0.275637,-0.292372,-0.309017,
	-0.325568,-0.342020,-0.358368,-0.374607,-0.390731,-0.406737,
	-0.422618,-0.438371,-0.453990,-0.469472,-0.484810,-0.500000,
	-0.515038,-0.529919,-0.544639,-0.559193,-0.573576,-0.587785,
	-0.601815,-0.615661,-0.629320,-0.642788,-0.656059,-0.669131,
	-0.681998,-0.694658,-0.707107,-0.719340,-0.731354,-0.743145,
	-0.754710,-0.766044,-0.777146,-0.788011,-0.798636,-0.809017,
	-0.819152,-0.829038,-0.838671,-0.848048,-0.857167,-0.866025,
	-0.874620,-0.882948,-0.891007,-0.898794,-0.906308,-0.913545,
	-0.920505,-0.927184,-0.933580,-0.939693,-0.945519,-0.951057,
	-0.956305,-0.961262,-0.965926,-0.970296,-0.974370,-0.978148,
	-0.981627,-0.984808,-0.987688,-0.990268,-0.992546,-0.994522,
	-0.996195,-0.997564,-0.998630,-0.999391,-0.999848,-1.000000,
	-0.999848,-0.999391,-0.998630,-0.997564,-0.996195,-0.994522,
	-0.992546,-0.990268,-0.987688,-0.984808,-0.981627,-0.978148,
	-0.974370,-0.970296,-0.965926,-0.961262,-0.956305,-0.951057,
	-0.945519,-0.939693,-0.933580,-0.927184,-0.920505,-0.913545,
	-0.906308,-0.898794,-0.891007,-0.882948,-0.874620,-0.866025,
	-0.857167,-0.848048,-0.838671,-0.829038,-0.819152,-0.809017,
	-0.798636,-0.788011,-0.777146,-0.766044,-0.754710,-0.743145,
	-0.731354,-0.719340,-0.707107,-0.694658,-0.681998,-0.669131,
	-0.656059,-0.642788,-0.629320,-0.615661,-0.601815,-0.587785,
	-0.573576,-0.559193,-0.544639,-0.529919,-0.515038,-0.500000,
	-0.484810,-0.469472,-0.453990,-0.438371,-0.422618,-0.406737,
	-0.390731,-0.374607,-0.358368,-0.342020,-0.325568,-0.309017,
	-0.292372,-0.275637,-0.258819,-0.241922,-0.224951,-0.207912,
	-0.190809,-0.173648,-0.156434,-0.139173,-0.121869,-0.104528,
	-0.087156,-0.069756,-0.052336,-0.034899,-0.017452,-0.000000,
	0.017452,0.034899,0.052336,0.069756,0.087156,0.104528,0.121869,
	0.139173,0.156434,0.173648,0.190809,0.207912,0.224951,0.241922,
	0.258819,0.275637,0.292372,0.309017,0.325568,0.342020,
	0.358368,0.374607,0.390731,0.406737,0.422618,0.438371,0.453990,
	0.469472,0.484810,0.500000,0.515038,0.529919,0.544639,0.559193,
	0.573576,0.587785,0.601815,0.615661,0.629320,0.642788,0.656059,
	0.669131,0.681998,0.694658,0.707107,0.719340,0.731354,0.743145,
	0.754710,0.766044,0.777146,0.788011,0.798636,0.809017,0.819152,
	0.829038,0.838671,0.848048,0.857167,0.866025,0.874620,0.882948,
	0.891007,0.898794,0.906308,0.913545,0.920505,0.927184,0.933580,
	0.939693,0.945519,0.951057,0.956305,0.961262,0.965926,0.970296,
	0.974370,0.978148,0.981627,0.984808,0.987688,0.990268,0.992546,
	0.994522,0.996195,0.997564,0.998630,0.999391,0.999848};

//------------------------------------------------------------------------------------
// Get Cosine
//------------------------------------------------------------------------------------
double vw_dcos(int Angle)
{
	return Cos[Angle];
}









//------------------------------------------------------------------------------------
// Sine Tab
//------------------------------------------------------------------------------------
double Sin[360] = {0.000000,0.017452,0.034899,0.052336,0.069756,0.087156,
	0.104528,0.121869,0.139173,0.156434,0.173648,0.190809,0.207912,
	0.224951,0.241922,0.258819,0.275637,0.292372,0.309017,0.325568,
	0.342020,0.358368,0.374607,0.390731,0.406737,0.422618,0.438371,
	0.453990,0.469472,0.484810,0.500000,0.515038,0.529919,0.544639,
	0.559193,0.573576,0.587785,0.601815,0.615661,0.629320,0.642788,
	0.656059,0.669131,0.681998,0.694658,0.707107,0.719340,0.731354,
	0.743145,0.754710,0.766044,0.777146,0.788011,0.798636,0.809017,
	0.819152,0.829038,0.838671,0.848048,0.857167,0.866025,0.874620,
	0.882948,0.891007,0.898794,0.906308,0.913545,0.920505,0.927184,
	0.933580,0.939693,0.945519,0.951057,0.956305,0.961262,0.965926,
	0.970296,0.974370,0.978148,0.981627,0.984808,0.987688,0.990268,
	0.992546,0.994522,0.996195,0.997564,0.998630,0.999391,0.999848,
	1.000000,0.999848,0.999391,0.998630,0.997564,0.996195,0.994522,
	0.992546,0.990268,0.987688,0.984808,0.981627,0.978148,0.974370,
	0.970296,0.965926,0.961262,0.956305,0.951057,0.945519,0.939693,
	0.933580,0.927184,0.920505,0.913545,0.906308,0.898794,0.891007,
	0.882948,0.874620,0.866025,0.857167,0.848048,0.838671,0.829038,
	0.819152,0.809017,0.798636,0.788011,0.777146,0.766044,0.754710,
	0.743145,0.731354,0.719340,0.707107,0.694658,0.681998,0.669131,
	0.656059,0.642788,0.629320,0.615661,0.601815,0.587785,0.573576,
	0.559193,0.544639,0.529919,0.515038,0.500000,0.484810,0.469472,
	0.453990,0.438371,0.422618,0.406737,0.390731,0.374607,0.358368,
	0.342020,0.325568,0.309017,0.292372,0.275637,0.258819,0.241922,
	0.224951,0.207912,0.190809,0.173648,0.156434,0.139173,0.121869,
	0.104528,0.087156,0.069756,0.052336,0.034899,0.017452,0.000000,
	-0.017452,-0.034899,-0.052336,-0.069756,-0.087156,-0.104528,
	-0.121869,-0.139173,-0.156434,-0.173648,-0.190809,-0.207912,
	-0.224951,-0.241922,-0.258819,-0.275637,-0.292372,-0.309017,
	-0.325568,-0.342020,-0.358368,-0.374607,-0.390731,-0.406737,
	-0.422618,-0.438371,-0.453990,-0.469472,-0.484810,-0.500000,
	-0.515038,-0.529919,-0.544639,-0.559193,-0.573576,-0.587785,
	-0.601815,-0.615661,-0.629320,-0.642788,-0.656059,-0.669131,
	-0.681998,-0.694658,-0.707107,-0.719340,-0.731354,-0.743145,
	-0.754710,-0.766044,-0.777146,-0.788011,-0.798636,-0.809017,
	-0.819152,-0.829038,-0.838671,-0.848048,-0.857167,-0.866025,
	-0.874620,-0.882948,-0.891007,-0.898794,-0.906308,-0.913545,
	-0.920505,-0.927184,-0.933580,-0.939693,-0.945519,-0.951057,
	-0.956305,-0.961262,-0.965926,-0.970296,-0.974370,-0.978148,
	-0.981627,-0.984808,-0.987688,-0.990268,-0.992546,-0.994522,
	-0.996195,-0.997564,-0.998630,-0.999391,-0.999848,-1.000000,
	-0.999848,-0.999391,-0.998630,-0.997564,-0.996195,-0.994522,
	-0.992546,-0.990268,-0.987688,-0.984808,-0.981627,-0.978148,
	-0.974370,-0.970296,-0.965926,-0.961262,-0.956305,-0.951057,
	-0.945519,-0.939693,-0.933580,-0.927184,-0.920505,-0.913545,
	-0.906308,-0.898794,-0.891007,-0.882948,-0.874620,-0.866025,
	-0.857167,-0.848048,-0.838671,-0.829038,-0.819152,-0.809017,
	-0.798636,-0.788011,-0.777146,-0.766044,-0.754710,-0.743145,
	-0.731354,-0.719340,-0.707107,-0.694658,-0.681998,-0.669131,
	-0.656059,-0.642788,-0.629320,-0.615661,-0.601815,-0.587785,
	-0.573576,-0.559193,-0.544639,-0.529919,-0.515038,-0.500000,
	-0.484810,-0.469472,-0.453990,-0.438371,-0.422618,-0.406737,
	-0.390731,-0.374607,-0.358368,-0.342020,-0.325568,-0.309017,
	-0.292372,-0.275637,-0.258819,-0.241922,-0.224951,-0.207912,
	-0.190809,-0.173648,-0.156434,-0.139173,-0.121869,-0.104528,
	-0.087156,-0.069756,-0.052336,-0.034899,-0.017452};

//------------------------------------------------------------------------------------
// Get Sine
//------------------------------------------------------------------------------------
double vw_dsin(int Angle)
{
	return Sin[Angle];
}








//------------------------------------------------------------------------------------
// Fast string comparison
//------------------------------------------------------------------------------------
int vw_strcmp(const char *a, const char *b)
{
	while(*a == *b)
	{
		if(*a == '\0')return 0;
		a++;
		b++;
	}
	return 1;
}





//------------------------------------------------------------------------------------
// преобразуем утф8 в утф32, как результат возвращаем указатель на след утф8 символ
//------------------------------------------------------------------------------------
const char* utf8_to_utf32(const char* utf8, unsigned* utf32)
{
	unsigned char* u_utf8 = (unsigned char*) utf8;

	unsigned char b = *u_utf8++;

	if (!(b & 0x80))
	{
		if (utf32)
			*utf32 = b;
		return utf8 + 1;
	}

	unsigned len = 0;
	while (b & 0x80)
	{
		b <<= 1;
		++len;
	}

	unsigned c = b;
	unsigned shift = 6 - len;

	while (--len)
	{
		c <<= shift;
		c |= (*u_utf8++) & 0x3f;
		shift = 6;
	}

	if (utf32)
		*utf32 = c;

	return (char*) u_utf8;
}





//------------------------------------------------------------------------------------
// Fast root (without sqrtf)
//------------------------------------------------------------------------------------
#ifdef WIN32 // для MSVC используем
float __fastcall InvSqrt(const float x)
#else
float InvSqrt(const float x)
#endif
{
	union
	{
		float f;
		int i;
	} t;
	float y;

	t.f = x;
	t.i = 0x5f3759df - (t.i >> 1);
	y = t.f;
	y = y * (1.5F - (0.5F * x * y * y));

 	return y;
}

float vw_sqrtf(float x)
{
	return x*InvSqrt(x);
}





//------------------------------------------------------------------------------------
// Rand
//------------------------------------------------------------------------------------
#include "MersenneTwister.h"
MTRand mtrand1;

float vw_fRand()
{
	// 0.0f - 1.0f
	return mtrand1.rand();
}

float vw_fRandNum(float Max)
{
	// 0.0f - Max
	return mtrand1.rand(Max);
}

int vw_iRandNum(int Max)
{
	// 0 - Max
	return mtrand1.randInt(Max);
}












//------------------------------------------------------------------------------------
// Fast normalization...
//------------------------------------------------------------------------------------
void Normalise(VECTOR3D *v)
{
	float L_squared, one_over_L;
	L_squared = (v->x * v->x) + (v->y * v->y) + (v->z * v->z);
	one_over_L = InvSqrt(L_squared);
	v->x = v->x * one_over_L;
	v->y = v->y * one_over_L;
	v->z = v->z * one_over_L;
}


//------------------------------------------------------------------------------------
// Точная нормализация
//------------------------------------------------------------------------------------
void NormaliseHi(VECTOR3D *v)
{
	float Length;
	Length = sqrtf((v->x * v->x) + (v->y * v->y) + (v->z * v->z));
	if (Length < 0.001f) return; // если все координаты очень маленькие
	v->x = v->x / Length;
	v->y = v->y / Length;
	v->z = v->z / Length;
}




//------------------------------------------------------------------------------------
// 3D Vector
//------------------------------------------------------------------------------------
float VECTOR3D::Length()
{
	return vw_sqrtf(x * x + y * y + z * z);
}

void VECTOR3D::Normalize()
{
	Normalise(this);
}

void VECTOR3D::NormalizeHi()
{
	NormaliseHi(this);
}

void VECTOR3D::Multiply( VECTOR3D A)
{
	float tV[3];
	tV[0] = y * A.z - z * A.y;
	tV[1] = z * A.x - x * A.z;
	tV[2] = x * A.y - y * A.x;
	x = tV[0];
	y = tV[1];
	z = tV[2];
}











//------------------------------------------------------------------------------------
// Get max
//------------------------------------------------------------------------------------
float Max3(float a1,float a2,float a3)
{
	if ((a1>=a2)&(a1>=a3)){return a1;}
	if ((a2>=a1)&(a2>=a3)){return a2;}
	if ((a3>=a1)&(a3>=a2)){return a3;}
	return a1;
}







//------------------------------------------------------------------------------------
// Get min
//------------------------------------------------------------------------------------
float Min3(float a1,float a2,float a3)
{
	if ((a1<=a2)&(a1<=a3)){return a1;}
	if ((a2<=a1)&(a2<=a3)){return a2;}
	if ((a3<=a1)&(a3<=a2)){return a3;}
	return a1;
}









//-----------------------------------------------------------------------------
// Get Plane ABCD value, via 3 points on plane
//-----------------------------------------------------------------------------
void GetPlaneABCD(float *A, float *B, float *C, float *D, VECTOR3D Point1, VECTOR3D Point2, VECTOR3D Point3)
{
	*A = (Point2.y-Point1.y)*(Point3.z-Point1.z)-(Point2.z-Point1.z)*(Point3.y-Point1.y);
	*B = (Point2.z-Point1.z)*(Point3.x-Point1.x)-(Point2.x-Point1.x)*(Point3.z-Point1.z);
	*C = (Point2.x-Point1.x)*(Point3.y-Point1.y)-(Point2.y-Point1.y)*(Point3.x-Point1.x);
	*D = -Point1.x*(Point2.y-Point1.y)*(Point3.z-Point1.z)
			-Point1.y*(Point2.z-Point1.z)*(Point3.x-Point1.x)
			-Point1.z*(Point2.x-Point1.x)*(Point3.y-Point1.y)
			+Point1.z*(Point2.y-Point1.y)*(Point3.x-Point1.x)
			+Point1.y*(Point2.x-Point1.x)*(Point3.z-Point1.z)
			+Point1.x*(Point2.z-Point1.z)*(Point3.y-Point1.y);
}









//------------------------------------------------------------------------------------
// Rotate point on Angle regard to point(0,0,0)
//------------------------------------------------------------------------------------
const float p180 = 0.0174532925f;
void RotatePoint(VECTOR3D *Point, VECTOR3D Angle)
{
	float xTMP = Point->x;
	float yTMP = Point->y;
	float zTMP = Point->z;

		// X
		if (Angle.x != 0)
		{
			float a = -Angle.x*p180;
			float c = cosf(a);
			float s = sinf(a);
			Point->y = yTMP*c + zTMP*s;
			Point->z = -yTMP*s + zTMP*c;
			xTMP = Point->x;
			yTMP = Point->y;
			zTMP = Point->z;
		}

		// Y
		if (Angle.y != 0)
		{
			float a = Angle.y*p180;
			float c = cosf(a);
			float s = sinf(a);
			Point->x = xTMP*c + zTMP*s;
			Point->z = -xTMP*s + zTMP*c;
			xTMP = Point->x;
			yTMP = Point->y;
		}

		// Z
		if (Angle.z != 0)
		{
			float a = -Angle.z*p180;
			float c = cosf(a);
			float s = sinf(a);
			Point->x = xTMP*c + yTMP*s;
			Point->y = -xTMP*s + yTMP*c;
		}
}


//------------------------------------------------------------------------------------
// обратный поворот точки (обратная последовательность поворота по осям)
//------------------------------------------------------------------------------------
void RotatePointInv(VECTOR3D *Point, VECTOR3D Angle)
{
	float xTMP = Point->x;
	float yTMP = Point->y;
	float zTMP = Point->z;

		// Z
		if (Angle.z != 0)
		{
			float a = -Angle.z*p180;
			float c = cosf(a);
			float s = sinf(a);
			Point->x = xTMP*c + yTMP*s;
			Point->y = -xTMP*s + yTMP*c;
			xTMP = Point->x;
			yTMP = Point->y;
			zTMP = Point->z;
		}

		// Y
		if (Angle.y != 0)
		{
			float a = Angle.y*p180;
			float c = cosf(a);
			float s = sinf(a);
			Point->x = xTMP*c + zTMP*s;
			Point->z = -xTMP*s + zTMP*c;
			yTMP = Point->y;
			zTMP = Point->z;
		}

		// X
		if (Angle.x != 0)
		{
			float a = -Angle.x*p180;
			float c = cosf(a);
			float s = sinf(a);
			Point->y = yTMP*c + zTMP*s;
			Point->z = -yTMP*s + zTMP*c;
		}
}
