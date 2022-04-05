
#include <bits/stdc++.h>
using namespace std;

void combinationUtil(int arr[], int data[],
                     int start, int end,
                     int index, int r);

void printCombination(int arr[], int n, int r)
{

    int data[r];

    combinationUtil(arr, data, 0, n - 1, 0, r);
}

void combinationUtil(int arr[], int data[],
                     int start, int end,
                     int index, int r)
{

    if (index == r)
    {
        for (int j = 0; j < r; j++)
            cout << data[j] << " ";
        cout << endl;
        return;
    }

    for (int i = start; i <= end &&
                        end - i + 1 >= r - index;
         i++)
    {
        data[index] = arr[i];
        combinationUtil(arr, data, i + 1,
                        end, index + 1, r);
    }
}

int main()
{
    int s, x;
    cin >> s >> x;

    int arr[s];
    for (int i = 0; i < s; i++)
    {
        arr[i] = i + 1;
    }
    int n = sizeof(arr) / sizeof(arr[0]);
    printCombination(arr, n, x);
}
