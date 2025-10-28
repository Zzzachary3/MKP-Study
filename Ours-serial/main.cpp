// #include "Graph.h"
// #include "Utility.h"
// #include "Timer.h"
// #include "Command.h"
// using namespace std;
// #define LEN_LIMIT (1<<10)
// char filename[LEN_LIMIT];

// #define DENSE_SEARCH




#include "Graph.h"
#include "Utility.h"
#include "Timer.h"
#include "Command.h"
#include <string.h> // For strncpy
#include <stdio.h>  // For printf
#include <stdlib.h> // For atoi

using namespace std;

#define LEN_LIMIT (1 << 10)
char filename[LEN_LIMIT];
CommandLine cmd;

int main(int argc, char *argv[])
{
	cmd = CommandLine(argc, argv);

	bool dense_search = cmd.GetOptionValue("-dense", "false") == "true";
	bool verify = cmd.GetOptionValue("-verify", "false") == "true";

	printf("\n-----------------------------------------------------------------------------------------\n");
	strncpy(filename, argv[1], LEN_LIMIT);
	int k = atoi(argv[2]);
	Graph *graph = new Graph(filename, k);
	graph->twoHopG = cmd.GetOptionValue("-twoHopG", "true") == "true";
	graph->topCTCP = cmd.GetOptionValue("-topCTCP", "true") == "true";
	graph->read();

	if (verify)
	{
		graph->verify_kplex();
		return 0;
	}
	graph->search();
	if (dense_search)
		graph->search_dense();

	// delete graph; // there are some bugs in releasing memory
	printf("-----------------------------------------------------------------------------------------\n\n");
}
