class Solution {
   public:
    Node* cloneGraph(Node* node) {
        if (node == nullptr) {
            return nullptr;
        }

        unordered_map<Node*, Node*> nodeMapping;
        queue<Node*> q;

        nodeMapping[node] = new Node(node->val);
        q.push(node);

        while (!q.empty()) {
            Node* curr = q.front();
            q.pop();

            for (Node* neighbor : curr->neighbors) {
                if (nodeMapping.find(neighbor) == nodeMapping.end()) {
                    nodeMapping[neighbor] = new Node(neighbor->val);
                    q.push(neighbor);
                }

                nodeMapping[curr]->neighbors.push_back(nodeMapping[neighbor]);
            }
        }

        return nodeMapping[node];
    }
};