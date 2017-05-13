#ifndef BTREE_H_INCLUDED
#define BTREE_H_INCLUDED

template<typename T>
class BTree {
    private:
        struct Node {
            Node* left  = nullptr;
            Node* right = nullptr;
            T data;

            Node(T& data)
            :   data(data)
            { }
        };

        Node* root = nullptr;

    public:
        ~BTree() {
            destroy_tree(root);
        }

        void destroy_tree() {
            destroy_tree(root);
        }

        void insert(T& value) {
            if(root == nullptr)
                root = new Node(value);
            else
                insert(value, root);
        }

        Node* search(T& value) {
            return search(value, root);
        }

    private:
        void destroy_tree(Node* leaf) {
            if(leaf != nullptr) {
                destroy_tree(leaf->left);
                destroy_tree(leaf->right);
                delete leaf;
            }
        }

        void insert(T& value, Node* leaf) {
            if(value < leaf->data) {
                if(leaf->left != nullptr)
                    insert(value, leaf->left);
                else
                    leaf->left = new Node(value);
            }
            else {
                if(leaf->right != nullptr)
                    insert(value, leaf->right);
                else
                    leaf->right = new Node(value);
            }
        }

        Node* search(T& value, Node* leaf) {
            if(leaf != nullptr) {
                if(value == leaf->data)
                    return leaf;
                else if(value < leaf->data)
                    return search(value, leaf->left);
                else
                    return search(value, leaf->right);
            }
            else
                return nullptr;
        }
};

#endif // BTREE_H_INCLUDED
