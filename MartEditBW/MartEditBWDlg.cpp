
// MartEditBWDlg.cpp : implementation file
//

#include "pch.h"
#include "framework.h"
#include "MartEditBW.h"
#include "MartEditBWDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CAboutDlg dialog used for App About

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Implementation
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CMartEditBWDlg dialog



CMartEditBWDlg::CMartEditBWDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_MARTEDITBW_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	
}

void CMartEditBWDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_TAB_CONTROL, tab_control);
}

BEGIN_MESSAGE_MAP(CMartEditBWDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_NOTIFY(TCN_SELCHANGE, IDC_TAB_CONTROL, &CMartEditBWDlg::OnTcnSelchangeTabControl)
END_MESSAGE_MAP()


// CMartEditBWDlg message handlers

BOOL CMartEditBWDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here
	SetWindowText(L"MartEditBW");

	change_price_tab.Create(IDD_CHANGE_PRICE_TAB, &tab_control);
	change_items_tab.Create(IDD_CHANGE_ITEMS_TAB, &tab_control);

	CRect tab_rect;
	tab_control.GetItemRect(0, &tab_rect);

	TCITEM tabs[(unsigned int)TabType::SIZE];
	for (unsigned int i = 0u; i < (unsigned int)TabType::SIZE; ++i)
	{
		tabs[i].mask = TCIF_TEXT | TCIF_PARAM;
		switch ((TabType)i)
		{
		case TabType::ITEMS:
			tabs[i].lParam = (LPARAM)&change_items_tab;
			tabs[i].pszText = L"Items";

			change_items_tab.SetWindowPos(NULL, tab_rect.left, tab_rect.bottom + 1, 0, 0, SWP_NOSIZE | SWP_NOZORDER);
			break;
		case TabType::PRICE:
			tabs[i].lParam = (LPARAM)&change_price_tab;
			tabs[i].pszText = L"Price";

			change_price_tab.SetWindowPos(NULL, tab_rect.left, tab_rect.bottom + 1, 0, 0, SWP_NOSIZE | SWP_NOZORDER);
			break;
		}
		tab_control.InsertItem(i, &tabs[i]);
	}

	change_items_tab.ShowWindow(SW_SHOW);
	change_price_tab.ShowWindow(SW_HIDE);

	tab_control.SetCurSel(0u);

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CMartEditBWDlg::OnCancel()
{
	if (change_items_tab.SomethingToSave() || change_price_tab.SomethingToSave())
	{
		if (MessageBox(L"Are you sure you want to exit?\nYou have unsaved changes", L"MartEditBW - Unsaved Changes", MB_YESNO | MB_ICONEXCLAMATION) == IDNO)
			return;
	}

	CDialog::OnCancel();
}

void CMartEditBWDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CMartEditBWDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CMartEditBWDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void CMartEditBWDlg::OnTcnSelchangeTabControl(NMHDR* pNMHDR, LRESULT* pResult)
{
	*pResult = 0;

	int tab_selected = tab_control.GetCurSel();

	switch ((TabType)tab_selected)
	{
	case TabType::ITEMS:
		change_items_tab.ShowWindow(SW_SHOW);
		change_price_tab.ShowWindow(SW_HIDE);
		break;
	case TabType::PRICE:
		change_items_tab.ShowWindow(SW_HIDE);
		change_price_tab.ShowWindow(SW_SHOW);
		break;
	}
}