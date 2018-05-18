
#include "iterator.hpp"
#include <iostream>

using namespace std;

namespace BSTree {

    template <typename T>
    class Tree {
    public:
       // using iterator = pre_order::iterator;
        //using reverse_iterator = post_order::iterator;

        Tree(std::initializer_list<T>);

        auto push_back(Node<T>*&,Node<T>*&,const T&) -> Node<T>*;

        auto begin() -> pre_iterator<T>;
        auto end() -> pre_iterator<T>;

        //auto rbegin() -> reverse_iterator;
        //auto rend() -> reverse_iterator;

    private:
        Node<T>* root;
    };

template <typename T>
    Tree<T>::Tree(std::initializer_list<T> list){
    root = nullptr;
	for(auto i : list){
        push_back(root,root,i);
	}

    }
 template <typename T>
auto Tree<T>::push_back(Node<T>*& root, Node<T>*& parent,const T& value) -> Node<T>* {
	if (root == nullptr) {
		root = new Node<T> {value, nullptr, nullptr, nullptr};
		if(root != this->root)
			root->parent = parent;
	} else {
		if (root->data < value) {
			root->left = push_back(root->left, root, value);
		} else if (root->data > value) {
			root->right = push_back(root->right, root, value);
		} else if(root -> data == value) {
			cout<<"tree is have this node"<<endl;
			return root;
		}
	}
	return root;
}
template <typename T>
auto Tree<T>::begin() -> pre_iterator<T>{
    pre_iterator<T> iter(root);
    return iter;
}

template <typename T>
auto Tree<T>::end() -> pre_iterator<T>{
    pre_iterator<T> iter(root);
    for(int i=0;i<=7;i++){
    ++iter;
    }
    cout<<iter.node->curr->data<<" ";
    return iter;
}

}
