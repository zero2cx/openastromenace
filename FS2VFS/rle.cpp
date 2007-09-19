/////////////////////////////////////////////////
// Viewizard Game Engine
/////////////////////////////////////////////////
// File: rle.cpp
/////////////////////////////////////////////////
// Copyright (c) 2001-2006, Michael Kurinnoy
// All Rights Reserved.
/////////////////////////////////////////////////
// Ver : 2.0
/////////////////////////////////////////////////


// Function:
// vw_DATAtoRLE
// vw_RLEtoDATA


#include "vfs_var.h"




////////////////////////////////////////////////////////////
// ������� ������ ������� RLE
////////////////////////////////////////////////////////////
int vw_DATAtoRLE()
{
	// ��������� ������� ��������� ��������,
	// ������� ��-�..
	int block = 0;
	dsizeVFS = 0;
	int *Start = 0;
	int *Stop = 0; 
	bool rep = false; // ����-��� �������...
    byte PRactiv = srcVFS[0]; // ���������� �������� (�����������) ����

    // ����������� ������...
    Start = new int[ssizeVFS / 2];
	if (Start == 0) return 0;
    Stop = new int[ssizeVFS / 2];
	if (Stop == 0) return 0;

	for (int i=1; i<ssizeVFS; i++)
	{
		if (PRactiv == srcVFS[i])
		{
			if (!rep) {Start[block] = i - 1; rep=true;}
			Stop[block] = i;
		}
		else
			if (rep) {rep=false;block++;}
      
		PRactiv = srcVFS[i];
	}
	if (rep) {rep=false;block++;} //���� �� �����...

    // ����� ������ �������. ��������.

	if (block > 0)
	{
		int Sr=0;// ��������� ����� ������������������...
		int St;  // �������� ����� ������������������...
		int dl;  // ����� ������������������...

		for (int i=0; i<block; i++)
		{
			St = Start[i] - 1;
			dl = St - Sr + 1;
			// ����� � ���������� �� ����� �� FF ...���� ������������������ �� ���������
			while (dl >= 0xFF)
			{
				dsizeVFS += 2;
				dsizeVFS += 0xFF;
				dl -= 0xFF;
			}
			// �����...��, ��� ��������...
			if (dl > 0) dsizeVFS += 2 + dl;   

			Sr = Start[i];
			St = Stop[i];
			dl = St - Sr + 1;
			// �����...������������������ ������������� ������...
			while (dl >= 0xFF)
			{
				dsizeVFS += 2;
				dl -= 0xFF;
			}
			// �����...��, ��� ��������...
			if (dl > 0) dsizeVFS += 2; 

			Sr = St + 1;
		}
		St = ssizeVFS-1;
		dl = St - Sr + 1;
		// ����� � ���������� �� ����� �� FF ...���� ������������������ �� ���������
		while (dl >= 0xFF)
		{
			dsizeVFS += 2;
			dsizeVFS += 0xFF;
			dl -= 0xFF;
		}
		// �����...��, ��� ��������...
		if (dl > 0) dsizeVFS += 2 + dl;   
	}
	else 
	{
		int Sr=0;// ��������� ����� ������������������...
		int dl;  // ����� ������������������...
		dl = ssizeVFS - 0;
        // ����� � ���������� �� ����� �� FF ...���� ������������������ �� ���������
		while (dl >= 0xFF)
		{
			dsizeVFS += 2;
			dsizeVFS += 0xFF;
			dl -= 0xFF;
		}
		// �����...��, ��� ��������...
		if (dl > 0) dsizeVFS += 2 + dl; 	
	}

    // ����������� ������...
	dstVFS = 0;
    dstVFS = new byte[dsizeVFS];
	if (dstVFS == 0)
	{
		delete [] Start; Start = 0;
		delete [] Stop; Stop = 0;
		return 0;
	}


    // ������...
    int j = 0; // ��������� �� ������� � ��������������� ������.

	if (block > 0)
	{
		int Sr=0; //(������������� �� ������ - ��� 0)
		int St;
		int dl;
		int popr=j;

		for (int i=0; i<block; i++)
		{
			St = Start[i] - 1;
			dl = St - Sr + 1;
			popr=0;
			// ����� � ���������� �� ����� �� FF ...���� ������������������ �� ���������
			while (dl >= 0xFF)
			{
				dstVFS[j] = 0;
				j++;
				dstVFS[j] = 0xFF;
				j++;
				dl -= 0xFF;
				memcpy( dstVFS + j, srcVFS + Sr + popr, 0xFF );
				popr += 0xFF;
				j += 0xFF;
			}
			// �����...��, ��� ��������...
			if (dl > 0) 
			{
				dstVFS[j] = 0;
				j++;
				dstVFS[j] = (byte)dl;
				j++;
				memcpy( dstVFS + j, srcVFS + Sr +  popr, dl );
				popr += (byte)dl;
				j += dl;
			};   

			Sr = Start[i];
			St = Stop[i];
			dl = St - Sr + 1;
			// �����...������������������ ������������� ������...
			while (dl >= 0xFF)
			{
				dstVFS[j] = 0xFF;
				j++;
				dstVFS[j] = srcVFS[Start[i]];
				j++;
				dl -= 0xFF;
			}
			// �����...��, ��� ��������...
			if (dl > 0) 
			{
				dstVFS[j] = dl;
				j++;
				dstVFS[j] = srcVFS[Start[i]];
				j++;
			}

			Sr = St + 1;
		}
		St = ssizeVFS-1;
		dl = St - Sr + 1;
		popr=0;
        // ����� � ���������� �� ����� �� FF ...���� ������������������ �� ���������
        // �������� (�� ������ ���������� ����)
		while (dl >= 0xFF)
		{
			dstVFS[j] = 0;
			j++;
			dstVFS[j] = 0xFF;
			j++;
			dl -= 0xFF;
			memcpy( dstVFS + j, srcVFS + Sr + popr, 0xFF );
		    popr += 0xFF;
			j += 0xFF;
		}
		// �����...��, ��� ��������...
		if (dl > 0) 
		{
			dstVFS[j] = 0;
			j++;
			dstVFS[j] = (byte)dl;
			j++;
			memcpy( dstVFS + j, srcVFS + Sr + popr, (byte)dl );
		    popr += dl;
			j += dl;
		};    

	}
	else
	{
		int Sr=0;// ��������� ����� ������������������...
		int dl;  // ����� ������������������...
		dl = ssizeVFS - 0;
		int popr=j;
		while (dl >= 0xFF)
		{
			dstVFS[j] = 0;
			j++;
			dstVFS[j] = 0xFF;
			j++;
			dl -= 0xFF;
			memcpy( dstVFS + j, srcVFS + Sr + popr, 0xFF );
		    popr += 0xFF;
			j += 0xFF;
		}
		// �����...��, ��� ��������...
		if (dl > 0) 
		{
			dstVFS[j] = 0;
			j++;
			dstVFS[j] = (byte)dl;
			j++;
			memcpy( dstVFS + j, srcVFS + Sr + popr, (byte)dl );
		    popr += dl;
			j += dl;
		};       
	}

    delete [] Start; Start = 0;
	delete [] Stop; Stop = 0;

	return 0;
}



////////////////////////////////////////////////////////////
// ������ ������ ������� RLE
////////////////////////////////////////////////////////////
int vw_RLEtoDATA(int size)
{
	// ������� ���-�� ������...
	int i = 0;
	dsizeVFS = 0;

	if (size == 0)
	{
		while (i<ssizeVFS)
		{
			// ���� ������������� ������������������...
			if (srcVFS[i] != 0)
			{
				dsizeVFS += srcVFS[i];
				i++;
				// ���������� ���� ����������...
				i++;
			}
			else // ���� ������������������ ������. ������.
			{
				// ���������� 0
				i++;
				byte temp = srcVFS[i] ;
				i++;
				// ����������� ����������� ��������
				dsizeVFS += temp;
				// ��������� �� ����� �������...
				i += temp;
			}
		}
	}
	else dsizeVFS = size;

	// �������� ������...
	dstVFS = 0;
	dstVFS = new byte[dsizeVFS];
	if (dstVFS == 0) return 0;
  
	// �������������...
	i = 0;
	int j = 0; // ������� ��������� � ������������� �������...
	while (i<ssizeVFS)
	{
		// ���� ������������� ������������������...
		if (srcVFS[i] != 0)
		{
			// ������ ���-�� ��������...
			byte rep = srcVFS[i];
			i++;
			// ������ ���� ����������...
			byte tmp = srcVFS[i];
			i++;
			// ������� ����������...
			memset(dstVFS + j, tmp, rep);
			j += rep;
		}
		else // ���� ������������������ ������. ������.
		{
			// ���������� 0
			i++;
			// ���������� ������...
			byte temp = srcVFS[i];
			i++;
			// �������� ������....
			memcpy( dstVFS + j, srcVFS + i, temp );
			// ��������� �� ����� �������...
			i += temp;
			j += temp;
		}
	}
  
	return 0;
}


