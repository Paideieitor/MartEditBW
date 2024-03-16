#pragma once
#include "afxdialogex.h"

#include "ItemChanger.h"

// CChangeItemsDlg dialog

class CChangeItemsDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CChangeItemsDlg)

public:
	CChangeItemsDlg(CWnd* pParent = nullptr);   // standard constructor
	virtual ~CChangeItemsDlg();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_CHANGE_ITEMS_TAB };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	virtual BOOL OnInitDialog();

	DECLARE_MESSAGE_MAP()

private:

	afx_msg void OnBnClickedMartPathButton();
	afx_msg void OnCbnSelchangeMartCombo();
	afx_msg void OnLbnSelchangeMartItemList();
	afx_msg void OnCbnSelchangeChooseItemCombo();
	afx_msg void OnBnClickedSaveItemButton();

	CEdit mart_path_edit;
	CComboBox mart_combo;
	CListBox mart_item_list;
	CComboBox choose_item_combo;
	CButton save_item_button;

	ItemChanger item_changer;

	int last_mart_combo_idx = 0;
	int last_choose_item_combo_idx = 0;
	int current_item_list_idx = -1;

	std::vector<CString> current_mart;
	std::vector<CString> unsaved_item_changes;

public:
	bool SomethingToSave();
};
