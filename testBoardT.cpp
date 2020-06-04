#include "catch.h"
#include "GameBoard.h"
#include <fstream>
#include <stdexcept>

TEST_CASE("tests for GameBoard", "[GameBoard]"){
	
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
		
		Board board1("test1.txt");
		Board board5("test5.txt");
	}
	
	SECTION("Constructor -Exception"){
        REQUIRE_THROWS_AS(new Board("test2.txt"), std::out_of_range);
        REQUIRE_THROWS_AS(new Board("test3.txt"), std::invalid_argument);
        REQUIRE_THROWS_AS(new Board("test4.txt"), std::invalid_argument);
    }
	
	SECTION("test countPop"){
		board1.countPop(2,2) = 3;
		board1.countPop(2,4) = 4;
		board1.countPop(4,4) = 1;
		board1.countPop(0,0) = 0;
		board1.countPop(5,0) = 1;
		board1.countPop(5,5) = 2;
		board1.countPop(0,5) = 1;
		
		board5.countPop(6,7) = 3;
		board5.countPop(2,3) = 6;
		board5.countPop(1,8) = 1;
		board5.countPop(9,9) = 2;
		board5.countPop(0,0) = 1;
		board5.countPop(0,9) = 0;
		board5.countPop(9,0) = 2;
	}
	
}