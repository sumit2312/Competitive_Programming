              ASCII values
     0 - 9    :    48 - 57
     A - Z    :    65 - 90
     a - z    :    97 - 122

       
---------------------------------- BITWISE OPERATIONS ---------------------------
       x<<y - x*2^y
       x>>y - x/2^y
       
----------------------------       STRING        --------------------------------------

 ------ isalnum()  --------
The isalphanum() function returns a non-zero integer if an argument (character) passed to the function is an alphanumeric (alphabet and number) character.

//Removing a particular character fom a string
string s;
char c;
s.erase(remove(s.begin(), s.end(), c), s.end());

// TRANSFORM TO lowercase
transform(s.begin(), s.end(), s.begin(), ::tolower);

// TRANSFORM TO UPPERCASE
transform(s.begin(), s.end(), s.begin(), ::toupper);
-----------------------------------------------------------------------


// Set 
set<int> s;
s.insert()
s.erase()
// Find if an element is in the set
set.find(x)!=s.end()  //Element is in the set



---------------------------------------------------------------------------------------------------

//  STACK 

empty() – Returns whether the stack is empty – Time Complexity : O(1)
size() – Returns the size of the stack – Time Complexity : O(1)
top() – Returns a reference to the top most element of the stack – Time Complexity : O(1)
push(g) – Adds the element ‘g’ at the top of the stack – Time Complexity : O(1)
pop() – Deletes the top most element of the stack – Time Complexity : O(1)


----------------------------------------------------------------------------------------------------

//  QUEUE

empty() – Returns whether the queue is empty.
size() – Returns the size of the queue.
queue::swap() in C++ STL: Exchange the contents of two queues but the queues must be of same type, although sizes may differ.
queue::emplace() in C++ STL: Insert a new element into the queue container, the new element is added to the end of the queue.
queue::front() and queue::back() in C++ STL– front() function returns a reference to the first element of the queue. back() function returns a reference to the last element of the queue.
push(g) and pop() – push() function adds the element ‘g’ at the end of the queue. pop() function deletes the first element of the queue.


-----------------------------------------              DEQUE             -----------------------------

std::deque<value_type>
deque<int> mydeque; //Creates a double ended queue of deque of int type
int length = mydeque.size(); //Gives the size of the deque

Push
mydeque.push_back(1); //Pushes element at the end
mydeque.push_front(2); //Pushes element at the beginning


Pop
mydeque.pop_back(); //Pops element from the end
mydeque.pop_front(); //Pops element from the beginning

Empty
mydeque.empty() //Returns a boolean value which tells whether the deque is empty or not
