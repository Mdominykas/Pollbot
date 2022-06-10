#include <bits/stdc++.h>
#include "Poll.h"
#include "NameEnterBot.h"
#include "Selecting.h"
#include "Constants.h"
using namespace std;

namespace greetings
{
	void greet(ostream &outputStream)
	{
		int greetingNum = rand() % Constants::greetings.size();
		outputStream << Constants::greetings[greetingNum] << "\n";
	}

	void greetWithName(ostream &outputStream, string name)
	{
		int greetNum = rand() % Constants::greetingsForName.size();
		outputStream << Constants::greetingsForName[greetNum] << " " << name<< "\n";
	}	
}

vector<possibleAction> actionsWhatToDo =
{
	possibleAction("Create poll", "create"),
	possibleAction("Vote", "vote"),
	possibleAction("Change user", "change"),
	possibleAction("See results", "results"),
	possibleAction("Quit", "quit")
};

void clearTerminal()
{
	std::cout << "\033[H\033[2J\033[3J";
}

int main()
{
	ifstream cin("input.txt");
	ofstream cout("output.txt");

	srand(time(NULL));
	greetings::greet(cout);
	NameEnterBot nameEnterBot = NameEnterBot();

	vector<Poll> polls;

	bool finished = false;
	while(!finished)
	{
		if(!Constants::loggedIn)
		{
			Constants::currentUser = nameEnterBot.getUserName(cin, cout);
			greetings::greetWithName(cout, Constants::currentUser);
			Constants::loggedIn = true;
		}

		int action = selection::selectAction(cin, cout, actionsWhatToDo);
		switch(action)
		{
			case CREATE:
			{
				polls.push_back(Poll::createPoll(cin, cout));
				if(polls.back().getOptions().size() == 0)
				{
					polls.pop_back();
					cout << Constants::pollNotCreated << endl;
				}
				else
					cout << Constants::pollCreated << endl;
				break;
			}
			case VOTE:
			{
				if(polls.size() != 0)
				{
					int pollNum = selection::selectPoll(cin, cout, polls);
					if(pollNum != -1)
					{
						int option = selection::selectNumberedAction(cin, cout, polls[pollNum].getOptions());
						if(option != -1)
							polls[pollNum].vote(Constants::currentUser, option);
					}
				}
				else
					cout << Constants::noPollCreated << endl;
				break;
			}
			case CHANGE_USER:
			{
				Constants::loggedIn = false;
				clearTerminal();
				cout << Constants::beingLoggedOut << endl;
				break;
			}
			case SEE_RESULTS:
			{
				if(polls.size() != 0)
				{
					int pollNum = selection::selectPoll(cin, cout, polls);
					if(pollNum != -1)
					{
						polls[pollNum].printResults(cout);
					}
				}
				else
					cout << Constants::noPollCreated << endl;
				break;
			}
			case QUIT:
			{
				cout << Constants::beingLoggedOut << endl;
				cout << Constants::goodbyeMessage << endl;
				finished = true;
				break;
			}
			default:
			{
				// clearTerminal();
				cout << Constants::errorBeingLoggedOut << endl;
				Constants::loggedIn = false;
				break;
			}
		}
	}

	return 0;
}
