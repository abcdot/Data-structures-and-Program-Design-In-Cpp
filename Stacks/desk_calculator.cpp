

#include <iostream>
#include <cctype>

typedef double Stack_entry;
#include "stack_demo.h"

char get_commond()
{
  char command;
  bool waiting = true;

  cout << "Select command and press <Enter>：" << endl
       << "[?]push to stack [=]print top" << endl
       << "[+][-][*][/] are arithmetic operations" << endl
       << "[Q] Quit" << endl;

  while (waiting)
  {
    cin >> command;
    command = tolower(command);
    if (command == '?' || command == '=' || command == '+' || command == '-' ||
        command == '*' || command == '/' || command == 'q' || command == 'q')
      waiting = false;
    else
    {
      cout << "Please enter a valid command:" << endl
           << "[?]push to stack[=]print top" << endl
           << "[+][-][*][/] are arithmetic operations" << endl
           << "[Q] Quit" << endl;
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
