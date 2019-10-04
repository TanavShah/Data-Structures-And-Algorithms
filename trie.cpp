#include<bits/stdc++.h>
using namespace std;


// C++ implementation of insert, search, delete and display operations on Trie


const int sz=26;

// Trie node
struct node
{
    struct node* children[sz];
    // iseow is true if the node is at end of a word
    bool iseow;
};

// Returns new trie node initialized to NULLs
struct node* getnode(void)
{
    struct node* parent = new node;
    parent->iseow = false;
    for(int i=0;i<sz;++i)
        parent->children[i]=NULL;
    return parent;
};

// If not present, insert value into trie
// If value is prefix of trie node, just mark leaf node
void ins(struct node* root, string value)
{
    struct node* crawl = root;
    for(int i=0;i<value.length();++i)
    {
        int j= value[i]-'a';
        if(!crawl->children[j])
            crawl->children[j]=getnode();
        crawl = crawl->children[j];
    }
    // Mark last node as leaf
    crawl->iseow = true;
}

// Returns true if value is present in trie else false
bool sch(struct node* root, string value)
{
    struct node* crawl = root;
    for(int i=0;i<value.length();++i)
    {
        int j=value[i]-'a';
        if(!crawl->children[j])
            return false;
        crawl = crawl->children[j];
    }
    return (crawl != NULL && crawl->iseow);
}

// Returns true if root has no children else false
bool Empty(node* root)
{
    for(int i=0;i<sz;++i)
        if(root->children[i])
        return false;
    return true;
}

// Recursive function to delete a value from given Trie
node* Remove(node* root, string value, int depth = 0)
{
    // If trie is empty
    if(!root)
        return NULL;
    // If the last character of value is being used
    if(depth==value.size())
    {
        // This node is no more the end of the word after removing value
        if(root->iseow)
            root->iseow=false;
        // If given value is not prefix of any other word
        if(Empty(root))
        {
            delete (root);
            root = NULL;
        }
        return root;
    }
    // If not the last character, recur for the child using ASCII value
    int j=value[depth]-'a';
    root->children[j]=Remove(root->children[j], value, depth+1);
    // If root does not have any child and it is not end of another word
    if(Empty(root) && root->iseow == false)
    {
        delete (root);
        root = NULL;
    }
    return root;
}

// Function to check if current node is leaf or not
bool Leaf(struct node* root)
{
    return root->iseow != false;
}

// Function to display the contents of trie
void display(struct node* root, char ch[], int lvl)
{
    // If node is leaf, it indicates end of string
    // Therefore, a NULL character is added and string is printed
    if(Leaf(root))
    {
        ch[lvl]='\0';
        cout<<ch<<endl;
    }
    int i;
    for(i=0;i<sz;++i)
    {
        // If NON-NULL child is found
        // Parent value is added and display function is recursively called for child
        if(root->children[i])
        {
            ch[lvl]=i+'a';
            display(root->children[i], ch, lvl+1);
        }
    }
}

// Testing above functions
int main()
{
    // Sample input strings (use only 'a' through 'z')
    string s[] = {"github","algorithm","ds","trie","git","tree","dsu"};
    int n = sizeof(s)/sizeof(s[0]);
    struct node* root = getnode();
    // Constructing the trie
    for(int i=0;i<n;++i)
        ins(root, s[i]);
    // Searching for values
    sch(root, "the")?cout<<"Present\n":cout<<"Absent\n";
    sch(root, "github")?cout<<"Present\n":cout<<"Absent\n";
    // Removing a given value
    Remove(root, "ds");
    int lvl=0;
    char ch[50];

    display(root, ch ,lvl);
}
