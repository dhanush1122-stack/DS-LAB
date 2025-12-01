#include <stdio.h>
#include <stdlib.h>

// Graph using adjacency list
struct Node { int vertex; struct Node* next; };
struct Graph {
    int numVertices;
    struct Node** adjLists;
    int* visited;
};

struct Node* createNode(int v){
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->vertex=v; node->next=NULL;
    return node;
}

struct Graph* createGraph(int vertices){
    struct Graph* g = (struct Graph*)malloc(sizeof(struct Graph));
    g->numVertices = vertices;
    g->adjLists = (struct Node**)malloc(vertices*sizeof(struct Node*));
    g->visited = (int*)malloc(vertices*sizeof(int));
    for(int i=0;i<vertices;i++){ g->adjLists[i]=NULL; g->visited[i]=0;}
    return g;
}

void addEdge(struct Graph* g,int src,int dest){
    struct Node* node = createNode(dest);
    node->next=g->adjLists[src]; g->adjLists[src]=node;
    node = createNode(src);
    node->next=g->adjLists[dest]; g->adjLists[dest]=node;
}

void resetVisited(struct Graph* g){
    for(int i=0;i<g->numVertices;i++) g->visited[i]=0;
}

void DFSUtil(struct Graph* g,int v){
    g->visited[v]=1;
    printf("%d ",v);
    struct Node* temp=g->adjLists[v];
    while(temp){
        if(!g->visited[temp->vertex]) DFSUtil(g,temp->vertex);
        temp=temp->next;
    }
}

void DFS(struct Graph* g,int start){
    printf("DFS: ");
    DFSUtil(g,start);
    printf("\n");
}

void displayGraph(struct Graph* g){
    for(int i=0;i<g->numVertices;i++){
        printf("%d: ",i);
        struct Node* temp = g->adjLists[i];
        while(temp){ printf("%d -> ",temp->vertex); temp=temp->next;}
        printf("NULL\n");
    }
}

// Main menu
int main(){
    int vertices, choice, src, dest, start;
    printf("Enter number of vertices: "); scanf("%d",&vertices);
    struct Graph* g = createGraph(vertices);

    while(1){
        printf("\n--- DFS MENU ---\n1.Add Edge\n2.Display Graph\n3.DFS\n4.Exit\nEnter choice: ");
        scanf("%d",&choice);
        switch(choice){
            case 1:
                printf("Enter source and destination: "); scanf("%d %d",&src,&dest);
                addEdge(g,src,dest);
                break;
            case 2:
                displayGraph(g);
                break;
            case 3:
                printf("Enter starting vertex: "); scanf("%d",&start);
                resetVisited(g);
                DFS(g,start);
                break;
            case 4: exit(0);
            default: printf("Invalid choice!\n");
        }
    }
}

