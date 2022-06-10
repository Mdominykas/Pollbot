#include <bits/stdc++.h>
#include "NameEnterBot.h"
using namespace std;

void NameEnterBot::findGreeting()
{
	currentGreeting = 0;
	for(int i = 0; i < threshold.size(); i++)
	{
		currentGreeting = i;
		if(currentHappiness >= threshold[i])
			return;
	}
	currentGreeting = threshold.size();
}

bool NameEnterBot::isName(const string &s)
{
	bool allNotFirstLower = true;
	for(int i = 1; i < s.size(); i++)
		allNotFirstLower = allNotFirstLower && islower(s[i]);
	return !s.empty() && isupper(s[0]) && allNotFirstLower;
}

void NameEnterBot::setHappiness(int val)
{
	currentHappiness = val;
	findGreeting();
}

void NameEnterBot::increaseHappiness()
{
	setHappiness(currentHappiness + 1);
}

void NameEnterBot::decreaseHappiness()
{
	setHappiness(currentHappiness - 1);
}

void NameEnterBot::askForName(ostream &outputStream) const
{
	outputStream << commonComment << "\n";
	outputStream<< posNameEnterings[currentGreeting] << "\n";
}

pair<bool, std::string> NameEnterBot::tryReadingUsersName(istream &inputStream) const
{
	string input;
	getline(inputStream, input);
	stringstream ss(input);
	vector<string> names;
	string name;
	while(ss >> name)
	{
		if(isName(name))
			names.push_back(name);
		else
			return make_pair(false, "");
	}
	if(names.size() > 0)
	{
		string finalName = names[0];
		for(int i = 1; i < names.size(); i++)
			finalName = finalName + " " + names[i];
		return make_pair(true, finalName);
	}
	return make_pair(false, "");
}

string NameEnterBot::getUserName(istream &inputStream, ostream &outputStream)
{
	while(true)
	{
		askForName(outputStream);
		pair<bool, string> result = tryReadingUsersName(inputStream);
		if(result.first)
		{
			increaseHappiness();
			return result.second;
		}
		else
		{
			decreaseHappiness();
		}
	}
}
