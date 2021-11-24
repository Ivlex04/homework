#include<iostream>
#include<ctime>

void random_array(int* array, int size)
{
    for (int i = 0; i < size; i++) array[i] = rand() % 90 + 10;
}

void print_array(int *array, int size)
{
    for (int i = 0; i < size; i++) {
        std::cout << array[i] << " ";
    }
    std::cout << std::endl;
}

void move_to_left(int* array, int begin, int end)
{
    int tmp = array[begin];
    for (int i = begin; i < end; i++) {
        array[i] = array[i + 1];
    }
    array[end] = tmp;
}

void move_to_right(int* array, int begin, int end)
{
    int tmp = array[end];
    for (int i = end; i > begin; i--)
    {
        array[i] = array[i - 1];
    }
    array[begin] = tmp;
}

void qsort(int* array, int begin, int end)
{
    int mid = (begin + end) / 2;
    for (int i = 0; i <= end; i++)
    {
        if (array[i] > array[mid] and i < mid)
        {
            move_to_left(array, i, mid);
            mid--;
            i--;
        }
        if (array[i] < array[mid] and i > mid)
        {
            move_to_right(array, mid, i);
            mid++;
        }
    }

    if (begin < mid-1)
    {
        qsort(array, begin, mid - 1);
    }
    if (mid+1 < end)
    {
        qsort(array, mid + 1, end);
    }
    return;
}

int main()
{
    srand(time(0));

    int n;

    std::cout<< "Enter the length of mas:" << std::endl;

    std::cin >> n;

    int* mas = new int[n];

    random_array(mas, n);

    print_array(mas, n);

    qsort(mas,0, n-1);

    print_array(mas, n);

    return 0;
}
