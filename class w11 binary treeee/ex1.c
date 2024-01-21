#include <stdio.h>
#include <stdlib.h>
// Ôn thi binary trê
// đệ quy làm đệ quy
// phần dễ nhất dung kĩ thuật đệ quy phân
// lesson binarytree section 5 practice 4
typedef struct NodeType {
    int data;
    struct NodeType* left, * right;
} TreeNode;

typedef struct BinaryTreeType {
    struct NodeType* root;
} BinaryTree;

TreeNode* makeNode(int data) {
    TreeNode *s =  (TreeNode*)malloc(sizeof(TreeNode));
    // ham data 
    s->data = data;
    s->right = NULL;
    s->right = NULL;
    return s;
}

void print(TreeNode* node) {
    if(node == NULL )
    {
        return;
    }
    printf("\n %d",node->data);
    print(node->left);
    print(node->right);
 }

void init(BinaryTree* tree) {
    tree->root = NULL;
}

// hàm insert
void insert(BinaryTree* tree, int data) { 
    TreeNode * temp = tree->root;
    TreeNode * pre = NULL;
    TreeNode * temp2 = makeNode(data);
    // trường hợp insert ở đầu
    if(tree->root == NULL)
    {
        // kiểm tra 
        tree->root = temp2;
        return;
    }
    int isLeaf(TreeNode *node)
    {
        me
    }
    // di chuyển về vị trí lá thích hợp
    while(temp != NULL)
    {
        pre = temp;
        if(data < temp->data)
        {
            temp = temp->left;
        }
        else{
            temp= temp->right;
        }
    }
    // thực hiện lệnh chèn
    if(pre->data < data)
    {
        pre->right = temp2;
    }else 
    {
        pre->left = temp2;
    }
}
delet()
{
    // No child
    // 1 child
    // 2 child
    //curr-> right is not leaf

}

int main() {
    BinaryTree tree;
    init(&tree);
    //insert các cây ở câu 1.1
    int arr[14]={50,25,75,10,33,56,89,4,11,40,52,61,82,95};
    for(int i=0;i<14;i++)
    {
        insert(&tree,arr[i]);
    }
    print(tree.root);
    return 0;
}
