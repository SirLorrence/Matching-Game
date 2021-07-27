
// MatchingGameDoc.h : interface of the CMatchingGameDoc class
//


#pragma once
// include to header for file access
#include "MatchingGameBoard.h" 
class CMatchingGameDoc : public CDocument {
protected: // create from serialization only
	CMatchingGameDoc() noexcept;
	DECLARE_DYNCREATE(CMatchingGameDoc)

	// Attributes
public:

	// Operations
public:
	//-------- GAME BOARD INFO
	COLORREF GetBoardSpace(int row, int col) { return _gameBoard.GetBoardSpace(row, col); }
	void SetUpBoard() { _gameBoard.SetUpBoard(); }
	int GetWidth() { _gameBoard.GetWidth(); }
	int GetHeight() { _gameBoard.GetHeight(); }
	int GetRows() { _gameBoard.GetRows(); }
	int GetColumns() { _gameBoard.GetColumns(); }
	int DeleteBoard() { _gameBoard.DeleteBoard(); }



	// Overrides
public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
#ifdef SHARED_HANDLERS
	virtual void InitializeSearchContent();
	virtual void OnDrawThumbnail(CDC& dc, LPRECT lprcBounds);
#endif // SHARED_HANDLERS

	// Implementation
public:
	virtual ~CMatchingGameDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:
	//----------- Game Board Instance
	MatchingGameBoard _gameBoard;

	// Generated message map functions
protected:
	DECLARE_MESSAGE_MAP()

#ifdef SHARED_HANDLERS
	// Helper function that sets search content for a Search Handler
	void SetSearchContent(const CString& value);
#endif // SHARED_HANDLERS
};
