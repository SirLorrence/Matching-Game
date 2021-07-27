
// MatchingGame.h : main header file for the MatchingGame application
//
#pragma once

#ifndef __AFXWIN_H__
	#error "include 'pch.h' before including this file for PCH"
#endif

#include "resource.h"       // main symbols


// CMatchingGameApp:
// See MatchingGame.cpp for the implementation of this class
//

class CMatchingGameApp : public CWinAppEx
{
public:
	CMatchingGameApp() noexcept;


// Overrides
public:
	virtual BOOL InitInstance();

// Implementation
	UINT  m_nAppLook;
	BOOL  m_bHiColorIcons;

	virtual void PreLoadState();
	virtual void LoadCustomState();
	virtual void SaveCustomState();

	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CMatchingGameApp theApp;
