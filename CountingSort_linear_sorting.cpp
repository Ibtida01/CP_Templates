void countingSort(vector<int>& arr, int startingIdx, int endingIdx, int minimum_val, int maximum_val)//arr = array to be sorted, might of edges too (for kruskal's algo)
{
    int arr_size=endingIdx-startingIdx+1;
    int i,k=0,sizeTemp = maximum_val-minimum_val+1;
    int temp[sizeTemp];

    // Initializing all element of counting array with 0
    for(i=0; i<sizeTemp; i++){
        temp[i] = 0;
    }

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
