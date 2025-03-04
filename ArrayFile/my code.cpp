 // ArrayFile.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <vector>
#include <time.h>
#include <limits>

using namespace std;

//Створення і заповнення масиву 
void Array(int n, vector<int>& array ) {
    for (int i = 0; i < n; ++i) {
        array[i] = rand() % 19 - 9; // Генерація випадкових чисел
    }
    cout<<"\n";
}
//Друк масиву
void Print(int n, vector<int>& array) {
    for (int i = 0; i < n; ++i) {
        cout << array[i] << " ";
    }
    cout<<"\n";
}

int sum_positive(const vector<int>& array) {
    int sum = 0;
    for (int num : array) {
        if (num > 0) {
            sum += num;
        }
    }
    return sum;
}

int sum_negative(const vector<int>& array) {
    int sum = 0;
    for (int num : array) {
        if (num < 0) {
            sum += num;
        }
    }
    return sum;
}

int mult_positive(const vector<int>& array) {
    int prod = 1;
    bool hasPositive = false;
    for (int num : array) {
        if (num > 0) {
            prod *= num;
            hasPositive = true;
        }
    }
    return hasPositive ? prod : 0;
}

int mult_negative(const vector<int>& array) {
    int prod = 1;
    bool hasNegative = false;
    for (int num : array) {
        if (num < 0) {
            prod *= num;
            hasNegative = true;
        }
    }
    return hasNegative ? prod : 0;
}

int Task_2(int n, const vector<int>& array){

    int a1 = array[0];
    int indexMultThree = -1;
    
    // Знайти перший елемент, кратний 3
    for (int i = 0; i < n; ++i) {
        if (array[i] % 3 == 0) {
            indexMultThree = i;
            break;
        }
    }
    
    if (indexMultThree == -1 || indexMultThree == n - 1) {
        cout << "Не знайдено відповідних елементів.";
        return 0;
    }
    
    int maxValue = numeric_limits<int>::min();
    int maxIndex = -1;
    
    // Пошук максимального серед чисел менших за a1, починаючи після першого кратного 3
    for (int i = indexMultThree + 1; i < n; ++i) {
        if (array[i] < a1 && array[i] > maxValue) {
            maxValue = array[i];
            maxIndex = i;
        }
    }
    
    if (maxIndex != -1) {
        cout << "Індекс першого максимального значення: " << maxIndex << endl;
    } else {
        cout << "Не знайдено відповідного елемента.";
    }
    
    return maxValue;
}

int main() {
    int N;
    cout << "Size of array: ";
    cin >> N;

    vector<int> array(N);//ініціалізація масиву
    srand(static_cast<unsigned int>(time(NULL)));

    Array(N, array);
    cout << "Output array: ";
    Print(N, array);

    cout << "Task 1" << endl;
    cout << "Sum of positive: "  << sum_positive(array) << endl;
    cout << "Sum of negative: "  << sum_negative(array) << endl;
    cout << "Mult of positive: " << mult_positive(array) << endl;
    cout << "Mult of negative: " << mult_negative(array) << endl;

    cout << endl;

    cout << "Task 2" << endl;

    cout << endl;

    cout << "Max: " << Task_2(N, array) << endl;

    cout << endl;
    return 0;
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
