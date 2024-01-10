#include <iostream>
#include <vector>

#define INT_MAX 10000000

using namespace std;

class Node;
class Edge;

vector<Node*> nodes;
vector<Edge*> edges;

struct Node
{
    char id;
    Node* previous;
    int distanceFromStart;

    Node(char id)
    {
        this->id = id;
        this->previous = nullptr;
        this->distanceFromStart = INT_MAX;
        nodes.push_back(this);
    }
};

struct Edge
{
    Node* node1;
    Node* node2;
    int distance;

    Edge(Node* node1, Node* node2, int distance)
    {
        this->node1 = node1;
        this->node2 = node2;
        this->distance = distance;
        edges.push_back(this);
    }
    bool Connects(Node* node1, Node* node2)
    {
        return ((node1 == this->node1 && node2 == this->node2) || (node1 == this->node2 && node2 == this->node1));
    }
};
struct Dijkstra
{
    // Знаходить вузол з найменшою дистанцією,
    // видаляє його, і повертає його.
    Node* ExtractSmallest(vector<Node*>& nodes)  
    {
        int size = nodes.size();
        if (size == 0)
        {
            return nullptr;
        }
        int smallestPosition = 0;
        Node* smallest = nodes.at(0);
        for (int i = 0; i < size; ++i)
        {
            Node* current = nodes.at(i);
            if (current->distanceFromStart < smallest->distanceFromStart)
            {
                smallest = current;
                smallestPosition = i;
            }
        }
        nodes.erase(nodes.begin() + smallestPosition);
        return smallest;
    }

    // Повертає вершини, суміжні з даною
    vector<Node*>* AdjacentRemainingNodes(Node* node)  
    {
        vector<Node*>* adjacentNodes = new vector<Node*>();
        const int size = edges.size();
        for (int i = 0; i < size; ++i)
        {
            Edge* edge = edges.at(i);
            Node* adjacent = nullptr;
            if (edge->node1 == node)
            {
                adjacent = edge->node2;
            }
            else if (edge->node2 == node)
            {
                adjacent = edge->node1;
            }
            if (adjacent && Contains(nodes, adjacent))
            {
                adjacentNodes->push_back(adjacent);
            }
        }
        return adjacentNodes;
    }

    vector<Edge*>* AdjacentEdges(vector<Edge*>& edges, Node* node)  //суміжні ребра
    {
        vector<Edge*>* adjacentEdges = new vector<Edge*>();

        const int size = edges.size();
        for (int i = 0; i < size; ++i)
        {
            Edge* edge = edges.at(i);
            if (edge->node1 == node)
            {
                adjacentEdges->push_back(edge);
            }
            else if (edge->node2 == node)
            {
                adjacentEdges->push_back(edge);
            }
        }
        return adjacentEdges;
    }

    // Повертає відстань між двома вершинами
    int Distance(Node* node1, Node* node2)
    {
        const int size = edges.size();
        int ret_value = -1;
        for (int i = 0; i < size; ++i)
        {
            Edge* edge = edges.at(i);
            if (edge->Connects(node1, node2))
            {
                ret_value = edge->distance;
            }
        }
        return ret_value;
    }

    bool Contains(vector<Node*>& nodes, Node* node)
    {
        const int size = nodes.size();
        bool ret_value = false;
        for (int i = 0; i < size; ++i)
        {
            if (node == nodes.at(i))
            {
                ret_value = true;
            }
        }
        return ret_value;
    }

    void RemoveEdge(vector<Edge*>& edges, Edge* edge)
    {
        vector<Edge*>::iterator it;
        for (it = edges.begin(); it != edges.end(); ++it)
        {
            if (*it == edge)
            {
                edges.erase(it);
                return;
            }
        }
    }

    void Dijkstras()
    {
        while (nodes.size() > 0)
        {
            Node* smallest = ExtractSmallest(nodes);
            vector<Node*>* adjacentNodes = AdjacentRemainingNodes(smallest);

            const int size = adjacentNodes->size();
            for (int i = 0; i < size; ++i)
            {
                Node* adjacent = adjacentNodes->at(i);
                int distance = Distance(smallest, adjacent) + smallest->distanceFromStart;

                if (distance < adjacent->distanceFromStart)
                {
                    adjacent->distanceFromStart = distance;
                    adjacent->previous = smallest;
                }
            }
            delete adjacentNodes;
        }
    }

    int ShortestRouteTo(Node* destination) 
    {
        Node* previous = destination;
        return previous->distanceFromStart;
    }

    void PrintShortestRouteTo(Node* destination)
    {
        Node* previous = destination;
        cout << "Distance from start: " << destination->distanceFromStart << endl;
        while (previous)
        {
            cout << previous->id << " ";
            previous = previous->previous;
        }
        cout << endl;
    }
};

void DijkstrasTest() 
{
    Node* a = new Node('a');
    Node* b = new Node('b');
    Node* c = new Node('c');
    Node* d = new Node('d');
    Node* e = new Node('e');
    Node* f = new Node('f');
    Node* g = new Node('g');

    Edge* e1 = new Edge(a, c, 1);
    Edge* e2 = new Edge(a, d, 2);
    Edge* e3 = new Edge(b, c, 2);
    Edge* e4 = new Edge(c, d, 1);
    Edge* e5 = new Edge(b, f, 3);
    Edge* e6 = new Edge(c, e, 3);
    Edge* e7 = new Edge(e, f, 2);
    Edge* e8 = new Edge(d, g, 1);
    Edge* e9 = new Edge(g, f, 1);

    Dijkstra djsk;

    a->distanceFromStart = 0;  
    djsk.Dijkstras();
    djsk.PrintShortestRouteTo(e);
}

int main() 
{
    DijkstrasTest();

    return 0;
}