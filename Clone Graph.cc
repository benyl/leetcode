/*
Clone Graph

http://oj.leetcode.com/problems/clone-graph/

Clone an undirected graph. Each node in the graph contains a label and a list of its neighbors.


OJ's undirected graph serialization:
Nodes are labeled from 0 to N - 1, where N is the total nodes in the graph.

We use # as a separator for each node, and , as a separator for each neighbor of the node.
As an example, consider the serialized graph {1,2#2#2}.

The graph has a total of three nodes, and therefore contains three parts as separated by #.

Connect node 0 to both nodes 1 and 2.
Connect node 1 to node 2.
Connect node 2 to node 2 (itself), thus forming a self-cycle.
Visually, the graph looks like the following:

       1
      / \
     /   \
    0 --- 2
         / \
         \_/
*/

/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
class Solution {
public:
    unordered_map<int, UndirectedGraphNode *> cloneNode;
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        cloneNode.clear();
        return doClone(node);
    }
    
    UndirectedGraphNode *doClone(UndirectedGraphNode *node) {
        if(!node) return NULL;
        
        if(cloneNode.count(node->label)!=0)
            return cloneNode[node->label];
        
        UndirectedGraphNode *clone = new UndirectedGraphNode(node->label);
        cloneNode[node->label] = clone;
        
        for(int i=0; i<node->neighbors.size(); ++i)
            clone->neighbors.push_back(doClone(node->neighbors[i]));
        
        return clone;
    }
};