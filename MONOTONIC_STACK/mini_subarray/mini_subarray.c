# include <unistd.h>
# include <stdio.h>


// int mini_max_subarray(int *nums, int size)
// {
//     int mini;
//     int sum = 0;
//     int i = 0;
//     int j;
//     while(i < size)
//     {  
//         mini = nums[i];
//         j = i;
//         while(j < size)
//         {
//             if(nums[j] < mini)
//                 mini = nums[j];

//             sum += mini;
//             j++;
//         }
//         i++;
//     }
//     return sum;
//}

int mini(int nb1, int nb2)
{
    return (nb1 < nb2) ? nb1 : nb2;
}
int mini_subarray(int *nums, int size)
{
    int curr = nums[0];
    int glob = nums[0];
    int i = 1;
    while(i < size)
    {
        curr = (curr + nums[i] < nums[i]) ? nums[i] + curr : nums[i];
        if(curr < glob)
            glob = curr;
        i++;
    }
    return glob;
}
int main()
{
    int arr[] = {3, 5, 2, 4};
    printf("%d\n", mini_subarray(arr, 4));
}