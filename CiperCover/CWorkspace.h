#ifndef _CWorkspace_
#define _CWorkspace_

class CWorkspace
{
public:
	CWorkspace(CDataChain& data);
	~CWorkspace(void);
	//�������� ����� ����������� ����
	void Init(int nDepth, int nLength);
	//������� ������ �� ������ ����������� ����.
	const char* GetChainString();
private:
	//������ �� ��������� (���������� �� CDataChain) �� �����������
	CDataChain& m_refChain;};#endif