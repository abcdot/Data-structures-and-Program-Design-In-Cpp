#include <stack>
#include <iostream>

using namespace std;

// main() 是程序开始执行的地方
int main()
{
  int n;
  double item;

  stack<double> numbers; // 数据结构 <元素类型> 名称
  cout << "输入 n 个数据，反转后输出" << endl
       << "请在下面一行输入反转数据的个数:" << endl; // 输出
  cin >> n;                                          //输入数据的个数

  // 循环入栈
  for (int i = 0; i < n; i++)
  {
    cin >> item; // 在输入界面可以回车 or 空格
    numbers.push(item);
  }

  cout << endl
       << endl; // 在输出页面显示两行空格

  // 循环出栈
  while (!numbers.empty())
  {
    cout << numbers.top() << " ";
    numbers.pop(); // pop 出去无返回值 fuck
  }

  cout << endl;
  return 0;
}
