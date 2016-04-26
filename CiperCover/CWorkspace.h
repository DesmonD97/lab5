#ifndef _CWorkspace_
#define _CWorkspace_

#include "CDataChain.h"
#include <string>

class CWorkspace
{
public:
	CWorkspace(CDataChain& data);
	~CWorkspace(void);
	//�������� ����� ����������� ����
	void Init(int nDepth, int nLength);
	//������� ������ �� ������ ����������� ����.
	const char* GetChainString();
	// ������ � ���� sFileLepath ���� CWorkspace
	bool Save(std::string& sFilepath);
	// ³������� ���� Workspace �� ����� sFileLepath
	bool Load(std::string& sFilepath);
private:
	//������ �� ��������� (���������� �� CDataChain) �� �����������
	CDataChain& m_refChain;
};

#endif