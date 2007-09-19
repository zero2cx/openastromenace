/////////////////////////////////////////////////
// Viewizard Game Engine
/////////////////////////////////////////////////
// File: haff.cpp
/////////////////////////////////////////////////
// Copyright (c) 2001-2006, Michael Kurinnoy
// All Rights Reserved.
/////////////////////////////////////////////////
// Ver : 2.0
/////////////////////////////////////////////////

// Function:
// vw_DATAtoHAFF
// vw_HAFFtoDATA

#include "vfs_var.h"






////////////////////////////////////////////////////////////
// ������� ������ ������� �������� � ������������ ��������
////////////////////////////////////////////////////////////
int vw_DATAtoHAFF()
{
	// ���. ������ ��������� ������� ������...
    // �������� ������ � ��������� ������� �������...
	byte Count[256]; // ���������� ����� (���) �������� � �������...
	int  mathTab[256]; // ���-�� ��������� ������� ��-��...
	int  TabCount = 0;// ���-�� ���������... (��� ����������� �����. �������...)
    short bitMask[256]; // ������� ����� ��� ������� ��-�� �������...(2 ���� - �� ����.)
	int bitMaskS[256]; // ���������� ��� � �����...
	dsizeVFS = 0;

    // ������� ������ (����) � �������...����. ����. ���������...
    for (int i = 0; i < 256; i++) 
	{
		Count[i] = i;
		mathTab[i] = 0;
		bitMask[i] = 0;
		bitMaskS[i] = 0;
	}

	// ��������� ������...
    for (int i = 0; i < ssizeVFS; i++) mathTab[srcVFS[i]]++;

	// �������������� ���������� �������...
    // ��������� ������ �� ����������� ���-�� ���������...����������� ����������
	for (int i = 0; i < 255; i++) 
		for (int j = 0; j < 255; j++) 
			if (mathTab[j+1] > mathTab[j])
			{
				int tmp1 = mathTab[j+1];
				mathTab[j+1] = mathTab[j];
				mathTab[j] = tmp1;
				byte tmp2 = Count[j+1];
				Count[j+1] = Count[j];
				Count[j] = tmp2;
			}

	// ������� ��������, ������� ���� � ������������������ (�.� ������ ��-�� ������. ����.)
	for (int i = 0; i < 256; i++) 
		if (mathTab[i] >0) TabCount++;

    // ���������� ����� ��� ������������ ���������....
    // ��� 0...
    bitMask[0] = 0;
    bitMaskS[0] = 1;
    // ��� 1...
    bitMask[1] = 2;
    bitMaskS[1] = 2;
    // ��� 2,3...
	for (int i = 2; i < 4; i++) 
    {
		bitMask[i] = i-2;
		bitMask[i] = bitMask[i] | 12; // 1100
		bitMaskS[i] = 4;
	}
    // ��� 4,7...
	for (int i = 4; i < 8; i++) 
    {
		bitMask[i] = i-4;
		bitMask[i] = bitMask[i] | 56; // 111000
		bitMaskS[i] = 6;
	}
    // ��� 8,15...
	for (int i = 8; i < 16; i++) 
    {
		bitMask[i] = i-8;
		bitMask[i] = bitMask[i] | 240; // 11110000
		bitMaskS[i] = 8;
	}
    // ��� 16,31...
	for (int i = 16; i < 32; i++) 
    {
		bitMask[i] = i-16;
		bitMask[i] = bitMask[i] | 992; // 1111100000
		bitMaskS[i] = 10;
	}
    // ��� 32,63...
	for (int i = 32; i < 64; i++) 
    {
		bitMask[i] = i-32;
		bitMask[i] = bitMask[i] | 4032; // 11111110000000
		bitMaskS[i] = 12;
	}
    // ��� 64,127...
	for (int i = 64; i < 128; i++) 
    {
		bitMask[i] = i-64;
		bitMask[i] = bitMask[i] | 16256; // 11111110000000
		bitMaskS[i] = 14;
	}
    // ��� 128,255...
	for (int i = 128; i < 256; i++) 
    {
		bitMask[i] = i-128;
		bitMask[i] = bitMask[i] | 65280; // 1111111100000000
		bitMaskS[i] = 16;
	}

	// ������� ���-�� ������������ �����...
    dsizeVFS ++;// ���-�� ��������� � �������...
    dsizeVFS += TabCount;// ����� ��� �������...
    // ��������� ����� ��� ������...
	int tmp = 0;
    for (int i = 0; i < TabCount; i++) 
	{
		tmp += (mathTab[i] * bitMaskS[i]);
	}
	dsizeVFS += 4 ; //������� ���...
    dsizeVFS += tmp / 8 +1;// �.�. ������� � �����...

    // ����������� ������...
	dstVFS = 0;
    dstVFS = new byte[dsizeVFS];
	if (dstVFS == 0) return 0;

    // ������� �������� ������������������...
    int j = 0; // ��������� �� ������� � ��������������� ������.

	// ���������� ������� ���...
	dstVFS[j] =  (byte)tmp;
	j++;
    tmp /= 0x100;
	dstVFS[j] =  (byte)tmp;
	j++;
    tmp /= 0x100;
	dstVFS[j] =  (byte)tmp;
	j++;
    tmp /= 0x100;
	dstVFS[j] =  (byte)tmp;
	j++;

	// ���������� ���-�� ������ � �������...
	dstVFS[j] = (byte)(TabCount-1) ;// ����� ���� �� 0 �� 255 ...
	j++;
	// ����� �������...
    for (int i = 0; i < TabCount; i++) 
	{
		dstVFS[j] = Count[i];// ���������� ������ ���...
		j++;
	}
    // "����������������" ������� �� ��������� ������������������...
    short tmbitMask[256]; 
	int tmbitMaskS[256]; 
    for (int i = 0; i < 256; i++) 
	{
		tmbitMask[Count[i]] = bitMask[i]; 
		tmbitMaskS[Count[i]] = bitMaskS[i];
	}


    // ���������� ������ � ������...
	short tmpMask = 0;// �����, � ������� ����� ��������...
    int BitWr = 0; // ���-�� ���, ������� ���� �������� �� �����...
	int DstBA = 0; // ������� ��������� �� �������� ��� � ����� �������. �������...
    byte T = 0; // ������� ��� �� ���������...
	dstVFS[j] = 0; // ������������� �� ���...

    for (int i = 0; i < ssizeVFS; i++) 
	{
		// ����� �������� ������... 
		tmpMask = tmbitMask[srcVFS[i]];
		BitWr = tmbitMaskS[srcVFS[i]];

 		// ���. ������� ���...
		//tmpMask = (short)(tmpMask * exp( (16-BitWr) * log(2)));
		if (BitWr == 1) tmpMask = tmpMask * 32768;
		if (BitWr == 2) tmpMask = tmpMask * 16384;
		if (BitWr == 4) tmpMask = tmpMask * 4096;
		if (BitWr == 6) tmpMask = tmpMask * 1024;
		if (BitWr == 8) tmpMask = tmpMask * 256;
		if (BitWr == 10) tmpMask = tmpMask * 64;
		if (BitWr == 12) tmpMask = tmpMask * 16;
		if (BitWr == 14) tmpMask = tmpMask * 4;

		// � ����� �� BitWr
		while (BitWr > 0)
		{
			// �������� �������� ���� � tmpMask
			// ��������� ������� � dst[j]
			if ((tmpMask & 0x8000) == 0x8000) T = 1;
			else T = 0;
			// ������� ������� (��� �������������) ���
			tmpMask = tmpMask * 2;
			// ����� �� DstBA � tmpMask
			if (DstBA == 1) T = T * 2;
			if (DstBA == 2) T = T * 4;
			if (DstBA == 3) T = T * 8;
			if (DstBA == 4) T = T * 16;
			if (DstBA == 5) T = T * 32;
			if (DstBA == 6) T = T * 64;
			if (DstBA == 7) T = T * 128;

			dstVFS[j] = dstVFS[j] + T;
			BitWr -- ;
			// ���������� DstBA
			DstBA++;
			// �������� �� ���������� DstBA==8
			if (DstBA > 7)
			{
 				// ���� �� - j++, dst[j] = 0, DstBA=0
				j++;
				dstVFS[j] = 0;
				DstBA=0;
			}	
		}
	}

	return 0;
}



////////////////////////////////////////////////////////////
// ������ ������ ������� �������� � ������������ ��������
////////////////////////////////////////////////////////////
int vw_HAFFtoDATA(int size)
{
	// ������ ������� ���...
	int BitCount = 0 ;
	BitCount = srcVFS[3];
    BitCount *= 0x100; // ����� �� 8 ���...
	BitCount += srcVFS[2];
    BitCount *= 0x100; // ����� �� 8 ���...
	BitCount += srcVFS[1];
    BitCount *= 0x100; // ����� �� 8 ���...
	BitCount += srcVFS[0];

    // ������ ���-�� ��������� �������
    int  TabCount = srcVFS[4] + 1;// ���-�� ���������...

	// � �����, ������ ��� �������� �������
	byte Count[256]; // ���������� ����� (���) �������� � �������...
	for (int i = 5; i < TabCount+5; i++) 
		Count[i-5] = srcVFS[i];// ���������� ������ ���...

	// ������ ������ - ������� ������ ������. ������...
	dsizeVFS = 0;
	byte tmpMask = 0;// �����, � ������� ����� ��������...
	byte mMask = 0;// �����, ������� ����������...
	int cBit = 0;// ���-�� �������������� ��� � �����...
    int j = 0; // ��������� �� ������� � ��������������� ������.
	bool Dat = false;
	int tmpBitCount = BitCount;
	bool ex = false;

	if (size == 0)
	{
		for (int i = 0 + 4 + 1 + TabCount; i < ssizeVFS; i++) 
		{
			tmpMask = srcVFS[i];
			if (tmpBitCount<=0) break;
			// �������� � ������ ����� � �����...
			for (int k = 0; k < 8; k++)
			{
				ex=false;
				// ���� ������� ������������������ � ����. ��� - 0, ������ 0...
				if ((cBit==0)&((tmpMask & 1) == 0)&(!Dat)&(!ex)) 
				{
					// ����� � ���. ������. 0-� �������...
					dsizeVFS++;
					tmpBitCount --;
					if (tmpBitCount<=0) break;
					ex=true;
				}
				// ���� ������� ������������������ � ����. ��� - 1, ��������...
				if ((cBit>=0)&((tmpMask & 1) == 1)&(!Dat)&(!ex)) 
				{
					// ��. ������� ���...
					cBit++;
					tmpBitCount --;
					if (tmpBitCount<=0) break;
					ex=true;
				}
				if ((Dat)&(!ex))
				{
  					mMask = mMask*2;
					mMask = mMask & 0xFE;
					mMask = mMask | (tmpMask & 1);
					cBit --;
					if (cBit<=0)
					{
						Dat = false;
						dsizeVFS++;
						cBit = 0;
					}
					tmpBitCount --;
					if (tmpBitCount<=0) break;
					ex=true;
				}
				if ((cBit>0)&((tmpMask & 1) == 0)&(!Dat)&(!ex)) 
				{
					mMask = 1;
					cBit --;
					if (cBit>0) {Dat= true;}
					else
					{ dsizeVFS++; }
					tmpBitCount --;
					if (tmpBitCount<=0) break;
					ex=true;
				}
				// �����. - ��������� �� ���� ���...
				tmpMask = tmpMask/2;
			}
		}
	}
	else dsizeVFS = size;

	// ����������� ������...
	dstVFS = 0;
    dstVFS = new byte[dsizeVFS];
	if (dstVFS == 0) return 0;

	// ������ ������ - ��������� ������������. ������...
	cBit = 0;
	Dat = false;
	tmpBitCount = BitCount;
	ex = false;
	for (int i = 0 + 4 + 1 + TabCount; i < ssizeVFS; i++) 
	{
		tmpMask = srcVFS[i];
		if (tmpBitCount<=0) break;
		// �������� � ������ ����� � �����...
		for (int k = 0; k < 8; k++)
		{
			ex=false;
			// ���� ������� ������������������ � ����. ��� - 0, ������ 0...
			if ((cBit==0)&((tmpMask & 1) == 0)&(!Dat)&(!ex)) 
			{
				// ����� � ���. ������. 0-� �������...
				dstVFS[j] = Count[0];
				j++;
				tmpBitCount --;
				if (tmpBitCount<=0) break;
				ex=true;
			}
			// ���� ������� ������������������ � ����. ��� - 1, ��������...
			if ((cBit>=0)&((tmpMask & 1) == 1)&(!Dat)&(!ex)) 
			{
				// ��. ������� ���...
				cBit++;
				tmpBitCount --;
				if (tmpBitCount<=0) break;
				ex=true;
			}
			if ((Dat)&(!ex))
			{
				mMask = mMask*2;
				mMask = mMask & 0xFE;
				mMask = mMask | (tmpMask & 1);
				cBit --;
				if (cBit<=0)
				{
					Dat = false;
					dstVFS[j] = Count[mMask];
					cBit = 0;
					j++;
				}
				tmpBitCount --;
				if (tmpBitCount<=0) break;
				ex=true;
			}

			if ((cBit>0)&((tmpMask & 1) == 0)&(!Dat)&(!ex)) 
			{
				mMask = 1;
				cBit --;
				if (cBit>0) {Dat= true;}
				else
				{
					dstVFS[j] = Count[mMask];
					j++;
				}
				tmpBitCount --;
				if (tmpBitCount<=0) break;
				ex=true;
			}

			// �����. - ��������� �� ���� ���...
			tmpMask = tmpMask/2;
		}
	} 

	return 0;
}
