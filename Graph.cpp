/**
 * \file GameBoard.h
 * \author Senyuan Tan   tans19
 * \date 2019/03/25
 * \brief Detail code for cpp.
 */

//implement
//include

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include "Graph.h"

#define MAX_WIDTH 300
#define MAX_HEIGHT 300

unsigned int width;
unsigned int height;
unsigned int size;
bool cells1[90000];



Graph::Graph(std::string filename){
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
	
int graphOut(){
	for(unsigned int i = 0; i < size; ++i){
		if(i % width == 0){
			if(cells1[i] == false){
				std::cout << "+" << "\n";
			}
			else if(cells1[i] == true){
				std::cout << " "<< "\n";
			}
		}
		else{
			if(cells1[i] == false){
				std::cout << "[" << "+" << "]" << " ";
			}
			else if(cells1[i] == true){
				std::cout << "[" << " " << "]" << " ";
			}
		}
	}
	return 0;
}