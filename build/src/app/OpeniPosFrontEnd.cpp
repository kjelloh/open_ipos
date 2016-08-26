#include "OpeniPosFrontEnd.h"
#include <iostream>
#include <Windows.h>

OpeniPosFrontEnd::OpeniPosFrontEnd(const tris::backend::API_STRING& sExe) : tris::FrontEnd<tris::frontend::Console>(sExe) {}

bool OpeniPosFrontEnd::execute(const tris::backend::API_STRING& sCommandLine, bool& done) {
	bool result = true; // Default known command.
	if (sCommandLine == "LoadAPI") {
		const auto  szDllPath = R"(open_ipos_api.dll)";
		auto hDll = LoadLibrary(szDllPath);
		if (hDll == NULL) {
			std::cout << "\nFailed to Load API " << szDllPath;
		}
		else {
			std::cout << "\nLoaded API " << szDllPath;
		}
	}
	else {
		result = false; // command unknown (not implemented)
	}
	return result;
}

bool OpeniPosFrontEnd::help(const tris::backend::API_STRING& sCommandLine) {
	return tris::FrontEnd<tris::frontend::Console>::help(sCommandLine); // Invoke default help
}

