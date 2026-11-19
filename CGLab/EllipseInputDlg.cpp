/*
 *
 * Dialogs/EllipseInputDlg.cpp
 * Ziyu ZHOU @ SDAU
 * 27/11/24
 *
*/

#include "pch.h"
#include "EllipseInputDlg.hpp"
#include "CGLabView.h"

IMPLEMENT_DYNAMIC(EllipseInputDlg, CDialog)

EllipseInputDlg::EllipseInputDlg(CWnd* pParent)
    : CDialog(IDD_ELLIPSE, pParent)
    , m_centreX(0)
    , m_centreY(0)
    , m_a(0)
    , m_b(0)
{
}

EllipseInputDlg::~EllipseInputDlg()
{
}

void EllipseInputDlg::DoDataExchange(CDataExchange* pDX)
{
    CDialog::DoDataExchange(pDX);
    DDX_Text(pDX, IDC_ELLIPSE_CENTRE_X, m_centreX);
    DDX_Text(pDX, IDC_ELLIPSE_CENTRE_Y, m_centreY);
    DDX_Text(pDX, IDC_ELLIPSE_A, m_a);
    DDX_Text(pDX, IDC_ELLIPSE_B, m_b);
}

BEGIN_MESSAGE_MAP(EllipseInputDlg, CDialog)
    ON_EN_CHANGE(IDC_ELLIPSE_CENTRE_X, &EllipseInputDlg::OnPreviewChanged)
    ON_EN_CHANGE(IDC_ELLIPSE_CENTRE_Y, &EllipseInputDlg::OnPreviewChanged)
    ON_EN_CHANGE(IDC_ELLIPSE_A, &EllipseInputDlg::OnPreviewChanged)
    ON_EN_CHANGE(IDC_ELLIPSE_B, &EllipseInputDlg::OnPreviewChanged)
END_MESSAGE_MAP()

BOOL EllipseInputDlg::OnInitDialog()
{
    CDialog::OnInitDialog();
    UpdateData(FALSE);
    // 确保默认值真正写入控件
    SetDlgItemInt(IDC_ELLIPSE_CENTRE_X, m_centreX, TRUE);
    SetDlgItemInt(IDC_ELLIPSE_CENTRE_Y, m_centreY, TRUE);
    SetDlgItemInt(IDC_ELLIPSE_A, m_a, TRUE);
    SetDlgItemInt(IDC_ELLIPSE_B, m_b, TRUE);
    OnPreviewChanged();
    return TRUE;
}

void EllipseInputDlg::OnPreviewChanged()
{
    if (!m_pPreviewView) return;
    int cx = static_cast<int>(GetDlgItemInt(IDC_ELLIPSE_CENTRE_X, nullptr, TRUE));
    int cy = static_cast<int>(GetDlgItemInt(IDC_ELLIPSE_CENTRE_Y, nullptr, TRUE));
    int a = static_cast<int>(GetDlgItemInt(IDC_ELLIPSE_A, nullptr, TRUE));
    int b = static_cast<int>(GetDlgItemInt(IDC_ELLIPSE_B, nullptr, TRUE));
    m_pPreviewView->PreviewEllipse(MyGraphics::Point2D(cx, cy), a, b);
}