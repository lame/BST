#ifndef BST_H
#define BST_H

#include <queue>
#include <iostream>
#include <sstream>
#include <string>

using namespace std;
const int DEFAULT_THRESHOLD = 1;

namespace cop4530{

  template <typename T>
  class BST
  {

    public:
      //default
      BST(int th = DEFAULT_THRESHOLD);
      //constructor
      BST(const string input, int th = DEFAULT_THRESHOLD);
      //copy constructor
      BST(const BST &rhs);
      //destructor
      ~BST( );
  
      const T &findMin( ) const;
      const T &findMax( ) const;
      const BST &operator=( const BST &rhs );

      bool contains(const T & x);
      bool empty( ) const;

      void buildFromInputString(const string input);
      void printInOrder( ) const;
      void printLevelOrder( ) const;
      void makeEmpty( );
      
      void insert( const T & x );
      void remove( const T &x);
      //something else?
      int numOfNodes() const;
      int height() const;

    private:
      int thresholdVal;
      struct BSTNode{
        T element;
        int searchCount;
        BSTNode *left;
        BSTNode *right;
        BSTNode(const T &theElement, BSTNode *lt, BSTNode *rt){
          element = theElement;
          left = lt;
          right = rt;
          searchCount = 0;
        }
      };

    BSTNode *root; //necessary?
 
    void insert (const T & x, BSTNode * & t) const;
    void remove (const T & x, BSTNode * & t) const;
 
    BSTNode * findMin( BSTNode *t ) const;
    BSTNode * findMax( BSTNode *t ) const;
 
    bool contains(const T& x, BSTNode *&t);
 
    void makeEmpty( BSTNode * & t );
    void printInOrder(BSTNode *t) const;
    void printLevelOrder(BSTNode *t) const;
    
    void rotateWithLeftChild(BSTNode * & t);
    void rotateWithRightChild(BSTNode * & t);


    int numOfNodes(BSTNode *t) const;
    int height(BSTNode *t) const;
  
    BSTNode * clone( BSTNode *t ) const;
  };
  
  #include "bst.hpp"
}
#endif
