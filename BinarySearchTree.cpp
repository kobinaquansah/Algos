#include <iostream>
using std::cout;
using std::endl;
using std::cin;
class Alg
{
public:
    virtual void insert(int number) = 0;
    virtual void search(int number) = 0;
};
class BST_Node: Alg
{
private:
    int root;
    int no_items = 1;
    BST_Node *left;
    BST_Node *right;
public:
    BST_Node(int number):
        root(number),left(0),right (0){};
    void insert(int number) override
    {
        insert_(this,number);
    }
    void search(int number) override
    {
        search_(this,number);
    }
private:
    void insert_(BST_Node *node, int number)
    /*BST Insert*/
        {
        if (number<node->root)
            {
            if (node->left==0)
                {
                BST_Node *l_sub = new BST_Node(number);
                node->left = l_sub;
                }
            else if (node->left->root == number)
                {
                (node->left->no_items)++;
                }
            else
                {
                node = node->left;
                insert_(node, number);
                }
            }
        else if (number>node->root)
            {
            if (node->right==0)
                {
                BST_Node *r_sub = new BST_Node(number);
                node->right = r_sub;
                }
            else if (node->right->root == number)
                {
                (node->right->no_items)++;
                }
            else
                {
                node = node->right;
                insert_(node, number);
                }
            }
        else
            NULL;
    }
    void search_(BST_Node *node, int number)
    /*BST Search*/
    {
        if (node->root == number)
        {
            cout<<node->no_items<<endl;
        }
        else if ((node->left == 0) && (node->right == 0))
        {
            cout<<node->no_items<<endl;
        }
        else if (number<node->root)
            {
            node = node->left;
            search_(node, number);
            }
        else if (number>node->root)
            {
            node = node->right;
            search_(node, number);
            }
        else
            cout<<"EXCEPTIONAL CONDITION"<<endl;
            };
        };

int main()
{
    //BST Test
    BST_Node *instance = new BST_Node(5);
    instance->insert(10);
    instance->insert(10);
    instance->insert(10);
    instance->search(10);
    instance->insert(50);
    instance->insert(30);
    instance->insert(30);
    instance->search(30);
}
