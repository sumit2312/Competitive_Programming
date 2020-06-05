// https://practice.geeksforgeeks.org/problems/queue-using-two-stacks/1

// Making push operation costly


/* The structure of the class is
class StackQueue{
private:   
    // These are STL stacks ( http://goo.gl/LxlRZQ )
    stack<int> s1;
    stack<int> s2;
public:
    void push(int);
    int pop();
}; */

/* The method push to push element into the queue */
void StackQueue :: push(int x)
 {
        while(!s1.empty()){
            s2.push(s1.top());
            s1.pop();
        }
        s1.push(x);
        while(!s2.empty()){
            s1.push(s2.top());
            s2.pop();
        }
 }

/*The method pop which return the element poped out of the queue*/
int StackQueue :: pop()
{
    if(s1.empty()){
        return -1;
    }
    int x = s1.top();
    s1.pop();
    return x;
}


// Making pop operaion costly

void StackQueue :: push(int x)
 {
        s1.push(x);
 }

/*The method pop which return the element poped out of the queue*/
int StackQueue :: pop()
{
    if(s1.empty() && s2.empty()){
        return -1;
    }
    if(s2.empty()){
        while(!s1.empty()){
            s2.push(s1.top());
            s1.pop();
        }
    }
    int ans = s2.top();
    s2.pop();
    return ans;
}
