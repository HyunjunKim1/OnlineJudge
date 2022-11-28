#include <iostream>
#define MAX 26

using namespace std;

int N;

typedef struct node
{
    char left, right;
};

node nodes[MAX];

void preorder(char ch)
{
    if (ch == '.')
        return;
    cout << ch;
    preorder(nodes[ch - 'A'].left);
    preorder(nodes[ch - 'A'].right);
    
}

void inorder(char ch)
{
    if (ch == '.')
        return;

    inorder(nodes[ch - 'A'].left);
    cout << ch;
    inorder(nodes[ch - 'A'].right);
}

void postorder(char ch)
{
    if (ch == '.')
        return;

    postorder(nodes[ch - 'A'].left);
    postorder(nodes[ch - 'A'].right);
    cout << ch;
    
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> N;

    char ch, left, right;
    for(int i = 0; i < N; i++)
    {
        cin >> ch >> left >> right;

        nodes[ch - 'A'].left = left;
        nodes[ch - 'A'].right = right;
    }

    preorder('A');
    cout << "\n";

    inorder('A');
    cout << "\n";

    postorder('A');
}
