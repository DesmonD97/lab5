#ifndef _CWorkspace_
#define _CWorkspace_

#include "CDataChain.h"
#include "CLink.h"
#include <string>

class CWorkspace
{
public:
	CWorkspace(CDataChain& data);
	~CWorkspace(void);
	void Init(int nDepth, int nLength);
	const char* GetChainString();
	bool Save(std::string& sFilepath);
	bool Load(std::string& sFilepath);

//Work with Links
	 
	bool AddLink(int nStartPos, int nLength, CLink* pLink);
	bool RemoveLink(int nPosInList);
	bool GetAllLinks(LinksArray& aLinks);
	CDataChain& getRefChain();
private:
	LinksArray m_aLinks;
};

#endif
