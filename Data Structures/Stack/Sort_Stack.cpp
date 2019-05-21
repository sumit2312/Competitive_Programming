///**************ALGO********************//
Create a temporary stack say tmpStack.
1.While input stack is NOT empty do this:
2.Pop an element from input stack call it temp
  -while temporary stack is NOT empty and top of temporary stack is greater than temp,
    pop from temporary stack and push it to the input stack
  -push temp in temporary stack
3.The sorted numbers are in tmpStack

//*******************************************//

// This function return the sorted stack 
stack<int> sortStack(stack<int> &input) 
{ 
    stack<int> tmpStack; 
  
    while (!input.empty()) 
    { 
        // pop out the first element 
        int tmp = input.top(); 
        input.pop(); 
  
        // while temporary stack is not empty and top 
        // of stack is greater than temp 
        while (!tmpStack.empty() && tmpStack.top() > tmp) 
        { 
            // pop from temporary stack and push 
            // it to the input stack 
            input.push(tmpStack.top()); 
            tmpStack.pop(); 
        } 
  
        // push temp in tempory of stack 
        tmpStack.push(tmp); 
    } 
  
    return tmpStack; 
} 
