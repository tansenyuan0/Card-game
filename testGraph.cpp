/**
 * \file testGraph.cpp
 * \author Senyuan tan
 * \date 2019/04/13
 * \brief Unit testing for Graph
 */

#include "catch.h"
#include "Board.h"
#include "Graph.h"
#include <fstream>
#include <iostream>

TEST_CASE("tests for Graph", "[Graph]"){
	
	SECTION("test GameBoardT blank constructor"){
		
		std::ofstream file("test1.txt");
		file << 6 << " " << 6 << "\n";
		file << "1 0 1 0 0 1 0 0 1 0 0 1 0 0 0 0 0 0 1 1 1 0 0 0 0 0 1 0 1 0 0 1 1 0 1 0";
		file.close();
		
		file.open("test2.txt");
		file << 600 << " " << 600 << "\n";
		file.close();
		
		file.open("test3.txt");
		file << 4 << " " << 4 << "\n";
		file << "0 2 4 5 2 0 4 5 0 1 2 4 0 8 6 4";
		file.close();
		
		file.open("test4.txt");
		file << 4 << " " << 4 << "\n";
		file << "1 1 0 0 0 1 0 1 0 0 0 0 1 1 1 0 0 0 1 0 0 1 0 1";
		file.close();
		
		file.open("test5.txt");
		file << 10 << " " << 10 << "\n";
		file << "1 0 0 1 0 0 1 0 1 0 0 1 0 0 0 0 1 0 1 0 0 0 1 0 1 1 1 0 0 0 0 1 1 1 1 1 0 0 0 0 0 0 0 1 1 1 1 1 1 1 0 0 0 0 0 0 0 1 1 1 1 1 1 1 1 0 0 0 0 0 0 0 0 0 0 1 1 1 1 1 0 0 0 0 1 1 0 0 1 0 1 0 0 1 0 0 1 0 1 0";
		file.close();
		
		Graph graph1("test1.txt");
		Graph graph5("test5.txt");
	}
	
	SECTION("test to screen - 1st test"){
		graph1.graphOut();
		REQUIRE(true);
	}
	
	SECTION("test to screen - 2nd test"){
		graph5.graphOut();
		REQUIRE(true);
	}
	
}

