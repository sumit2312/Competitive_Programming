// https://practice.geeksforgeeks.org/problems/stack-using-two-queues/1

//  Making the push operation costly

/* In this method we always push in q2.And after pushing we push all the elements of q1 to q2 which makes q1 empty
   and then we swap these queue which make q2 empty . and the recent inserted element is in front of q1 => so pop from q1.
   and hence q2 becomes empty we make push in this queue. And again process continues   
*/
   


/* The structure of the class is
class QueueStack{
private:
    queue<int> q1;
    queue<int> q2;
public:
    void push(int);
    int pop();
};
 */

/* The method push to push element into the stack */
void QueueStack :: push(int x)
{
    q2.push(x);
    while(!q1.empty()){
        q2.push(q1.front());
        q1.pop();
    }
    queue<int> temp;
    temp = q1;
    q1 = q2;
    q2 = temp;
}

/*The method pop which return the element poped out of the stack*/
int QueueStack :: pop()
{
    if(q1.empty()){
        return -1;
    }
    int x = q1.front();
    q1.pop();
    return x;
}
