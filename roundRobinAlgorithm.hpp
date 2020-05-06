#include <iostream>
#include "team.hpp"
#include "teamList.hpp"
#include <string>

#ifndef ROUNDROBIN_H
#define ROUNDROBIN_H

// FUNCTION DEFINITIONS
void roundRobinAlgorithm(int numTeams, bool isEven, teamList teamDataList);
int * initializeNumArray(int numTeams,bool isEven);
void printRoundHeader(int roundNumber);
void printGameDivider(int gameNumber);
void printMatch(int head, int tail, int * numArray, teamList teamDataList);
void swapArray(int * numArray);

void roundRobinAlgorithm(int numTeams, bool isEven, teamList teamDataList){
	//int numGames = (numTeams*(numTeams-1))/2;
	std::cout << "START OF ROUND ROBIN" <<std::endl;
	int *numArray{initializeNumArray(numTeams, isEven)};
	if(isEven){
		for(int i{0}; i < numTeams -1; i++){ // n -1 rounds (if even)
			printRoundHeader(i +1);
			int head{0};
			int tail{numTeams - 1}; // end of numArray

			// assign matches for round
			while(head < (numTeams/2)){ // num Games/round
				printGameDivider(head +1);
				printMatch(head, tail, numArray, teamDataList);
				head++;
				tail--;
			}
			// even swap arrays
			for(int i{1}; i < numTeams; i++){
				if(numArray[i] != numTeams){
					numArray[i]+=1;
				}
				else{
					numArray[i] = 2;
				}
			}
		}
	}
	else{
		// odd
		for(int i{0};i <numTeams; i++){ // n rounds if odd
			printRoundHeader(i+1);
			int head{0};
			int tail{numTeams}; // end of numArray
			int gameNum{1};
			while(head <= (numTeams -1)/2){ // numGames/round
				if(!(numArray[head] == -1 || numArray[tail] == -1)){
					// run if fake character isn't present
					printGameDivider(gameNum);
					printMatch(head,tail,numArray,teamDataList);
					gameNum++;
				}
				head++;
				tail--;
			}

			// odd swap array
			for(int i{1}; i <= numTeams; i++){
				if(numArray[i] == -1){
					numArray[i] = 2;
				}
				else if(numArray[i] == numTeams){
					numArray[i] = -1;
				}
				else{
					numArray[i] += 1;
				}
			}
		}
	}
	// memory deallocation
	delete numArray;
	numArray = nullptr;
}

void printRoundHeader(int roundNumber){
	std::cout << "===================" << std::endl;
	std::cout << "Round " + std::to_string(roundNumber) <<std::endl;
}

void printGameDivider(int gameNumber){
	std::cout << "-------------------"  << std::endl;
	std::cout << "Game " + std::to_string(gameNumber) <<std::endl;
}


int * initializeNumArray(int numTeams,bool isEven){
	int arrayLength{numTeams};
	if(!isEven){
		arrayLength+=1;
	}
	int * p_array {new int[arrayLength]};
	for(int i{0}; i<arrayLength;i++){
		p_array[i] = i+1;
	}

	if(!isEven){
		p_array[arrayLength-1] = -1;
	}
	return p_array;
}

void printMatch(int head, int tail, int * numArray, teamList teamDataList){
	std::string output {};
	output+= teamDataList.getTeamById(numArray[head]).getTeamName();
	output+= "vs\n";
	output+= teamDataList.getTeamById(numArray[tail]).getTeamName();
	std::cout << output;
}

void swapArray(int * numArray){

}


#endif
