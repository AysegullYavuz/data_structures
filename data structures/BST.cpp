#include <iostream>
#include <stack>
#include <queue>

//Binary Search Tree - ýnOrder,preOrder,postOrder,levelOrder

using namespace std;

class Node {
public:
    int data;//The values we will write into the tree
    Node* left; //Shows the left side of the tree
    Node* right;//Shows the right side of the tree

    Node(int value) {
        data = value;
        left = NULL;
        right = NULL;
    }
};

class BST {
public:
    Node* root;// Represents the element at the beginning of the tree
    BST() {
        root = NULL;
    }

    bool isEmpty() {//Checks whether BST is empty or not
        return root == NULL;
    }

    void insert(int data) {
        Node* newNode = new Node(data);

        if (root == NULL) {//In case tree is empty
            root = newNode;
            return;
        }

        Node* current = root;
        Node* parent = NULL;

        while (current != NULL) {//We will determine the location of the node to be added
            parent = current;//parent always stores the previous state of current
            if (data < current->data)//if current is less than data, go to the left subtree.
                current = current->left;
            else
                current = current->right;//If it is large, go to the right subtree.
        }//The loop exits, that is, current becomes null

        if (data < parent->data)//If data is less than parent's data, make the new node the parent's left child
            parent->left = newNode;
        else
            parent->right = newNode;//If not, have a right child.
    }

    void preOrder() {//root-left-right in preorder form
        if (root == NULL)//exit the loop if the tree contains no elements
            
        return;

        stack<Node*> nodeStack;//We will check the elements with stack
        nodeStack.push(root);//root is added first
        
        while (!nodeStack.empty()) {//Continue as long as there are no nodes left in the stack.
            //current represents the node that is currently trading
            Node* current = nodeStack.top();//Remove the top node from the stack
            nodeStack.pop();

            cout << current->data << " ";//Print the data of the current node to the screen

            if (current->right != NULL) {//If current node has a right child
               
                nodeStack.push(current->right); //its right child is added to the stack
            }
            if (current->left != NULL) {//If current node has a left child
                nodeStack.push(current->left);//its left child is added to the stack
            }
        }
    }

    void inOrder() {// left-root-right in inOrder form
        
        if (root == NULL) 
        return;

        stack<Node*> nodeStack;
        Node* current = root;//current represents the current node of the tree. Initially starts from the root node

        while (current != NULL || !nodeStack.empty()) {//continue as long as there are no nodes left on the stack or current is NULL
            while (current != NULL) {//As long as it's not current's left child, keep going
                nodeStack.push(current);//On each pass add current to the stack and move current to the right
                current = current->left;
            }

            current = nodeStack.top();//Remove the node (current) at the top of the stack and remove it from the stack
            nodeStack.pop();

            cout << current->data << " ";

            current = current->right;//Move current to the right child of the currently processed node. This step is done to traverse the right subtree
        }
    }

    void postOrder() {//left-right-root in postOrder form
        
        if (root == NULL) 
        return;

        stack<Node*> nodeStack1;//nodeStack1 is the first stack that will be used to keep track of nodes.
        stack<Node*> nodeStack2;//nodeStack2, It is the second stack that will be used to store the nodes in reverse order.
        nodeStack1.push(root);//root is added to stack1

        while (!nodeStack1.empty()) {//Continue as long as there are no nodes left in the first pile.
            Node* current = nodeStack1.top();//remove the top of stack1
            nodeStack1.pop();
            nodeStack2.push(current);//add to stack2

            if (current->left != NULL) {//If current has a left child
                nodeStack1.push(current->left);//its left child is added to nodeStack1
            }
            if (current->right != NULL) {//If current has a right child
                nodeStack1.push(current->right);// its right child is added to nodeStack1
            }
        }

        while (!nodeStack2.empty()) {// Continue as long as there are no nodes left in the second pile
            cout << nodeStack2.top()->data << " ";//print the top of stack2 to the screen
            nodeStack2.pop();//and remove it from stack2
        }
    }
    void levelOrder() {
        if (root == NULL)
            return;

        queue<Node*> nodeQueue;//We will use queue for node control
        nodeQueue.push(root);// we add the root node

        while (!nodeQueue.empty()) {
            Node* treeNode = nodeQueue.front();
            cout << treeNode->data << " ";//The data of the processed node is printed on the screen
            nodeQueue.pop();//The processed node is removed

            if (treeNode->left != NULL)// If current node has a left child
                nodeQueue.push(treeNode->left);//left child is added to the queue

            if (treeNode->right != NULL)//If current node has a right child
                nodeQueue.push(treeNode->right);// right child is added to the queue
        }
    }
};

int main() {
    BST bst;
    //We add elements
    bst.insert(10);
    bst.insert(35);
    bst.insert(55);
    bst.insert(58);
    bst.insert(48);
    bst.insert(42);
    bst.insert(15);
    //We print as preorder
    cout << "preOrder (root first): ";
    bst.preOrder();
    cout << endl;
    //We print as inorder
    cout << "inOrder (root in the middle): ";
    bst.inOrder();
    cout << endl;
    //We print as postorder
    cout << "postOrder (lastly the root): ";
    bst.postOrder();
    cout<<endl;
    //We print as level order
    cout << "Level Order: ";
    bst.levelOrder();
    cout << endl;

    return 0;
}

