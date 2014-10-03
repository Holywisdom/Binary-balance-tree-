#include <iostream>
#include <stdlib.h>
#include <cstdlib>
#include <vector>
#include "tree.h"

using namespace std;

vector<int> myvec ;


int main()
{
    
	Tree<int> mytree ;
    Tree<int> mytree2 ;
    
    
    
    int n ;
    
    cout << "Input number of : "  ;
    cin >> n ;
    
    
    int *ran_num =  new int[n] ;
    int newline[500] ;
    
    cout << "Number before insert :  " ;
    
    for(int i = 1 ; i <= n ; i++) {
        
        ran_num[i] = (arc4random()%100) + 1 ;
        
        cout << ran_num[i] << " " ;
        if (i==n) {
            cout << endl ;
        }
        mytree.insert(ran_num[i]) ;
       // myvec.push_back(ran_num[i]) ;

    }
    
    cout << "Number inorder  : " ;  mytree.inorder() ;
    
    cout << endl ;
    
    cout << "Number in array : " ;
    
    for (int i = 0 ; i < n ; i++) {
          cout << ar[i] << " " ;
    //      mytree2.insert(ar[i]) ;
    }
    
    cout << endl ;
    
    
    
    for (int i = 0 ; i < n ; i++ ) {
        
        newline[i] = ar[i] ;
       // cout << " newline is : " << newline[i] ;
 
    }
    
    mytree.display() ;
    
    cout << endl << endl << endl ;
    
    cout << "Tree hieght  : " << mytree.height() <<endl;
    cout << endl ;
    
    
    
 //   make_heap(ar.begin(), ar.end()) ;
    
    
   // push_heap(ar.begin(), ar.end());
    
    //mytree2.moveDown(newline,0,n) ;
    /*
    for (int i = 0 ; i < n ; i++ ) {
        mytree2.insert(ar[i]) ;
    }
     */
    
    
    mytree2.balance(newline,0,n-1) ;
    
    mytree2.display() ;
    
    
    cout << endl << endl << endl ;
   // mytree2.inorder() ;
    
    cout  << endl << "Tree hieght2 : " << mytree2.height() <<endl;
    
    
    
   // cout << "size of vector is : " << ar.size() ;
    
   
    cout << endl ;
    cout << "Input number Do you want to search ? : " ;
    int val ;
    cin >> val ;
    cout << endl ;
    cout << val << " has alloca memory refer in address : " << mytree2.search(val) << " (0x0 is not found that number) " << endl << endl ;
    
    
    cout << "Input number Do you want to delete ? : " ;
    int val2 ;
    cin >> val2 ;
    mytree2.findAndDeleteByMerging(val2) ;
    cout << endl ;
    cout << "--------------After Detale-----------------" ;
    cout << endl ;
    ar.clear() ; //delete all in vector
    cout << "Number inorder after delete : " ;  mytree2.inorder() ;
    cout << endl ;
    mytree2.display() ;
    cout << endl << endl ;
    cout << "--------------New Balance------------------" ;
    cout << endl ;
    
    
    
    cout << endl ;
    cout << "size of vector is : " << ar.size() << endl ;
    
    
    
    for (int i = 0 ; i < n-1 ; i++ ) {
        
        newline[i] = ar[i] ;
    }
    
    mytree2.clear() ; // clear all old node
    mytree2.balance(newline,0,n-2) ;
    mytree2.display();
    
    cout << endl << endl ;
    cout << "Number inorder after new balance : " ; mytree2.inorder() ;

    cout << endl ;
}
