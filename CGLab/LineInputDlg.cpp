/*
 * 
 * Dialogs/LineInputDlg.cpp
 * Ziyu ZHOU @ SDAU
 * 26/11/24
 * 
*/

#include "pch.h"
#include "LineInputDlg.hpp"
#include "CGLabView.h"

IMPLEMENT_DYNAMIC(LineInputDlg, CDialog)

LineInputDlg::LineInputDlg(CWnd* pParent)
    : CDialog(IDD_LINE, pParent)
    , m_x0(0)
    , m_y0(0)
    , m_x1(0)
    , m_y1(0)
{
}

LineInputDlg::~LineInputDlg()
{
}

void LineInputDlg::DoDataExchange(CDataExchange* pDX)
{
    CDialog::DoDataExchange(pDX);
    DDX_Text(pDX, IDC_LINE_DDA_X0, m_x0);
    DDX_Text(pDX, IDC_LINE_DDA_Y0, m_y0);
    DDX_Text(pDX, IDC_LINE_DDA_X1, m_x1);
    DDX_Text(pDX, IDC_LINE_DDA_Y1, m_y1);
}

BEGIN_MESSAGE_MAP(LineInputDlg, CDialog)
    ON_EN_CHANGE(IDC_LINE_DDA_X0, &LineInputDlg::OnPreviewChanged)
    ON_EN_CHANGE(IDC_LINE_DDA_Y0, &LineInputDlg::OnPreviewChanged)
    ON_EN_CHANGE(IDC_LINE_DDA_X1, &LineInputDlg::OnPreviewChanged)
    ON_EN_CHANGE(IDC_LINE_DDA_Y1, &LineInputDlg::OnPreviewChanged)
END_MESSAGE_MAP()

BOOL LineInputDlg::OnInitDialog()
{
    CDialog::OnInitDialog();
    UpdateData(FALSE);
    // 确保默认值真正写入控件（预览和确定都以控件内容为准）
    SetDlgItemInt(IDC_LINE_DDA_X0, m_x0, TRUE);
    SetDlgItemInt(IDC_LINE_DDA_Y0, m_y0, TRUE);
    SetDlgItemInt(IDC_LINE_DDA_X1, m_x1, TRUE);
    SetDlgItemInt(IDC_LINE_DDA_Y1, m_y1, TRUE);
    OnPreviewChanged();
    return TRUE;
}

void LineInputDlg::OnPreviewChanged()
{
    if (!m_pPreviewView) return;
    int x0 = static_cast<int>(GetDlgItemInt(IDC_LINE_DDA_X0, nullptr, TRUE));
    int y0 = static_cast<int>(GetDlgItemInt(IDC_LINE_DDA_Y0, nullptr, TRUE));
    int x1 = static_cast<int>(GetDlgItemInt(IDC_LINE_DDA_X1, nullptr, TRUE));
    int y1 = static_cast<int>(GetDlgItemInt(IDC_LINE_DDA_Y1, nullptr, TRUE));
    m_pPreviewView->PreviewLine(MyGraphics::Point2D(x0, y0),
        MyGraphics::Point2D(x1, y1));
}

