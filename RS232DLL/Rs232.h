//Rs232.h
//Rs232c�� �ϱ����� Ŭ���� ���
#pragma once


#define MAXBLOCK        80
#define MAXPORTS        20

// Flow control flags

#define FC_DTRDSR       0x01
#define FC_RTSCTS       0x02
#define FC_XONXOFF      0x04

// ascii definitions

#define ASCII_BEL       0x07
#define ASCII_BS        0x08
#define ASCII_LF        0x0A
#define ASCII_CR        0x0D
#define ASCII_XON       0x11
#define ASCII_XOFF      0x13

#define WM_RECEIVE_RS232				(WM_USER+8080)

// function prototypes (private)

/////////////////////////////////////////////////////////////////////////////
// CRs232 window


//class AFX_EXT_CLASS CRs232 : public CObject
class AFX_EXT_CLASS CRs232
{
	//DECLARE_DYNCREATE( CRs232 )

	CString CharToString(char *szStr);


public:
	HANDLE      m_hComDev ;						//����Ʈ ����̽� ���� �ڵ�
	BOOL        m_bConnected;					//����Ʈ�� ����Ǹ� 1�� ����
	//BYTE       m_cRxBuffer[ MAXBLOCK + 1] ;	//����Ʈ���� ������ ����Ÿ
	CString       m_cRxBuffer;					//����Ʈ���� ������ ����Ÿ
	HWND m_hwnd;								//�޼����� ������ ������ �÷���

	// Attributes
public:
	BYTE			m_nPort;
	BOOL			m_bXonXoff;
	BYTE			m_nByteSize, m_nFlowCtrl, m_nParity, m_nStopBits ;
	DWORD			m_dwBaudRate ;
	HANDLE			m_hWatchThread;
	HWND			m_hTermWnd ;
	DWORD			m_dwThreadID ;
	OVERLAPPED		m_osWrite, m_osRead ;

	BOOL			m_bCR, m_bLF;
	BOOL			m_bOnLine;

// Construction
public:
	CRs232();

	// Implementation
public:
	~CRs232();

	void ClearReceive();
	//������ �����Ѵ�.
	BOOL CloseConnection();

	void SetXonOff(BOOL chk);//XonOff ����
	//����Ʈ�� ������
	void SetComPort(int port,DWORD rate,BYTE bytesize,BYTE stop,BYTE parity);
	//Dtr Rts����
	void SetDtrRts(BYTE chk);
	//Rs232 ��Ʈ�� �����.
	BOOL CreateRs232Info();
	//Rs232 ��Ʈ�� �����Ѵ�.
	BOOL DestroyRs232();
	//����Ʈ���� ����Ÿ�� �޴´�.
	int  ReadRs232Block( LPSTR, int ) ;
	//����Ʈ�� ����Ÿ�� �ִ´�.
	BOOL WriteRs232Block( LPSTR, DWORD);
	BOOL OpenComPort() ;//����Ʈ�� ���� ������ �õ��Ѵ�.
	//��Ʈ�� �����Ѵ�.
	BOOL SetupConnection() ;
	//���� ����Ÿ�� ���ۿ� �����Ѵ�.
	void SetReadData(LPSTR data);
	//�޼��縦 ���� ������ �÷��� �����Ѵ�.
	void SetHwnd(HWND hwnd);


// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CRs232)
	//}}AFX_VIRTUAL

	// Generated message map functions
//	DECLARE_MESSAGE_MAP()
protected:
	static UINT Rs232WatchProc(LPVOID pParam);
};


