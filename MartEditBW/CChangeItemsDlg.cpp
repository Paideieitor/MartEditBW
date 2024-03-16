// CChangeItemsDlg.cpp : implementation file
//

#include "pch.h"
#include "MartEditBW.h"
#include "afxdialogex.h"
#include "CChangeItemsDlg.h"


// CChangeItemsDlg dialog

IMPLEMENT_DYNAMIC(CChangeItemsDlg, CDialogEx)

CChangeItemsDlg::CChangeItemsDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_CHANGE_ITEMS_TAB, pParent)
{

}

CChangeItemsDlg::~CChangeItemsDlg()
{
}

void CChangeItemsDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_MART_PATH_EDIT, mart_path_edit);
	DDX_Control(pDX, IDC_MART_COMBO, mart_combo);
	DDX_Control(pDX, IDC_MART_ITEM_LIST, mart_item_list);
	DDX_Control(pDX, IDC_CHOOSE_ITEM_COMBO, choose_item_combo);
	DDX_Control(pDX, IDC_SAVE_ITEM_BUTTON, save_item_button);
}

BOOL CChangeItemsDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	std::vector<CString> mart_names = item_changer.GetMartNames();
	for (unsigned int i = 0u; i < mart_names.size(); ++i)
		mart_combo.AddString(mart_names[i]);
	mart_combo.SetCurSel(last_mart_combo_idx);
	
	std::vector<CString> item_names = item_changer.GetItemNames();
	for (unsigned int i = 0u; i < item_names.size(); ++i)
		choose_item_combo.AddString(item_names[i]);
	choose_item_combo.SetCurSel(last_choose_item_combo_idx);

	save_item_button.EnableWindow(FALSE);
	
	return TRUE;
}


BEGIN_MESSAGE_MAP(CChangeItemsDlg, CDialogEx)
	ON_BN_CLICKED(IDC_MART_PATH_BUTTON, &CChangeItemsDlg::OnBnClickedMartPathButton)
	ON_CBN_SELCHANGE(IDC_MART_COMBO, &CChangeItemsDlg::OnCbnSelchangeMartCombo)
	ON_LBN_SELCHANGE(IDC_MART_ITEM_LIST, &CChangeItemsDlg::OnLbnSelchangeMartItemList)
	ON_CBN_SELCHANGE(IDC_CHOOSE_ITEM_COMBO, &CChangeItemsDlg::OnCbnSelchangeChooseItemCombo)
	ON_BN_CLICKED(IDC_SAVE_ITEM_BUTTON, &CChangeItemsDlg::OnBnClickedSaveItemButton)
END_MESSAGE_MAP()


// CChangeItemsDlg message handlers
void CChangeItemsDlg::OnBnClickedMartPathButton()
{
	if (SomethingToSave())
	{
		if (MessageBox(L"Are you sure you want to change folder?\nYou have unsaved changes", L"MartEditBW - Unsaved Changes", MB_YESNO | MB_ICONEXCLAMATION) == IDNO)
			return;
	}

	LPCTSTR file_dlg_filter = L"Binary (*.bin)|*.bin|";
	CFileDialog file_dlg(TRUE, L"bin", NULL, OFN_HIDEREADONLY | OFN_FILEMUSTEXIST, file_dlg_filter, AfxGetMainWnd());

	if (file_dlg.DoModal() == IDOK)
	{
		mart_path_edit.SetWindowTextW(file_dlg.GetPathName());
		item_changer.SetMartFilePath(file_dlg.GetPathName());

		last_mart_combo_idx = 0;
		mart_combo.SetCurSel(last_mart_combo_idx);
		last_choose_item_combo_idx = 0;
		choose_item_combo.SetCurSel(last_choose_item_combo_idx);

		current_item_list_idx = -1;
		mart_item_list.ResetContent();
		current_mart.clear();
		unsaved_item_changes.clear();

		save_item_button.EnableWindow(FALSE);

		Invalidate();
		UpdateWindow();
	}
}

void CChangeItemsDlg::OnCbnSelchangeMartCombo()
{
	if (mart_combo.GetCurSel() == last_mart_combo_idx)
		return;

	if (SomethingToSave())
	{
		if (MessageBox(L"Are you sure you want to change mart?\nYou have unsaved changes", L"MartEditBW - Unsaved Changes", MB_YESNO | MB_ICONEXCLAMATION) == IDNO)
			return;
	}

	CString mart_name;
	mart_combo.GetLBText(mart_combo.GetCurSel(), mart_name);

	std::vector<CString> mart_items;
	int error = item_changer.LoadMartItems(mart_name, mart_items);
	if (error < 0)
	{
		mart_combo.SetCurSel(last_mart_combo_idx);
		AfxMessageBox(item_changer.GetLastMartError());
		return;
	}

	mart_item_list.ResetContent();
	current_mart.clear();
	unsaved_item_changes.clear();
	for (unsigned int i = 0u; i < mart_items.size(); ++i)
	{
		mart_item_list.AddString(mart_items[i]);
		current_mart.push_back(mart_items[i]);
		unsaved_item_changes.push_back(mart_items[i]);
	}

	choose_item_combo.SetCurSel(0);

	last_mart_combo_idx = mart_combo.GetCurSel();
	last_choose_item_combo_idx = 0;
	current_item_list_idx = -1;

	save_item_button.EnableWindow(FALSE);
}


void CChangeItemsDlg::OnLbnSelchangeMartItemList()
{
	CString item_name;
	mart_item_list.GetText(mart_item_list.GetCurSel(), item_name);

	int item_list_position = choose_item_combo.FindStringExact(-1, item_name);
	choose_item_combo.SetCurSel(item_list_position);

	last_choose_item_combo_idx = item_list_position;
	current_item_list_idx = mart_item_list.GetCurSel();
}


void CChangeItemsDlg::OnCbnSelchangeChooseItemCombo()
{
	int current_idx = choose_item_combo.GetCurSel();
	if (current_idx == 0 || current_idx == last_choose_item_combo_idx || current_item_list_idx < 0)
	{
		choose_item_combo.SetCurSel(last_choose_item_combo_idx);
		return;
	}

	CString item_name;
	choose_item_combo.GetLBText(choose_item_combo.GetCurSel(), item_name);

	unsaved_item_changes[current_item_list_idx] = item_name;
	mart_item_list.DeleteString(current_item_list_idx);
	mart_item_list.InsertString(current_item_list_idx, item_name);

	last_choose_item_combo_idx = current_idx;

	save_item_button.EnableWindow(FALSE);
	for (unsigned int i = 0u; i < current_mart.size(); ++i)
		if (current_mart[i] != unsaved_item_changes[i])
		{
			save_item_button.EnableWindow(TRUE);
			break;
		}
}


void CChangeItemsDlg::OnBnClickedSaveItemButton()
{
	CString mart_name;
	mart_combo.GetLBText(mart_combo.GetCurSel(), mart_name);

	int error = item_changer.SaveItemChanges(mart_name, unsaved_item_changes);
	if (error < 0)
	{
		AfxMessageBox(item_changer.GetLastMartError());
		return;
	}

	current_mart = unsaved_item_changes;
	save_item_button.EnableWindow(FALSE);
}

bool CChangeItemsDlg::SomethingToSave()
{
	bool output = false;
	for (unsigned int i = 0u; i < current_mart.size(); ++i)
		if (current_mart[i] != unsaved_item_changes[i])
		{
			output = true;
			break;
		}
	return output;
}
