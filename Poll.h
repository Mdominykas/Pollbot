#ifndef POLL_H_INCLUDED
#define POLL_H_INCLUDED

#include <bits/stdc++.h>

enum actionsToDoEnum
{
	CREATE,
	VOTE,
	CHANGE_USER,
	SEE_RESULTS,
	QUIT
};

enum addMoreOptionsEnum
{
	MORE,
	ENOUGH
};

class Poll
{
private:
	class impl;
	std::unique_ptr<impl> pImpl;
public:
	Poll(const std::string &name);
	Poll(const Poll &other);
	~Poll();
	Poll& operator=(Poll rhs);
	std::string getName() const;
	bool haveVoted(const std::string &name) const;
	bool addOption(const std::string &option);
	std::vector<std::string> getVoters() const;
	std::vector<std::string> getOptions() const;
	bool vote(const std::string &userName, int optionId);
	void printOptions(std::ostream &outputStream) const;
	void printResults(std::ostream &outputStream) const;
	static Poll createPoll(std::istream &inputStream, std::ostream &outputStream);
};

#endif