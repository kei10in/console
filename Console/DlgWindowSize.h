
#pragma once

//////////////////////////////////////////////////////////////////////////////


//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////


//////////////////////////////////////////////////////////////////////////////

class DlgWindowSize 
	: public CDialogImpl<DlgWindowSize>
	, public CWinDataExchange<DlgWindowSize>
{
	public:
		enum { IDD = IDD_WINDOWSIZE };

		DlgWindowSize(const DWORD rows, const DWORD columns);
		~DlgWindowSize();

		BEGIN_DDX_MAP(DlgWindowSize)
			DDX_UINT_RANGE(IDC_ROWS, m_rows, static_cast<DWORD>(10), static_cast<DWORD>(200))
			DDX_UINT_RANGE(IDC_COLUMNS, m_columns, static_cast<DWORD>(10), static_cast<DWORD>(200))
		END_DDX_MAP()

		BEGIN_MSG_MAP(DlgWindowSize)
			MESSAGE_HANDLER(WM_INITDIALOG, OnInitDialog)
			COMMAND_ID_HANDLER(IDOK, OnCloseCmd)
			COMMAND_ID_HANDLER(IDCANCEL, OnCloseCmd)
		END_MSG_MAP()

// Handler prototypes (uncomment arguments if needed):
//		LRESULT MessageHandler(UINT /*uMsg*/, WPARAM /*wParam*/, LPARAM /*lParam*/, BOOL& /*bHandled*/)
//		LRESULT CommandHandler(WORD /*wNotifyCode*/, WORD /*wID*/, HWND /*hWndCtl*/, BOOL& /*bHandled*/)
//		LRESULT NotifyHandler(int /*idCtrl*/, LPNMHDR /*pnmh*/, BOOL& /*bHandled*/)

		LRESULT OnInitDialog(UINT /*uMsg*/, WPARAM /*wParam*/, LPARAM /*lParam*/, BOOL& /*bHandled*/);
		LRESULT OnCloseCmd(WORD /*wNotifyCode*/, WORD wID, HWND /*hWndCtl*/, BOOL& /*bHandled*/);

	public:

		const DWORD GetRows() const { return m_rows; }
		const DWORD GetColumns() const { return m_columns; }

	private:

		DWORD	m_rows;
		DWORD	m_columns;
};

//////////////////////////////////////////////////////////////////////////////
