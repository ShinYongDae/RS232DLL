// RS232DLL.h : RS232DLL DLL�� �⺻ ��� �����Դϴ�.
//

#pragma once

#ifndef __AFXWIN_H__
	#error "PCH�� ���� �� ������ �����ϱ� ���� 'stdafx.h'�� �����մϴ�."
#endif

#include "resource.h"		// �� ��ȣ�Դϴ�.


// CRS232DLLApp
// �� Ŭ������ ������ ������ RS232DLL.cpp�� �����Ͻʽÿ�.
//

class CRS232DLLApp : public CWinApp
{
public:
	CRS232DLLApp();

// �������Դϴ�.
public:
	virtual BOOL InitInstance();

	DECLARE_MESSAGE_MAP()
};
