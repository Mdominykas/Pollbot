#ifndef NAME_ENTER_BOT_H_INCLUDED
#define NAME_ENTER_BOT_H_INCLUDED

#include <bits/stdc++.h>

class NameEnterBot
{
private:
	int currentHappiness = 4;
	int currentGreeting = 0;
	std::vector<std::string> posNameEnterings = {
		"Please, enter your name",
		"Entering your name is neccessary to continue",
		"ENTER YOUR NAME (OR A FAKE ONE, I DON'T CARE)"
	};
	std::vector<int> threshold = {2, 0};
	std::string commonComment = "Your name(s) should be a alphabetic word "
						  		"with first letter capitalised";
	void increaseHappiness();
	void decreaseHappiness();
	void findGreeting();
public:
	static bool isName(const std::string &s);
	void setHappiness(int val);
	void askForName(std::ostream &outputStream) const;
	std::pair<bool, std::string> tryReadingUsersName(std::istream &inputStream) const;
	std::string getUserName(std::istream &inputStream, std::ostream &outputStream);
};

#endif