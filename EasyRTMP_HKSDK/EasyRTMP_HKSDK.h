// DecCallBack_Demo.h : main header file for the DECCALLBACK_DEMO application
//

#if !defined(AFX_DECCALLBACK_DEMO_H__E647C405_6C5E_4D1F_8556_C1046F1C8848__INCLUDED_)
#define AFX_DECCALLBACK_DEMO_H__E647C405_6C5E_4D1F_8556_C1046F1C8848__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CDecCallBack_DemoApp:
// See DecCallBack_Demo.cpp for the implementation of this class
//

class CDecCallBack_DemoApp : public CWinApp
{
public:
	CDecCallBack_DemoApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDecCallBack_DemoApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CDecCallBack_DemoApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DECCALLBACK_DEMO_H__E647C405_6C5E_4D1F_8556_C1046F1C8848__INCLUDED_)
