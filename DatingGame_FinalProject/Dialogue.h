#ifndef DIALOGUE_H_
#define DIALOGUE_H_

#include <string>
#include <vector>

//Class has all dialogue for all the game
class Dialogue
{
	std::vector<std::string> dialogues;
	std::vector<int> pageCode;
	std::vector<bool> girls;

	bool questAsked;
	int answer;
public:
	Dialogue();
	~Dialogue();

	std::vector<std::string> convo();
	std::vector<std::string> quest();

	int getPageCode(int num){ return pageCode[num];};
	bool getGirls(int num){ return girls[num]; };
	bool getQuestAsked(){ return questAsked; };
	int getAnswer(){ return answer; };
	void setAnswer(int newAnswer){ answer = newAnswer; };
};

#endif