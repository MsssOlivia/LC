//A is sorted array
int binary_search(int A[], int key, int len) {
  int low=0;
  int high=len-1;
  while(low<=high){
  int mid=low+(high-low)/2;
  if (A[mid]==key) return mid;
  if(A[mid]>key) {
    high=mid-1;
  }
  if(A[mid]<key) {
    low =mid+1;
  }
  }
  return -1;
}
