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

int Score(struct node* root)
{
    if(root == NULL)
    {
        return 0;
    }
    else
    {
        return std::max(std::max(root->data + Score(root->left), root->data + Score(root->right)), root->data);
    }
}

int MaxPathSum(struct node* root)
{
    if(root == NULL)
    {
        return 0;
    }
    else
    {
        return std::max(std::max(root->data + Score(root->left) + Score(root->right), root->data) , std::max(MaxPathSum(root->left), MaxPathSum(root->right)))
    ;}
}

int main()
{
    int val, flag;
    std::cout<<"Enter element 1::";
    std::cin>>val;
    struct node *root = new node(val);
    struct node *temp = root;
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
            else if (temp->data <= val && temp->right != NULL)
            {
                temp = temp->right;
            }
            else if (temp->data <= val && temp->right == NULL)
            {
                temp->right = temp2;
                break;
            }
        }
        temp = root;
    } while (val != 0);

    std::cout << "The tree is :: ";
    inorder(root);

    std::cout<<"Maximum Path Sum now:: "<<std::endl;
    std::cout<<"The maximum path sum is :: "<<MaxPathSum(root)<<std::endl;
}