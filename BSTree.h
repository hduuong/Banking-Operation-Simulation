//  file BSTree.h
//  Binary Search Tree Template class
//  @author Duong H Chau
//  @author professor Zander
//  @version lab5

#ifndef FinalLab_BSTree_h
#define FinalLab_BSTree_h

#include <iostream>
#include <fstream> 
using namespace std;

//------------------------------ class BSTree ---------------------------------
//  BSTree class: binary search tree to hold Client objects, with additional
//    functionality:
//    -- inserting a new client in the tree
//    -- retrieve a client
//    -- display client info
//    -- check if Firm is empty (contains no clients)
//    -- destroy Client Oobjects (makeEmpty used in destructor)
//
//  Assumptions:
//    -- each node has a pointer to two other nodes and a pointer to a Client
//    -- makeEmpty is used to delete a client from the tree (all account memory
//       is released
//    -- clients are sorted by client ID
//------------------------------------------------------------------------------
template <typename T>
class BSTree {
public:
    BSTree(); 
	~BSTree();      // calls makeEmpty which deallocates all memory 

	// insert object into the tree, parameter holds pointer to object to insert 
	bool insert(T*); 
 
	// retrieve object, first parameter is object to retrieve 
	// second parameter holds pointer to found object, NULL if not found 
	bool retrieve(const T& , T*&)const; 
 
	void display()const;     //displays the contents of a tree to cout 
	void makeEmpty();        //empties the current tree, deallocates all memory 
	bool isEmpty()const;     //returns true if tree is empty 

 private: 
	struct Node{        //glue that holds data properly 
		T* data; 
		Node* right; 
		Node* left; 
	};

	Node* root;                           // root of the tree.
	void makeEmptyHelper(Node*);          //empties the current tree, deallocates all memory 
	void printHelper(Node*)const;              //This help make the output object to print the tree in in-order
};

	//----------------------------------------------------------------------------
	// Constructor
    // default constructor
	template <typename T>
	BSTree<T>::BSTree() {
		root = NULL;
	}

	//----------------------------------------------------------------------------
	// Destructor
	// call makeEmpty to clear out memories
	template <typename T>
	BSTree<T>::~BSTree() {
		makeEmpty();
	}

	//----------------------------------------------------------------------------
	// Insert
	// add a new data to the tree
	// @param dataptr pointer to the data need to be added in
	// @return true if successfull, false if not
	template <typename T>
	bool BSTree<T>::insert(T* dataptr) {
		Node* ptr = new Node;
		if (ptr == NULL) return false;            // out of memory
	    ptr->data = dataptr;
		ptr->left = ptr->right = NULL;
		if (isEmpty()) {
			root = ptr;
		}
		else {
			Node* current = root;                           // walking pointer
			bool inserted = false;                          // whether inserted yet

      // if item is less than current item, insert in left subtree,
      // otherwise insert in right subtree
			while (!inserted) {
				if (*ptr->data < *current->data) {
					if (current->left == NULL) {              // insert left
						current->left = ptr;
						inserted = true;
					} else
						current = current->left;               // one step left
				} else if (*ptr->data > *current->data) {
					if (current->right == NULL) {             // insert right
						current->right = ptr;
						inserted = true;
					} else
						current = current->right;              // one step right
				} else {
					return false;                             // already have this item
				}
			}
		}
		return true;
	}
	//----------------------------------------------------------------------------
	// retrieve
	// set the holder to the actual data, if the object == data
	// @param object the object comparing
	// @param holder the pointer that will hold the data, if false it holds NULL
	// @return true if found the data, false if not
	template <typename T>
	bool BSTree<T>::retrieve(const T& object , T*& holder)const{
		Node* pointer = root;
		while(pointer!=NULL){
			if(*pointer->data == object){
				holder = pointer->data;
		//		cout<<" ######## retrieve true :" << object << endl; 
				return true;
			}else if(*pointer->data > object){
				pointer = pointer->left;
			}else{
				pointer = pointer->right;
			}
		}
	//	cout<<" ######## retrieve  false :" << object << endl; 
		return false;
	}
	//----------------------------------------------------------------------------
	// MakeEmpty 
	// a public makeEmpty method
	// this calls the helper method to do it task recursively
	template <typename T>
	void BSTree<T>::makeEmpty(){
		makeEmptyHelper(root);
	}
	//----------------------------------------------------------------------------
	// MakeEmptyHelper
	// a private helper method, recursion method
	// empty the tree recursively
	// @param node a node of the tree
	template <typename T>
	void BSTree<T>::makeEmptyHelper(Node* node){
		if(node == NULL) return;
		delete node->data;
		makeEmptyHelper(node->left);
		makeEmptyHelper(node->right);
		node = NULL;
	}
	//----------------------------------------------------------------------------
	// display
	// a public method
	// this calls a helper  method todisplay the tree recursively
	template <typename T>
	void BSTree<T>::display()const{
		if(root != NULL)
			printHelper(root);
		else
			cout<< "The is no Client" <<endl;
	}
	//-----------------------------------------------------------------------------
	// printhelper
	// a private helper method
	// print the tree out using recursion (in-order order)
	// @param node a node of the tree
	template <typename T>
	void BSTree<T>::printHelper(Node* node)const{
		if(node->left != NULL) printHelper(node->left);
		cout<<*node->data<<endl;
		if(node->right != NULL) printHelper(node->right);
	}
	//-----------------------------------------------------------------------------
	// isEmpty
	// check if tree is empty
	// @return true if it is empty, false if is not.
	template <typename T>
	bool BSTree<T>::isEmpty()const{
		return root == NULL;
	}

#endif
