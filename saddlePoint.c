#include <stdio.h>

/**
  * 寻找鞍点
  * 鞍点-矩阵中个元素在其列中为最小值，其行中为最大值。
 */

main()
{
    int i, j, k, row, col, max, min,flag=1;
    //获取输入
    // for (i = 0; i < 4; i++)
    //     for (j = 0; j < 4; j++)
    //         scanf("%d", &a[i][j]);

    int a[3][3] = {
        1, 2, 7,
        4, 5, 6,
        7, 8, 9};

    for (i = 0; i < 3; i++)
    {
        max = a[i][0];
        for (j = 1; j < 3; j++)
            if (a[i][j] > max)
            {
                max = a[i][j];
                col = j; //最大数所在的列号
            }
        //find the min in this col
        min = a[0][col];
        for (k = 1; k < 3; k++)
        {
            if (a[k][col] < min)
            {
                min = a[k][col];
                row = k;
            }
        }

        if (max == min){
            printf("a[%d][%d]=%d\n", row, col, a[row][col]);
            flag=1;
            break;

        }
    }
    if (flag==0) {
        printf("not found");
    }
    
}