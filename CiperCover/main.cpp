#include <iostream>
#include <string>
#include "CDataSimple.h"
#include "CWorkspace.h"
#include "CDialogManager.h"
#include "CLink.h"

using namespace std;

void initSequence(CWorkspace& ws) {
	int nDepth = 0;
	int nMaxLength = 0;
	
	cout << "Last number" << endl;
	cin >> nDepth;
	cout << "Input Lenght" << endl;
	cin >> nMaxLength;

	ws.Init(nDepth, nMaxLength);
}

void showFullSequence(CWorkspace& ws) {
	cout << ws.GetChainString() << endl;
}

void saveSequence(CWorkspace& ws) {
	string path;
	cout << "Write where to save, or Enter * to use default path (save.bin)" << endl;
	cin >> path;
	if (path.length() == 1 && path[0] == '*') {
		path = "save.bin";
	}
	ws.Save(path);
}

void loadSequence(CWorkspace& ws) {
	string path;
	cout << "Write path to file, or Enter * to use default path (save.bin)" << endl;
	cin >> path;
	if (path.length() == 1 && path[0] == '*') {
		path = "save.bin";
	}
	ws.Load(path);
}

void findSubstring(CWorkspace& ws) {
	
CLink* link = new CLink(ws.getRefChain());
	
	string str;
	cout << "Write string to find " << endl; 
	cin >> str;

	if (link->Attach(str.c_str())) {
		string out_str(ws.GetChainString());
		out_str.insert(link->startPos(), " (");
		out_str.insert(link->startPos() + link->size() + 2, ") ");
		cout << endl;
		cout << "Substring \"" <<  str << "\" finded." << endl;
		cout << out_str << endl;
		cout << "Do you want to save it y/n" << endl;

		char choise;
		cin >> choise;
		if (tolower(choise) == 'y') {
			ws.AddLink(link->startPos(), link->size(), link);

			string path;
			cout << "Vrite path to file, or Enter * to use default path (save.bin)" << endl;
			cin >> path;
			if (path.length() == 1 && path[0] == '*') {
				path = "save.bin";
			} else {
				ws.Save(path);
			}
		} 
	} else {
		cout << "No matches found" << endl;
	}
}

void showAllLinks(CWorkspace& ws) {
	string ChainString(ws.GetChainString());
	LinksArray aLinks;
	ws.GetAllLinks(aLinks);

	cout << endl;
	cout << "Links count: " << aLinks.size() << endl;

	for (int i = 0; i < aLinks.size(); i++) {
		cout << i + 1 << " ";
		cout << '"' << ChainString.substr(aLinks[i]->startPos(), aLinks[i]->size()) << '"' << endl;
	}

	cout << endl;

}

int main (int argc, char* argv[]) {
	CDataSimple data;
	CWorkspace ws(data);
	CDialogManager mgr(ws);
	mgr.RegisterCommand("Init sequence", initSequence);
	mgr.RegisterCommand("Show sequence", showFullSequence);
	mgr.RegisterCommand("Save", saveSequence);
	mgr.RegisterCommand("Load", loadSequence);
	mgr.RegisterCommand("Find substring", findSubstring);
	mgr.RegisterCommand("Show all links", showAllLinks);
	mgr.Run();

	return 0;
}
