
// MatchingGameView.h : interface of the CMatchingGameView class
//

#pragma once


class CMatchingGameView : public CView
{
protected: // create from serialization only
	CMatchingGameView() noexcept;
	DECLARE_DYNCREATE(CMatchingGameView)

// Attributes
public:
	CMatchingGameDoc* GetDocument() const;

// Operations
public:

// Overrides
public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// Implementation
public:
	virtual ~CMatchingGameView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	afx_msg void OnFilePrintPreview();
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in MatchingGameView.cpp
inline CMatchingGameDoc* CMatchingGameView::GetDocument() const
   { return reinterpret_cast<CMatchingGameDoc*>(m_pDocument); }
#endif

