#pragma once
#include "tris/build/src/Core.h"
#include <memory>

class ZeposApiCore :
	public tris::Core
{
public:
	ZeposApiCore();
	~ZeposApiCore();


private:
	struct impl;
	std::unique_ptr<impl> m_pimpl;
};
