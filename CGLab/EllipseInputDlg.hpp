/*
 * 
 * Dialogs/EllipseInputDlg.hpp
 * Ziyu ZHOU @ SDAU
 * 27/11/24
 * 
*/

#pragma once
#include "resource.h"

class CCGLabView;

class EllipseInputDlg : public CDialog {
    DECLARE_DYNAMIC(EllipseInputDlg)

public:
    EllipseInputDlg(CWnd* pParent = nullptr);
    virtual ~EllipseInputDlg();

    enum { IDD = IDD_ELLIPSE };

    void SetPreviewView(CCGLabView* view) { m_pPreviewView = view; }

protected:
    virtual void DoDataExchange(CDataExchange* pDX);
    virtual BOOL OnInitDialog();
    afx_msg void OnPreviewChanged();
    DECLARE_MESSAGE_MAP()
    CCGLabView* m_pPreviewView = nullptr;

public:
    int m_centreX;
    int m_centreY;
    int m_a;  // ³¤Öá
    int m_b;  // ¶ÌÖá
};

