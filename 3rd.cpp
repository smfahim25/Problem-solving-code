#include <bits/stdc++.h>
using namespace std;

int countPairs(int arr[], int n, int k)
{
    int pairs = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (arr[i] + arr[j] == k)
            {
                pairs++;
            }
        }
    }
    return pairs;
}

int merge(int arr[], int temp[], int left, int mid, int right, int k)
{
    int i, j, count = 0;
    int left_end = mid - 1;
    int temp_pos = left;
    int size = right - left + 1;

    while ((left <= left_end) && (mid <= right))
    {
        if (arr[left] <= arr[mid])
        {
            temp[temp_pos++] = arr[left++];
        }
        else
        {
            temp[temp_pos++] = arr[mid++];
            count += (left_end - left + 1);
        }
    }

    while (left <= left_end)
        temp[temp_pos++] = arr[left++];

    while (mid <= right)
        temp[temp_pos++] = arr[mid++];

    for (i = 0; i < size; i++)
    {
        arr[right] = temp[right];
        right--;
    }

    return count;
}

void merge_sort(int arr[], int temp[], int left, int right, int k)
{
    int mid;
    if (right > left)
    {
        mid = (right + left) / 2;
        merge_sort(arr, temp, left, mid, k);
        merge_sort(arr, temp, mid + 1, right, k);
        merge(arr, temp, left, mid + 1, right, k);
    }
}

int main()
{
    int n, k;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cin >> k;
    int temp[n];
    int pairs = countPairs(arr, n, k);
    merge_sort(arr, temp, 0, n - 1, k);
    cout << pairs << endl;
    return 0;
}
