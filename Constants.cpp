#include<bits/stdc++.h>
#include "Constants.h"


vector<string> Constants::greetings = {
	"Hello, fellow poll enthusiast",
	"Greetings, my dear human",
	"Welcome to poll bot"
};

vector<string> Constants::greetingsForName = {
	"Hello, ",
	"Welcome, ",
	"Let's get started, "
};

string Constants::currentUser = "";

bool Constants::loggedIn = false;

string Constants::pollCreated = "Poll successfully created";
string Constants::beingLoggedOut = "You are being logged out";
string Constants::goodbyeMessage = "Thank you for your time, goodbye";
string Constants::errorBeingLoggedOut = "Can't understand what you want\nYou are being logged out";
string Constants::enterPollName = "Enter poll name";
string Constants::enterPollOption = "Enter your poll option";
string Constants::currentOptions = "Current options are";
string Constants::pollNotCreated = "Poll hasn't been created";
string Constants::noPollCreated = "There is no poll created";
string Constants::toSelectNumbered = "Enter number of option that you want to choose";
int Constants::implCounter = 0;

vector<possibleAction> Constants::pollOptions = 
{
	possibleAction("Add more options", "more"),
	possibleAction("Create poll", "enough")
};
