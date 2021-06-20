



//. 单值二叉树


bool _isUnivalTree(struct TreeNode* root, int val)
{
    if (root)
    {
        return root->val == val
            && _isUnivalTree(root->left, val)
            && _isUnivalTree(root->right, val);
    }
    return true;
}

bool isUnivalTree(struct TreeNode* root) {
    if (root == NULL)
        return true;
    return _isUnivalTree(root, root->val);
}


//翻转一棵二叉树

void swap(struct TreeNode* root)
{
    if (root == NULL)
        return NULL;
    struct TreeNode* tmp = root->left;
    root->left = root->right;
    root->right = tmp;

    swap(root->left);
    swap(root->right);

}

struct TreeNode* invertTree(struct TreeNode* root)
{
    if (root == NULL)
        return NULL;
    swap(root);
    return root;
}


//给你两棵二叉树的根节点 p 和 q ，
//编写一个函数来检验这两棵树是否相同。
//如果两个树在结构上相同，并且节点具有相同的值，则认为它们是相同的。

bool isSameTree(struct TreeNode* p, struct TreeNode* q) {
    if (p == NULL && q == NULL)
        return true;
    if (p == NULL || q == NULL)
        return false;
    return p->val == q->val
        && isSameTree(p->left, q->left)
        && isSameTree(p->right, q->right);
}



//给定两个非空二叉树 s 和 t，检验 s 中是否包含和 t 具有相同结构和节点值的子树。
//s 的一个子树包括 s 的一个节点和这个节点的所有子孙。s 也可以看做它自身的一棵子树


bool isSameTree(struct TreeNode* p, struct TreeNode* q) {
    if (p == NULL && q == NULL)
        return true;
    if (p == NULL || q == NULL)
        return false;
    return p->val == q->val
        && isSameTree(p->left, q->left)
        && isSameTree(p->right, q->right);
}

bool isSubtree(struct TreeNode* s, struct TreeNode* t) {
    if (t == NULL)
        return true;
    if (s == NULL)
        return false;
    return isSameTree(s, t)
        || isSubtree(s->left, t)
        || isSubtree(s->right, t);

}


//给定一个二叉树，检查它是否是镜像对称的。
//       1
//     /   \
//    2      2
//   / \    / \
//  3  4    4  3

bool _isSym(struct TreeNode* left, struct TreeNode* right)
{
    if (left == NULL && right == NULL)
        return true;
    if (left == NULL || right == NULL)
        return false;
    return left->val == right->val
        && _isSym(left->left, right->right)
        && _isSym(left->right, right->left);
}

bool isSymmetric(struct TreeNode* root) {
    if (root == NULL)
        return true;
    return _isSym(root->left, root->right);
}



//给定一个二叉树，判断它是否是高度平衡的二叉树。
//一个二叉树每个节点 的左右两个子树的高度差的绝对值不超过 1 。
int getHeight(struct TreeNode* root)
{
    if (root)
    {
        int left = getHeight(root->left);
        int right = getHeight(root->right);
        return left > right ? left + 1 : right + 1;
    }
    return 0;
}

bool isBalanced(struct TreeNode* root) {
    if (root == NULL)
        return true;
    int left = getHeight(root->left);
    int right = getHeight(root->right);
    //当前节点左右字数高度差小于2
    return abs(left - right) < 2
        && isBalanced(root->left)
        && isBalanced(root->right);
}


//用数组把二叉树前序遍历的值保存返回

//给你二叉树的根节点 root ，返回它节点值的 前序 遍历。


int getSize(struct TreeNode* root)
{
    if (root)
    {
        return getSize(root->left) + getSize(root->right) + 1;
    }
    return 0;
}

void preorder(struct TreeNode* root, int* arr, int* idx)
{
    if (root)
    {
        arr[*idx] = root->val;
        (*idx)++;
        preorder(root->left, arr, idx);
        preorder(root->right, arr, idx);
    }
}

int* preorderTraversal(struct TreeNode* root, int* returnSize) {
    int sz = getSize(root);
    int* arr = (int*)malloc(sizeof(struct TreeNode*) * sz);
    int idx = 0;
    preorder(root, arr, &idx);
    *returnSize = idx;
    return arr;
}


//前序遍历  非递归 栈实现


int* preorderTraversal(struct TreeNode* root, int* returnSize)

{
    int sz = getSize(root);
    int* arr = malloc(sizeof(int) * sz);
    stack  st;
    initStack(&st);
    int idx = 0;
    //当前遍历的节点不为空 或者栈不为空
    while (root || !stackEmpty)
    {
        //1.访问最左路径
        while (root)
        {
            arr[idx++] = root->_val;
            //当前节点入栈
            stackPush(&st, root);
            root = root->left;
        }


        //2.获取栈顶元素,访问右子树
        root = stackTop(&st);
        stackPop(&st);
        root = root->right;
    }
    *returnSize = idx;
    return arr;
}


//中序遍历  非递归 栈实现


int* preorderTraversal(struct TreeNode* root, int* returnSize)

{
    int sz = getSize(root);
    int* arr = malloc(sizeof(int) * sz);
    stack  st;
    initStack(&st);
    int idx = 0;
    //当前遍历的节点不为空 或者栈不为空
    while (root || !stackEmpty)
    {
        //1.访问最左路径
        while (root)
        {
            //当前节点入栈
            stackPush(&st, root);
            root = root->left;
        }
        
        //2.获取栈顶元素,访问元素
        root = stackTop(&st);
        stackPop(&st);
        arr[idx++] = root->val;
        //3.访问栈顶元素的右子树
        root = root->right;
    }
    *returnSize = idx;
    return arr;
}