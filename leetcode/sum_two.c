/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

#include <stdio.h>
#include<stdlib.h>
int* twoSum(int* nums, int numsSize, int target, int* returnSize){
    returnSize = (int*)malloc(2*sizeof(int));
    for(int i = 0; i< numsSize-1; i++){
        for(int j=i+1; j<numsSize; j++){
            if(nums[i]+nums[j]==target){
                returnSize[0]=i;
                returnSize[1]=j;
                return returnSize;
            }
        }
    }
}

int main(){

    int nums[]={1,4,5,7,8};
    int numsSize=5;
    int target=5;
    int *returnSize=twoSum(nums,numsSize,target,returnSize);

    printf("%d,%d",returnSize[0],returnSize[1]);
    return 0;
}
