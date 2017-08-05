#include <bits/stdc++.h>

using namespace std;

struct AdjListNode
{
    int dest;
    AdjListNode* next;
};

struct AdjList
{
    AdjListNode* head;
};

// Graph is visualized as an array of adjacency lists.
//Let size of graph be V.

struct Graph
{
    int v;
    AdjList *arr;
};

AdjListNode* newAdjListNode(int n)
{
    AdjListNode* newnode= new AdjListNode;
    newnode->dest=n;
    newnode->next=NULL;

    return newnode;
}

Graph* createGraph(int n)
{
    Graph* newGraph=new Graph;
    newGraph->v=n;
    newGraph->arr=new AdjList[n];

    for(int i=0; i<n; i++)
    {
        newGraph->arr[i].head=NULL;
    }

    return newGraph;
}

void addEdge(Graph* g, int src, int dest)
{
    AdjListNode* newNode=newAdjListNode(dest);
    newNode->next=g->arr[src].head;
    g->arr[src].head=newNode;

    newNode=newAdjListNode(src);
    newNode->next=g->arr[dest].head;
    g->arr[dest].head=newNode;
}

void printGraph(Graph* g)
{
    for(int k=0; k<g->v; k++)
    {
        AdjListNode* crawler=g->arr[k].head;

        cout << k << ": ";

        while(crawler)
        {
            cout << crawler->dest << " ";
            crawler=crawler->next;
        }
        cout << endl;
    }
}

int main()
{
    int v;
    cout << "Enter Graph vertices:" ;
    cin >> v;
    Graph* g=createGraph(v);

    char ans='y';
    while(ans=='y')
    {
        int src, dest;
        cout << "Enter source:"; cin >> src;
        cout << "Enter destination:"; cin >> dest;
        addEdge(g, src, dest);

        printGraph(g); cout << endl;

        cout<< "Add more edges:"; cin >> ans;
    }
    cout << "Final Graph:";
    printGraph(g);

    return 0;
}
