#ifndef GRAPHNODE_H_
#define GRAPHNODE_H_

#include <memory>
#include <string>
#include <vector>

#include "chatbot.h"

using namespace std;

// forward declarations
class GraphEdge;

class GraphNode {
   private:
    //// STUDENT CODE
    ////

    // !Task 4: make outgoing edge exclusively owned by the class using unique smart pointer
    // data handles (owned)
    vector<unique_ptr<GraphEdge>> _childEdges;  // edges to subsequent nodes

    // !Task 4: incoming edge is not owned, thus stays unchanged
    // data handles (not owned)
    vector<GraphEdge *> _parentEdges;  // edges to preceding nodes
    ChatBot _chatBot;

    ////
    //// EOF STUDENT CODE

    // proprietary members
    int _id;
    vector<string> _answers;

   public:
    // constructor / destructor
    GraphNode(int id);
    ~GraphNode();

    // getter / setter
    int GetID() { return _id; }
    int GetNumberOfChildEdges() { return _childEdges.size(); }
    GraphEdge *GetChildEdgeAtIndex(int index);
    vector<string> GetAnswers() { return _answers; }
    int GetNumberOfParents() { return _parentEdges.size(); }

    // proprietary functions
    void AddToken(string token);  // add answers to list
    void AddEdgeToParentNode(GraphEdge *edge);
    // !Task 4: passing children edges using move semanics and rvalues
    void AddEdgeToChildNode(unique_ptr<GraphEdge> &&edge);

    //// STUDENT CODE
    ////

    void MoveChatbotHere(ChatBot &&chatbot);

    ////
    //// EOF STUDENT CODE

    void MoveChatbotToNewNode(GraphNode *newNode);
};

#endif /* GRAPHNODE_H_ */