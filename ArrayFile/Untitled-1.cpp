// ArrayFile.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <fstream>
#include <ios>
#include <vector>
#include <iomanip>
#include <time.h>
#include <math.h>
#include <limits>

using namespace std;

typedef double* pDouble;
/*
*   ConsoleInputArrayDouble
*   
*/
int ConsoleInputSizeArray(const int sizeMax)
{
    int size = 0; 
    do {
        cout << " Input size Array ( 0< 1 < " << sizeMax << " ) ";
        cin >> size;
    } while (size <= 0 || size >= sizeMax);
    return size;
}
/*
*   ConsoleInputArrayDouble
*
*/
int ConsoleInputArray(int sizeMax, double A[])
{
    int size = ConsoleInputSizeArray(sizeMax);
        for (int i = 0; i < size; i++) {
        cout << " Array[ " << i << "] "; cin >> A[i];
    }
    return size;
}

/*
*   RndInputArrayDouble
*
*/
int RndInputArray(int sizeMax, double A[])
{
    int size = ConsoleInputSizeArray(sizeMax);
    int r1=0, r2=0;
    srand(size);

    for (int i = 0; i < size; i++) {
        r1 = rand();
        r2 = rand();
        A[i] = 100.0 * r1;
        A[i] = A[i] / (1.0 + r2);
        cout << A[i] << "   ";
    }
    return size;
}

int ConsoleInputDynamicArrayNew(int sizeMax, pDouble &pA)
{
    int size = ConsoleInputSizeArray(sizeMax);
    pA = new double[size];
    if (pA == nullptr) { return 0; }
    for (int i = 0; i < size; i++) {
        cout << " Array[ " << i << "] "; cin >> pA[i];
    }
    return size;
}

int ConsoleInputDynamicArray_calloc(int sizeMax, pDouble& pA)
{
    int size = ConsoleInputSizeArray(sizeMax);
    pA = (double*)calloc(size, sizeof(double));      // pA = (double*)malloc(size * sizeof(double)); 
    if (pA == nullptr) { return 0; }
    for (int i = 0; i < size; i++) {
        cout << " Array[ " << i << "] "; cin >> pA[i];
    }
    return size;
}

void ConsoleInputVector(int sizeMax, vector<double> &A)
{
    int size = ConsoleInputSizeArray(sizeMax);
    double d;
    for (int i = 0; i < size; i++) {
        cout << " Array[ " << i << "] "; cin >> d; A.push_back(d);
    }
    return ;
}


/*
*  WriteArrayTextFile 
*
*/

void WriteArrayTextFile(int n, double *arr, const char *fileName )
{
    ofstream fout(fileName);
    if (fout.fail()) return;
    fout << n << endl;
    for (int i = 0; i < n; i++)
        fout << arr[i] << "   ";
    fout.close(); //
}
/*
*  ReadArrayTextFile
*
*/


int ReadArrayTextFile(int n, double* arr, const char* fileName)
{
    int size;
    ifstream fin(fileName);
    if (fin.fail()) return 0;
    fin >> size;
    if (size <= 0) return 0;
    if (size > n) size = n;   
    for (int i = 0; i < n; i++)
       fin>> arr[i];
    fin.close();
    return size;
    
}


void WriteArrayBinFile(int n, double* arr, const char* fileName)
{
    //ios_base
    ofstream bfout(fileName, ios_base::binary);
    if (bfout.fail()) return;
    bfout.write((const char*)&n, sizeof(int));
    std::streamsize  cn = static_cast<std::streamsize>(n) *sizeof(double);
    bfout.write((const char*)arr, cn);
    bfout.close();
}

int ReadArrayBinFile(int n, double* arr, const char* fileName)
{
    int size=0;
    ifstream bfin(fileName, ios_base::binary);
    if (bfin.fail()) return 0;
    bfin.read((char*)&size, sizeof(int));
    if (size <= 0) return 0;
    if (size > n) size = n;
    bfin.read((char*)arr, static_cast<std::streamsize>(size) * sizeof(double));
    bfin.close();
    // ssdhs
    return size;
}

// Task 1 functions
void Array(int n, vector<int>& array) {
    for (int i = 0; i < n; ++i) {
        array[i] = rand() % 19 - 9;
    }
    cout<<"\n";
}

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

// Task 2 functions
int Task_2(int n, const vector<int>& array){
    int a1 = array[0];
    int indexMultThree = -1;
    
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

void ShowMainMenu()
{
    cout << "    Main Menu  \n";
    cout << "    1.  Task 1  \n";
    cout << "    2.  Task 2  \n";
    cout << "    3.  Task 3  \n";
  }

void MenuTask()
{
    cout << "     Menu Task   \n";
    cout << "    1.  Local array  \n";
    cout << "    2.  Dynamic array 1 \n";
    cout << "    3.  Dynamic array 2  new \n"; 
    cout << "    4.  Dynamic array : vector \n";
    cout << "    5.  Exit \n";
}

void MenuInput()
{
    cout << "     Menu Input   \n";
    cout << "    1.  Console all \n";
    cout << "    2.  Console - size, array - random \n";
    cout << "    3.  File 1.txt \n";
    cout << "    4.  bb    \n";
    cout << "    5.  Exit \n";
}


/*
* Задано одновимірний масив А розміру 2N. 
* Побудувати два масиви В і С розміру N, 
* включивши  у масив В елементи масиву А з парними індексами,
* а у С - з непарними.
*****************
*  A - in 
*  B, C - out 
*/
void  TestVariant(int N, double* A, double* B, double* C) {
    for (int i = 0; i < N; i++) {
        B[i] = A[2 * i];
        C[i] = A[2 * i + 1];
    }
}
/*
*  Task  Var
* 
* 
*/
void TaskV()
{
    char ch = '5';
    do {
        system("cls");
        MenuTask();
        ch = getchar();
        getchar();
            switch (ch) {
             case '1': cout << " 1 "; break;
             case '2': cout << " 2 "; break;
            //
            case '5': return;
            }
        cout << " Press any key and enter\n";
        ch = getchar();
        } while (ch != 27);
    
}

void Task1() {
    int N;
    cout << "Size of array: ";
    cin >> N;

    vector<int> array(N);
    srand(static_cast<unsigned int>(time(NULL)));

    Array(N, array);
    cout << "Output array: ";
    Print(N, array);

    cout << "Task 1" << endl;
    cout << "Sum of positive: "  << sum_positive(array) << endl;
    cout << "Sum of negative: "  << sum_negative(array) << endl;
    cout << "Mult of positive: " << mult_positive(array) << endl;
    cout << "Mult of negative: " << mult_negative(array) << endl;

    cout << "\nPress Enter to continue...";
    cin.ignore();
    cin.get();
}

void Task2() {
    int N;
    cout << "Size of array: ";
    cin >> N;

    vector<int> array(N);
    srand(static_cast<unsigned int>(time(NULL)));

    Array(N, array);
    cout << "Output array: ";
    Print(N, array);

    cout << "Task 2" << endl;
    cout << "Max: " << Task_2(N, array) << endl;

    cout << "\nPress Enter to continue...";
    cin.ignore();
    cin.get();
}

void ArrayLocal()
{
    double A[1000], B[500], C[500];
    int n;
    char ch = '5';
    do {
        system("cls");
        MenuTask();
        ch = getchar();
        getchar();
        switch (ch) {
        case '1': cout << " 1 "; break;
        case '2': cout << " 2 "; break;
            //
        case '5': return;
        }
        cout << " Press any key and enter\n";
        ch = getchar();
    } while (ch != 27);

}


int main()
{ 
    ShowMainMenu();
    

    char ch = '0';
    while (ch != '4') {
        ShowMainMenu();
        cout << "    4.  Exit \n";
        cout << "Enter your choice: ";
        cin >> ch;
        
        switch(ch) {
            case '1':
                Task1();
                break;
            case '2':
                Task2();
                break;
            case '3':
                TaskV();
                break;
            case '4':
                cout << "Exiting program...\n";
                break;
            default:
                cout << "Invalid option. Try again.\n";
        }
    }

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