#define MOD 1000000007
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int a[], int low, int high) {
    int pivot = a[low];
    int i = low + 1;
    int j = high;

    while (i <= j) {
        while (i <= high && a[i] <= pivot) i++;
        while (a[j] > pivot) j--;

        if (i < j)
            swap(&a[i], &a[j]);
    }

    swap(&a[low], &a[j]);
    return j;
}

void quickSort(int a[], int low, int high) {
    if (low < high) {
        int p = partition(a, low, high);
        quickSort(a, low, p - 1);
        quickSort(a, p + 1, high);
    }
}

long long two_power(int a) {
    long long result = 1;
    long long base = 2;
    
    while (a > 0) {
        if (a % 2 == 1)
            result = (result * base) % MOD;
        base = (base * base) % MOD;
        a /= 2;
    }
    
    return result;
}
int numSubseq(int* nums, int numsSize, int target) {
    quickSort(nums,0,numsSize-1);
    int left=0;
    int right=numsSize-1;
    long long subseq=0;
    int sum;
    while(left<=right){
        sum=nums[left]+nums[right];
        if(sum>target)
        right--;
        else
        {
            int elements=right-left-1;
            subseq+=two_power(elements+1);
            left++;
        }
    }
    return subseq%MOD;
}
