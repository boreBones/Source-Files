#include "Dialogue.h"

Dialogue::Dialogue():
dialogues(), pageCode(), girls(),  questAsked(false), answer(0)
{
	for (unsigned i = 0; i < 5; i++)
		dialogues.push_back("");

	for (unsigned i = 0; i < 2 ; i++)
		pageCode.push_back(0);

	for (unsigned i = 0; i < 6; i++)
		girls.push_back(false);
}

Dialogue::~Dialogue()
{
}

//Displays Dialogue
std::vector<std::string> Dialogue::convo()
{
	for (unsigned i = 0; i < dialogues.size(); i++)
		dialogues[i] = "";

	for (unsigned i = 0; i < girls.size(); i++)
		girls[i] = false;

	pageCode[0]++;

	switch (pageCode[0]) {
	case 1:
		dialogues[1] = "Instructions:";
		dialogues[2] = "Key Press 1 or 2 to make a decision";
		break;
	case 2:
		dialogues[1] = "First, we'll introduce them.";
		dialogues[2] = "Then you'll make some decisions.";
		dialogues[3] = "Great girl, or demonous monster?";
		dialogues[4] = "Your choices affect the outcome.";
		break;
	case 3:
		dialogues[0] = "Checkout Girl 1!";
		dialogues[1] = "The Party Girl";
		dialogues[2] = "Chatting up a storm, loud & carefree.";
		dialogues[3] = "She seems nice...";
		dialogues[4] = "...but seems is a dangerous word...";
		girls[0] = true;
		break;
	case 4:
		dialogues[0] = "Checkout Girl 2!";
		dialogues[1] = "The Couger";
		dialogues[2] = "She is older but";
		dialogues[3] = "that just means she has more experience...";
		girls[1] = true;
		break;
	case 5:
		dialogues[0] = "Checkout Girl 3!";
		dialogues[1] = "The Mysterious Girl";
		dialogues[2] = "Oh she brought her friend, 2 for the price of 1!";
		dialogues[3] = "She is reserved, shy, being overshadowed by her";
		dialogues[4] = "obnoxious wingwoman";
		girls[2] = true;
		girls[3] = true;
		break;
	case 6:
		dialogues[0] = "Do you want to talk to girl one?";
		dialogues[3] = "Press 1: Yes, sure.";
		dialogues[4] = "Press 2: No, not feeling it.";
		pageCode[1] = 1;
		questAsked = true;
		girls[0] = true;
		break;
	case 7:
		//girl 1
		dialogues[1] = "You ask about her hobbies and interests.";
		dialogues[2] = "She says she plays volleyball, loves painting & Mexican food.";
		dialogues[3] = "Press 1: You thinks it's cute";
		dialogues[4] = "Press 2: Burrito breath, no thanks";
		pageCode[1] = 3;
		questAsked = true;
		girls[0] = true;
		break;
	case 8:
		dialogues[0] = "(You are showing off those moves)";
		dialogues[1] = "Suddenly, a drunken fool bumps your woman!";
		dialogues[2] = "Press 1: Fight for her honour.";
		dialogues[3] = "Press 2: Remain a coward.";
		pageCode[1] = 4;
		questAsked = true;
		girls[0] = true;
		break;

	case 9:
		dialogues[0] = "You get to your place";
		dialogues[1] = "But wait, something's not right";
		dialogues[2] = "Ruuuunnn, she's a monster";
		dialogues[3] = "You picked the wrong girl. Game Over!";
		dialogues[4] = "Press Space to Quit!";
		girls[4] = true;
		break;

	case 10:
		dialogues[1] = "DEAD";
		break;

	case 25:
		dialogues[0] = "Do you want to talk to Girl #2 or #3?";
		dialogues[2] = "Press 1: The Cougar. Roar.";
		dialogues[3] = "Press 2: The 2 for 1 Special";
		pageCode[1] = 2;
		questAsked = true;
		break;
	case 50:
		//Girl2
		dialogues[0] = "The Cougar continued.";
		dialogues[1] = "It's your turn to ask something.";
		dialogues[3] = "Press 1: Ask about her age.";
		dialogues[4] = "Press 2: Ask about work.";
		pageCode[1] = 5;
		girls[1] = true;
		questAsked = true;
		break;

	case 51:
		dialogues[0] = "Capture the Cougar.";
		dialogues[1] = "Press 1: Ask her over to your place.";
		dialogues[2] = "Press 2: Play it safe & ask her to dance.";
		pageCode[1] = 8;
		girls[1] = true;
		questAsked = true;
		break;

	case 52:
		dialogues[0] = "Some degenerate spills his drink on her!";
		dialogues[1] = "Press 1: The macho route - put your dukes up";
		dialogues[2] = "Press 2: Let it slide.";
		pageCode[1] = 9;
		girls[1] = true;
		questAsked = true;
		break;
	case 53:
		dialogues[0] = "*Insert Monster picture*";
		pageCode[0] = 9;
		break;

	case 100:
		dialogues[1] = "Girl #3: The Third Wheel.";
		dialogues[2] = "Press 1: Talk to the main chick.";
		dialogues[3] = "Press 2: Talk to her friend.";
		pageCode[1] = 6;
		questAsked = true;
		girls[2] = true;
		girls[3] = true;
		break;
	case 101:
		dialogues[0] = "Girl #3: Three's a Crowd";
		dialogues[1] = "Press 1: Whisk her away to the dance floor.";
		dialogues[2] = "Press 2: Dance with her friend.";
		pageCode[1] = 7;
		questAsked = true;
		girls[2] = true;
		girls[3] = true;
		break;
	case 102:
		dialogues[0] = "*Insert picture of monster*";
		break;

	case 103:
		//Say Yes to girl 3
		dialogues[0] = "After finishing dancing, you decide to order a drink for you two";
		dialogues[1] = "Her friend show up again,";
		dialogues[2] = "She starts attacking your girl";
		dialogues[3] = "She says that your girl ditched her and she wanted to dance with you";
		dialogues[4] = "Your girl doesn't like this at all and stays quiet";
		girls[2] = true;
		girls[3] = true;
		break;

	case 104:
		dialogues[0] = "What do you do?";
		dialogues[2] = "Press 1: Tell her friend to GTFO";
		dialogues[3] = "Press 2: This girl is boring, go for the friend";
		questAsked = true;
		girls[2] = true;
		girls[3] = true;
		pageCode[1] = 10;
		break;

	case 105:
		dialogues[0] = "A Bar Brawl starts, What do you do?";
		dialogues[2] = "Press 1: Try to stop the fight";
		dialogues[3] = "Press 2: Just avoid the fight";
		questAsked = true;
		girls[2] = true;
		pageCode[1] = 11;
		break;

	case 107:
		dialogues[1] = "You ask her for her phone number";
		dialogues[2] = "She agrees, and happily gives it to you";
		dialogues[3] = "Before she leaves she gives you a kiss";
		girls[2] = true;
		break;

	case 108:
		dialogues[1] = "Congraulations You have Won the Game!";
		dialogues[2] = "Press Space to Quit!";
		break;
	case 109:
		dialogues[1] = "Winner!";
	}

	return dialogues;
}

//Displays Questions
std::vector<std::string> Dialogue::quest()
{
	for (unsigned i = 0; i < dialogues.size(); i++)
		dialogues[i] = "";

	switch (pageCode[1]) {
	case 1:
		if (answer == 1)
		{
			dialogues[2] = "You chose girl one!";
			pageCode[0] = 6;
		}
		else if (answer == 2){
			dialogues[2] = "You chose to talk to another girl!";
			dialogues[3] = "Girl 2 and 3 are left.";
			pageCode[0] = 24;
		}
		break;
	case 2:
		if (answer == 1)
		{
			dialogues[1] = "You chose girl two!";
			dialogues[2] = "She tells you about her divorce, her stressful job in advertising,";
			dialogues[3] = " and her dreams of moving to Europe.";
			dialogues[4] = "You're wondering, how old is this chick?";
			pageCode[0] = 49;
		}
		else if (answer == 2){
			dialogues[2] = "You chose girl three!";
			dialogues[3] = "(and her friend)";
			pageCode[0] = 100;
		}
		break;

	case 3:
		if (answer == 1){
			dialogues[0] = "Things are going well with girl 1";
			dialogues[1] = "Your favourite song comes on.";
			dialogues[2] = "You ask her to dance.";
			pageCode[0] = 7;
		}
		else if (answer == 2){
			dialogues[2] = "Let's find someone better.";
			pageCode[0] = 24;
		}
		break;

	case 4:
		if (answer == 1){
			dialogues[2] = "A few broken ribs later,";
			dialogues[3] = "you win the fight and her affections.";
			dialogues[4] = "You ask her over to your place.";
			pageCode[0] = 8;

		}
		else if (answer == 2){
			dialogues[1] = "You spineless, nerd.";
			dialogues[2] = "As you scamper off, the drunk breaks a bottle over your head!";
			dialogues[3] = "You die. Game over";
			pageCode[0] = 9;
		}
		break;

	case 5:
		if (answer == 1){
			dialogues[2] = "Oh no! Bad Move";
			dialogues[3] = "*Three finger snap*, she's outta there real quick!";
			dialogues[4] = "Let's try your luck with Girl #3";
			pageCode[0] = 99;
		}
		else if (answer == 2){
			dialogues[2] = "She is pleased that you showed interest.";
			dialogues[3] = "She gently rests her arm on your shoulder...";
			dialogues[4] = "Where do we go from here?";
			pageCode[0] = 50;

		}
		break;
	case 6:
		if (answer == 1){
			dialogues[1] = "You chose the main chick.";
			dialogues[2] = "As you make small talk";
			dialogues[3] = "some sick beats come on the jukebox.";
			pageCode[0] = 100;

		}
		else if (answer == 2){
			dialogues[1] = "You chose to talk to her friend instead.";
			dialogues[2] = "Ouch. She seems cheesed";
			dialogues[3] = "She storms off & her friend chases after her.";
			dialogues[4] = "Game Over!! #99Problems";
			pageCode[0] = 9;
		}
		break;

	case 7:
		if (answer == 1){
			dialogues[1] = "You chose to dance. She is excited.";
			dialogues[2] = "You begin making small talk about the weather.";
			dialogues[3] = "You're getting bored.";
			girls[2] = true;
			girls[3] = false;
			pageCode[0] = 102;
		}
		else if (answer == 2){
			dialogues[1] = "The friend is impressed. You start dancing with her";
			dialogues[2] = "You lean in for a celebratory kiss...but wait...";
			dialogues[3] = "...her appearance is changing.";
			dialogues[4] = "No surprise here, the mysterious one is a monster!! GAME OVER!";
			girls[2] = false;
			girls[3] = false;
			girls[5] = true;
			pageCode[0] = 9;
		}
		break;

	case 8:
		if (answer == 1){
			dialogues[2] = "A bold move, indeed.";
			dialogues[3] = "But it pays off, you get back to your place";
			dialogues[4] = "But wait, something is off...MONSTERRRR";
			girls[4] = true;
			girls[1] = false;
			pageCode[0] = 9;

		}
		else if (answer == 2){
			dialogues[1] = "Let's boogie!";
			dialogues[2] = "Oh no, trouble in paradise...";
			pageCode[0] = 51;
		}
		break;

	case 9:
		if (answer == 1){
			dialogues[1] = "I guess you had 1 too many drinks.";
			dialogues[2] = "And can't seem to land a punch.";
			dialogues[3] = "Ka-pow, you're dead.";
			dialogues[4] = "Game Over.";
			pageCode[0] = 9;
		}
		else if (answer = 2){
			dialogues[1] = "The coward's way.";
			dialogues[2] = "She calls you a p_$$y and goes to talk your friend.";
			dialogues[4] = "You lose, game Over.";
			pageCode[0] = 9;
		}
		break;
	case 10:
		if (answer == 1){
			dialogues[1] = "Her friend tears up and leaves the bar";
			dialogues[2] = "The girl says thank you for standing up to her";
			pageCode[0] = 104;
		}
		else if (answer = 2){
			dialogues[1] = "You ditch the girl, the friend is impressed. You win.";
			dialogues[2] = "You lean in for a celebratory kiss...but wait...";
			dialogues[3] = "...her appearance is changing.";
			dialogues[4] = "No surprise here, the mysterious one is a monster!! GAME OVER!";
			girls[2] = false;
			girls[3] = false;
			girls[5] = true;
			pageCode[0] = 9;
		}
		break;
	case 11:
		if (answer == 1){
			dialogues[0] = "You try to stop the fight but that doesn't help";
			dialogues[1] = "You instead get punched in the face";
			dialogues[2] = "Your girl runs after you and tries to tend your wounds";
			dialogues[3] = "You instantly feel better and start talking to her";
			dialogues[4] = "Its getting late and she needs to go back home";
			pageCode[0] = 106;
		}
		else if (answer = 2){
			dialogues[1] = "You ignore the fight and instead talk to her";
			dialogues[2] = "You guys are sharing fun stories about each other";
			dialogues[3] = "Its getting late and she needs to go back home";
			pageCode[0] = 106;
		}
		break;
	}

	answer = 0;
	questAsked = false;
	return dialogues;
}