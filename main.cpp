#include <iostream>
#include <string>
#include "team.hpp"
#include "teamList.hpp"
#include "roundRobinAlgorithm.hpp"

int main();

int main(){
	int numTeams {};
	teamList mainList {};
	std::cout << "Number of teams: ";
	std::cin >> numTeams;

	while(numTeams <= 1){
		std::cout << "Please input a number greater than 1" << std::endl;
		std::cout << "Number of teams:";
		std::cin >> numTeams;
	}
	std::cin.ignore(1000,'\n');
	// ignores new line created by input
	std::cout << "===================" <<std::endl;

	for(int i{0}; i < numTeams; i++){
		std::string teamName {};
		std::cout << "Team " + std::to_string(i+1) <<std::endl;
		std::cout << "Enter Team name: ";
		std::getline(std::cin, teamName);
		// push team into list
		mainList.pushEnd(new team(teamName,i +1));
		std::cout << "===================" <<std::endl;
	}
	//mainList.printTeams();
	roundRobinAlgorithm(numTeams, numTeams % 2 == 0, mainList);
}
