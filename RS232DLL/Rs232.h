//Rs232.h
//Rs232c를 하기위한 클래스 헤더
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
	HANDLE      m_hComDev ;						//컴포트 디바이스 연결 핸들
	BOOL        m_bConnected;					//컴포트가 연결되면 1로 설정
	//BYTE       m_cRxBuffer[ MAXBLOCK + 1] ;	//컴포트에서 들어오는 데이타
	CString       m_cRxBuffer;					//컴포트에서 들어오는 데이타
	HWND m_hwnd;								//메세지를 전달할 윈도우 플러그

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
	//연결을 해제한다.
	BOOL CloseConnection();

	void SetXonOff(BOOL chk);//XonOff 설정
	//컴포트를 설정함
	void SetComPort(int port,DWORD rate,BYTE bytesize,BYTE stop,BYTE parity);
	//Dtr Rts설정
	void SetDtrRts(BYTE chk);
	//Rs232 포트를 만든다.
	BOOL CreateRs232Info();
	//Rs232 포트를 해제한다.
	BOOL DestroyRs232();
	//컴포트에서 데이타를 받는다.
	int  ReadRs232Block( LPSTR, int ) ;
	//컴포트에 데이타를 넣는다.
	BOOL WriteRs232Block( LPSTR, DWORD);
	BOOL OpenComPort() ;//컴포트를 열고 연결을 시도한다.
	//포트를 연결한다.
	BOOL SetupConnection() ;
	//읽은 데이타를 버퍼에 저장한다.
	void SetReadData(LPSTR data);
	//메세재를 보낼 윈도우 플래를 설정한다.
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


