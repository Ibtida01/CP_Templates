int* merge(int sz1,int sz2,int* arr1,int* arr2)//arr1 and arr2--> arrays to be merged,sz1 &sz2 are their sizes
{
    int* merged=(int*)malloc((sz1+sz2)*sizeof(int));//merged is the array to be returned
    int i,j,k;
    for(i=0,j=0,k=0; i<sz1 && j<sz2; k++)
    {
        if(arr1[i]<=arr2[j])
        {
            merged[k]=arr1[i];
            ++i;
        }
        else
        {
            merged[k]=arr2[j];
            ++j;
        }
    }
    for(; j<7; ++j,k++)
        merged[k]=arr2[j];
    for(; i<10; i++,k++)
        merged[k]=arr1[i];
    return merged;
}
