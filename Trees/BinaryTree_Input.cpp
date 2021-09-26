#include <iostream>
struct node
{
    struct node *left;
    struct node *right;
    int data;

    node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};

void inorder(struct node *root)
{
    if (root == NULL)
    {
        return;
    }
    std::cout << root->data << " ";
    inorder(root->left);
    inorder(root->right);
    return;
}

int main()
{
    struct node *root = new node(10);
    struct node *temp = root;
    int val, flag;
    std::cout << root->data << std::endl;
    do
    {
        std::cout << "Enter new value :: ";
        std::cin >> val;
        struct node *temp2 = new node(val);
        while (1)
        {
            if (temp->data > val && temp->left != NULL)
            {
                temp = temp->left;
            }
            else if (temp->data > val && temp->left == NULL)
            {
                temp->left = temp2;
                break;
            }
            else if (temp->data < val && temp->right != NULL)
            {
                temp = temp->right;
            }
            else if (temp->data < val && temp->right == NULL)
            {
                temp->right = temp2;
                break;
            }
        }
        temp = root;
        std::cout << "More? (1 - Yes | 0 - No) : ";
        std::cin >> flag;
    } while (flag != 0);

    std::cout << "The tree is :: ";
    inorder(root);
}
