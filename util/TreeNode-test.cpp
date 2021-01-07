#include <gtest/gtest.h>

#include "TreeNode.cpp"

using namespace std;

bool operator==(const TreeNode &a, const TreeNode &b) {
  if (a.val != b.val) {
    return false;
  }

  if ((a.left == NULL) ^ (b.left == NULL)) {
    return false;
  }
  if (a.left != NULL && !((*a.left) == (*b.left))) {
    return false;
  }

  if ((a.right == NULL) ^ (b.right == NULL)) {
    return false;
  }
  if (a.right != NULL && !((*a.right) == (*b.right))) {
    return false;
  }

  return true;
}

/*
                  5
             4           8
         11     x      13      4
      7    2  x   x   x   1
*/
TEST(TreeNode, 5_4_8_11_null_13_4_7_2_null_null_null_1) {
  vector<vector<TreeNode>> x(8, vector<TreeNode>(8));

  // ROW 0
  x[0][0] = TreeNode(5);
  x[0][0].left = &x[1][0];
  x[0][0].right = &x[1][1];

  // ROW 1
  x[1][0] = TreeNode(4);
  x[1][0].left = &x[2][0];

  x[1][1] = TreeNode(8);
  x[1][1].left = &x[2][2];
  x[1][1].right = &x[2][3];

  // ROW 2
  x[2][0] = TreeNode(11);
  x[2][0].left = &x[3][0];
  x[2][0].right = &x[3][1];

  x[2][2] = TreeNode(13);
  x[2][2].right = &x[3][5];

  x[2][3] = TreeNode(4);

  // ROW 3
  x[3][0] = TreeNode(7);
  x[3][1] = TreeNode(2);
  x[3][5] = TreeNode(1);

  auto actual =
      TreeNode_from_string("[5,4,8,11,null,13,4,7,2,null,null,null,1]");
  EXPECT_EQ(x[0][0], *actual);
}
