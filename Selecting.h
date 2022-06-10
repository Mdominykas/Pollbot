#ifndef SELECTING_H_INCLUDED
#define SELECTING_H_INCLUDED

#include <bits/stdc++.h>
#include "Poll.h"

struct possibleAction
{
	std::string actionName;
	std::string phraseForSelecting;
	possibleAction(const std::string &actionName, const std::string &phraseForSelecting);
};

namespace selection
{
	int selectAction(std::istream &inputStream, std::ostream &outputStream, const std::vector<possibleAction> &possibleActions);

	int selectPoll(std::istream &inputStream, std::ostream &outputStream, const std::vector<Poll> &polls);

	int selectNumberedAction(std::istream &inputStream, std::ostream &outputStream, const std::vector<std::string> &actions);
}

#endif