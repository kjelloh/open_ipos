#pragma once
#include "tris/build/src/FrontEnd.h"

class OpeniPosFrontEnd :
	public tris::FrontEnd<tris::frontend::Console>
{
public:
	OpeniPosFrontEnd() = delete;
	~OpeniPosFrontEnd() = default;

	OpeniPosFrontEnd(const tris::backend::API_STRING& sExe);
	virtual bool execute(const tris::backend::API_STRING& sCommandLine, bool& done);
	virtual bool help(const tris::backend::API_STRING& sCommandLine);
};

