
// MFCApplication6Dlg.h : 헤더 파일
//

#pragma once


// CMFCApplication6Dlg 대화 상자
class CMFCApplication6Dlg : public CDialogEx
{
// 생성입니다.
public:
	CMFCApplication6Dlg(CWnd* pParent = NULL);	// 표준 생성자입니다.

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MFCAPPLICATION6_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 지원입니다.


// 구현입니다.
protected:
	HICON m_hIcon;

	// 생성된 메시지 맵 함수
	virtual BOOL OnInitDialog();
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	void __UpdateData(BOOL val);
	int returnLineCount(int font_size);
	void setFontSize(int font_size);
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	CString m_input;
	afx_msg void OnEnChangeEdit1();
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedButton3();
	afx_msg void OnBnClickedButton4();
	afx_msg void OnBnClickedButton5();
	afx_msg void OnBnClickedButton6();
	afx_msg void OnBnClickedButton7();
	afx_msg void OnBnClickedButton8();
	afx_msg void OnBnClickedButton9();
	afx_msg void OnBnClickedButton0();
	afx_msg void OnBnClickedButtonAdd();
	CString m_temp;
	afx_msg void OnBnClickedButtonEqu();
	CString m_op;
	afx_msg void OnBnClickedButtonDot();
	afx_msg void OnBnClickedButtonC();
	afx_msg void OnBnClickedButtonDel();
	afx_msg void OnBnClickedButtonLp();
	afx_msg void OnBnClickedButtonRp();
	afx_msg void OnBnClickedButtonFac();
	afx_msg void OnBnClickedButtonTen();
	afx_msg void OnBnClickedButtonRoot();
	afx_msg void OnBnClickedButtonSqu();
	afx_msg void OnBnClickedButtonPow();
	afx_msg void OnBnClickedButtonSub();
	afx_msg void OnBnClickedButtonMul();
	afx_msg void OnBnClickedButtonDiv();
	afx_msg void OnBnClickedButtonMod();
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	afx_msg void OnDrawItem(int nIDCtl, LPDRAWITEMSTRUCT lpDrawItemStruct);
	double calc();
};
