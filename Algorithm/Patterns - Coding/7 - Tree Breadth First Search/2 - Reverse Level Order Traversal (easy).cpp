Given a binary tree, populate an array to represent its level-by-level traversal in reverse order, i.e., the lowest level comes first. You should populate the values of all nodes in each level from left to right in separate sub-arrays.

deque<vector<int>> traverse(TreeNode *root) {
  deque<vector<int>> result = deque<vector<int>>();
  if (root == nullptr) {
    return result;
  }

  queue<TreeNode *> queue;
  queue.push(root);
  while (!queue.empty()) {
    int levelSize = queue.size();
    vector<int> currentLevel;
    for (int i = 0; i < levelSize; i++) {
      TreeNode *currentNode = queue.front();
      queue.pop();
      // add the node to the current level
      currentLevel.push_back(currentNode->val);
      // insert the children of current node to the queue
      if (currentNode->left != nullptr) {
        queue.push(currentNode->left);
      }
      if (currentNode->right != nullptr) {
        queue.push(currentNode->right);
      }
    }
    // append the current level at the beginning
    result.push_front(currentLevel);
  }

  return result;
}

Time complexity #
The time complexity of the above algorithm is O(N), where ‘N’ is the total number of nodes in the tree. This is due to the fact that we traverse each node once.

Space complexity #
The space complexity of the above algorithm will be O(N) as we need to return a list containing the level order traversal. We will also need O(N) space for the queue. Since we can have a maximum of N/2 nodes at any level (this could happen only at the lowest level), therefore we will need O(N) space to store them in the queue.
