#include <iostream>
#include <string>
#include <fstream>
#include <time.h>

#include "Base.h"
#include "Bot.h"
#include "Flag.h"
#include "TwoVector.h"

int main()
{
	using namespace std;

	srand(time(0));

	std::cout << "Hello Woooooorld\n";

	Bot* bottie = new Bot();
	Flag* flaggie = new Flag();
	Base* bassie = new Base();

	TwoVector vec1(0, 0);
	TwoVector vec2(10, 15);
	TwoVector vec3(20, 0);

	bottie->setPosition(vec1);
	flaggie->setPosition(vec2);
	bassie->setPosition(vec3);

	bottie->setFlag(flaggie);
	bottie->setBase(bassie);

	bottie->setTarget("flag");

	ofstream fout;
	fout.open("ctf.txt");


	cout << "Bot Position: x = " << bottie->getPosition().getX() << "\ty = " << bottie->getPosition().getY() << "\n";
	cout << "Bot Velocity: x = " << bottie->getVelocity().getX() << "\ty = " << bottie->getVelocity().getY() << "\n";
	cout << "Bot Target: x = " << bottie->getTarget().getX() << "\ty = " << bottie->getTarget().getY() << "\n";
	cout << "Bot Points: " << bottie->getPoints() << "\n";
	cout << "Flag Position: x = " << flaggie->getPosition().getX() << "\ty = " << flaggie->getPosition().getY() << "\n";
	cout << "Base Position: x = " << bassie->getPosition().getX() << "\ty = " << bassie->getPosition().getY() << "\n";
	cout << "\n";

	fout << "Bot Position: x = " << bottie->getPosition().getX() << "\ty = " << bottie->getPosition().getY() << "\n";
	fout << "Bot Velocity: x = " << bottie->getVelocity().getX() << "\ty = " << bottie->getVelocity().getY() << "\n";
	fout << "Bot Target: x = " << bottie->getTarget().getX() << "\ty = " << bottie->getTarget().getY() << "\n";
	fout << "Bot Points: " << bottie->getPoints() << "\n";
	fout << "Flag Position: x = " << flaggie->getPosition().getX() << "\ty = " << flaggie->getPosition().getY() << "\n";
	fout << "Base Position: x = " << bassie->getPosition().getX() << "\ty = " << bassie->getPosition().getY() << "\n";
	fout << "\n";

	while(bottie->getPoints() < 10)
	{
		bottie->update();
		cout << "Bot Position: x = " << bottie->getPosition().getX() << "\ty = " << bottie->getPosition().getY() << "\n";
		cout << "Bot Velocity: x = " << bottie->getVelocity().getX() << "\ty = " << bottie->getVelocity().getY() << "\n";
		cout << "Bot Target: x = " << bottie->getTarget().getX() << "\ty = " << bottie->getTarget().getY() << "\n";
		cout << "Bot Points: " << bottie->getPoints() << "\n";
		cout << "Flag Position: x = " << flaggie->getPosition().getX() << "\ty = " << flaggie->getPosition().getY() << "\n";
		cout << "Base Position: x = " << bassie->getPosition().getX() << "\ty = " << bassie->getPosition().getY() << "\n";
		cout << "\n";
		fout << "Bot Position: x = " << bottie->getPosition().getX() << "\ty = " << bottie->getPosition().getY() << "\n";
		fout << "Bot Velocity: x = " << bottie->getVelocity().getX() << "\ty = " << bottie->getVelocity().getY() << "\n";
		fout << "Bot Target: x = " << bottie->getTarget().getX() << "\ty = " << bottie->getTarget().getY() << "\n";
		fout << "Bot Points: " << bottie->getPoints() << "\n";
		fout << "Flag Position: x = " << flaggie->getPosition().getX() << "\ty = " << flaggie->getPosition().getY() << "\n";
		fout << "Base Position: x = " << bassie->getPosition().getX() << "\ty = " << bassie->getPosition().getY() << "\n";
		fout << "\n";
	}

	fout.close();

	return 0;
}
