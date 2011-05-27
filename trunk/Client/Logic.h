#pragma once
#include "SqlCmd.h"
#include "ClientNet.h"
class Logic
{
public:
	Logic(void);
	virtual ~Logic(void);
	void executeCmd(const char* cmd);
	SqlCmd* getSqlCmd(){ return &m_sqlCmd; }
protected:
	SqlCmd m_sqlCmd;
	ClientNet m_net;
};
