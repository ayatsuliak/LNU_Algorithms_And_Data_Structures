#include<iostream>

using namespace std;

struct Node
{
    int key;
    Node* left;
    Node* right;
    int height;
};

struct AVLTree
{
    size_t count = 0;
    int height(Node* N)
    {
        if (N == nullptr)
        {
            return 0;
        } 
        return N->height;
    }

    Node* newNode(int key)
    {
        Node* node = new Node();
        node->key = key;
        node->left = NULL;
        node->right = NULL;
        node->height = 1;
        count++;

        return node;
    }

    Node* rightRotate(Node* y)
    {
        Node* x = y->left;
        Node* T2 = x->right;

        x->right = y;
        y->left = T2;

        y->height = max(height(y->left), height(y->right)) + 1;
        x->height = max(height(x->left), height(x->right)) + 1;

        return x;
    }

    Node* leftRotate(Node* x)
    {
        Node* y = x->right;
        Node* T2 = y->left;

        y->left = x;
        x->right = T2;

        x->height = max(height(x->left), height(x->right)) + 1;
        y->height = max(height(y->left), height(y->right)) + 1;

        return y;
    }

    int getBalance(Node* N)
    {
        if (N == nullptr)
        {
            return 0;
        }
        
        return height(N->left) - height(N->right);
    }

    //Додає вершини до дерева і виконує балансування
    Node* insert(Node* node, int key)
    {
        if (node == nullptr)
        {
            return(newNode(key));
        }        

        if (key < node->key)
        {
            node->left = insert(node->left, key);
        }
        else if (key > node->key)
        {
            node->right = insert(node->right, key);
        }       
        else 
        {
            return node;
        }
        
        node->height = 1 + max(height(node->left), height(node->right));

        //перевіряє на збалансованість
        int balance = getBalance(node);

        // якщо вершина не збалансована, то є 4 випадки вирішення

        // поворот вліво
        if (balance > 1 && key < node->left->key)
        {
            return rightRotate(node);
        }        

        // поворот вправо
        if (balance < -1 && key > node->right->key)
        {
            return leftRotate(node);
        }        

        // поворот на ліво і на право
        if (balance > 1 && key > node->left->key)
        {
            node->left = leftRotate(node->left);
            return rightRotate(node);
        }

        // поворот на право і на ліво
        if (balance < -1 && key < node->right->key)
        {
            node->right = rightRotate(node->right);
            return leftRotate(node);
        }

        return node;
    }

    Node* nodeWithMinValue(Node* node)
    {
        Node* current = node;
        while (current->left != nullptr)
        {
            current = current->left;
        }
        return current;
    }

    Node* deleteNode(Node* root, int key)
    {
        if (root == nullptr)
        {
            return root;
        }
        if (key < root->key)
        {
            root->left = deleteNode(root->left, key);
        }
        else if (key > root->key)
        {
            root->right = deleteNode(root->right, key);
        }
        else
        {
            if ((root->left == nullptr) || (root->right == nullptr))
            {
                Node* temp = root->left ? root->left : root->right;
                if (temp == nullptr)
                {
                    temp = root;
                    root = nullptr;
                }
                else
                {
                    *root = *temp;
                }
                free(temp);
            }
            else
            {
                Node* temp = nodeWithMinValue(root->right);
                root->key = temp->key;
                root->right = deleteNode(root->right, temp->key);
            }
        }
        if (root == nullptr)
        {
            return root;
        }
        root->height = 1 + max(height(root->left), height(root->right));
        int balanceFactor = getBalance(root);
        if (balanceFactor > 1)
        {
            if (getBalance(root->left) >= 0)
            {
                return rightRotate(root);
            }
            else
            {
                root->left = leftRotate(root->left);
                return rightRotate(root);
            }
        }
        if (balanceFactor < -1)
        {
            if (getBalance(root->right) <= 0)
            {
                return leftRotate(root);
            }
            else
            {
                root->right = rightRotate(root->right);
                return leftRotate(root);
            }
        }
        return root;
    }    

    void preOrder(Node* root)
    {
        if (root != nullptr)
        {
            cout << root->key << " ";
            preOrder(root->left);
            preOrder(root->right);
        }
    }
};

int main()
{
    Node* root = nullptr;
    AVLTree tree;

    root = tree.insert(root, 8);
    root = tree.insert(root, 10);
    root = tree.insert(root, 4);
    root = tree.insert(root, 2);
    root = tree.insert(root, 6);
    root = tree.insert(root, 1);

    cout << "Preorder traversal of the "
        "constructed AVL tree is \n";
    tree.preOrder(root);

    /* AVL 
             4
            / \
           2   8
          /   / \
         1   6   10
    */

    return 0;
}