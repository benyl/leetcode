/*
Copy List with Random Pointer 

http://oj.leetcode.com/problems/copy-list-with-random-pointer/

A linked list is given such that each node contains an additional random pointer which could point to any node in the list or null.

Return a deep copy of the list.
*/

/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
public:
    unordered_map<RandomListNode *, RandomListNode *> nodeMap;
    RandomListNode *copyRandomList(RandomListNode *head) {
        if(!head) return NULL;
        
        nodeMap.clear();
        nodeMap.insert(make_pair((RandomListNode *) NULL, (RandomListNode *) NULL));
        
        for(RandomListNode *p=head; p!=NULL; p=p->next) // build orign node to clone node mapping
            nodeMap.insert(make_pair(p, new RandomListNode(p->label)));
        
        for(RandomListNode *p=head; p!=NULL; p=p->next) { // link clone node according to orign node
            nodeMap[p]->next = nodeMap[p->next];
            nodeMap[p]->random = nodeMap[p->random];
        }
        return nodeMap[head];
    }
};