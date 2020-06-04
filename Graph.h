#ifndef A4_GRAPH_H_
#define A4_GRAPH_H_

#include <string>

class Graph{
	private:
		unsigned int width;
		unsigned int height;
		unsigned int size;
		bool cells1[90000];
		unsigned int cellT(unsigned i, unsigned j);
	
	public:
		Graph(std::string filename);
		int graphOut();
};

#endif