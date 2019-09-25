#include "AVLTree.hpp"
using namespace std;

AVL_Tree::AVL_Tree(){
    
    this->root = NULL;
}

void AVL_Tree::setRoot(Node *root){
    
    this->root = root;
}
Node *AVL_Tree::getRoot(){
    
    return this->root;
}

/*
 * height of tree or subtree
 *
 * a node's height equals the max of node's left child's height and node's right child's height plus 1
 *
 *parameters:
            1, node;//the node that we want to measure with
 *
 *return: the height of the node
 */
int AVL_Tree::height(Node *node){
    
    int h = -1;
    
    if (node != NULL) {
        
        int l_height = height(node->getLeft());
        int r_height = height(node->getRight());
        h = std::max(l_height,r_height) + 1;
    }
    
    return h;
}
/*
 * the height difference of two children nodes
 *
 *parameters:
 *          1, node;//the node which we want to know the differences of its two children
 *
 *return: int; the height difference of the two children nodes
 */

int AVL_Tree::heightDiff(Node *node){
    
    int l_height = height(node->getLeft());
    int r_height = height(node->getRight());
    
    return l_height-r_height;
    
}


/*
 *
 *4 types of rotations
 *
 *1)left left pattern
 *2)left right pattern
 *3)right right pattern
 *4)right left pattern
 *
 */
void AVL_Tree::ll_rotation(Node *node){

    int value = node->getData();
    Node *temp = node->getLeft();
    
    node->setData(temp->getData());
    node->setLeft(temp->getLeft());
    
    temp->setData(value);
    temp->setLeft(temp->getRight());
    temp->setRight(node->getRight());
    node->setRight(temp);
    
}
void AVL_Tree::lr_rotation(Node *node){
 
    Node *temp = node->getLeft();
    node->setLeft(temp->getRight());
    temp->setRight(temp->getRight()->getLeft());
    node->getLeft()->setLeft(temp);
    ll_rotation(node);
    
    
}
void AVL_Tree::rr_rotation(Node *node){
    
    
    int value = node->getData();
    Node *temp = node->getRight();
    
    node->setData(temp->getData());
    node->setRight(temp->getRight());
    
    temp->setData(value);
    temp->setRight(temp->getLeft());
    temp->setLeft(node->getLeft());
    node->setLeft(temp);
    
}
void AVL_Tree::rl_rotation(Node *node){
    
    Node *temp = node->getRight();
    node->setRight(temp->getLeft());
    temp->setLeft(node->getRight()->getRight());
    node->getRight()->setRight(temp);
    rr_rotation(node);
    
}



/*
 *Description: balancing the node whoes two children nodes' height difference is greater than 1 or smaller than -1
 *
 *parameters:
 *          1, node;//the node which we want to rotate with, it is the polar point of the rotation
 *
 *
 *return: void
 *
 *
 *
 */
void AVL_Tree::balance(Node *node){
    
    int balance_factor = heightDiff(node);//differences of the node's two sub nodes.
    
    if (balance_factor>1) {//left side is heavy
        
        if (heightDiff(node->getLeft())>0) {//left left case
            
            ll_rotation(node);
            
        }else{//left right case
            
            lr_rotation(node);
        }
        
    }else if (balance_factor<-1){//right side heavy
        
        if (heightDiff(node->getRight())<0) {//right right case
            
            rr_rotation(node);
            
        }else{//right left case
            
            rl_rotation(node);
        }
        
    }
}


/*
 * Description: insert a node into the AVL tree and keep the whole structure balanced after inserting
 *
 *Parameters:
 *          1, Node *node;//the node which needs to be inserted
 *          2, Node *root;//the root of the tree or subtree; 
 *
 *Return: Node *;//the parent node of the inserted node;
 */

Node *AVL_Tree::insert(Node *node, Node *root){
    
    if (this->root == NULL) {
        
        Node *root = new Node();
        root->setLeft(NULL);
        root->setRight(NULL);
        root->setData(node->getData());
        this->root = root;
        
        return root;
    }
    
    if (root == NULL) {
        
        return node;
        
    }else if(node->getData() < root->getData()){
        
        root->setLeft(insert(node, root->getLeft()));
        balance(root);
        
    }else if (node->getData()>=root->getData()){
        
        root->setRight(insert(node, root->getRight()));
        balance(root);
    }
    
    return root;
}

/*
 *Description: print out the sorted nodes of the AVL tree of AVL subtree
 *
 *parameters:
 *          1, Node *node;//the root of the AVL tree of AVL subtree
 *
 *
 */
void AVL_Tree::inorderSort(Node *node){
    
    if (node == NULL) {
        
        return;
    }
    
    inorderSort(node->getLeft());
    std::cout<<node->getData()<<" ";
    inorderSort(node->getRight());
    
}