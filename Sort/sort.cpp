template <class T>
// 直接插入排序
void insertionSort(T a[], int n)
{
  for (int i = 1; i < n; i++)
  {
    // 临时变量存储待排元素
    T temp = a[i];

    // 对 j 进行初始化
    int j = i;

    // 查找插入位置
    while (j > 0 && temp < a[j - 1])
    {
      a[j] = a[j - 1];
      j--;
    }

    // 将元素插入到该位置
    a[j] = temp;
  }
}

// 简单选择排序
template <class T>
void mySwap(T &a, T &b)
{
  T temp = a;
  a = b;
  b = temp;
}

template <class T>
void selectionSort(T a[], int n)
{
  for (int i = 0; i < n - 1; i++)
  {
    int min_num_index = i;
    for (int j = i + 1; j < n; j++)
    {
      if (a[j] < a[min_num_index])
      {
        min_num_index = j
      }
    }

    mySwap(a[i], a[min_num_index]);
    /* code */
  }
}

// 冒泡排序

template <class T>
void bubbleSort(T a[], int n)
{
  int i = n - 1;
  while (i > 0)
  {
    int last_change_index = 0;
    for (int j = 0; j < n; j++)
    {
      if (a[j + 1] < a[j])
      {
        mySwap(a[j], a[j + 1]);
        last_change_index = j;
      }
      i = last_change_index;
    }
  }
}