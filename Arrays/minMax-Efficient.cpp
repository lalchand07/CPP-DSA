/*******************************************
Maximum and minimum of an Array
*******************************************/

#include <iostream>

using namespace std;

// class Pair to get min and max number to return from functin...
class Pair{
	public:
		int min;
		int max;
	void display(){
		cout<<"\nMax in Array is : "<<min<<endl;
		cout<<"Min in Array is : "<<max<<endl;
	}	
};

// getMinMax function code...
struct Pair getMinMax(int arr[], int low,
                                 int high)
{
    struct Pair minmax, mml, mmr;    
    int mid;
     
    // If there is only one element
    if (low == high)
    {
        minmax.max = arr[low];
        minmax.min = arr[low];    
        return minmax;
    }
     
    // If there are two elements
    if (high == low + 1)
    {
        if (arr[low] > arr[high])
        {
            minmax.max = arr[low];
            minmax.min = arr[high];
        }
        else
        {
            minmax.max = arr[high];
            minmax.min = arr[low];
        }
        return minmax;
    }
     
    // If there are more than 2 elements
    mid = (low + high) / 2;
    mml = getMinMax(arr, low, mid);
    mmr = getMinMax(arr, mid + 1, high);
     
    // Compare minimums of two parts
    if (mml.min < mmr.min)
        minmax.min = mml.min;
    else
        minmax.min = mmr.min;    
     
    // Compare maximums of two parts
    if (mml.max > mmr.max)
        minmax.max = mml.max;
    else
        minmax.max = mmr.max;    
     
    return minmax;
}
 
// Driver code
int main()
{
    int arr[] = { 1000, 11, 445,
                  1, 330, 3000 };
    int arr_size = 6;
     
    struct Pair minmax = getMinMax(arr, 0,
                             arr_size - 1);
                              
    cout << "Minimum element is "
         << minmax.min << endl;
    cout << "Maximum element is "
         << minmax.max;
          
    return 0;
}
