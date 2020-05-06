#include "team.hpp"
#ifndef TEAMLIST_H
#define TEAMLIST_H

class teamList {
public:
	// fields
	team * p_head;

	// methods
	teamList();
	void pushEnd(team * newTeam);
	team  getTeamById(int id);
	void deleteTeamById(int id);
	void printTeams();
};

teamList::teamList(){
	p_head = nullptr;
}

void teamList::pushEnd(team *newTeam){
	if(p_head == nullptr){
		p_head = newTeam;
	}
	else{
		team * p_iterate{p_head};
		while(p_iterate->getNextTeam() != nullptr){
			p_iterate = p_iterate->getNextTeam();
		}
		// sets newTeam to the end of the list.
		p_iterate->setNextTeam(newTeam);
	}
}

void teamList::printTeams(){
	team * p_iterate{p_head};
	std::cout << "Current Teams: " <<std::endl;
	while(p_iterate != nullptr){
		std::cout <<  p_iterate->getTeamName();
		std::cout << p_iterate->getTeamId();
		p_iterate = p_iterate->getNextTeam();
	}
}

team teamList::getTeamById(int id){
	team * p_iterate{p_head};
	while(p_iterate->getTeamId() != id){
		p_iterate = p_iterate->getNextTeam();
	}
	return *p_iterate;
}

#endif
