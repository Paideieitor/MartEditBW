
// MartEditBWDlg.h : header file
//

#pragma once

#include "CChangePriceDlg.h"
#include "CChangeItemsDlg.h"

// CMartEditBWDlg dialog
class CMartEditBWDlg : public CDialogEx
{
// Construction
public:
	CMartEditBWDlg(CWnd* pParent = nullptr);	// standard constructor

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MARTEDITBW_DIALOG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	virtual void OnCancel();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()

private:
	enum class TabType
	{
		ITEMS = 0u,
		PRICE = 1u,
		SIZE = 2u
	};

	afx_msg void OnTcnSelchangeTabControl(NMHDR* pNMHDR, LRESULT* pResult);

	CTabCtrl tab_control;
	CChangePriceDlg change_price_tab;
	CChangeItemsDlg change_items_tab;
};
