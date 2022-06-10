#ifndef CONSTANTS_H_INCLUDED
#define CONSTANTS_H_INCLUDED

#include <string>
#include <vector>

#include "Selecting.h"

using namespace std;

class Constants
{
public:
	static vector<string> greetings;
	static vector<string> greetingsForName;
	static string currentUser;
	static bool loggedIn;
	static string pollCreated;
	static string beingLoggedOut;
	static string errorBeingLoggedOut;
	static string goodbyeMessage;
	static vector<possibleAction> pollOptions;
	static string enterPollName;
	static string enterPollOption;
	static string currentOptions;
	static string pollNotCreated;
	static string noPollCreated;
	static string toSelectNumbered;
	static int implCounter;
};


#endif