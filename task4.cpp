/*
 Заполните массив элементами арифметической прогрессии. Её первый элемент и разность нужно ввести с клавиатуры.

Заполните массив из N элементов случайными целыми числами в диапазоне 1..N так, чтобы в массив обязательно вошли все числа от 1 до N (постройте случайную перестановку).

Заполните массив случайными числами в диапазоне 1000.2000 и подсчитайте число элементов, у которых вторая с конца цифра – чётная.

Делаем все в одном проекте через функции, так же нужно написать функцию для вывода массива (void print_array(int array[], const int size).
Без функции print_array проверять не буду.
 */


#include <iostream>
#include <ctime>

void print_array(int a[], int n)
{
    for(int i=0; i<n; i++)
    {
        std::cout << a[i] << " ";
    }
    std::cout << std::endl;
}

void arithmetic_fill(int mas[], int n, int a1, int d)
{
    for(int i=0; i<n;i++)
    {
        mas[i]=a1+d*i;
    }
}

void random_fill(int a[], int n)
{
    srand(time(0));
    for(int i=0 ; i<n ; i++)
    {
        a[i] = rand()%1001 + 1000;
    }
}

void swap(int &a, int &b)
{
    int t = a;
    a = b;
    b = t;
}

void prestan_fill(int a[], int n)
{
    srand(time(0));
    for (int  i = 0; i<n ; i++)
    {
        a[i]= i+1;
    }
    print_array(a,n);
    for (int i = 0; i < n; i++)
    {
        swap(a[i], a[rand()%(n-i)+1]);
    }
}

int main() {
    int n, a1, d;
    std::cout << "enter the length of the array" << std::endl;
    std::cin >> n;

    std::cout << "enter the first element of AP and its difference" << std::endl;
    std::cin >> a1 >> d;

    int* a = new int[n];
    int* b = new int[n];
    int* c = new int[n];

    arithmetic_fill(a, n, a1, d);
    print_array(a,n);

    random_fill(b,n);
    print_array(b,n);

    int count = 0;
    for(int i = 0; i<n ; i++)
    {
        if ((b[i] / 10) % 2 == 0)
        {
            count++;
        }
    }
    std::cout << count << std::endl;

    prestan_fill(c,n);
    print_array(c,n);

    delete a;
    delete b;
    delete c;
    return 0;
}
