/*
 * 
 * Dialogs/CircleInputDlg.hpp
 * Ziyu ZHOU @ SDAU
 * 27/11/24
 * 
*/

#pragma once

#include "resource.h"

class CCGLabView;

class CircleInputDlg : public CDialog {
    DECLARE_DYNAMIC(CircleInputDlg)

public:
    CircleInputDlg(CWnd* pParent = nullptr);
    virtual ~CircleInputDlg();

    enum { IDD = IDD_CIRCLE };

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
    int m_radius;
};

