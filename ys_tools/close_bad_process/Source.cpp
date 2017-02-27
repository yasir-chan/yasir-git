

#include "..\..\include\ys_common.h"
#include <windows.h>


int main(int, char**)
{
	std::vector<std::string> bad_lists;
	//bad_lists.push_back("Microsoft.VsHub.Server.HttpHost.exe");
	//bad_lists.push_back("Microsoft.VsHub.Server.HttpHostx64.exe");
	//bad_lists.push_back("vcpkgsrv.exe");
	//bad_lists.push_back("ScriptedSandbox64.exe");
	//bad_lists.push_back("VsHub.exe");
	//bad_lists.push_back("ThunderPlatform.exe");
	//bad_lists.push_back("dgservice.exe");
	bad_lists.push_back("vrmonitor.exe");
	bad_lists.push_back("vrcompositor.exe");
	bad_lists.push_back("vrdashboard.exe");
	bad_lists.push_back("vrserver.exe");

	char cmd[1024];
	while (true)
	{
		Sleep(5000);
		for (size_t i = 0; i < bad_lists.size(); i++)
		{
			sprintf(cmd, "taskkill /f /t /im %s", bad_lists[i].c_str());
			system(cmd);
		}
	}
	return EXIT_SUCCESS;
}