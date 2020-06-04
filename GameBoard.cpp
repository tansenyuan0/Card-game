/**
 * \file GameBoard.cpp
 * \author Senyuan Tan   tans19
 * \date 2019/03/25
 * \brief The detail code of te function
 */
//implement here
#include "GameBoard.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>


#define MAX_WIDTH 300
#define MAX_HEIGHT 300

/*
define global variable
*/
unsigned int width;
unsigned int height;
unsigned int size;
bool cells1[90000];
bool cells2[90000];


BoardT::BoardT(std::string filename){
	std::ifstream myfile;
	unsigned int index;
	unsigned int x;
	unsigned int y;
	unsigned int cell;
	myfile.open(filename);
	if(!myfile.is_open()){
		throw std::invalid_argument("");
	}
	
/*
get the board size of the game.
*/
	if(myfile >> x >> y){
		if(x > MAX_WIDTH){
			throw std::out_of_range("");
		}
		else if(y > MAX_HEIGHT){
			throw std::out_of_range("");
		}
		else{
			width = x;
			height = y;
			size = x * y;
		}
	}
	
/*
get the state of every cell
*/
	index = 0;
	while(myfile >> cell){
		if(index == size){
			throw std::invalid_argument("");
		}
		if(cell == 0){
			cells1[index] = false;
		}
		else if(cell == 1){
			cells1[index] = true;
		}
		else{
			throw std::invalid_argument("");
		}
		++index;
	}
	
	myfile.close();
}
	



unsigned int BoardT::cellT(unsigned int x, unsigned int y){
		return width * y + x;
}

unsigned int BoardT::countPop(unsigned int i, unsigned int j){
	//count the numbers of alive cells of a cell's neighborhood
	
	unsigned int count = 0;
	if(i > width){
		throw std::invalid_argument("");
	}
	if(j > height){
		throw std::invalid_argument("");
	}
	if(cells1[cellT(i-1,j-1)] == true){
		count += 1;
	}
	if(cells1[cellT(i, j-1)] == true){
		count += 1;
	}
	if(cells1[cellT(i+1, j-1)] == true){
		count += 1;
	}
	if(cells1[cellT(i-1, j)] == true){
		count += 1;
	}
	if(cells1[cellT(i+1, j)] == true){
		count += 1;
	}
	if(cells1[cellT(i-1, j+1)] == true){
		count += 1;
	}
	if(cells1[cellT(i, j+1)] == true){
		count += 1;
	}
	if(cells1[cellT(i+1, j+1)] == true){
		count += 1;
	}
	return count;
}

void BoardT::nextState(){

	for(unsigned int i; i < width; i++){
		for(unsigned int j; j < height; j++){
			//Dead to alive cell
			if(cells1[cellT(i,j)] == false && countPop(i,j) == 3){
				cells2[cellT(i,j)] = true;
			}
			//alive to alive cell
			else if(cells1[cellT(i,j)] == true && (countPop(i,j) == 2 || countPop(i,j) == 3)){
				cells2[cellT(i,j)] = true;
			}
			//alive to dead cell - overpopulation
			else if(cells1[cellT(i,j)] == true && countPop(i,j) >= 4){
				cells2[cellT(i,j)] = false;
			}
			//alive to dead cell - solitude
			else if(cells1[cellT(i,j)] == true && countPop(i,j) < 2){
				cells2[cellT(i,j)] = false;
			}
			else{
				cells2[cellT(i,j)] = false;
			}
		}
	}
}

void BoardT::updateState(){
	//update the game info
	std::copy(cells2, cells2 + 90000, cells1);
}

void BoardT::updateFile(std::string filename){
	std::fstream myfile;
	myfile.open(filename);
	if(!myfile.is_open()){
		throw std::invalid_argument("");
	}
	myfile << width << height << "\n";
	for(unsigned int i = 0; i < size; ++i){
		if(cells1[i] == true){
			myfile << 1;
		}
		else if(cells1[i] == false){
			myfile << 0;
		}
		else{
			throw std::invalid_argument("");
		}
	}
	
	myfile.close();
}




