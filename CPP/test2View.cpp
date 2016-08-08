// test2View.cpp : implementation of the CTest2View class
//

#include "stdafx.h"
#include "test2.h"

#include "test2Doc.h"
#include "test2View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CTest2View

IMPLEMENT_DYNCREATE(CTest2View, CView)

BEGIN_MESSAGE_MAP(CTest2View, CView)
	//{{AFX_MSG_MAP(CTest2View)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CTest2View construction/destruction

CTest2View::CTest2View()
{
	// TODO: add construction code here

}

CTest2View::~CTest2View()
{
}

BOOL CTest2View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CTest2View drawing

void CTest2View::OnDraw(CDC* pDC)
{
	CTest2Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
}

/////////////////////////////////////////////////////////////////////////////
// CTest2View printing

BOOL CTest2View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CTest2View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CTest2View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CTest2View diagnostics

#ifdef _DEBUG
void CTest2View::AssertValid() const
{
	CView::AssertValid();
}

void CTest2View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CTest2Doc* CTest2View::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CTest2Doc)));
	return (CTest2Doc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CTest2View message handlers
