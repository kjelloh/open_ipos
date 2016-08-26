#pragma once
#include "tris/build/src/Core.h"
#include <memory>

class OpeniPosAPICore :
	public tris::Core
{
public:
	OpeniPosAPICore();
	~OpeniPosAPICore();


private:
	struct impl;
	std::unique_ptr<impl> m_pimpl;
};
