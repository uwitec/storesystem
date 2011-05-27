#include "StdAfx.h"
#include "Logic.h"

Logic::Logic(void)
{
	m_sqlCmd.setLogic(this);
}

Logic::~Logic(void)
{
}

void Logic::executeCmd(const char* cmd)
{
	m_net.send(cmd);
}