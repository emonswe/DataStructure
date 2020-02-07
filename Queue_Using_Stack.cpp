#include<iostream>
#include<stack>
using namespace std;

//here we define a type intStack as int type stack.
typedef stack<int> intStack;

//function for enqueue/push element to queue.
void enQ(intStack &s,int a);

//function for dequeue/pop element to queue
void deQ(intStack &s1,intStack &s2);

//code start execute from main function
int main()
{
    //declare two int type stack
    intStack s1,s2;

    //here n for switch case and value use for take input
    int n,value;

    cout<<"Enqueue:1"<<endl<<"Dequeue:2"<<endl<<"Exit:3"<<endl;
    /*
    enter
    Enqueue:1
    Dequeue:2
    Exit:3
    */

    while(cin>>n) //loop will continue until get exit command
    {
        switch(n)
        {
        case 1:
            {
                cout<<"Enter number: ";
                cin>>value;
                enQ(s1,value);
                break;
            }
        case 2:
            {
                deQ(s1,s2);
                break;
            }
        case 3:
            {
                exit(0);
            }
        default:
            cout<<"Invalid command"<<endl;
        }
    }
    return 0;

}
void enQ(intStack &s,int a)
{
    //push a value to first stack.push always happened in first stack.
    s.push(a);
}
void deQ(intStack &s1,intStack &s2)
{
    int a;
    if(s1.empty() && s2.empty())
    {
        cout<<"Warning! empty"<<endl;
        return;
    }
//if second stack is empty then element will replace from first stack to second stack
//then pop operation happened in second stack
//pop always happened in second stack
    if(s2.empty())
    {
        while(!s1.empty())
        {
            //fist push happened in second stack then pop happened in first stack
            //this process continue until fist stack get blank
            a=s1.top();
            s2.push(a);
            s1.pop();
        }
    }
    cout<<"Popped:"<<s2.top()<<endl;
    //pop element from second stack
    s2.pop();

}
