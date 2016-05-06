#ifndef _CDataSimple_
#define _CDataSimple_

#include "CDataChain.h"

class CDataSimple : public CDataChain
{
private:
	// Return long of numbers
	int _numberLength(int number);
	// 123 => ['1', '2', '3'];
	char* _intToChars(int number);
public:
	CDataSimple(void);
	~CDataSimple(void);
	//Generator of numbers
	void Generate(int nDepth, int nMaxLength = 0);
};

#endif
