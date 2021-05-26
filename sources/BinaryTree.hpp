#include <string>
#include <iostream>

namespace ariel{

    template<typename T> 
    class BinaryTree{
        private:
            struct Node {
                T data;
                Node *left, *right;
                Node(const T& d): data(d){}
            };

        public:
            class iterator{
                private:
                    Node* currentNode;
                public:
                    bool operator==(const iterator& rhs) const {
                        return false;
                    }
                    bool operator!=(const iterator& rhs) const {
                        return false;
                    }
                    iterator& operator++() {
                        return *this;
                    }
                    T& operator*() const {
                        return currentNode->data;
                    }
                    T* operator->() const {
                        return nullptr;
                    }
            };
            
            Node* root;
            iterator BTiterator;
            BinaryTree(): root(nullptr), BTiterator(iterator{}){}
            ~BinaryTree(){}

            BinaryTree& add_root(const T &root_new){
                return *this;
            }

            BinaryTree& add_left(T parent, T child){
                return *this;
            }

            BinaryTree& add_right(T parent, T child){
                return *this;
            }
            
            iterator begin_preorder(){
                return BTiterator;
            }

            iterator end_preorder(){
                return BTiterator;
            }

            iterator begin_inorder(){
                return BTiterator;
            }

            iterator end_inorder(){
                return BTiterator;
            }

            iterator begin_postorder(){
                return BTiterator;
            }

            iterator end_postorder(){
                return BTiterator;
            }

            iterator begin(){
                return BTiterator;
            }

            iterator end(){
                return BTiterator;
            }

            friend std::ostream& operator<< (std::ostream& os, const BinaryTree& binarytree){
                return os;
            }       
    };
}