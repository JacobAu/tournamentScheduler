#include <string>

#ifndef TEAM_H
#define TEAM_H


class team{
public:
	team(std::string teamName, int id);
	int getTeamId();
	std::string getTeamName();
	team * getNextTeam();
	void setNextTeam(team *p_new);
private:
	std::string teamName_;
	team * nextTeam_;
	int id_;
};

team::team(std::string teamName, int id){
	teamName_ = teamName;
	id_ = id;
	nextTeam_ = nullptr;
}

// get functions
int team::getTeamId(){return id_;};
std::string team::getTeamName(){return teamName_;}
team * team::getNextTeam(){return nextTeam_;}

void team::setNextTeam(team * p_new){
	nextTeam_ = p_new;
}


#endif
