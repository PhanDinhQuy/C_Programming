/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
#include <stdlib.h>
int compare(const void *a, const void *b) {
    int *intervalA = *(int **)a;
    int *intervalB = *(int **)b;
    if (intervalA[0] != intervalB[0])
    {
        return intervalA[0] - intervalB[0];
    }
    else 
    {
        return intervalA[1] - intervalB[1];
    }
}

int max(int a, int b)
{
    if(a >= b)
    {return a;}
    else
    {return b;}
}

int** merge(int** intervals, int intervalsSize, int* intervalsColSize, int* returnSize, int** returnColumnSizes) {
    if(intervalsSize == 0)
    {
        *returnSize = 0;
        return NULL;
    }
    //quick sort để sort lại interval trước khi so sánh
    qsort(intervals, intervalsSize, sizeof(int*),compare);
    // cấp phát bộ nhớ cho result
    int** result = (int**) malloc(intervalsSize * sizeof(int*));
    * returnColumnSizes = (int*) malloc(intervalsSize * sizeof(int));

    int count = 0;
    int currentstart = intervals[0][0];
    int currentend = intervals[0][1];

    for (int i = 1; i < intervalsSize; i++)
    {
        if(currentend >= intervals[i][0])
        {
            currentend = max(currentend, intervals[i][1]);
        }
        else
        {
            result[count] = (int*)malloc(2 * sizeof(int));
            result[count][0] = currentstart;
            result[count][1] = currentend;
            (*returnColumnSizes)[count] = 2;
            count++;
            currentstart = intervals[i][0];
            currentend = intervals[i][1];
        }
    }
    result[count] = (int*)malloc(2 * sizeof(int));
    result[count][0] = currentstart;
    result[count][1] = currentend;
    (*returnColumnSizes)[count] = 2;
    count++;
    
    *returnSize = count;
    return result;
}
