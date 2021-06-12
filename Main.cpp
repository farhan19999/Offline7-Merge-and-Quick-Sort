#include "SortingAlgorithm.h"

int main()
{
    while(1)
    {



        double qsort_time = 0;
        double msort_time = 0;



        int choice;
        cout<<" Choose one of the option to generate an Array : "<<endl;
        cout<<" 1. Ascending array"<<endl;
        cout<<" 2. Random array"<<endl;
        cout<<" 3. Descending array"<<endl;
        cout<<" 4. Quit"<<endl;
        cin>>choice;

        if(choice == 4)break;

        int n;
        cout<<" Enter n( numbers of integers) : "<<endl;
        cin>>n;

        vector<int>input_array(n);
        vector<int>mergeSortArray(n);
        vector<int>qsortArray(n);
        int* a = new int[n];


        srand(time(0));

       if(choice == 1)
        {
            int d;
            if(n>RAND_MAX) d = 1000;
            else d = RAND_MAX/n;
            for(int i = 0 ; i<n ; i++)
            {
                int t = i*d + rand()%d;
                input_array[i] = t;
                mergeSortArray[i] = t;
                qsortArray[i] = t;
                a[i] = t;
            }
        }

        else if(choice == 2)
        {
            for(int i = 0 ; i<n ; i++)
            {
                int t = rand();
                input_array[i] = t;
                mergeSortArray[i] = t;
                qsortArray[i] = t;
                a[i] = t;
            }
        }

        else if(choice == 3)
        {
            int d;
            if(n>RAND_MAX) d = 1000;
            else d = RAND_MAX/n;
            for(int i = n-1 ; i>=0 ; i--)
            {
                int t = i*d + rand()%d;
                input_array[i] = t;
                mergeSortArray[i] = t;
                qsortArray[i] = t;
                a[i] = t;
            }
        }




        clock_t mergeSortstart = clock();
        MergeSort(mergeSortArray, 0, mergeSortArray.size()-1);
        msort_time =(clock()-mergeSortstart)*1000/CLOCKS_PER_SEC;
        cout<<" Time required for merge sort = "<< msort_time<< " ms "<<endl;

        clock_t qSortstart = clock();
        gQuickSort(a, 0, qsortArray.size()-1);
        qsort_time =(clock()-qSortstart)*1000/CLOCKS_PER_SEC;
        cout<<" Time required for Quick sort = "<< qsort_time<< " ms "<<endl;

        cout<<"Do you want to print the array?(Y/N) "<<endl;
        char ch;
        cin >>ch;
        if(ch == 'Y' || ch =='y')
        {cout<<"Merge Sorted Array "<< " Quick Sorted Array"<<endl;
        for(int i = 0; i<n ; i++ )cout<<mergeSortArray[i]<<"   "<<qsortArray[i]<<endl;}

    }

    return 0;
}
