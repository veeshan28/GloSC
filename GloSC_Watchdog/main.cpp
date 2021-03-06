/*
Copyright 2018-2019 Peter Repukat - FlatspotSoftware

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.
*/

/*
 
GloSC_Watchdog, unhooks Steam if SteamTarget gets killed.

*/

#define NOMINMAX
#include <Windows.h>

#include "../common/Injector.h"
#include "../common/process_alive.h"

#define LOGURU_IMPLEMENTATION 1
#include "../common/loguru.hpp"


int CALLBACK WinMain(
	_In_ HINSTANCE hInstance,
	_In_ HINSTANCE hPrevInstance,
	_In_ LPSTR     lpCmdLine,
	_In_ int       nCmdShow
)
{
	while (process_alive::IsProcessRunning(L"SteamTarget.exe"))
	{
		Sleep(1000);
	} 
	
	Injector::unhookSteam();

	return 0;
}