#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 5

struct Vertex {
    char label;
    bool visited;
};

//queue variables

int queue[MAX];
int rear = -1;
int front = 0;
int queueItemCount = 0;

//graph variables

//array of vertices
struct Vertex* lstVertices[MAX];

//adjacency matrix
int adjMatrix[MAX][MAX];

//vertex count
int vertexCount = 0;

//queue functions

void insert(int data) {
    queue[++rear] = data;
    queueItemCount++;
}

int removeData() {
    queueItemCount--;
    return queue[front++];
}

bool isQueueEmpty() {
    return queueItemCount == 0;
}

//graph functions

//add vertex to the vertex list
void addVertex(char label) {
    struct Vertex* vertex = (struct Vertex*) malloc(sizeof(struct Vertex));
    vertex->label = label;
    vertex->visited = false;
    lstVertices[vertexCount++] = vertex;
}

//add edge to edge array
void addEdge(int start,int end) {
    adjMatrix[start][end] = 1;
    adjMatrix[end][start] = 1;
}


void displayVertex(int vertexIndex) {
    printf("%d ",lstVertices[vertexIndex]->label);
}


int getAdjUnvisitedVertex(int vertexIndex) {
    int i;

    for(i = 0; i<vertexCount; i++) {
        if(adjMatrix[vertexIndex][i] == 1 && lstVertices[i]->visited == false)
            return i;
    }

    return -1;
}

void breadthFirstSearch() {
    int i;

    //mark first node as visited
    lstVertices[0]->visited = true;

    //display the vertex
    displayVertex(0);

    //insert vertex index in queue
    insert(0);
    int unvisitedVertex;

    while(!isQueueEmpty()) {
        //get the unvisited vertex of vertex which is at front of the queue
        int tempVertex = removeData();

        //no adjacent vertex found
        while((unvisitedVertex = getAdjUnvisitedVertex(tempVertex)) != -1) {
            lstVertices[unvisitedVertex]->visited = true;
            displayVertex(unvisitedVertex);
            insert(unvisitedVertex);
        }

    }

    //queue is empty, search is complete, reset the visited flag
    for(i = 0;i<vertexCount;i++) {
        lstVertices[i]->visited = false;
    }
}

int main() {
    int i, j;

    for(i = 0; i<MAX; i++)  {
        for(j = 0; j<MAX; j++) // matrix to 0
            adjMatrix[i][j] = 0;
}
    int novert;
    printf("Enter the number of vertices:\n");
    scanf("%d",&novert);


    int ver;
    for(int s=0;s<novert;s++){
        printf("Enter the vertex\n");
        scanf("%d",&ver);
//        ver = (char)ver;
        addVertex(ver);
    }
    int src;
    int des;
    for(int t=0;t<novert+1;t++){
        printf("Enter the edge coordinated space seperated:\n");
        scanf("%d %d",&src,&des);
        addEdge(src,des);
    }

printf("\nBreadth First Search: ");

breadthFirstSearch();

printf("\n");
    for(i = 0; i<MAX; i++)  {
        for(j = 0; j<MAX; j++) // matrix to 0
            printf("%d %d ",adjMatrix[i][j],ver);
        printf("\n");
    }

return 0;
}