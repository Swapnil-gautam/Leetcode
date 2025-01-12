/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* dfs(Node* node, unordered_map<Node*, Node*>& mp){
        Node* NewNode = new Node(node->val);
        mp[node] = NewNode;
       
        for(auto& neighbor: node->neighbors){
            if(mp.find(neighbor)==mp.end()){
                (NewNode->neighbors).push_back(dfs(neighbor, mp));
            }else{
                (NewNode->neighbors).push_back(mp[neighbor]);
            }
        }
        return NewNode;
    }

    Node* cloneGraph(Node* node) {
        if(node==NULL) return NULL;
        unordered_map<Node*, Node*> mp;
        return dfs(node, mp);
    }
};