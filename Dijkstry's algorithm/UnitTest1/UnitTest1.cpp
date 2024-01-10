#include "pch.h"
#include "CppUnitTest.h"
#include "../Dijkstry's algorithm/Source.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(TestAlgorithm)
	{
	public:

        TEST_METHOD(TestDistance)
        {
            Dijkstra djsk;

            Node* a = new Node('a');
            Node* b = new Node('b');
            Node* c = new Node('c');
            Node* d = new Node('d');

            Edge* e1 = new Edge(a, c, 1);
            Edge* e2 = new Edge(a, d, 2);
            Edge* e3 = new Edge(b, c, 2);
            Edge* e4 = new Edge(c, d, 1);
            Assert::AreEqual(djsk.Distance(a, d), 2);
            Assert::AreEqual(djsk.Distance(a, c), 1);
            Assert::AreEqual(djsk.Distance(c, d), 1);
            Assert::AreEqual(djsk.Distance(b, c), 2);
        }

        TEST_METHOD(TestConnects)
        {
            Node* a = new Node('a');
            Node* b = new Node('b');
            Node* c = new Node('c');
            Node* d = new Node('d');

            Edge* e1 = new Edge(a, c, 1);
            Edge* e2 = new Edge(a, d, 2);
            Edge* e3 = new Edge(b, c, 2);
            Edge* e4 = new Edge(c, d, 1);
            
            Assert::IsTrue(e1->Connects(a, c) == true);
            Assert::IsTrue(e2->Connects(a, d) == true);
            Assert::IsTrue(e1->Connects(b, c) == false);
        }

        TEST_METHOD(TestRemoveEdge)
        {
            Dijkstra djsk;

            Node* a = new Node('a');
            Node* b = new Node('b');
            Node* c = new Node('c');
            Node* d = new Node('d');

            Edge* e1 = new Edge(a, c, 1);
            Edge* e2 = new Edge(a, d, 2);
            Edge* e3 = new Edge(b, c, 2);
            Edge* e4 = new Edge(c, d, 1);

            vector<Edge*> edges;
            edges.push_back(e1);
            edges.push_back(e2);
            edges.push_back(e3);
            edges.push_back(e4);

            Assert::IsTrue(edges.size() == 4);
            djsk.RemoveEdge(edges, e2);
            Assert::IsTrue(edges.size() == 3);
        }

        TEST_METHOD(TestDijkstrasAndShortestRoute)
        {
            Dijkstra djsk;

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

            a->distanceFromStart = 0;  
            djsk.Dijkstras();
            
            Assert::IsTrue(djsk.ShortestRouteTo(d) == 2);
            Assert::IsTrue(djsk.ShortestRouteTo(c) == 1);
            Assert::IsTrue(djsk.ShortestRouteTo(e) == 4);
        }
	};
}
