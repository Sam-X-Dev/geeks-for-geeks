/* Structure of Binary Tree Node
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};*/

class Solution {
  public:
    vector<int> leftView(Node *root) {
        vector<int> ans;

        if (root == nullptr)
            return ans;

        queue<Node*> q;
        q.push(root);

        while (!q.empty()) {

            int size = q.size();

            for (int i = 0; i < size; i++) {

                Node* curr = q.front();
                q.pop();

                if (i == 0)
                    ans.push_back(curr->data);

                if (curr->left != nullptr)
                    q.push(curr->left);

                if (curr->right != nullptr)
                    q.push(curr->right);
            }
        }

        return ans;
    }
};