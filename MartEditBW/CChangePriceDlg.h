#pragma once
#include "afxdialogex.h"

#include "PriceChanger.h"

// CChangePriceDlg dialog

class CChangePriceDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CChangePriceDlg)

public:
	CChangePriceDlg(CWnd* pParent = nullptr);   // standard constructor
	virtual ~CChangePriceDlg();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_CHANGE_PRICE_TAB };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	virtual BOOL OnInitDialog();

	DECLARE_MESSAGE_MAP()

private:

	afx_msg void OnBnClickedFilePathButton();
	afx_msg void OnCbnSelchangeItemCombo();
	afx_msg void OnEnChangePriceEdit();
	afx_msg void OnBnClickedSaveButton();

	CEdit file_path_edit;
	CComboBox item_combo;
	CEdit price_edit;
	CButton save_price_button;

	PriceChanger price_changer;

	int last_item_combo_idx = 0;
	CString current_saved_price = L"0";

public:
	bool SomethingToSave();
};
