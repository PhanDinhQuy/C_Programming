/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* numbers, int numbersSize, int target, int* returnSize) {
    int left =0;
    int right = numbersSize -1;

    while ( left < right)
    {
        int current_sum = numbers[left] + numbers[right];
        if( current_sum == target)
        {
            int* result = (int*)malloc(2 * sizeof(int));
            result[0] = left + 1;
            result[1] = right + 1;
            *returnSize = 2;
            return result;
        }
        else if( current_sum > target)
        {
            right--;
        }
        else
        {
            left++;
        }
    }
    *returnSize = 0;
    return NULL;
}
