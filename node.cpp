


class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int value)
    {
        data = value;
        left = right = NULL;
    }
};

class BST
{
public:
    Node *root;

    BST()
    {
        root = NULL;
    }

    Node *insert(Node *r, int item)
    {
        if (r == NULL)
        {
            return new Node(item);
        }

        if (item <= r->data)
        {
            r->left = insert(r->left, item);
        }
        else
        {
            r->right = insert(r->right, item);
        }

        return r;
    }

    void insert(int item)
    {
        root = insert(root, item);
    }

    void Preoredr(Node *r)
    {
        if (r == NULL)
        {
            return;
        }
        cout << r->data << "\t";
        Preoredr(r->left);
        Preoredr(r->right);
    }

    void inorder(Node *r)
    {
        if (r == NULL)
        {
            return;
        }
        inorder(r->left);
        cout << r->data << "\t";
        inorder(r->right);
    }
    void postorder(Node *r)
    {
        if (r == NULL)
        {
            return;
        }
        postorder(r->left);
        postorder(r->right);
        cout << r->data << "\t";
    }

    Node *search(Node *r, int k)
    {
        if (r == NULL)
        {
            return NULL;
        }
        else if (r->data == k)
        {
            return r;
        }
        else if (k < r->data)
        {
            return search(r->left, k);
        }
        else
        {
            return search(r->right, k);
        }
    }

    bool IsFound(int k)
    {
        root = search(root, k);
        if (root != NULL)
        {
            return true;
        }
        else
            return false;
    }

    Node *findMin(Node *r)
    {
        if (r == NULL)
        {
            return NULL;
        }
        else if (r->left == NULL)
        {
            return r;
        }
        else
            return findMin(r->left);
    }

    Node *findMax(Node *r)
    {
        if (r == NULL)
        {
            return NULL;
        }
        else if (r->right == NULL)
        {
            return r;
        }
        else
            return findMax(r->right);
    }

    Node *deleteNode(Node *r, int k)
    {
        if (r == NULL)
        {
            return r;
        }
        else if (k < r->data)
        {
            r->left = deleteNode(r->left, k);
        }
        else if (k > r->data)
        {
            r->right = deleteNode(r->right, k);
        }
        else
        {
            if (r->left == NULL && r->right == NULL)
            {
                delete r;
                return NULL;
            }
            else if (r->left == NULL)
            {
                Node *temp = r->right;
                delete r;
                return temp;
            }
            else if (r->right == NULL)
            {
                Node *temp = r->left;
                delete r;
                return temp;
            }
            else
            {
                Node *temp = findMin(r->right);
                r->data = temp->data;
                r->right = deleteNode(r->right, temp->data);
            }
        }
        return r;
    }

    void deleteNode(int k)
    {
        root = deleteNode(root, k);
    }
};