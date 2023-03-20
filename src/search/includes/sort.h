// sort an array in ascending order
void sort(int arr[], int n)
{
     for(int i=0; i < n;i++)
     {
          for(int j = i+1;j<n;j++)
          {
               if(arr[j] < arr[i])
               {
                    int temp = arr[i];
                    arr[i] = arr[j];
                    arr[j] = temp;
               }
          }
     }
}