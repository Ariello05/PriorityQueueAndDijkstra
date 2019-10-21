#include <iostream>
#include "stdafx.h"
#include "UniqueVector.h"
#include "DFA.h"
#include "AutomatonMatcher.h"
#include "TransitionCreator.h"

using std::string;
using std::wstring;
using std::u32string;
using std::cout;
using std::wcout;

/*
class InputAutomator {
public:
	InputAutomator():end('q'){}

	void runLoop() {
		char c;
		std::cin >> c;
		while (c != end) {
			std::cin >> c;
		}
	}

private:
	const char end;
};
*/

int wmain()
{
	SetConsoleOutputCP(CP_UTF8);
	SetConsoleCP(CP_UTF8);

	try {
		shared_ptr<DFA> d = std::make_shared<DFA>();
		d->printRoutes();
		TransitionCreator tc;
		tc.computeTransition(*d, "abab", "abcd");

		AutomatonMatcher am(d);
		am.setPattern("ababcbababababc");
		am.runMatcher();
	}
	catch (std::exception e) {
		cout << e.what();
	}
}

