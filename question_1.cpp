#include <iostream>
using namespace std;

int getMaxLength(int arr[], int n);
int main()
{
  int a[11] = {9, 8, 8, 8, 8, 7, 3, 3, 1, 1, 1};
  int n = 11;
  int b = getMaxLength(a, n);
  cout << "最长平台：" << b << endl;
  return 0;
}

int getMaxLength(int arr[], int n)
{
  int num = 0;
  int tmp = arr[0];
  int max_lengh = 0;

  for (int i = 0; i < n; i++)
  {
    if (arr[i] == tmp)
    {
      num++;
    }
    else
    {
      tmp = arr[i];
      if (num > max_lengh)
      {
        max_lengh = num;
      }
      num = 1;
    }
    if (num > max_lengh)
    {
      max_lengh = num;
    }
  }
  cout << max_lengh << endl;
  return max_lengh;
}