//Isabelle Kwan
//301542393
//itk1
#include "a4_BirthdayBST.hpp"

//internal recursive insert function
BirthdayBSTreeNode* BirthdayBST::insertNode_rec(BirthdayBSTreeNode* node,
                                Birthday* value){
    if (node == NULL){
        size++;
        return newNode(value);
    }
    //continue to either in the left- or right-subtree
    if (node->value > value){
      node->left = insertNode_rec(node->left, value);  
    }else{
        node->right = insertNode_rec(node->right, value);
        //returns itself (unchanged)
        return node;
    } 
}

//internal recursuve remove function
BirthdayBSTreeNode* BirthdayBST::removeNode_rec(BirthdayBSTreeNode* node,
                                Birthday* value){
    if (node == NULL) {
        return node; //empty tree, do nothing, NULL is returned
    }
    //find the node to remove
    if (compareBirthdaysByMD(node->value,value)>0){
        node->left = removeNode_rec(node->left, value);
    }else if (compareBirthdaysByMD(node->value,value)<0){ 
        node->right = removeNode_rec(node->right, value);
    } else { //node is found
        if (node->left == NULL && node->right == NULL) { //node is a leaf
            return NULL; //let its caller update the child pointer to NULL
        } else if (node->right == NULL) { //node has a single left child
            BirthdayBSTreeNode* leftChild = node->left;
            return leftChild; //
        } else if (node->left == NULL) { //node has a single right child
            BirthdayBSTreeNode* rightChild = node->right;
            return rightChild; 
        } else { 
            //if node has 2 children
            BirthdayBSTreeNode* minRightNode = minSuccessor(node->right);
            //copy the value from the minimum successor
            node->value = minRightNode->value;
            //move on to the right and remove this “duplicate”
            node->right = removeNode_rec(node->right, minRightNode->value);
            }
        }
    return node; //update the child pointer
}
 
//internal recursive find function for duplicates, useful for insert
BirthdayBSTreeNode* BirthdayBST::findNodeByYMDN_rec(BirthdayBSTreeNode* node,
                                short year, short month, short day,
                                string name){
    if(node == NULL){
        return node; //empty, return nothing
    }else{
                                                                 //**********
    }
}
//internal recursive find function for same month and day, useful for remove
BirthdayBSTreeNode* BirthdayBST::findNodeByMD_rec(BirthdayBSTreeNode* node,
                                short month, short day){
    if (node==NULL){
        return node;
    }else{
        if(node->value->month == month){
            if(node->value->day == day){
                return node;                                    //**********
        }  
    } 
    }  
}     
//internal recursive print function with matching month and day
void BirthdayBST::printAllNodeWithMatchingMD_rec(BirthdayBSTreeNode* node, 
                                    ostream& os,short month, short day){
    if(node==NULL){
        return;
    }else{
                                                               //**********
    }
}

//internal recursive print function performing an in-order traversal
void BirthdayBST::inOrderPrint_rec(BirthdayBSTreeNode* node, ostream& os){
    if (node == NULL) {
        return;
    } else { //note the order of actions
        inOrderPrint_rec(node->left,os);
        print_Birthday(node->value,os);
        inOrderPrint_rec(node->right,os);
    return;
    }
}

//internal recursive delete function releasing memory use by the tree
//also releases the Birthday structs along the way
void BirthdayBST::deleteTree_rec(BirthdayBSTreeNode* node){
    if(node==NULL){
        return;
    }else{
        delete root;
    }
}

//internal helper function for creating a new tree node
BirthdayBSTreeNode* newNode(Birthday* value){
    BirthdayBSTreeNode* node = new BirthdayBSTreeNode;
    node->value = value;
    node->left = NULL;
    node->right = NULL;
    node->parent = NULL; 
    return node;
}
//internal helper function for finding the minimal successor, used by remove
BirthdayBSTreeNode* minSuccessor(BirthdayBSTreeNode* node){
    BirthdayBSTreeNode* minNode = node;
    //keep going if there is a left child (smaller value)
    while (minNode != NULL && minNode->left != NULL) {
        minNode = minNode->left;
    }
    return minNode;
}

BirthdayBST::BirthdayBST(){
    root = NULL;
    size = 0;
}

int BirthdayBST::getSize(){
    return size;
}

void BirthdayBST::insertNode(Birthday* value){
    insertNode_rec(root,value);
}

Birthday* BirthdayBST::removeNode(Birthday* value){
    removeNode_rec(root,value);
}

Birthday* BirthdayBST::findNodeByYMDN(short year, short month, short day,
                                string name){
    findNodeByYMDN_rec(root,year,month,day,name);
}

Birthday* BirthdayBST::findNodeByMD(short month, short day){
    findNodeByMD_rec(root,month,day);
}

void BirthdayBST::printAllNodeWithMatchingMD(short month, short day, 
                                            ostream& os){
    printAllNodeWithMatchingMD_rec(root,os,month,day);
}

void BirthdayBST::inOrderPrint(ostream& os){
    inOrderPrint_rec(root,os);
}

BirthdayBST::~BirthdayBST(){
    deleteTree_rec(root);
}
