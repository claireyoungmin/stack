#include <iostream>

using namespace std;

template <class T>
class Node{
    public:
        T item;
        Node<T> *next;
        Node();
        Node(T);
};

template <class T>
Node<T>::Node(){
    next = NULL;
}

template <class T>
Node<T>::Node(T x){
    item = x;
    next = NULL;
}

template <class T>
class stack{
    private:
        int size;
        Node<T> *top;
    public:
        stack();
        stack(const stack<T>&);
        void push(T);
        ~stack();
        bool pop();
        int getSize();
        void display();
        T peek();
};

template <class T>
stack<T>::stack(){
    size = 0;
    top = NULL;
}

template <class T>  // copy constructor
stack<T>::stack(const stack<T> &l){
    size = 0;
    top = NULL;
    int i = 0;
    for(Node<T> *tmp = l.top; i<l.size; tmp = tmp->next,i++)
        push(tmp->item);
}


template <class T>  //  destructor
stack<T>::~stack(){
    for(Node<T> *tmp = top; tmp!=NULL; ){
        top = top->next;
        delete tmp;
        tmp = top;
    }
}

template <class T>
void stack<T>::push(T x){
	Node<T> *n = new Node<T>(x);
    if(top == NULL) //  stack is empty
        top = n;
    else{
    	n->next = top;
    	top = n;
    }
    size++;
}

template <class T>
bool stack<T>::pop(){
    if(size==0)
        return false;
    else{
        Node<T>*tmp=top;
        top = top->next;
        delete tmp;
    }
    size--;
    return true;
}

template <class T>
int stack<T>::getSize(){
    return size;
}

template <class T>
void stack<T>::display(){
    Node<T> *tmp = top;
    for(int i=0;i<size;i++,tmp=tmp->next)
        cout << tmp->item << " ";
}

template <class T>
T stack<T>::peek(){
    if(size==0)
        throw 404;
    return top->item;
}


int main(){
 stack<int> a;
    int n,item,op;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> op;
        switch(op){
            case 1:
                cin >> item;
                a.push(item);
                a.display();
                break;
            case 2:
                a.pop();
                a.display();
                break;
            case 3:
                try{
                    cout << a.peek();
                }
                catch(int e){
                    cout << "stack is empty.";
                }
                break;
            default:
                a.display();
        }
        cout << endl;
    }
    return 0;
}

