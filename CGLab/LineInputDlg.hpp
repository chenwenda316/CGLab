/*
 * 
 * Dialogs/LineInputDlg.hpp
 * Ziyu ZHOU @ SDAU
 * 26/11/24
 * 
*/

#pragma once
#include "resource.h"

class CCGLabView;

class LineInputDlg : public CDialog
{
    DECLARE_DYNAMIC(LineInputDlg)

public:
    LineInputDlg(CWnd* pParent = nullptr);
    virtual ~LineInputDlg();

    enum { IDD = IDD_LINE };

    void SetPreviewView(CCGLabView* view) { m_pPreviewView = view; }

    int m_x0;
    int m_y0;
    int m_x1;
    int m_y1;

protected:
    virtual void DoDataExchange(CDataExchange* pDX);
    virtual BOOL OnInitDialog();
    afx_msg void OnPreviewChanged();
    DECLARE_MESSAGE_MAP()
    CCGLabView* m_pPreviewView = nullptr;
};
