#include <bits/stdc++.h>

#include "Poll.h"
#include "Selecting.h"
#include "Constants.h"

using namespace std;

class Poll::impl
{
public:
	std::string name;
	std::set<std::string> voters;
	std::vector<int> results;
	std::vector<std::string> options;
	impl(const std::string &name) : name(name) {}
	~impl() {}
};


Poll::Poll(const string &name) : pImpl(new impl(move(name)))
{
}

Poll::~Poll() = default;

Poll::Poll(const Poll& other)
    : pImpl(new impl(*other.pImpl))
{
}
 
Poll& Poll::operator=(Poll rhs)
{
    swap(pImpl, rhs.pImpl);
    return *this;
}

string Poll::getName() const
{
	return pImpl->name;
}

vector<string> Poll::getVoters() const
{
	vector<string> votersVector;
	for(auto voter : pImpl->voters)
		votersVector.push_back(voter);
	return votersVector;
}

vector<string> Poll::getOptions() const
{
	return pImpl->options;
}

bool Poll::haveVoted(const string &name) const
{
	return pImpl->voters.find(name) != pImpl->voters.end();
}

bool Poll::addOption(const string &option)
{
	for(string oldOp : pImpl->options)
	{
		if(oldOp == option)
			return false;
	}
	pImpl->options.push_back(option);
	pImpl->results.push_back(0);
	return true;
}

bool Poll::vote(const string &userName, int optionId)
{
	if(haveVoted(userName))
		return false;
	pImpl->results[optionId]++;
	pImpl->voters.insert(userName);
	return true;
}

void Poll::printOptions(ostream &outputStream) const
{
	for(int i = 0; i < pImpl->options.size(); i++)
		outputStream << i << ". " << pImpl->options[i] << "\n";
}

void Poll::printResults(ostream &outputStream) const
{
	outputStream << "poll \"" << pImpl->name << "\" results:\n";
	vector<pair<int, string> > sortedResults;
	for(int i = 0; i < pImpl->options.size(); i++)
		sortedResults.push_back({pImpl->results[i], pImpl->options[i]});
	sort(sortedResults.begin(), sortedResults.end(), greater<>());

	for(int i = 0; i < sortedResults.size(); i++)
	{
		outputStream << (i+1) << ": \"" << sortedResults[i].second << "\" with " << sortedResults[i].first << " votes\n";
	}
}

Poll Poll::createPoll(std::istream &inputStream, std::ostream &outputStream)
{
	outputStream << Constants::enterPollName << endl;
	string pollName;
	getline(inputStream, pollName);
	Poll poll(pollName);
	while(true)
	{
		int action = selection::selectAction(inputStream, outputStream, Constants::pollOptions);
		if(action == ENOUGH)
			break;
		else if(action == MORE)
		{
			outputStream << Constants::enterPollOption << endl;
			string optionName;
			getline(inputStream, optionName);
			poll.addOption(optionName);
			outputStream << Constants::currentOptions << endl;
			poll.printOptions(outputStream);
		}
		else
			outputStream << "Couldn't get what you were doing\n";
	}
	return poll;
}