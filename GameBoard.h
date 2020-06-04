/**
 * \file GameBoard.h
 * \author Senyuan Tan   tans19
 * \date 2019/04/03
 * \brief Define function inside of GameBoard
 */
 
#ifndef A4_GAME_BOARD_H_
#define A4_GAME_BOARD_H_

#include <string>

class BoardT{
	private:
		unsigned int width;
		unsigned int height;
		unsigned int size;
		bool cell1[90000];
		bool cell2[90000];
		unsigned int cellT(unsigned int x, unsigned int y);
	public:
		/**
		 *  \brief constuct a new BoardT
		 *  \details create a new instance of given some value
		 *  \param The file's name is taken into the board and create the game board.
		 */
		BoardT(std::string filename);
		
		/**
		 *  \brief constuct a function countPop()
		 *  \details create a function countPop to count the numbers of alive cells between certain cell's neighborhood.
		 *  \param unsigned int i and j. where i is the x index and j is the y index. And the global variable width is the width of the gameBoard.
		 */
		unsigned int countPop(unsigned int i, unsigned int j);
		
		/**
		 *  \brief constuct a function nextState()
		 *  \details create a function nextState to store the state of next move after one round.
		 *  \param unsigned int i and j, where i is the x index and j is the y index. And the global variable width is the width of the gameBoard.
		 */
		void nextState();
		
		/**
		 *  \brief constuct a function updateState()
		 *  \details create a function updateState to update state of the game board
		 *  \param no parameter
		 */
		void updateState();
		
		/**
		 *  \brief constuct a function updateFile()
		 *  \details create a function updateFile to update the information in the file.
		 *  \param Take in the string that is the filename for open and write to rewrite the file.
		 */
		void updateFile(std::string filename);
};

#endif