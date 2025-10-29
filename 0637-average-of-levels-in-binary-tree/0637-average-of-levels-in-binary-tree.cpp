/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<double> averageOfLevels(TreeNode* root) {
        // initialize variables
        queue<TreeNode*> q;  // queue of nodes
        vector<double> averages;  // vector of all averages of all levels
        double levelSum = 0;  // sum of all node values in a level
        double levelAverage;  // average of node values in a level
        int levelSize;  // number of nodes exist in a level

        // add the root of node to the queue
        q.push(root);

        // loop if sitll has node in the queue
        while (!q.empty()) {
            // initiate the number of nodes of current level based on the size of the queue
            levelSize = q.size();

            // loop for every node in this level - FIFO
            for (int i = 0; i < levelSize; ++i) {
                // select a node from the queue
                TreeNode* currentNode = q.front();
                // delete the selected node from the queue
                q.pop();

                // accummulate the sum of the selected node
                levelSum += currentNode->val;

                // if the node has left child node
                if (currentNode->left) {
                    // add to the queue for next round/ level calculation
                    q.push(currentNode->left);
                }
                // if the node has right child node
                if (currentNode->right) {
                    // add to the queue for next round/ level calculation
                    q.push(currentNode->right);
                }
            }
            // after looping every node of the level, calculate the average of all nodes in this level
            levelAverage = static_cast<double>(levelSum) / levelSize;
            // add the average value in the answer vector
            averages.push_back(levelAverage);
            // reset levelSum to 0
            levelSum = 0;
        }
        return averages;
    }
};