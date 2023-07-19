#pragma once

#include "C:/Users/adminstrator/Desktop/Common/Common.h"
#include "C:/Users/adminstrator/Desktop/Common/comstruct.h"
#include <iostream>
#include <vector>
#include "DNFstring.h"
#include "struct.h"

#define WM_INET_NOTIFY 0x410


#define NOTIFY_SERVER_SET 1   //�����������ж� ���������ж�

#define NOTIFY_CONNECT_SUCCESS 2
#define NOTIFY_CONNECT_FAILED 3

#define NOTIFY_LOGIN_SUCCESS 4
#define NOTIFY_LOGIN_FAILED 5

#define NOTIFY_GETCHARACINFO_SUCCESS 20
#define NOTIFY_GETCHARACINFO_FAILED 21

#define NOTIFY_CREATE_CHARAC_SUCCESS 30
#define NOTIFY_CREATE_CHARAC_FAILED_NAMEREPEAT 31
#define NOTIFY_CREATE_CHARAC_FAILED_INVALID_CHAR 35
#define NOTIFY_CREATE_CHARAC_FAILED 32
#define NOTIFY_CREATE_CHARAC_FAILED_charac_too_many 36

#define NOTIFY_DELETE_SUCCESS 40
#define NOTIFY_DELETE_FAIL_SQL_ERR 41
#define NOTIFY_DELETE_FAIL_CHARAC_NOT_EXIST 42



#pragma comment(lib,"ws2_32.lib")
using namespace std;

class CClient {
public:
	CClient();

	static DWORD WINAPI ConnectToServer(LPVOID pParam);
	BOOL SetNotifyMsg(WPARAM wParam, LPARAM lParam);


	bool LoginProcess(); //�����¼
	bool AskCharacProcess(); //�����ɫ��Ϣ
	bool CreateCharacProcess(int job, const char* name);//���󴴽���ɫ
	bool DeleteCharacProcess(const char* name);//����ɾ����ɫ


	bool processMsg(CMsgHead* msg, char* buf); //������������ص�����
	~CClient();

	SOCKET m_ClientSock;
	HANDLE m_hThread;
	char m_szIp[MAX_IP_LEN];
	UINT m_Port;

	
};

//����
CClient* GetCClient();





