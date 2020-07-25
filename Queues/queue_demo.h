const int maxqueue = 10;
typedef char Queue_entry;
typedef enum Error_code
{
  success,
  overflow,
  underflow
} outcome;

using namespace std;

class Queue
{
public:
  Queue();
  bool empty() const;
  Error_code serve();
  Error_code retrieve(Queue_entry &item) const;
  Error_code append(const Queue_entry &item);
  int size() const;

protected:
  int count;
  int front, rear;
  Queue_entry entry[maxqueue];
};

// class Extended_queue : public Queue
// {
// public:
//   bool full() const;
//   int size() const;
//   void clear();
//   Error_code serve_and_retrieve(Queue_entry &item);
// }

Queue::Queue()
{
  count = 0;
  rear = maxqueue - 1;
  front = 0;
}

bool Queue::empty() const
{
  // return count == 0;
  bool outcome = true;
  if (count != 0)
    outcome = false;
  return outcome;
}

Error_code Queue::append(const Queue_entry &item)
{
  Error_code outcome = success;
  if (count >= maxqueue)
    outcome = overflow;
  else
  {
    count++;
    rear = ((rear + 1) == maxqueue) ? 0 : (rear + 1);
    entry[rear] = item;
  }
  return outcome;
}

Error_code Queue::serve()
{
  Error_code outcome = success;
  if (count <= 0)
    outcome = underflow;
  else
  {
    count--;
    front = ((front + 1) == maxqueue) ? 0 : (front + 1);
  }
  return outcome;
}

Error_code Queue::retrieve(Queue_entry &item) const
{
  Error_code outcome = success;
  if (count <= 0)
    outcome = underflow;
  else
    item = entry[front];
  return outcome;
}

int Queue::size() const
{
  return count;
}
