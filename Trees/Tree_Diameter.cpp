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
}


int diameter(struct node *root, int dia1, int dia2)
{
    // if(root->data == dia1 && root->data == dia2)
    // {
    //     return 1;
    // }

    if(root->data > dia1 && root->data > dia2)
    {
        return diameter(root->left, dia1, dia2);
    }

    if(root->data < dia1 && root->data < dia2)
    {
        return diameter(root->right, dia1, dia2);
    }

    if((root->data >= dia1 && root->data <= dia2) || (root->data <= dia1 && root->data >= dia2))
    {
        int left = 0, right = 0;
        struct node* temp = root;
        while(temp->data != dia1)
        {
            if(temp == NULL)
            {
                return -1;
            }
            if(temp->data > dia1)
            {
                temp = temp->left;
                left++;
            }
            else
            {
                temp = temp->right;
                left++;
            }
        }

        temp = root;
        while(temp->data != dia2)
        {
            if(temp == NULL)
            {
                return -1;
            }
            if(temp->data < dia2)
            {
                temp = temp->right;
                right++;
            }
            else
            {
                temp = temp->left;
                right++;
            }    
        }
        return left + right + 1;
    }
    return 0;
}

int main()
{
    int val, flag;
    std::cout<<"Enter element 1:: ";
    std::cin>>val;
    struct node *root = new node(val);
    struct node *temp = root;
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
        // std::cout << "More? (1 - Yes | 0 - No) : ";
        // std::cin >> flag;
    } while (val != 0);

    std::cout << "\nThe tree is :: ";
    inorder(root);
    std::cout<<std::endl<<std::endl;
    std::cout<<"-- I'm now gonna calculate the diameter of the tree -- \n";
    int dia1, dia2;   //Assumption that dia1 < dia2
    do
    {
        std::cout<<"Enter value of Node 1:: ";
        std::cin>>dia1;
        std::cout<<"Enter value of Node 2:: ";
        std::cin>>dia2;
        int result = diameter(root, dia1, dia2);
        if(result == -1)
        {
            std::cout<<"The entered elements are invalid\n";
        }
        else
        {
            std::cout<<"The diameter of the tree is "<<result<<std::endl;
        }
        std::cout<<"Calculate more? (Yes - 1 | No - 0) ::";
        std::cin>>flag;
    }
    while(flag != 0);
    std::cout<<"\n --- Been a pleasure! Thank you! ---\n";
}