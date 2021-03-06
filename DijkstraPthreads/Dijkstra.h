#ifndef DIJKSTRA_H
#define DIJKSTRA_H

/* Standard library imports */
#include <float.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

/*Unix specific imports*/
#include <unistd.h>
#include <pthread.h>

/* Local application / library specific imports */
#include "ProjectDefinitions.h"
#include "thpool.h"
#include "Node.h"

/*Config application specific macros*/
#define INF_DIST (10000000)                 // Initial infinite distance between two nodes
#define THREADS_PER_BLOCK (128)				// Number of threads assigned per block
#define MAX_BUF (200)						// Maximum size of path string
#define SOURCE_VERTEX (0)					// Source vertex
#define THREAD_POOL_SIZE  (8192)

typedef struct graphInfo {
    Node* graph;
    int* shortestDistances;
    int* updateShortestDistances;
    int* processedVertices;
    int* numVertices;
    int threadId;
    pthread_mutex_t* mutex_lock;
} GraphInfo_t;


/*Input and output path variables*/
EXTERN char parrentDirectoryPath[MAX_BUF];
EXTERN char inputTestsPath[MAX_BUF];
EXTERN char outputTestsPath[MAX_BUF];

/*Input and output specific functions*/
EXTERN FUNC(void, HOST) getParentDirectoryPath();
EXTERN FUNC(P2VAR(Node, HOST), HOST) readInputData(P2VAR(int, HOST) numVertices, P2VAR(int, HOST) numEdges);
EXTERN FUNC(void, HOST) printCollectedData(P2CONST(int, HOST) shortestDistances, P2CONST(int, HOST) numVertices, CONSTVAR(float, HOST) elapsedTimeMs, CONSTVAR(int, HOST) testCaseNumber);


/*Util functions*/
EXTERN FUNC(void, HOST) initArray(P2VAR(int, HOST) arrayData, P2CONST(int, HOST) size, CONSTVAR(int, HOST) initValue);

// /*Processing functions*/
EXTERN void* processEdges(P2VAR(void, HOST) args);
EXTERN FUNC(int, HOST) allVerticesProcessed(P2CONST(int, HOST) processedVertices, P2CONST(int, HOST) numVertices);
EXTERN FUNC(void, HOST) Dijkstra(P2VAR(Node, HOST) graph, P2VAR(int, HOST) shortestDistances, P2VAR(int, HOST) updateShortestDistances, P2VAR(int, HOST) processedVertices, P2VAR(int, HOST) numVertices, CONSTVAR(int, HOST) testCaseNumber);

// /*Start tests suite function*/
EXTERN FUNC(void, HOST) startTests();

#endif // !DIJKSTRA_H
