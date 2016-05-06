//#ifndef _CDataChain_
//#define _CDataChain_
#pragma once

#include <string>

class CDataChain
{
public:
	CDataChain(void);
	virtual ~CDataChain(void);
	virtual void Generate(int nDepth, int nMaxLength = 0) = 0;
	size_t GetLength();
	int Find(const char* sSubStr, int nPos = 0);
	std::string GetSubStr(int nPos, int nLength = -1);
	const char* GetFullString();
	std::string setString(std::string& str);
protected:
	std::string m_sChain;
};
