# include <stdio.h>
# include <stdlib.h>


int countStudents(int* students, int studentsSize, int* sandwiches, int sandwichesSize)
{
    int *stack = malloc(studentsSize * sizeof(int));
    if(!stack)
        return 0;

    int i = 0;
    int j = -1;
    int k = 0;
    int count = 0;
    while(i < studentsSize)
    {
        stack[++j] = i;
        while(j >= 0 && i < sandwichesSize && students[stack[j]] == sandwiches[k])
        {
            // printf("%d %d %d\n", students[stack[j]], sandwiches[k], stack[j]);
            k++;
            j--;
            count++;
        }
        i++;
    }
    return count - sandwichesSize;
}
int main()
{
    int arr1[] = {1, 1, 0, 0};
    int arr2[] = {0, 1, 0, 1};
    printf("%d\n", countStudents(arr1, 4, arr2, 4));
}