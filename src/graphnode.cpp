#include "graphnode.h"

#include "graphedge.h"

using namespace std;

GraphNode::GraphNode(int id) { _id = id; }

GraphNode::~GraphNode() {
    //// STUDENT CODE
    ////

    // !Task 0: this delete statement will cause double delete
    // !Task 0: which leads to the segmentation error
    // delete _chatBot;

    ////
    //// EOF STUDENT CODE
}

void GraphNode::AddToken(std::string token) { _answers.push_back(token); }

void GraphNode::AddEdgeToParentNode(GraphEdge *edge) { _parentEdges.push_back(edge); }

void GraphNode::AddEdgeToChildNode(unique_ptr<GraphEdge> &&edge) {
    // !Task 4: passing children edges using move semanics and rvalues
    _childEdges.push_back(move(edge));
}

//// STUDENT CODE
////
void GraphNode::MoveChatbotHere(ChatBot &&chatbot) {
    // !Task 5: move around chatbot using move semantics and rvalues
    _chatBot = move(chatbot);
    _chatBot.SetCurrentNode(this);
}

void GraphNode::MoveChatbotToNewNode(GraphNode *newNode) {
    newNode->MoveChatbotHere(move(_chatBot));
    // !Task 5: the std::move automatically invalidate the source pointer
    // _chatBot = nullptr;  // invalidate pointer at source
}
////
//// EOF STUDENT CODE

GraphEdge *GraphNode::GetChildEdgeAtIndex(int index) {
    //// STUDENT CODE
    ////

    // !Task 4: use .get() to return the raw pointer managed by unique smart pointer
    return _childEdges[index].get();

    ////
    //// EOF STUDENT CODE
}