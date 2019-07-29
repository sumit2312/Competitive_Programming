// Question  -  https://leetcode.com/problems/lru-cache/
// More about splice - https://www.geeksforgeeks.org/list-splice-function-in-c-stl/
// https://www.youtube.com/watch?v=S6IfqDXWa10
class LRUCache {
    int capacity;
    list<pair<int,int>> li;
    unordered_map<int, list<pair<int,int>>::iterator> um;
public:
    LRUCache(int capacity) : capacity{capacity} {}
    
    int get(int key) {
        if(um.find(key)==um.end()) return -1;
        li.splice(li.begin(),li,um[key]); // put um[key] to the front
        return um[key]->second;
    }
    
    void put(int key, int value) {
        if(get(key)!=-1){
            um[key]->second = value;
            return;
        }
        
        if(um.size()==capacity){
            int delKey = li.back().first;
            li.pop_back();
            um.erase(delKey);
        }
        li.emplace_front(key, value);
        um[key] = li.begin();
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
 /------------------------------------------------------------------------------------------------------------------------/
 
 It is a cache replacement policy that says to evict the least recently used item in the cache.

Every time an item is used it goes to the "front" of the cache since it has been used and has priority.

Items that are not used will go to the "end" of the cache eventually and get evicted since they are the least used items, they never got a bump up by being used.

Additional Cache Eviction Policies: https://en.wikipedia.org/wiki/Cache_r...


What is a Cache?

A cache is a hardware or software component that stores data so that future requests for that data can be served faster; the data stored in a cache might be the result of an earlier computation or a copy of data stored elsewhere.


What Is An LRU Cache?

So a LRU Cache is a storage of items so that future access to those items can be serviced quickly and an LRU policy is used for cache eviction.


The Constraints/Operations

Lookup of cache items must be O(1)
Addition to the cache must be O(1)
The cache should evict items using the LRU policy


The Approach

There are many ways to do this but the most common approach is to use 2 critical structures: a doubly linked list and a hashtable.


Our Structures

Doubly Linked List: This will hold the items that our cache has. We will have n items in the cache.

This structure satisfies the constraint for fast addition since any doubly linked list item can be added or removed in O(1) time with proper references.

Hashtable: The hashtable will give us fast access to any item in the doubly linked list items to avoid O(n) search for items and the LRU entry (which will always be at the tail of the doubly linked list).

This is a very common pattern, we use a structure to satisfy special insertion or remove properties (use a BST, linked list, etc.) and back it up with with a hashtable so we do not re-traverse the structures every time to find elements.


Complexities

Time

Both get and put methods are O( 1 ) in time complexity.

Space

We use O( n ) space since we will store n items where n ist the capacity of the cache.
