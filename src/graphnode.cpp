#include "graphedge.h"
#include "graphnode.h"
#include <memory>

GraphNode::GraphNode(int id)
{
    _id = id;
}

GraphNode::~GraphNode()
{
    //// STUDENT CODE: This bug was deallocating memory that is deleted elsewhere. Task 0.
    ////
    // delete _chatbot;
    ////
    //// EOF STUDENT CODE
}

void GraphNode::AddToken(std::string token)
{
    _answers.push_back(token);
}

void GraphNode::AddEdgeToParentNode(GraphEdge *edge)
{
    _parentEdges.push_back(edge);
}

void GraphNode::AddEdgeToChildNode(std::unique_ptr<GraphEdge> edge) // Modified this function to accomodate the smart pointer and move operation. Task 4.
{
    _childEdges.push_back(std::move(edge)); // Move unique_ptr for new edge into the vector of unique_ptrs defined by _childEdges. Task 4.
}

//// STUDENT CODE
////
void GraphNode::MoveChatbotHere(ChatBot chatbot)
{
    _chatBot = std::move(chatbot); // Move the chatbot. Task 5
    _chatBot.SetCurrentNode(this);
}

void GraphNode::MoveChatbotToNewNode(GraphNode *newNode)
{
    newNode->MoveChatbotHere(std::move(_chatBot)); // Move chatbot to newNode. Task 5
   // _chatBot = nullptr; // invalidate pointer at source // Not needed Task 5
}
////
//// EOF STUDENT CODE

GraphEdge *GraphNode::GetChildEdgeAtIndex(int index)
{
    //// STUDENT CODE
    ////

    return (_childEdges[index]).get(); // Modified for smart pointer

    ////
    //// EOF STUDENT CODE
}