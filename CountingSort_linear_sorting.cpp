template <typename t>
void countingSort(vector<t>& arr, int startingIdx, int endingIdx, int minimum_val, int maximum_val)//arr = array to be sorted, might of edges too (for kruskal's algo)
{
    int arr_size=endingIdx-startingIdx+1;
    int i,k=0,sizeTemp = maximum_val-minimum_val+1;
    vector<int> temp(sizeTemp,0);
    // Initialized all element of counting array with 0

    //Store the frequency of each element of the original array
    //at the relative position in counting array
    for(i=0; i<=endingIdx; i++){
        temp[arr[i]-minimum_val]++;
    }

    //Iterate through the counting array and re-write the original array.
    for (i=minimum_val; i<=maximum_val; i++){
        while(temp[i-minimum_val]-->0){
            arr[k++]=i;
        }
    }
}
