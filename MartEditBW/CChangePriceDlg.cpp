// CChangePriceDlg.cpp : implementation file
//

#include "pch.h"
#include "MartEditBW.h"
#include "afxdialogex.h"
#include "CChangePriceDlg.h"

// CChangePriceDlg dialog

IMPLEMENT_DYNAMIC(CChangePriceDlg, CDialogEx)

CChangePriceDlg::CChangePriceDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_CHANGE_PRICE_TAB, pParent)
{
}

CChangePriceDlg::~CChangePriceDlg()
{
}

void CChangePriceDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_ITEM_PATH_EDIT, file_path_edit);
	DDX_Control(pDX, IDC_ITEM_COMBO, item_combo);
	DDX_Control(pDX, IDC_PRICE_EDIT, price_edit);
	DDX_Control(pDX, IDC_SAVE_BUTTON, save_price_button);
}

BEGIN_MESSAGE_MAP(CChangePriceDlg, CDialogEx)
	ON_BN_CLICKED(IDC_FILE_PATH_BUTTON, &CChangePriceDlg::OnBnClickedFilePathButton)
	ON_CBN_SELCHANGE(IDC_ITEM_COMBO, &CChangePriceDlg::OnCbnSelchangeItemCombo)
	ON_EN_CHANGE(IDC_PRICE_EDIT, &CChangePriceDlg::OnEnChangePriceEdit)
	ON_BN_CLICKED(IDC_SAVE_BUTTON, &CChangePriceDlg::OnBnClickedSaveButton)
END_MESSAGE_MAP()


BOOL CChangePriceDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	std::vector<CString> item_names = price_changer.GetItemNames();
	if (item_names.size() > 0u)
	{
		for (unsigned int i = 0u; i < item_names.size(); ++i)
			item_combo.AddString(item_names[i]);

		item_combo.SetCurSel(last_item_combo_idx);
		price_edit.SetWindowTextW(current_saved_price);

		save_price_button.EnableWindow(FALSE);
	}
	return TRUE;
}

// CChangePriceDlg message handler

void CChangePriceDlg::OnBnClickedFilePathButton()
{
	if (SomethingToSave())
	{
		if (MessageBox(L"Are you sure you want to change file?\nYou have unsaved changes", L"MartEditBW - Unsaved Changes", MB_YESNO | MB_ICONEXCLAMATION) == IDNO)
			return;
	}

	CFolderPickerDialog file_dlg(NULL, NULL, AfxGetMainWnd());

	if (file_dlg.DoModal() == IDOK)
	{
		price_changer.SetItemFolderPath(file_dlg.GetFolderPath());
		file_path_edit.SetWindowTextW(file_dlg.GetFolderPath());

		// Reset Price Changer when targeting a new folder
		item_combo.SetCurSel(0);

		CString item_name;
		item_combo.GetLBText(item_combo.GetCurSel(), item_name);

		CString price = price_changer.LoadCurrentPrice(item_name.GetBuffer());
		price_edit.SetWindowTextW(price);

		last_item_combo_idx = item_combo.GetCurSel();
		current_saved_price = price;

		save_price_button.EnableWindow(FALSE);

		Invalidate();
		UpdateWindow();
	}
}


void CChangePriceDlg::OnCbnSelchangeItemCombo()
{
	if (item_combo.GetCurSel() == last_item_combo_idx)
		return;

	if (SomethingToSave())
	{
		if (MessageBox(L"Are you sure you want to change item?\nYou have unsaved changes", L"MartEditBW - Unsaved Changes", MB_YESNO | MB_ICONEXCLAMATION) == IDNO)
			return;
	}

	CString item_name;
	item_combo.GetLBText(item_combo.GetCurSel(), item_name);

	CString price = price_changer.LoadCurrentPrice(item_name.GetBuffer());
	if (price.GetLength() <= 0)
	{
		item_combo.SetCurSel(last_item_combo_idx);
		AfxMessageBox(price_changer.GetLastMartError());
		return;
	}
	price_edit.SetWindowTextW(price);

	last_item_combo_idx = item_combo.GetCurSel();
	current_saved_price = price;

	save_price_button.EnableWindow(FALSE);
}

bool EraseNumbers(CString& str)
{
	const wchar_t* numbers = L"0123456789";

	for (unsigned int i = 0u; i < str.GetLength(); ++i)
	{
		wchar_t character = str[i];
		bool is_a_number = false;

		for (unsigned int j = 0u; j < 10u; ++j)
			if (str[i] == numbers[j])
			{
				is_a_number = true;
				break;
			}

		if (!is_a_number)
		{
			str.Delete(i, 1);
			return true;
		}
	}
	return false;
}

void CChangePriceDlg::OnEnChangePriceEdit()
{
	CString price;
	price_edit.GetWindowTextW(price);

	if (EraseNumbers(price))
		price_edit.SetWindowTextW(price);

	if (current_saved_price == price)
		save_price_button.EnableWindow(FALSE);
	else
		save_price_button.EnableWindow(TRUE);
}


void CChangePriceDlg::OnBnClickedSaveButton()
{
	CString price;
	price_edit.GetWindowTextW(price);

	int error = price_changer.ChangeCurrentPrice(price);
	if (error < 0)
	{
		AfxMessageBox(price_changer.GetLastMartError());
		return;
	}

	current_saved_price = price;

	save_price_button.EnableWindow(FALSE);
}

bool CChangePriceDlg::SomethingToSave()
{
	CString price;
	price_edit.GetWindowTextW(price);

	if (current_saved_price == price)
		return false;
	else
		return true;
}
