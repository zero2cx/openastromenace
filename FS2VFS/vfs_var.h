/////////////////////////////////////////////////
// Viewizard Game Engine
/////////////////////////////////////////////////
// File: vfs_var.h
/////////////////////////////////////////////////
// Copyright (c) 2001-2006, Michael Kurinnoy
// All Rights Reserved.
/////////////////////////////////////////////////
// Ver : 2.0
/////////////////////////////////////////////////




#ifndef vfs_var_H
#define vfs_var_H



//------------------------------------------------------------------------------------
// include � lib...
//------------------------------------------------------------------------------------
#include <windows.h>
#include <stdio.h>













//------------------------------------------------------------------------------------
// VFS
//
// Virtual File System
// Now supported VFS: v1.1, v1.2, v1.3
//------------------------------------------------------------------------------------

// Current VFS version
#define VFS_VER									"v1.3" 
// Data compression
#define VFS_DATA_ARH_NONE						'0'
#define VFS_DATA_ARH_RLE						'1'
#define VFS_DATA_ARH_HAFF						'2'



struct eFILE
{
	char*	Name;		// File name
  	int		VFS_Offset;	// File offset in the VFS file
	int		PackLength;	// File size in the VFS file
	int		RealLength;	// File size in the memory (unpacked file size)
	int		Pos;		// Current position in the file
	bool	Flush;		// File will flushed on close.
	BYTE*	Data;		// Pointer to the file data (unpacked) in the memory

	eFILE*	Prev;		// Pointer to the previous opened file
	eFILE*	Next;		// Pointer to the next opened file
};



// VFS functions

// Create VFS file
int	vw_CreateVFS(const char *Name, const char *nArhKey, bool WriteArhKey, int Ver = 2);//2=1.2
// Close VFS file
void	vw_CloseVFS(void);
// Copy file from File System into VFS
int	vw_CopyFStoVFS(const char *SrcFileName, const char *DstFileName);
// Copy memory file into VFS
int	vw_WriteIntoVFS(const char *Name, const byte * buffer, int size);

//------------------------------------------------------------------------------------








//------------------------------------------------------------------------------------
// ����������
//------------------------------------------------------------------------------------


// File present in the VFS
#define VFS_FILE_VFS							0x0031
// File present in the File System
#define VFS_FILE_FS								0x0032


// ��������� ������ � ������� VFS (��� v1.3)
typedef struct
{
	DWORD	NameLen;	// ���-�� ���� � �����...
	char	*Name;		// ��� ������ (��� �����)
	int		Offset;		// �������� ������ ����� ������������ ������ �������� �������
	int		Length;		// ����� ����� � �������
	int		RealLength;	// ����� ����� ����� ����������
	// ��� 1.3
	byte	ArhKeyLen;	// ���-�� ���� ����� ��������
	char	*ArhKey;	// ����-��������
} eVFS_Entry;   

extern char *VFSFileName;		// ��� ����� VFS
extern FILE *VFSFile;			// ��������� �� ���� ����������� �������
extern byte *dstVFS;			// ������ ��� �������/������
extern byte *srcVFS;			// ������ ��� �������/������
extern int  dsizeVFS;			// ������ ��� �������/������
extern int  ssizeVFS;			// ������ ��� �������/������
extern int  DataStartOffsetVFS;// �������� ������ � ��������� VFS (��� 8 ���� ���� ����)
extern int  HeaderOffsetVFS;	// �������� ������� ������ � ��������� VFS
extern int  HeaderLengthVFS;	// ����� ������� ������ ��������� VFS
extern int  NumberOfFilesVFS;	// ���������� ������ � VFS
extern bool VFSFileOpen;	// ������ �������� VFS
extern bool VFSFileWritable;
extern eVFS_Entry *VFSdirArray;// ������ ������� VFS
extern bool SetUpperVFS;	// ��������� ���� � �������� ����� � ������� ������� (�������� ��� ����� ��������)
extern char *ArhKeyVFS;		// ����-��������
extern eFILE *StartFileVFS;	// ��������� �� ������ ���� � ������...
extern eFILE *EndFileVFS;		// ��������� �� ��������� ���� � ������...

extern int VFSversion;

int vw_DATAtoRLE(void);
int vw_DATAtoHAFF(void);
int vw_RLEtoDATA(int size);
int vw_HAFFtoDATA(int size);




/* 
�������� ��������� VFS v1.2

  4� - 'VFS_'
  4� - 'v1.2'

  ~~
   1� - 00, ���� �� ���������� ������������������ ��������������
  ���
   1� - ���-�� ���� ������������������ ��������������
   N� - ���������� ������������������
  ~~

  4� - �������� ������� ������
  4� - ����� ������� ������
  ?� - ������(���� ������ ���� �� ������)
 
   ����� ������� ������...
  --��������� ������ ������� ������
  2� - ���-�� �������� � ����� �����
  N� - ��� �����
  4� - �������� ������ ����� � �������
  4� - ����� �����
  4� - ����� ����� � ������������� ����
*/

/* 
�������� ��������� VFS v1.3

  4� - 'VFS_'
  4� - 'v1.3'
  4� - �������� ������� ������
  4� - ����� ������� ������
  ?� - ������(���� ������ ���� �� ������)
 
   ����� ������� ������...
  --��������� ������ ������� ������
  1� - 00, ���� �� ���������� ������������������ ��������������
     ���
  1� - ���-�� ���� ������������������ ��������������
  N� - ���������� ������������������
  2� - ���-�� �������� � ����� �����
  N� - ��� �����
  4� - �������� ������ ����� � �������
  4� - ����� �����
  4� - ����� ����� � ������������� ����
*/



#endif

