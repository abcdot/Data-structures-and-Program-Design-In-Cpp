#include "binary_tree.h"
/*
1、二叉查找树有哪些特点？
2、二叉查找树的时间复杂度是？
3、如何构建二叉查找树？ 
4、在构建的过程中应注意哪些问题？？？
5、如何提高二叉查找树的查找效率？
*/

template <class Record>
// 这里使用 public 继承，对比与 python or go 的继承的不同写法，以及各种什么特点，实现上有什么差别，
// 如 cpp 中 private 或 protected 内的函数 可以被派生类进行直接调用吗？
// python or go 中是如何实现继承也无法调用的函数的？ 首先是可以实现吗？ TODO 这里需要查一下资料
class Search_tree : public Binary_tree<Record>
{
private:
  /* data */
public:
  // 又是构造函数 对比 python 类中的 def __init__(self):
  // 枚举类型的返回值
  Error_code insert(const Record &new_data);
  Error_code remove(const Record &old_data);
  Error_code tree_search(Record &target) const;
  // Binary_node<Record> search_for_node(Binary_node<Record> *sub_root, const Record &target) const;

  Search_tree(/* args */);
  // 析构函数
  ~Search_tree();
};

// template <class Record>
// Search_tree::Search_tree(/* args */)
// {
// }

// Search_tree::~Search_tree()
// {
// }

// 递归版的 search ? 啥情况，怎么不兼容？ ❌
// template <class Record>
// Binary_node<Record> *Search_tree<Record>::search_for_node(Binary_node<Record> *sub_root, const Record &target) const
// {
//   if (sub_root == NULL || sub_root->data == target)
//     return sub_root;

//   else if (sub_root->data < target)
//     return search_for_node(sub_root->right, target);
//   else
//     return search_for_node(sub_root->left, target);
// }

// 非递归版的 search
// template <class Record>
// Binary_node<Record> *Search_tree<Record>::search_for_node_2(Binary_node<Record> *sub_root, const Record &target) const
// {
//   while (sub_root != NULL && sub_root->data != target)
//   {
//     if (sub_root->data < target)
//       sub_root = sub_root->right; // 大数往右找
//     else
//       sub_root = sub_root->left; // 小的数往左找
//   }
//   return sub_root;
// }