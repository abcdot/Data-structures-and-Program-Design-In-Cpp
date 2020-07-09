const int maxstack = 10;
// typedef char Stack_entry;
typedef double Stack_entry;

typedef enum Error_code
{
  success,
  overflow,
  underflow
} outcome;

using namespace std;

class Stack
{
public:
  Stack();
  bool empty() const;
  Error_code pop();
  Error_code top(Stack_entry &item) const;
  Error_code push(const Stack_entry &item);

private:
  int count;
  Stack_entry entry[maxstack];
};

Error_code Stack::push(const Stack_entry &item)
{
  Error_code outcome = success;
  if (count >= maxstack)
    outcome = overflow;
  else
    entry[count++] = item;
  return outcome;
}

Error_code Stack::pop()
{
  Error_code outcome = success;
  if (count == 0)
    outcome = underflow;
  else
    --count;
  return outcome;
}

Error_code Stack::top(Stack_entry &item) const
{
  Error_code outcome = success;
  if (count == 0)
    outcome = underflow;
  else
    item = entry[count - 1];
  return outcome;
}

bool Stack::empty() const
{
  bool outcome = true;
  if (count != 0)
    outcome = false;
  return outcome;
}

Stack::Stack()
{
  count = 0;
}
