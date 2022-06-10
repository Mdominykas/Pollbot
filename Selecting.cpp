#include <bits/stdc++.h>
#include "Selecting.h"
#include "Constants.h"
#include "Poll.h"

using namespace std;

possibleAction::possibleAction(const string &actionName, const string &phraseForSelecting)
{
	this->actionName = actionName;
	this->phraseForSelecting = phraseForSelecting;
}

namespace selection
{
	int selectAction(istream &inputStream, ostream &outputStream, const vector<possibleAction> &possibleActions)
	{
		for(auto posAction : possibleActions)
		{
			outputStream << "If you want to " + posAction.actionName << ", then enter: " << posAction.phraseForSelecting << "\n";
		}

		string input;
		getline(inputStream, input);
		for(int i = 0; i < possibleActions.size(); i++)
		{
			if(possibleActions[i].phraseForSelecting == input)
				return i;
		}
		return -1;
	}

	int selectPoll(istream &inputStream, ostream &outputStream, const vector<Poll> &polls)
	{
		outputStream << Constants::toSelectNumbered << endl;

		for(int i = 0; i < polls.size(); i++)
			outputStream << i << ". " << polls[i].getName() << "\n";

		string input;
		getline(inputStream, input);
		stringstream ss(input);
		int number;
		if((ss >> number) && (number < polls.size()))
		{
			return number;
		}
		return -1;
	}

	int selectNumberedAction(istream &inputStream, ostream &outputStream, const vector<string> &actions)
	{
		outputStream << Constants::toSelectNumbered << endl;
		for(int i = 0; i < actions.size(); i++)
			outputStream << i << ". " << actions[i] << "\n";

		string input;
		getline(inputStream, input);
		stringstream ss(input);
		int number;
		if((ss >> number) && (number < actions.size()))
		{
			return number;
		}
		return -1;
	}

}