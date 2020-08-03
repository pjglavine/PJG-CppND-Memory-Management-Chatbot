#ifndef GRAPHNODE_H_
#define GRAPHNODE_H_

#include <vector>
#include <string>
#include "chatbot.h"


// forward declarations
class GraphEdge;

class GraphNode
{
private:
    //// STUDENT CODE
    ////

    // data handles (owned)
    //std::vector<GraphEdge *> _childEdges;  // raw pointer for edges to subsequent nodes. Not used.
    std::vector<std::unique_ptr<GraphEdge>> _childEdges; // Create vector of unique_ptrs for storing the child edges. _edges ownership is moved from
    // ChatLogic to GraphNode via the AddEdgeToChildNode function which is rewritten to move unique_ptrs. Task 4.
    
    // data handles (not owned)
    std::vector<GraphEdge *> _parentEdges; // edges to preceding nodes 
    ChatBot _chatBot; // Create chatbot object, changed from pointer to simplify std::move() in MoveChatBotHere function Task 5

    ////
    //// EOF STUDENT CODE

    // proprietary members
    int _id;
    std::vector<std::string> _answers;

public:
    // constructor / destructor
    GraphNode(int id);
    ~GraphNode();

    // getter / setter
    int GetID() { return _id; }
    int GetNumberOfChildEdges() { return _childEdges.size(); }
    GraphEdge *GetChildEdgeAtIndex(int index);
    std::vector<std::string> GetAnswers() { return _answers; }
    int GetNumberOfParents() { return _parentEdges.size(); }

    // proprietary functions
    void AddToken(std::string token); // add answers to list
    void AddEdgeToParentNode(GraphEdge *edge);
    void AddEdgeToChildNode(std::unique_ptr<GraphEdge> edge); // Modified function declaration. Task 4.

    //// STUDENT CODE
    ////

    void MoveChatbotHere(ChatBot chatbot); // Modified function parameters to take a Chatbot object instead of pointer. Task 5

    ////
    //// EOF STUDENT CODE

    void MoveChatbotToNewNode(GraphNode *newNode);
};

#endif /* GRAPHNODE_H_ */