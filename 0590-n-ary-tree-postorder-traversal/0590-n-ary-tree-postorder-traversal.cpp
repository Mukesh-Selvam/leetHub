class Solution {
public:
    vector<int> postorder(Node* root) {
        if (!root) return {};
        
        vector<int> result;
        stack<Node*> st;
        st.push(root);
        
        while (!st.empty()) {
            Node* node = st.top();
            st.pop();
            result.push_back(node->val);
            
            for (Node* child : node->children) {
                st.push(child);
            }
        }
        
        reverse(result.begin(), result.end());
        
        return result;
    }
};