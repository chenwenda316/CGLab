/*
 * 
 * Dialogs/CircleInputDlg.cpp
 * Ziyu ZHOU @ SDAU
 * 27/11/24
 * 
*/

#include "pch.h"
#include "CircleInputDlg.hpp"
#include "CGLabView.h"
#include <cstdio>

IMPLEMENT_DYNAMIC(CircleInputDlg, CDialog)

CircleInputDlg::CircleInputDlg(CWnd* pParent)
    : CDialog(IDD_CIRCLE, pParent)
    , m_centreX(0)
    , m_centreY(0)
    , m_radius(0)
{
}

CircleInputDlg::~CircleInputDlg()
{
}

void CircleInputDlg::DoDataExchange(CDataExchange* pDX)
{
    CDialog::DoDataExchange(pDX);
    DDX_Text(pDX, IDC_CIRCLE_CENTRE_X, m_centreX);
    DDX_Text(pDX, IDC_CIRCLE_CENTRE_Y, m_centreY);
    DDX_Text(pDX, IDC_CIRCLE_RADIUS, m_radius);
}

BEGIN_MESSAGE_MAP(CircleInputDlg, CDialog)
    ON_EN_CHANGE(IDC_CIRCLE_CENTRE_X, &CircleInputDlg::OnPreviewChanged)
    ON_EN_CHANGE(IDC_CIRCLE_CENTRE_Y, &CircleInputDlg::OnPreviewChanged)
    ON_EN_CHANGE(IDC_CIRCLE_RADIUS, &CircleInputDlg::OnPreviewChanged)
END_MESSAGE_MAP()

BOOL CircleInputDlg::OnInitDialog()
{
    CDialog::OnInitDialog();
    UpdateData(FALSE);
    // 确保默认值真正写入控件
    SetDlgItemInt(IDC_CIRCLE_CENTRE_X, m_centreX, TRUE);
    SetDlgItemInt(IDC_CIRCLE_CENTRE_Y, m_centreY, TRUE);
    SetDlgItemInt(IDC_CIRCLE_RADIUS, m_radius, TRUE);
    OnPreviewChanged();
    return TRUE;
}

void CircleInputDlg::OnPreviewChanged()
{
    if (!m_pPreviewView) return;
    int cx = static_cast<int>(GetDlgItemInt(IDC_CIRCLE_CENTRE_X, nullptr, TRUE));
    int cy = static_cast<int>(GetDlgItemInt(IDC_CIRCLE_CENTRE_Y, nullptr, TRUE));
    int r = static_cast<int>(GetDlgItemInt(IDC_CIRCLE_RADIUS, nullptr, TRUE));
    m_pPreviewView->PreviewCircle(MyGraphics::Point2D(cx, cy), r);
}