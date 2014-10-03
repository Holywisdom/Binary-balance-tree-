#include <queue>
#include <stack>
#include <vector>
using namespace std;

#ifndef Binary_Search_Tree
#define Binary_Search_Tree

vector<int> ar ;

template<class T> class Tree;

template<class T>
class Node {
public:
    
	Node() { left=right=NULL; }
	Node(const T& el, Node *l=0, Node *r=0 ) {
        
        key=el; left=l; right=r;
	}
    T key;
    
	Node *left, *right;
};

template<class T>
class Tree {
public:
	Tree() { root = 0; }
	~Tree() { clear(); }
	void clear() { clear(root); root = 0; }
	bool isEmpty() { return root == 0; }
	void inorder() { inorder(root); }
	void insert(const T& el);
    void visit(Node<T> * p) ;
    int height() { return height(root);  }
    void balance(T data[], int first, int last) ;
    void display() { display(root,1); }
    void moveDown (T data[], int first, int last) ;
    T* search(const T& el) const { return search(root,el); }
    void deleteByMerging(Node<T>*&);
    void findAndDeleteByMerging(const T&);
    
    

    
    

protected:
	Node<T> *root;

	void clear(Node<T> *p);
	void inorder(Node<T> *p);
    int largest(Node<T> *p ) ;
    int height(Node<T> *p) ;
    void display(Node<T> *ptr, int level) ;
    T* search(Node<T>*, const T&) const;

};

template<class T>
void Tree<T>::clear(Node<T> *p)
{
	if (p != 0) {
	     clear(p->left);
	     clear(p->right);
	     delete p;
	}
}

template<class T>
void Tree<T>::inorder(Node<T> *p) {
	//TO DO! This is for an inorder tree traversal!
    
    if(p != 0)
    {   inorder(p->left);
         visit(p)  ;
        inorder(p->right);
    }
    
}

template<class T>
void Tree<T>::insert(const T &el) {
	Node<T> *p = root, *prev = 0 ;
	while(p != 0) {
		prev = p;
		if(p->key < el)
			p=p->right;
		else
			p=p->left;
	}
	if(root == 0)
		root = new Node<T>(el);
	else if(prev->key<el)
		prev->right = new Node<T>(el);
	else
		prev->left = new Node<T>(el);
}


template<class T>
void Tree<T>::visit(Node<T> * p){
    cout << p->key  << ' ' ;
    ar.push_back(p->key) ;
}


template<class T>
int Tree<T>::height(Node<T> *p){
    int left, right;
    
    if(p==NULL)
        return 0;
    left = height(p->left);
    right = height(p->right);
    if(left > right)
        return left+1;
    else
        return right+1;
}

template<class T>
void Tree<T>::moveDown (T data[], int first, int last) {
    int largest = 2*first + 1 ;
    while (largest <= last) {
        if (largest < last && data[largest] < data[largest+1])
            largest++;
        if (data[first] < data[largest]) {
            swap(data[first],data[largest]);
            first = largest ;
            largest = 2*first+1;
        }
        else largest = last+1;
    }
}

template<class T>
void Tree<T>::balance(T data[], int first, int last) {
    if (first <= last) {
        int middle = (first + last)/2;
        insert(data[middle]);
        balance (data,first,middle-1);
        balance (data,middle+1,last);
    }

}


template<class T>
void Tree<T>::display(Node<T> *ptr, int level)
{
    int i;
    if (ptr!=NULL)
    {
        display(ptr->right, level + 1);
        cout << endl ;
        if (ptr == root)
            cout<<"Root -> ";
        for (i = 0; i < level && ptr != root; i++)
            cout<<"        ";
        cout<<ptr->key;
        display(ptr->left, level + 1);
    }
}

template<class T>
T* Tree<T>::search(Node<T>* p, const T& el) const {
    while (p != 0)
        if (el == p->key)
            return &p->key;
        else if (el < p->key)
            p = p->left;
        else
            p = p->right;
    return 0;
}


template<class T>
void Tree<T>::deleteByMerging(Node<T>*& node) {
Node<T> *tmp = node;
if (node != 0) {
    if (!node->right)
        node = node->left;
        else if (node->left == 0) node = node->right;
            else {
                tmp = node->left;
                while (tmp->right != 0)
                    tmp = tmp->right;
                    tmp->right =
                    node->right;
                    tmp = node;
                    node = node->left;
                    }
    delete tmp;
    }
}

template<class T>
void Tree<T>::findAndDeleteByMerging(const T& el) {
    Node<T> *node = root, *prev = 0;
    while (node != 0) {
        if (node->key == el)
            break;
        prev = node;
        if (el < node->key)
            node = node->left;
        else node = node->right;
    }
    if (node != 0 && node->key == el)
        if (node == root)
            deleteByMerging(root);
        else if (prev->left == node)
            deleteByMerging(prev->left);
        else deleteByMerging(prev->right);
        else if (root != 0)
            cout << "element" << el << "is not in the tree\n";
        else cout << "the tree is empty\n";
}

#endif // Binary_Search_Tree
