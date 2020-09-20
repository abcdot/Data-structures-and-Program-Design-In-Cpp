template <class Entry>
struct Binary_node
{
  // data members
  Entry data;
  Binary_node<Entry> *left;
  Binary_node<Entry> *right;
  // consructors
  Binary_node();
  Binary_node(const Entry &x);
};

// 模版类
template <class Entry>
class Binary_tree
{
public:
  // Add metheds here
  // 构造函数 初始化时使用
  Binary_tree();

  // 二叉树是否为空
  bool empty() const;

  // 二叉树的宽度
  int width();

  // 二叉树的高度
  int height() const;

  // 二叉树所有结点个数
  int size() const;

  // 二叉树叶子结点数
  int leaf_count() const;

  // 前序遍历
  void preorder(void (*vist)(Entry &));

  // 中序遍历
  void inorder(void (*vist)(Entry &));

  // 后序遍历
  void postorder(void (*vist)(Entry &));

  // 层次遍历
  void level_travrse(void (*visit)(Entry &));

  // 清除二叉树所有结点
  void clear();

  // 插入新结点
  void insert(const Entry &);

  // 交换二叉树的左右子树
  void interchange();

  // 复制构造函数
  Binary_tree(const Binary_tree<Entry> &original);

  // 赋值运算符重载函数
  Binary_tree &operator=(const Binary_tree<Entry> &original);

  // 析构函数 对象销毁时使用
  ~Binary_tree();

protected:
  // Add axuiliary function prototypes here
  Binary_tree<Entry> *root;

  void recursive_inorder(Binary_node<Entry> *sub_root, void (*visit)(Entry &));

  void recursive_preorder(Binary_node<Entry> *sub_root, void (*visit)(Entry &));

  void recursive_postorder(Binary_node<Entry> *sub_root, void (*visit)(Entry &));

  int recursive_size(Binary_node<Entry> *sub_root) const;

  int recursive_leaf_count(Binary_node<Entry> *sub_root) const;

  int recursive_height(Binary_node<Entry> *sub_root) const;
  void recursive_clear(Binary_node<Entry> *&sub_root);
};

// 模版类的声明与实现 最好不要分离 // TODO
// https://www.zhihu.com/question/20630104
template <class Entry>
Binary_tree<Entry>::Binary_tree()
/* Post: An empty binary tree has been created.*/
{
  root = NULL;
}

template <class Entry>
bool Binary_tree<Entry>::empty() const
/*Post: A result of true is returned if the binary tree is empty.Othrewise, false is return. */
{
  return root == NULL;
}

template <class Entry>
/*Post: The tree has been been traversed in infix order sequence.
 * Use: The function recursive_inorder
 */
void Binary_tree<Entry>::inorder(void (*visit)(Entry &))
{
  // C++ 需要 ; 作为结束符
  recursive_inorder(root, visit);
}

// C++ 的类方法主要是在类外进行定义，在类内进行声明, 在类内可以直接写函数体吗？可以。内联函数。
// 返回类型  类名:: 函数名（参数类型 形参）
template <class Entry>
void Binary_tree<Entry>::recursive_inorder(Binary_node<Entry> *sub_root, void (*visit)(Entry &))
{
  if (sub_root != NULL)
  {
    recursive_order(sub_root->left, visit);
    (*visit)(sub_root->data);
    recursive_order(sub_root->right, visit);
  }
}

template <class Entry>
/*Post: The tree has been been traversed in infix order sequence.
 * Use: The function recursive_preorder
 */
void Binary_tree<Entry>::preorder(void (*visit)(Entry &))
{
  // C++ 需要 ; 作为结束符
  recursive_preorder(root, visit);
}

template <class Entry>
void Binary_tree<Entry>::recursive_preorder(Binary_node<Entry> *sub_root, void (*visit)(Entry &))
{
  if (sub_root != NULL)
  {
    (*visit)(sub_root->data);
    recursive_order(sub_root->left, visit);
    recursive_order(sub_root->right, visit);
  }
}
template <class Entry>
/*Post: The tree has been been traversed in infix order sequence.
 * Use: The function recursive_postorder
 */
void Binary_tree<Entry>::postorder(void (*visit)(Entry &))
{
  // C++ 需要 ; 作为结束符
  recursive_postorder(root, visit);
}

template <class Entry>
void Binary_tree<Entry>::recursive_postorder(Binary_node<Entry> *sub_root, void (*visit)(Entry &))
{
  if (sub_root != NULL)
  {
    recursive_order(sub_root->left, visit);
    recursive_order(sub_root->right, visit);
    (*visit)(sub_root->data);
  }
}

// 统计链式二叉树所有的结点数
template <class Entry>
int Binary_tree<Entry>::size() const // 为什么要在这里添加 const？
{
  recursive_size(root);
}

template <class Entry>
int Binary_tree<Entry>::recursive_size(Binary_node<Entry> *sub_root) const // 这里的形式参数为什么要用指针类型？
{
  if (sub_root == NULL)
    return 0;
  return 1 + recursive_size(sub_root->left) + recursive_size(sub_root->right);
}

//统计链式二叉树叶子数
template <class Entry>
int Binary_tree<Entry>::recursive_leaf_count(Binary_node<Entry> *sub_root) const
{
  if (sub_root == NULL)
    return 0;

  if (sub_root->left == NULL && sub_root->right == NULL)
    return 1;

  return recursive_leaf_count(sub_root->left) + recursive_leaf_count(sub_root->right);
}

template <class Entry>
int Binary_tree<Entry>::leaf_count() const
{
  return recursive_leaf_count(root);
}

// 链式二叉树的高度
template <class Entry>
int Binary_tree<Entry>::height() const
{
  return recursive_height(root);
}

template <class Entry>
int Binary_tree<Entry>::recursive_height(Binary_node<Entry> *sub_root) const
{
  if (sub_root == NULL)
    return 0;

  int l = recursive_height(sub_root->left);
  int r = recursive_height(sub_root->right);

  if (l > r)
    return l + 1;
  else
    return r + 1;
}

// 层次遍历
template <class Entry>
void Binary_tree<Entry>::level_travrse(void (*visit)(Entry &))
{
  Binary_node<Entry> *sub_root;

  if (root != NULL)
  {
    // TODO 这里的 Queue 没有引入啊为啥不报错嘞？是否是需要编译才能发现？ 需要查资料
    Queue<Binary_node<Entry> *> waiting_nodes;
    waiting_nodes.append(root);
    do
    {
      waiting_nodes.retrieve(sub_root);

      (*visit)(sub_root->data);

      if (sub_root->left)
        waiting_nodes.append(sub_root->left);

      if (sub_root->right)
        waiting_nodes.append(sub_root->right);

      waiting_nodes.serve();

    } while (!waiting_nodes.empty())
  }
}

// 交换左右孩子
template <class Entry>
void Binary_tree<Entry>::interchange()
{
  return recursive_interchange(root)
}

template <class Entry>
void recursive_interchange(Binary_node<Entry> *sub_root)
{
  if (sub_root != NULL)
  {
    Binary_node<Entry> *temp = sub_root->left;

    sub_root->left = sub_root->right;
    sub_root->right = tmp;

    recursive_interchange(sub_root->left);
    recursive_interchange(sub_root->right);
  }
}

// 宽度
/*
 * 解题思路：，宽度即某一层结点的最大数目，使用层次遍历的思想
 * 1、 使用两个队列，current_level 记录当前层的结点数， next_level 记录下一层结点数
 * 2、 先将根结点添加到 current_level 中，更新 max_level
 * 3、 对 current_level 进行遍历，依次取出队列中的结点，并判断取出的结点是否具有左右孩子结点，
 *    若存在，则将其左右孩子结点分别添加到 next_level 队列中；
 *    若不存在，直接从 current_level 出队列。（思考，不存的话是在什么情况下不存在？）
 * 4、当 current_level 为空时，将 next_level 负值给 current_level, 继续执行 1，2，3，4
 *    直至 currnet_level 与 next_level 都为空为止。 
 */
template <class Entry>
int Binary_tree<Entry>::width()
{
  if (root == NULL)
    return 0;

  Extended_queue<Binary_node<Entry> *> current_level;

  current_level.append(root);

  int max_level = 0;

  while (current_level.size() != 0)
  {
    if (current_level.size() > max_level)
      max_level = current_level.size();

    Extended_queue<Binary_node<Entry> *> next_level;

    do
    {
      Binary_node<Entry> *sub_root;
      current_level.retrieve(sub_root);

      if (sub_root->left)
        next_level.append(sub_root->left);
      if (sub_root->right)
        next_level.append(sub_root->right);

      current_level.serve();
    } while (!current_level.empty())

        current_level = next_level
  }

  return max_level
}

// 清除所有结点
// 析构函数
template <class Entry>
Binary_tree<Entry>::~Binary_tree() // ~ 这是英文符号， 打成中文的了  fuck！！！
{
  clear();
}

template <class Entry>
void Binary_tree<Entry>::clear()
{
  recursive_clear(root);
}

template <class Entry>
void Binary_tree<Entry>::recursive_clear(Binary_node<Entry> *&sub_root) // 这里为什么使用 *& 指针 + 引用？
{
  Binary_node<Entry> *temp = sub_root;
  if (sub_root == NULL)
    return;

  recursive_clear(sub_root->left);
  recursive_clear(sub_root->right);

  sub_root = NULL;

  delete temp;
}

// 赋值重载
template <class Entry>
Binary_tree<Entry> &Binary_tree<Entry>::operator=(const Binary_tree<Entry> &original) //这里传的是对象
{
  Binary_tree<Entry> new_copy(original);
  clear();
  root = new_copy.root;
  new_copy.root == NULL;
  return *this;
  // 这里看到了 this。对比与 python 的类内方法的书写，python 需要使用 self 那么 C++ 在调用类内方法的时候，是隐藏了 this吗？
  // TODO 需要查资料
}
