// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
class _stack{
stack<int> s;
int minEle;
public :
    int getMin();
    int pop();
    void push(int);
};


int main()
{
   int t;
   cin>>t;
   while(t--)
   {
       int q;
       cin>>q;
        _stack *a = new _stack();
       while(q--){

       int qt;
       cin>>qt;

       if(qt==1)
       {
           //push
           int att;
           cin>>att;
           a->push(att);
       }
       else if(qt==2)
       {
           //pop
           cout<<a->pop()<<" ";
       }
       else if(qt==3)
       {
           //getMin
           cout<<a->getMin()<<" ";
       }
       }
       cout<<endl;
   }

}


// } Driver Code Ends


/*
The structure of the class is as follows
class _stack{
stack<int> s;
int minEle;
public :
    int getMin();
    int pop();
    void push(int);
};
*/


/*returns min element from stack*/
int _stack :: getMin()
{
   //Your code here
    if (s.empty())
        return -1;
    return minEle;
}

/*returns poped element from stack*/
int _stack ::pop()
{
   //Your code here
    if (s.empty())
        return -1;
        
    int poped_elem = s.top();
    
    if (poped_elem < minEle) {
        int y = poped_elem;
        poped_elem = minEle;
        minEle = 2*minEle - y;
    }
    
    s.pop();
    return poped_elem;
    
}

/*
 * The idea is to store the minmum so far in such a way that,
 * the old minimum could be found using the current one. 
 *
 * Lets say 'x' is smaller than the current minimum.
 * So instead of pushing 'x' directly onto the stack we push 'y',
 * where  y = 2*x - minEle. and update minEle to x. 
 * 
 * Now, while popping, if we find element 'y' which is lesser than minEle, 
 * then that's our minEle so far. We pop that, and now to get the old minEle,
 * we can just get it from the above equation.
 *  
 *  x now is the minEle, 
 *  minEle is the old minEle which we want, 
 *  and y is what we pushed onto the stack,
 *
 *  so, our old_minEle =  2*minEle - y.
 */

/*push element x into the stack*/
void _stack::push(int x)
{
   //Your code here
    if (s.empty()) {
        s.push(x);
        minEle = x;
    }
    else if (x >= minEle) 
        s.push(x);
    else {
        s.push(2*x-minEle);
        minEle = x;
    }
}

