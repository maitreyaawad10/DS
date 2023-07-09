#include <bits/stdc++.h>

using namespace std;

// TC : O(1)
// SC : O(N)
class LRUCache
{
public:
    class Node
    {
    public:
        int key;
        int value;
        Node *next;
        Node *prev;

        Node(int _key, int _val)
        {
            key = _key;
            value = _val;
        }
    };

    Node *head = new Node(-1, -1);
    Node *tail = new Node(-1, -1);

    int size;
    unordered_map<int, Node *> mp;

    LRUCache(int capacity)
    {
        size = capacity;
        head->next = tail;
        tail->prev = head;
    }

    // DLLL FUNCTIONS(PERSONALLY DEFINED FUNCTIONS)
    void addNode(Node *newNode)
    {
        newNode->next = head->next;
        newNode->next->prev = newNode;
        newNode->prev = head;
        head->next = newNode;
    }

    void deleteNode(Node *nodeToDelete)
    {
        nodeToDelete->prev->next = nodeToDelete->next;
        nodeToDelete->next->prev = nodeToDelete->prev;
    }

    int get(int key)
    {
        if (mp.find(key) != mp.end())
        {
            Node *curr = mp[key];
            int returnValue = curr->value;
            mp.erase(key);

            deleteNode(curr);
            addNode(curr);

            mp[key] = head->next;

            return returnValue;
        }

        return -1;
    }

    void put(int key, int value)
    {
        if (mp.find(key) != mp.end())
        {
            Node *existingNode = mp[key];
            mp.erase(key);

            deleteNode(existingNode);
        }

        if (mp.size() == size)
        {
            Node *LRU = tail->prev;
            mp.erase(LRU->key);

            deleteNode(LRU);
        }

        Node *newNode = new Node(key, value);
        addNode(newNode);
        mp[key] = newNode;
    }
};