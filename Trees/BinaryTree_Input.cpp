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
    int val, flag, i = 1;
    std::cout << "Enter value "<<i++<<" ::";
    std::cin >> val;
    struct node *root = new node(val);
    struct node *temp = root;
    do
    {
        std::cout << "Enter value "<<i++<<" ::";
        std::cin >> val;
        if(val != 0)
        {
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
        }
    } while (val != 0);

    std::cout << "The tree is :: ";
    inorder(root);
}
