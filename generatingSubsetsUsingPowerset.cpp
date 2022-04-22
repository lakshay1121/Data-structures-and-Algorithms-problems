#include <bits/stdc++.h>
using namespace std;

vector<int> ans;

void generateSubsetsUsingPowerset(int size, int arr[])
{

    int index = 0;

    // first loop is for bits from 0 to 2^n - 1 which  can be written as ( 1<<n) - 1
    for (int bits = 0; bits < (1 << size); bits++)
    {

        // the second loop will iterate through all the elements of array
        for (index = 0; index < size; index++)
        {
            // now we will check if any element is having one in its bit representation then it mean that we will pick that element and if 0 exist , we don't pick that element
            if (bits & (1 << index))
            {
                // if that is == 1 we will push that in our answer
                ans.push_back(arr[index]);
            }
        }
    }

    for (auto it : ans)
    {
        cout << it << " ";
    }
}
int main()
{
    int arr[3] = {1, 2, 3};

    generateSubsetsUsingPowerset(3, arr);

    return 0;
}
