#include <bits/stdc++.h>
using namespace std;

vector<int> subsets;

void generateSubsets(int index, int size, int arr[])
{

    if (index == size)
    {
        // then we have to print our subsets
        for (auto it : subsets)
        {

            cout << it << " ";
        }

        if (subsets.size() == 0)
            cout << "{}"<< " ";
        cout << endl;
    }

    else
    {
        subsets.push_back(arr[index]);
        // picking the current element
        // call for the next index
        generateSubsets(index + 1, size, arr);
        // not picking the current element
        subsets.pop_back();
        generateSubsets(index + 1, size, arr);
    }
}
int main()
{
    int arr[3] = {1, 2, 3};

    generateSubsets(0, 3, arr);

    return 0;
}
