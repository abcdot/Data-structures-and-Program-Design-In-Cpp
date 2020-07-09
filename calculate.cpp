#include <iostream>
#include <cctype>
#include "stack_demo.h"

char get_commond()
{
  char command;
  bool waiting = true;
  cout << "选择对应的命令，然后敲击<回车>：" << endl;
  cout << "请输入有效的命令:" << endl
       << "[?]入栈[=]打印top" << endl
       << "[+][-][*][/]是运算符号" << endl
       << "[Q] 退出" << endl;
  while (waiting)
  {
    cin >> command;
    command = tolower(command);
    if (command == '?' || command == '=' || command == '+' || command == '-' ||
        command == '*' || command == '/' || command == 'q' || command == 'q')
      waiting = false;
    else
    {
      cout << "请输入有效的命令:" << endl
           << "[?]入栈[=]打印top" << endl
           << "[+][-][*][/]是运算符号" << endl
           << "[Q] 退出" << endl;
    }
  }
  return command;
}

bool do_command(char command, Stack &numbers)
{
  double p, q;
  switch (command)
  {
  case '?':
    cout << "Enter a real number:" << flush;
    cin >> p;
    if (numbers.push(p) == overflow)
      cout << "Warning:Stack full, lost number." << endl;
    break;
  case '=':
    if (numbers.top(p) == underflow)
      cout << "Stack empty." << endl;
    else
      cout << p << endl;
    break;
  case '+':
    if (numbers.top(p) == underflow)
      cout << "Stack empty." << endl;
    else
    {
      numbers.pop();
      if (numbers.top(q) == underflow)
      {
        cout << "Stack has just one entry." << endl;
        numbers.push(p);
      }
      else
      {
        numbers.pop();
        if (numbers.push(p + q) == overflow)
          cout << "Warning:Stack full, lost result." << endl;
      }
    }
    break;
  case 'q':
    cout << "Calculation finished.\n";
    return false;
  }
  return true;
}

int main()
{
  Stack stored_numbers;
  // introduction();
  // instructions();
  while (do_command(get_commond(), stored_numbers))
    ;
}
