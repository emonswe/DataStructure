//code for min heap
//implement using array

//here index start from 1 for important facilities.
 //value 100  200  50   70     250      300    150
 //index [1]   [2]  [3] [2*2] [2*2+1]  [2*3] [2*3+1]

#include<iostream>

using namespace std;

//function to determine left child of a node
int left_child(int a);

//function to determine right child of a node
int right_child(int a);

//this function use for determine smallest value(min heap)
// among root,left child,right child and replace that value to root.this is recursive function.
int heapify(int heap[],int heap_size,int i);

//this function use to build heap.
void heap_build(int heap[],int heap_size);

/* we can use this to know parent index for a node
int parent(int a)
{
    return a/2;
}
*/
//code start execute from main function
int main()
{
    //declare heap max size 100
    int n,heap[100];
    cin>>n;
    //input value index start from 1.
    for(int i=1;i<=n;i++)
    {
        cin>>heap[i];
    }

    //call heap builder function
    heap_build(heap,n);

    //print heap after build
    for(int i=1;i<=n;i++)
        cout<<heap[i]<<" ";

}


int left_child(int a)
{
    return a*2;
}

int right_child(int a)
{
    return a*2+1;
}


int heapify(int heap[],int heap_size,int i)
{
    int l,r,smallest,t;

    l=left_child(i);
    r=right_child(i);

    if(l<=heap_size && heap[l]<heap[i]) //if left child > root
        smallest=l; //left will be smallest
    else
        smallest=i; //root will be smallest

    if(r<=heap_size && heap[r]<heap[smallest]) // if right child > pre-compared smallest value
        smallest=r; //right will be smallest value

    if(smallest!=i)
    {
        //swap smallest node with root
        t=heap[i];
        heap[i]=heap[smallest];
        heap[smallest]=t;

        //this function call itself and pass smallest node as root for heapify
        heapify(heap,heap_size,smallest);
    }
    //if smallest==i then this function will return to its caller
}

void heap_build(int heap[],int heap_size)
{

    //this function start from heap_size/2. this index will be root of
    // last smallest sub tree.
    for(int i=heap_size/2;i>=1;i--)
    {
        heapify(heap,heap_size,i);
    }
}
