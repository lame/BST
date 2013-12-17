#ifndef BST_HPP
#define BST_HPP

#include <queue>
#include <string>
#include "bst.h"

using namespace std;
using namespace cop4530;

const int DEFAULT_THRESHOLD = 1;
//CONSTRUCTOR
//where to include default threshold val??
template <typename T>
BST<T>::BST(int th){
	root = NULL;
	thresholdVal = th;
}
template <typename T>
BST<T>::BST(const string input, int th){
	root = NULL;
	thresholdVal = th;
	buildFromInputString(input);
}
template <typename T>
BST<T>::BST(const BST &rhs){
	root = rhs.root;
	BSTNode *t = root;
	root = clone(t);
}
template <typename T>
BST<T>::~BST(){
	makeEmpty();
}
/*********************************************************************************/
template <typename T>
const T& BST<T>::findMin()const {
	return findMin(root);
}
template <typename T>
const BST<T>& BST<T>::operator=(const BST & rhs){
	if(this != &rhs){
		makeEmpty();
		root = clone(rhs.root);
	}
	return *this;
}
/*******************************************************************************/
template <typename T>
bool BST<T>::contains (const T & x){
	return contains (x, root);
}
template <typename T>
bool BST<T>::empty() const{
	if(root == NULL)
		return true;
	else 
		return false;
} 
/*******************************************************************************/
template <typename T>
void BST<T>::buildFromInputString(const string input){
	stringstream ss;
	ss << input;
	T token;
	while(ss >> token){
		insert(token);
	}
}
template <typename T>
void BST<T>::printInOrder() const{
	printInOrder(root);
}
/*******************************************************************************/
template <typename T>
void BST<T>::printLevelOrder() const{
	printLevelOrder(root);
}
template <typename T>
void BST<T>::makeEmpty(){
	makeEmpty(root);
}
/*******************************************************************************/
template <typename T>
void BST<T>::insert (const T & x){
	insert (x, root);
}
template <typename T>
void BST<T>::remove (const T & x){
	remove (x, root);
}
/*******************************************************************************/
template <typename T>
int BST<T>::numOfNodes() const{
	return numOfNodes(root);
}
template <typename T>
int BST<T>::height() const{
	if(root == NULL)
		return 0;
	else
		return height(root);
}
/*******************************************************************************/
/*******************************************************************************/
/*******************************************************************************/
template <typename T>
void BST<T>::insert (const T & x, BSTNode * & t) const{
	if(t == NULL)
		t = new BSTNode (x, NULL, NULL);
	else if(x < t->element)
		insert(x, t->left);
	else if(x > t->element)
		insert(x, t->right);
	else
		;
}
template <typename T>
void BST<T>::remove(const T & x, BSTNode * & t) const{
	if(t == NULL)
		return;
	if(x < t->element)
		remove(x, t->left);
	else if(x > t->element)
		remove(x, t->right);
	else if(t->left != NULL && t->right != NULL){
		t->element = findMin(t->right)->element;
		remove(t->element, t->right);
	}
	else{
		BSTNode *o = t;
		t = (t->left != NULL) ? t->left : t->right;
		delete o;
	}
}
/*******************************************************************************/
template <typename T>
typename BST<T>::BSTNode* BST<T>::findMin(BSTNode *t) const{
	if(t == NULL)	
		return NULL;
	if(t->left == NULL)
		return t;
	return findMin(t->left);
}
template <typename T>
typename BST<T>::BSTNode* BST<T>::findMax(BSTNode *t) const{
	if(t == NULL)
		return NULL;
	if(t->right == NULL)
		return t;
	return findMax(t->right);
}
/*******************************************************************************/
template <typename T>
bool BST<T>::contains(const T & x, BSTNode *&t){
	if (t == NULL){
		return false;
	}
	else if(x == root->element){
		root->searchCount++;
		return true;
	}
	else{
		if(t->left != NULL){
			if(t->left->element == x){
				t->left->searchCount++;
				if(t->left->searchCount%thresholdVal == thresholdVal)
					rotateWithLeftChild(t);
				return true;
			}
		} 
		if(t->right != NULL){
			if(t->right->element == x){
				t->right->searchCount++;
				if(t->right->searchCount%thresholdVal == thresholdVal)
					rotateWithRightChild(t);
				return true;
			}
		}
		if (x < t->element){
			return contains( x, t->left );
		}
		if (x > t->element){
			return contains( x, t->right );
		}
		else
			return false;
	}
	
}
/*******************************************************************************/
template <typename T>
void BST<T>::makeEmpty(BSTNode *&t){
	if(t != NULL){
		makeEmpty(t->left);
		makeEmpty(t->right);
		delete t;
	}
	t = NULL;
}
template <typename T>
void BST<T>::printInOrder(BSTNode *t) const{
	if(t != NULL){
		printInOrder(t->left);
		cout << t->element << " ";
		printInOrder(t->right);
	}
}
template <typename T>
void BST<T>::printLevelOrder(BSTNode *t) const{
	queue<BSTNode*> Q;
	if(!t)
		return;
	int currNodes = 1;	//root is present, past if statement
	int nextNodes = 0;	//none identified yet

	Q.push(t);
	while(Q.empty() == false){
		BSTNode *NODE = Q.front();
		Q.pop();
		--currNodes;
		if(NODE){
			cout << NODE->element << " ";
			Q.push(NODE->left);
			Q.push(NODE->right);
			nextNodes += 2;
		}
		if(currNodes == 0){
			currNodes = nextNodes;
			nextNodes = 0;
		}
	}
}
/********************************************************************/
template <typename T>
void BST<T>::rotateWithLeftChild(BSTNode *&t){
	//t = parent
	//temp = old parent
	BSTNode *temp = t;
	t = t->left;
	temp->left = t->right;
	t->right = temp;
}
template <typename T>
void BST<T>::rotateWithRightChild(BSTNode *&t){
	BSTNode *temp = t;
	t = t->right;
	temp->right = t->left;
	t->left = temp;
}
/*********************************************************************/
template <typename T>
int BST<T>::numOfNodes(BSTNode *t) const{
	if(t == NULL)
		return 0;
	else if(t->left == NULL && t->right == NULL)
		return 1;
	else
		return numOfNodes(t->left) + numOfNodes(t->right);
}
template <typename T>
int BST<T>::height(BSTNode *t) const{
	
	int rHeight = 0;
	int lHeight = 0;

	if(t == NULL)
		return -1;
	else{
		rHeight = height(t->right);
		lHeight = height(t->left);
	
		if(rHeight > lHeight)
			return (rHeight + 1);
		else
			return (lHeight + 1);
	}
}
/**********************************************************************/
template <typename T>
typename BST<T>::BSTNode* BST<T>::clone(BSTNode *t) const{
	if(t == NULL)
		return NULL;

	return new BSTNode(t->element, clone(t->left), clone(t->right));
}

#endif