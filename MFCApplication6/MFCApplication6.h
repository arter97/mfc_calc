
// MFCApplication6.h : PROJECT_NAME ���� ���α׷��� ���� �� ��� �����Դϴ�.
//

#pragma once

#ifndef __AFXWIN_H__
	#error "PCH�� ���� �� ������ �����ϱ� ���� 'stdafx.h'�� �����մϴ�."
#endif

#include "resource.h"		// �� ��ȣ�Դϴ�.


// CMFCApplication6App:
// �� Ŭ������ ������ ���ؼ��� MFCApplication6.cpp�� �����Ͻʽÿ�.
//

class CMFCApplication6App : public CWinApp
{
public:
	CMFCApplication6App();

// �������Դϴ�.
public:
	virtual BOOL InitInstance();

// �����Դϴ�.

	DECLARE_MESSAGE_MAP()
};

extern CMFCApplication6App theApp;