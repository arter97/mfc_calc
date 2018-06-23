
#include "stdafx.h"
#include "MFCApplication6.h"
#include "MFCApplication6Dlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

bool eflag = true;
bool dflag = false;

int p_count = 0;

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);  

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

CMFCApplication6Dlg::CMFCApplication6Dlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_MFCAPPLICATION6_DIALOG, pParent)
	, m_input(_T(""))
	, m_temp(_T(""))
	, m_op(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMFCApplication6Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_input);
	DDX_Text(pDX, IDC_EDIT2, m_temp);
	DDX_Text(pDX, IDC_EDIT3, m_op);
}

BEGIN_MESSAGE_MAP(CMFCApplication6Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &CMFCApplication6Dlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CMFCApplication6Dlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON3, &CMFCApplication6Dlg::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON4, &CMFCApplication6Dlg::OnBnClickedButton4)
	ON_BN_CLICKED(IDC_BUTTON5, &CMFCApplication6Dlg::OnBnClickedButton5)
	ON_BN_CLICKED(IDC_BUTTON6, &CMFCApplication6Dlg::OnBnClickedButton6)
	ON_BN_CLICKED(IDC_BUTTON7, &CMFCApplication6Dlg::OnBnClickedButton7)
	ON_BN_CLICKED(IDC_BUTTON8, &CMFCApplication6Dlg::OnBnClickedButton8)
	ON_BN_CLICKED(IDC_BUTTON9, &CMFCApplication6Dlg::OnBnClickedButton9)
	ON_BN_CLICKED(IDC_BUTTON0, &CMFCApplication6Dlg::OnBnClickedButton0)
	ON_BN_CLICKED(IDC_BUTTON_ADD, &CMFCApplication6Dlg::OnBnClickedButtonAdd)
	ON_BN_CLICKED(IDC_BUTTON_EQU, &CMFCApplication6Dlg::OnBnClickedButtonEqu)
	ON_BN_CLICKED(IDC_BUTTON_DOT, &CMFCApplication6Dlg::OnBnClickedButtonDot)
	ON_BN_CLICKED(IDC_BUTTON_C, &CMFCApplication6Dlg::OnBnClickedButtonC)
	ON_BN_CLICKED(IDC_BUTTON_DEL, &CMFCApplication6Dlg::OnBnClickedButtonDel)
	ON_BN_CLICKED(IDC_BUTTON_ROOT, &CMFCApplication6Dlg::OnBnClickedButtonRoot)
	ON_BN_CLICKED(IDC_BUTTON_SQU, &CMFCApplication6Dlg::OnBnClickedButtonSqu)
	ON_BN_CLICKED(IDC_BUTTON_POW, &CMFCApplication6Dlg::OnBnClickedButtonPow)
	ON_BN_CLICKED(IDC_BUTTON_SUB, &CMFCApplication6Dlg::OnBnClickedButtonSub)
	ON_BN_CLICKED(IDC_BUTTON_MUL, &CMFCApplication6Dlg::OnBnClickedButtonMul)
	ON_BN_CLICKED(IDC_BUTTON_DIV, &CMFCApplication6Dlg::OnBnClickedButtonDiv)
	ON_BN_CLICKED(IDC_BUTTON_MOD, &CMFCApplication6Dlg::OnBnClickedButtonMod)
	ON_BN_CLICKED(IDC_BUTTON_LP, &CMFCApplication6Dlg::OnBnClickedButtonLp)
	ON_BN_CLICKED(IDC_BUTTON_RP, &CMFCApplication6Dlg::OnBnClickedButtonRp)
	ON_WM_CTLCOLOR()
	ON_WM_DRAWITEM()
END_MESSAGE_MAP()


BOOL CMFCApplication6Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
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
	SetIcon(m_hIcon, TRUE);		
	SetIcon(m_hIcon, FALSE);	


	return TRUE; 
}

void CMFCApplication6Dlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CMFCApplication6Dlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); 
		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

HCURSOR CMFCApplication6Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

HBRUSH CMFCApplication6Dlg::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
	HBRUSH hbr = CDialogEx::OnCtlColor(pDC, pWnd, nCtlColor);
	return hbr;
}
/*********************************************
	   공학용 계산기 버튼 기능 구현하기
**********************************************/

//숫자버튼 1
void CMFCApplication6Dlg::OnBnClickedButton1()
{
	if (eflag == true)
		m_input = "";
	eflag = false;
	m_input.AppendChar('1');
	UpdateData(false);
}

//숫자버튼 2
void CMFCApplication6Dlg::OnBnClickedButton2()
{
	if (eflag == true)
		m_input = "";
	eflag = false;
	m_input.AppendChar('2');
	UpdateData(false);
}

//숫자버튼 3
void CMFCApplication6Dlg::OnBnClickedButton3()
{
	if (eflag == true)
		m_input = "";
	eflag = false;
	m_input.AppendChar('3');
	UpdateData(false);
}

//숫자버튼 4
void CMFCApplication6Dlg::OnBnClickedButton4()
{
	if (eflag == true)
		m_input = "";
	eflag = false;
	m_input.AppendChar('4');
	UpdateData(false);
}

//숫자버튼 5
void CMFCApplication6Dlg::OnBnClickedButton5()
{
	if (eflag == true)
		m_input = "";
	eflag = false;
	m_input.AppendChar('5');
	UpdateData(false);
}

//숫자버튼 6
void CMFCApplication6Dlg::OnBnClickedButton6()
{
	if (eflag == true)
		m_input = "";
	eflag = false;
	m_input.AppendChar('6');
	UpdateData(false);
}

//숫자버튼 7
void CMFCApplication6Dlg::OnBnClickedButton7()
{
	if (eflag == true)
		m_input = "";
	eflag = false;
	m_input.AppendChar('7');
	UpdateData(false);
}

//숫자버튼 8
void CMFCApplication6Dlg::OnBnClickedButton8()
{
	if (eflag == true)
		m_input = "";
	eflag = false;
	m_input.AppendChar('8');
	UpdateData(false);
}

//숫자버튼 9
void CMFCApplication6Dlg::OnBnClickedButton9()
{
	if (eflag == true)
		m_input = "";
	eflag = false;
	m_input.AppendChar('9');
	UpdateData(false);
}

//숫자버튼 0
void CMFCApplication6Dlg::OnBnClickedButton0()
{
	if (eflag == true)
		m_input = "0";
	eflag = false;
	m_input.AppendChar('0');
	UpdateData(false);
}

//소수점
void CMFCApplication6Dlg::OnBnClickedButtonDot()
{
	if (!dflag)
		m_input.AppendChar('.');
	dflag = true;
	UpdateData(false);
}

// Clear
void CMFCApplication6Dlg::OnBnClickedButtonC()
{
	m_input = "";
	m_op = "";
	m_temp = "";
	eflag = true;
	dflag = false;
	UpdateData(false);
}

// 1글자 지우기
void CMFCApplication6Dlg::OnBnClickedButtonDel()
{
	char buf[100];
	wcstombs(buf, m_input, 100);
	int len = strlen(buf);
	if (len > 0) {
		if (m_input.GetAt(len - 1) == '.') {
			dflag = false;
		}
		m_input.Delete(len - 1, 1);
	}
	UpdateData(false);
}

/***********************************************
         이하 어셈블리어 구현 필수
************************************************/

//왼쪽 괄호
void CMFCApplication6Dlg::OnBnClickedButtonLp()
{
	if (eflag == true)
		m_input = "";
	eflag = false;
	m_input.AppendChar('(');
	/*
	__asm{


	}
	*/
	UpdateData(false);
}

//오른쪽 괄호
void CMFCApplication6Dlg::OnBnClickedButtonRp()
{
	if (eflag == true)
		m_input = "";
	eflag = false;
	m_input.AppendChar(')');

	/*
	__asm{


	}
	*/
	UpdateData(false);
}


/*************
   1항연산자
**************/
//제곱근
void CMFCApplication6Dlg::OnBnClickedButtonRoot()
{
	char vchar[100];
	wcstombs(vchar, m_input, 100);
	double fval = atof(vchar);	//입력된 실수
	double res = 0;				//출력할 결과

	/*
	__asm{

	}
	*/

	char rval[100];
	sprintf(rval, "%lf", res);
	m_input = rval;				//결과 출력

	eflag = true;
	dflag = false;

	UpdateData(false);
}

//2제곱
void CMFCApplication6Dlg::OnBnClickedButtonSqu()
{
	char vchar[100];
	wcstombs(vchar, m_input, 100);
	double fval = atof(vchar);	//입력된 실수
	double res = 0;				//출력할 결과
	
	/*
	__asm{

	}
	*/
	
	char rval[100];
	sprintf(rval, "%lf", res);
	m_input = rval;				//결과 출력

	eflag = true;
	dflag = false;

	UpdateData(false);
}


/*************
   2항연산자
**************/
//덧셈 연산자 입력
void CMFCApplication6Dlg::OnBnClickedButtonAdd()
{
	if (m_op != "") {
		double res = calc();
		char rval[100];
		sprintf(rval, "%lf", res);
		m_temp = rval;
	}
	else m_temp = m_input;
	m_op = '+';
	m_input = "";
	dflag = false;
	UpdateData(false);
}
//뺄셈 연산자 입력
void CMFCApplication6Dlg::OnBnClickedButtonSub()
{
	if (m_op != "") {
		double res = calc();
		char rval[100];
		sprintf(rval, "%lf", res);
		m_temp = rval;
	}
	else m_temp = m_input;
	m_op = '-';
	m_input = "";
	dflag = false;
	UpdateData(false);
}
//곱셈 연산자 입력
void CMFCApplication6Dlg::OnBnClickedButtonMul()
{
	if (m_op != "") {
		double res = calc();
		char rval[100];
		sprintf(rval, "%lf", res);
		m_temp = rval;
	}
	else m_temp = m_input;
	m_op = '*';
	m_input = "";
	dflag = false;
	UpdateData(false);
}
//나눗셈 연산자 입력
void CMFCApplication6Dlg::OnBnClickedButtonDiv()
{
	if (m_op != "") {
		double res = calc();
		char rval[100];
		sprintf(rval, "%lf", res);
		m_temp = rval;
	}
	else m_temp = m_input;
	m_op = '/';
	m_input = "";
	dflag = false;
	UpdateData(false);
}
//Mod 연산자 입력
void CMFCApplication6Dlg::OnBnClickedButtonMod()
{
	if (m_op != "") {
		double res = calc();
		char rval[100];
		sprintf(rval, "%lf", res);
		m_temp = rval;
	}
	else m_temp = m_input;
	m_op = '%';
	m_input = "";
	dflag = false;
	UpdateData(false);
}
//n제곱 연산자 입력
void CMFCApplication6Dlg::OnBnClickedButtonPow()
{
	if (m_op != "") {
		double res = calc();
		char rval[100];
		sprintf(rval, "%lf", res);
		m_temp = rval;
	}
	else m_temp = m_input;
	m_op = '^';
	m_input = "";
	dflag = false;
	UpdateData(false);
}
/**********
  계산
***********/
double CMFCApplication6Dlg::calc()
{
	char vchar1[100], vchar2[100];
	wcstombs(vchar1, m_temp, 100);
	wcstombs(vchar2, m_input, 100);

	double fval1 = atof(vchar1);	//m_temp에 입력되어 있는 실수
	double fval2 = atof(vchar2);	//m_input에 입력되어 있는 실수
	double res = 0;						//출력할 결과
									//m_op에 입력되어 있는 값에 따라 연산
	switch (m_op.GetAt(0)) {
	case '+':
		//c++
		//res = fval1 + fval2;

		//inline assembly
		__asm {
			fld fval1
			fld fval2
			fadd
			fstp res
		}
		break;
	case '-':
		// res = fval1 - fval2
		// Inline assembly
		__asm{
			fld fval1
			fld fval2
			fsub
			fstp res
		}
		break;
	case '*':
		// res = fval1 * fval2
		// Inline assembly
		__asm {
			fld fval1
			fld fval2
			fmul
			fstp res
		}
		break;
	case '/':
		// res = fval1 / fval2
		// Inline assembly
		__asm {
			fld fval1
			fld fval2
			fdiv
			fstp res
		}
		break;
	case '%':
		/*
		__asm{

		}
		*/
		break;
	case '^':
		/*
		__asm{

		}
		*/
		break;
	default:
		res = fval2;
		break;
	}
	return res;
}
//등호 버튼
void CMFCApplication6Dlg::OnBnClickedButtonEqu()
{
	double res = calc();
	char rval[100];
	sprintf(rval, "%lf", res);
	m_input = rval;

	m_temp = "";
	m_op = "";
	eflag = true;
	dflag = false;

	UpdateData(false);
}





void setBtnColor(CDC  *dc, RECT rect, COLORREF color) {
	dc->FillSolidRect(&rect, color);
	dc->SetBkColor(color);
}

void CMFCApplication6Dlg::OnDrawItem(int nIDCtl, LPDRAWITEMSTRUCT lpDrawItemStruct)
{
#define green RGB(0,200,0)
#define red RGB(200,0,0)
	CDC dc;
	RECT rect;
	dc.Attach(lpDrawItemStruct->hDC);   
	dc.Draw3dRect(&rect, RGB(255, 255, 255), RGB(0, 0, 0));
	rect = lpDrawItemStruct->rcItem;  

	//버튼 색생 변경하기

	if (nIDCtl == IDC_BUTTON_ADD)		//덧셈
	{
		setBtnColor(&dc, rect, green);	//구현 완료 : green
	}
	if (nIDCtl == IDC_BUTTON_SUB)		//뺄셈
	{
		setBtnColor(&dc, rect, green);	//구현 완료 : green
	}
	if (nIDCtl == IDC_BUTTON_MUL)		//곱셈
	{
		setBtnColor(&dc, rect, green);	//구현 완료 : green
	}	
	if (nIDCtl == IDC_BUTTON_DIV)		//나눗셈
	{
		setBtnColor(&dc, rect, green);	//구현 완료 : green
	}
	if (nIDCtl == IDC_BUTTON_MOD)		//MOD
	{
		setBtnColor(&dc, rect, red);
	}
	if (nIDCtl == IDC_BUTTON_ROOT)		//제곱근
	{
		setBtnColor(&dc, rect, red);
	}
	if (nIDCtl == IDC_BUTTON_SQU)		//2제곱
	{
		setBtnColor(&dc, rect, red);
	}
	if (nIDCtl == IDC_BUTTON_POW)		//n제곱
	{
		setBtnColor(&dc, rect, red);
	}
	if (nIDCtl == IDC_BUTTON_LP)		//왼쪽괄호
	{
		setBtnColor(&dc, rect, red);
	}
	if (nIDCtl == IDC_BUTTON_RP)		//오른쪽괄호
	{
		setBtnColor(&dc, rect, red);
	}
	
	UINT state = lpDrawItemStruct->itemState;  //This defines the state of the Push button either pressed or not. 
	if ((state & ODS_SELECTED))
		dc.DrawEdge(&rect, EDGE_SUNKEN, BF_RECT);
	else
		dc.DrawEdge(&rect, EDGE_RAISED, BF_RECT);

	TCHAR buffer[MAX_PATH];           //To store the Caption of the button.
	ZeroMemory(buffer, MAX_PATH);     //Intializing the buffer to zero
	::GetWindowText(lpDrawItemStruct->hwndItem, buffer, MAX_PATH); //Get the Caption of Button Window 

	dc.DrawText(buffer, &rect, DT_CENTER | DT_VCENTER | DT_SINGLELINE);//Redraw the  Caption of Button Window 
	dc.Detach();  // Detach the Button DC
	CDialog::OnDrawItem(nIDCtl, lpDrawItemStruct);

}
