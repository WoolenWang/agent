/*
This Source Code Form is subject to the terms of the Mozilla
Public License, v. 2.0. If a copy of the MPL was not distributed
with this file, You can obtain one at http://mozilla.org/MPL/2.0/.
*/


#if defined OS_WINDOWS
#include <windows.h>
#include <tchar.h>
#include <pdh.h>
#include <stdio.h>
#include <winsvc.h>
#endif

#include "util.h"
#include "jsonwriter.h"

using namespace std;

class ServiceMng{
public:
	ServiceMng();
	int getServiceList(wchar_t** sret);
	int startService(wchar_t* serviceName);
	int stopService(wchar_t* serviceName);
private:
#if defined OS_WINDOWS
	bool checkStateService(SC_HANDLE schService,DWORD state);
	bool waitStateService(SC_HANDLE schService,DWORD state);
	int statusService(wchar_t* serviceName);
#endif

};
