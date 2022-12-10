#include <iostream> 
#include <vector> 

using namespace std;

typedef struct tree_node {
    int value = -1;
    tree_node* left;
    tree_node* right;
}tree_node;

vector<int> inorder_vec;
vector<int> postorder_vec;
tree_node* oldest_parent;

void make_tree(int inorder_start, int inorder_end, int postorder_start, int postorder_end, int direction, tree_node* parent) {
    int inorder_parent_index;

    if (inorder_start > inorder_end) return;
    if (postorder_start > postorder_end) return;

    tree_node* sub_parent = (tree_node*)malloc(sizeof(tree_node));
    sub_parent->left = NULL;
    sub_parent->right = NULL;
    sub_parent->value = postorder_vec.at(postorder_end);

    // param == root
    if (direction == 1) {
        oldest_parent = sub_parent;
    }
    // param == left 
    else if (direction == 2) {
        parent->left = sub_parent;
    }
    // param == right 
    else if (direction == 3) {
        parent->right = sub_parent;
    }

    if (inorder_start >= inorder_end) return;

    for (int i = inorder_start; i <= inorder_end; i++) {
        if (sub_parent->value == inorder_vec[i]) {
            inorder_parent_index = i;
            break;
        }
    }

    // right 
    make_tree(inorder_parent_index + 1, inorder_end, postorder_end - (inorder_end - inorder_parent_index), postorder_end - 1, 3, sub_parent);
    // left
    make_tree(inorder_start, inorder_parent_index - 1, postorder_start, postorder_start + (inorder_parent_index - inorder_start) - 1, 2, sub_parent);
}

void make_preorder(tree_node* each_node) {
    if (each_node == NULL) return;
    cout << each_node->value << " ";
    make_preorder(each_node->left);
    make_preorder(each_node->right);
}

int main() {
    int total_num = 0;
    cin >> total_num;

    // making inorder and postorder 
    for (int i = 0; i < total_num; i++) {
        int sub;
        cin >> sub;
        inorder_vec.push_back(sub);
    }

    for (int i = 0; i < total_num; i++) {
        int sub;
        cin >> sub;
        postorder_vec.push_back(sub);
    }

    // find preorder 
    make_tree(0, total_num - 1, 0, total_num - 1, 1, NULL);
    make_preorder(oldest_parent);

    return 0;
}