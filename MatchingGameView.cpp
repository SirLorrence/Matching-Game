
// MatchingGameView.cpp : implementation of the CMatchingGameView class
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "MatchingGame.h"
#endif

#include "MatchingGameDoc.h"
#include "MatchingGameView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMatchingGameView

IMPLEMENT_DYNCREATE(CMatchingGameView, CView)

BEGIN_MESSAGE_MAP(CMatchingGameView, CView)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
END_MESSAGE_MAP()

// CMatchingGameView construction/destruction

CMatchingGameView::CMatchingGameView() noexcept
{
	// TODO: add construction code here

}

CMatchingGameView::~CMatchingGameView()
{
}

BOOL CMatchingGameView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// CMatchingGameView drawing

void CMatchingGameView::OnDraw(CDC* /*pDC*/)
{
	CMatchingGameDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: add draw code for native data here
}

void CMatchingGameView::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CMatchingGameView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CMatchingGameView diagnostics

#ifdef _DEBUG
void CMatchingGameView::AssertValid() const
{
	CView::AssertValid();
}

void CMatchingGameView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMatchingGameDoc* CMatchingGameView::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMatchingGameDoc)));
	return (CMatchingGameDoc*)m_pDocument;
}
#endif //_DEBUG


// CMatchingGameView message handlers
