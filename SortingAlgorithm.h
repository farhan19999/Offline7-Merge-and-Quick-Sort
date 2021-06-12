#include<bits/stdc++.h>
using namespace std;
void Merge(vector<int>&a, int start, int mid, int end);
int Partition(vector<int>&a, int start, int end);
int gfgpartition(int a[], int low,int high );

void MergeSort(vector<int>&a, int start, int end)
{
    if(start>=end)return;

    int mid = (start+end)/2;
    MergeSort(a, start, mid);
    MergeSort(a, mid+1, end);
    Merge(a, start, mid, end);

}

void Merge(vector<int>&a, int start, int mid, int end)
{
    int i = start;
    int j = mid+1;

    vector<int>temp(end-start+1);

    for(int k = 0 ;  k<temp.size() ; k++)
    {
        if(i>mid)          temp[k] = a[j++];
        else if(j>end)     temp[k] = a[i++];
        else if(a[i]<a[j]) temp[k] = a[i++];
        else               temp[k] = a[j++];
    }
    int t = 0;
    for(int k = start; k<=end ; k++)
    {
        a[k] = temp[t++];
    }
}

void QuickSort(vector<int>&a, int start, int end)
{
    if(start<end)
    {
        int i = Partition(a, start, end);
        QuickSort(a, start, i-1);
        QuickSort(a, i+1, end);
    }
}
void gQuickSort(int a[], int start, int end)
{
    if(start<end)
    {
        int i = gfgpartition(a, start, end);
        gQuickSort(a, start, i-1);
        gQuickSort(a, i+1, end);
    }
}

int Partition(vector<int>&a, int start, int end)
{
    //srand(time(0));
    //int pivot = start + rand()%(end-start+1);
    int pivot = end;
    int i = start-1;

    for(int k = start ; k<end ; k++)
    {
        //if(k == pivot)continue;
        if(a[k]<a[pivot])
        {
            i++;
            swap(a[k],a[i]);
        }
    }
    i++;

    swap(a[i], a[pivot]);

    return i;
}
int gfgpartition (int arr[], int low, int high)
{
    int pivot = arr[high]; // pivot
    int i = (low - 1); // Index of smaller element and indicates the right position of pivot found so far

    for (int j = low; j <= high - 1; j++)
    {
        // If current element is smaller than the pivot
        if (arr[j] < pivot)
        {
            i++; // increment index of smaller element
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return (i + 1);
}
void swap(int &a, int &b)
{
    int t = a;
    a = b;
    b = t;
}
