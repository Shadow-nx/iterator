#include "node.hpp"
using namespace std;

namespace BSTree {

    template<typename T>
    class iterator;

    template <typename T>
    class pre_iterator;

    template <typename T>
    class post_iterator;

    template<typename T>
    class iterator {

        using pointer = T *;
        using reference = T &;
        using value_type = T;

    public:
    /*
        iterator();

        iterator(const iterator &);

        ~iterator();

        iterator& operator=(const iterator &);



        virtual iterator& operator++()=0;

        virtual reference operator*()=0;
        virtual iterator operator++(int);

        value_type operator*() const;

        pointer operator->() const;

        reference operator*() const;

        iterator operator++(int);
        template <typename T2>
        friend bool operator==(const iterator&, const iterator&);
        template <typename T3>
        friend bool operator!=(const iterator&, const iterator&);
        template <typename T4>
        friend void swap(iterator&, iterator&);
*/
    private:
        Node<T>* ptr;
    };

    template <typename T>
    class pre_iterator : iterator<T> {
    public:
        Road<T>* node;
        pre_iterator();
        pre_iterator(Node<T>* ptr);
        auto operator *() -> T&;
        auto operator++() ->pre_iterator<T>&;
        auto direct_bypass(Node<T>* root) -> void;
        auto insert(Node<T>* root) -> void;
        template <typename T2>
        auto friend operator!=( pre_iterator<T2>&, pre_iterator<T2>&) -> bool;
    // ...
    };

    template <typename T>
    class post_iterator : iterator<T> {
    private:
        Road<T>* node;
    protected:
        post_iterator();
        post_iterator(Node<T>* ptr);
        /*
        auto operator *() -> T&;
        auto operator++() ->post_iterator<T>&;
        auto direct_bypass(Node<T>* root) -> void;
        auto insert(Node<T>* root) -> void;
         template <typename T2>
         */
    // ...
    };

    template <typename T>
    pre_iterator<T>::pre_iterator(){
        node=nullptr;
    }

    template <typename T>
    pre_iterator<T>::pre_iterator(Node<T>* ptr){
        node=nullptr;
        direct_bypass(ptr);
    }

    template <typename T>
    auto pre_iterator<T>::direct_bypass(Node<T>* root) -> void {
        if(root!=nullptr){
            insert(root);
    		direct_bypass(root->right);
    		direct_bypass(root->left);
		}
    }

    template <typename T>
    auto pre_iterator<T>::insert(Node<T>* root) -> void {
        if(node==nullptr){
            node=new Road<T>{root,nullptr};
            return;
        }
        Road<T>* current=node;
        while(current->next!=nullptr && current->next!=node){
           current=current->next;
        }
        current->next=new Road<T>{root,node};
    }

    template <typename T>
    auto pre_iterator<T>::operator *() -> T&{
       return node->curr->data;
    }

    template <typename T>
    auto pre_iterator<T>::operator++() ->pre_iterator<T>&{
        node=node->next;
        return *this;
    }

    template <typename T2>
     auto operator!=(pre_iterator<T2>& l, pre_iterator<T2>& r) -> bool
    {
            if(l.node->curr!=r.node->curr)
            return true;

                return false;
    }
/*
    template <typename T>
    post_iterator<T>::post_iterator(){
        node=nullptr;
    }

    template <typename T>
    post_iterator<T>::post_iterator(Node<T>* ptr){
        node=nullptr;
        direct_bypass(ptr);
    }

    template <typename T>
    auto post_iterator<T>::direct_bypass(Node<T>* root) -> void {
        if(root!=nullptr){
            insert(root);
    		direct_bypass(root->right);
    		direct_bypass(root->left);
		}
    }

    template <typename T>
    auto post_iterator<T>::insert(Node<T>* root) -> void {
        if(node==nullptr){
            node=new Road<T>{root,nullptr};
            return;
        }
        Road<T>* current=node;
        while(current->next!=nullptr && current->next!=node){
           current=current->next;
        }
        current->next=new Road<T>{root,node};
    }

    template <typename T>
    auto post_iterator<T>::operator *() -> T&{
       return node->curr->data;
    }

    template <typename T>
    auto post_iterator<T>::operator++() ->post_iterator<T>&{
        node=node->next;
        return *this;
    }
    */
}
