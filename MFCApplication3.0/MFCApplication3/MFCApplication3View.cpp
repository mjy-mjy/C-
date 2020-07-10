
// MFCApplication3View.cpp : CMFCApplication3View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "MFCApplication3.h"
#endif

#include "MFCApplication3Doc.h"
#include "MFCApplication3View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCApplication3View

IMPLEMENT_DYNCREATE(CMFCApplication3View, CView)

BEGIN_MESSAGE_MAP(CMFCApplication3View, CView)
	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()

// CMFCApplication3View 构造/析构

CMFCApplication3View::CMFCApplication3View()
{
	// TODO: 在此处添加构造代码

}

CMFCApplication3View::~CMFCApplication3View()
{
}

BOOL CMFCApplication3View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMFCApplication3View 绘制

void CMFCApplication3View::OnDraw(CDC* /*pDC*/)
{
	CMFCApplication3Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	CClientDC dc(this);
	dc.Rectangle(pDoc->A);
	dc.Rectangle(pDoc->B);
	dc.Rectangle(pDoc->C);
	// TODO: 在此处为本机数据添加绘制代码
}


// CMFCApplication3View 诊断

#ifdef _DEBUG
void CMFCApplication3View::AssertValid() const
{
	CView::AssertValid();
}

void CMFCApplication3View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFCApplication3Doc* CMFCApplication3View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFCApplication3Doc)));
	return (CMFCApplication3Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFCApplication3View 消息处理程序


void CMFCApplication3View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CMFCApplication3Doc* pDoc = GetDocument();
	CClientDC dc(this);
	if(point.x > pDoc->A.TopLeft().x && point.y > pDoc->A.TopLeft().y && point.x < pDoc->A.BottomRight().x && point.y < pDoc->A.BottomRight().y)
	{
		pDoc->a = rand()%50;
		CString A;
		A.Format(_T("%d"),pDoc->a);
		dc.TextOutW(pDoc->A.TopLeft().x+100,pDoc->A.TopLeft().y+100,A);
		CString D = (_T("                "));
		dc.TextOutW(500,400,D);
	}
	else if(point.x > pDoc->B.TopLeft().x && point.y > pDoc->B.TopLeft().y && point.x < pDoc->B.BottomRight().x && point.y < pDoc->B.BottomRight().y)
	{
		pDoc->b = rand()%50;
		CString B;
		B.Format(_T("%d"),pDoc->b);
		dc.TextOutW(pDoc->B.TopLeft().x+100,pDoc->B.TopLeft().y+100,B);
		CString D = (_T("                "));
		dc.TextOutW(500,400,D);
	}
	else if(point.x > pDoc->C.TopLeft().x && point.y > pDoc->C.TopLeft().y && point.x < pDoc->C.BottomRight().x && point.y < pDoc->C.BottomRight().y)
	{
		pDoc->c = pDoc->a + pDoc->b;
		CString C;
		C.Format(_T("%d"),pDoc->c);
		dc.TextOutW(pDoc->C.TopLeft().x+100,pDoc->C.TopLeft().y+100,C);
		CString D = (_T("                "));
		dc.TextOutW(500,400,D);
	}
	else
	{
		CString D = (_T("点击无效"));
		dc.TextOutW(500,400,D);
	}
	CView::OnLButtonDown(nFlags, point);
}
