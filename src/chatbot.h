#ifndef CHATBOT_H_
#define CHATBOT_H_

#include <wx/bitmap.h>

#include <string>

using namespace std;

class GraphNode;  // forward declaration
class ChatLogic;  // forward declaration

class ChatBot {
   private:
    // data handles (owned)
    wxBitmap *_image;  // avatar image

    // data handles (not owned)
    GraphNode *_currentNode;
    GraphNode *_rootNode;
    ChatLogic *_chatLogic;

    // proprietary functions
    int ComputeLevenshteinDistance(string s1, string s2);

   public:
    // constructors / destructors
    ChatBot();                 // constructor WITHOUT memory allocation
    ChatBot(string filename);  // constructor WITH memory allocation
    ~ChatBot();

    //// STUDENT CODE
    ////

    // !Task 2: declare the copy constructor
    ChatBot(const ChatBot &source);
    // !Task 2: declare the copy assignment operator
    ChatBot &operator=(const ChatBot &source);
    // !Task 2: declare the move constructor
    ChatBot(ChatBot &&source);
    // !Task 2: declare the copy assignment operator
    ChatBot &operator=(ChatBot &&source);

    ////
    //// EOF STUDENT CODE

    // getters / setters
    void SetCurrentNode(GraphNode *node);
    void SetRootNode(GraphNode *rootNode) { _rootNode = rootNode; }
    void SetChatLogicHandle(ChatLogic *chatLogic) { _chatLogic = chatLogic; }
    ChatLogic *GetChatLogicHandle() { return _chatLogic; }
    wxBitmap *GetImageHandle() { return _image; }

    // communication
    void ReceiveMessageFromUser(string message);
};

#endif /* CHATBOT_H_ */
