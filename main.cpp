//знаходжу добуток 2 матриць,які читаю з файлу
//яку з синхронізаційних конструкцій краще використовувати для цієї задачі?
//a)	М’ютекс (Mutex)
//b)	Семафор (Semaphpre)
//c)	Interlocked-функції
//        d)	Критична секція (Critical section)
//e)	Спін-блокування (Spinlock)
//f)	Wait-Функції

// Можливість обмеження кількості потоків, які одночасно працюють із даними (щоб, наприклад, із 100 запущених потоків одночасно виконували обчислення лише 8, а інші чекали).


#include <iostream>
#include <Windows.h>
#include <fstream>
#include <string>
#include<tchar.h>
#include<strsafe.h>
#include<chrono>

//defining
#define CUR_THREADS 1000

typedef long long ll;

using namespace std;

ll timer = 1000;
ll counter = 0;
HANDLE hMutex;

//set priority for thread
void setHighPriority(HANDLE *hThreadArray, int thr) {
    SetThreadPriority(hThreadArray[thr], THREAD_PRIORITY_HIGHEST);
}

void setLowPriority(HANDLE *hThreadArray, int thr) {
    SetThreadPriority(hThreadArray[thr], THREAD_PRIORITY_LOWEST);
}

//checking are the files equal
bool eqFiles(string file1, string file2) {
    ifstream f1(file1.c_str(), ios::binary);
    ifstream f2(file2.c_str(), ios::binary);
    if (f1.is_open() && f2.is_open()) {
        //checking are the numbers of char equal
        f1.seekg(0, ios::end);
        f2.seekg(0, ios::end);
        if (f1.tellg() != f2.tellg()) {
            f1.close();
            f2.close();
            return false;
        }
        //checking are the characters equal
        f1.seekg(0, ios::beg);
        f2.seekg(0, ios::beg);
        char c1, c2;
        while (f1.get(c1) && f2.get(c2)) {
            if (c1 != c2) {
                f1.close();
                f2.close();
                return false;
            }
        }
        f1.close();
        f2.close();
        return true;
    } else {
        return false;
    }
}


typedef struct Thread {

    ll *matrix1; //first matrix
    ll *matrix2; //second matrix
    ll *res_matrix; //matrix-result
    chrono::time_point<chrono::steady_clock> start_program;//start time for program
    int size_matrix; //size size_matrix*size_matrix
    int pos_thread;  //start pos for thread
    int block_size;  //block size for thread
} THREAD, *PTHREAD;


//func for thread
DWORD WINAPI MyThreadFunction(LPVOID lpParam) {
    WaitForSingleObject(hMutex, INFINITE);

    auto *data = (PTHREAD) lpParam;

    ll *m1 = data->matrix1;
    ll *m2 = data->matrix2;
    ll *res = data->res_matrix;
    ll n = data->size_matrix;
    ll pos_thread = data->pos_thread;
    ll block_size = data->block_size;

    chrono::time_point<chrono::steady_clock> start_program = data->start_program;
    //calculating block of matrix-result
    for (ll x = pos_thread; x < (block_size + pos_thread); x++) {

        counter++;

        chrono::time_point<chrono::steady_clock> now = chrono::steady_clock::now();
        if(chrono::duration_cast<chrono::milliseconds>(now-start_program).count()>timer){
            timer+=1000;
            long double proc = ((long double)counter/(long double)(n*n))*(long double)100;
            cout<<"Calculating: "<<proc<<"%"<<endl;
        }
        ll i = x / n;
        ll j = x % n;

        res[i * n + j] = 0;

        for (ll k = 0; k < n; k++) {
            res[i * n + j] += m1[i * n + k] * m2[k * n + j];
        }
    }

    HeapFree(GetProcessHeap(), 0, lpParam);

    ReleaseMutex(hMutex);

    return 0;
}


long long *multi(ll *matrix1, ll *matrix2, int size_matrix) {
    ll *res_matrix = new ll[size_matrix * size_matrix];

    PTHREAD pInfos[CUR_THREADS];
    DWORD dwThreadIndetifire[CUR_THREADS];
    HANDLE hThreadArray[CUR_THREADS];
    long double time[CUR_THREADS];

//    int thr = 10;
//    setHighPriority(hThreadArray, thr);

    hMutex = CreateMutex(
            NULL,
            FALSE,
            "hMutex"
    );

    //current position, block size for matrix and mod
    int default_block_size = (size_matrix * size_matrix) / CUR_THREADS;
    int mod = (size_matrix * size_matrix) % CUR_THREADS;
    int current_block = 0;

    chrono::time_point<chrono::steady_clock> begin_time = chrono::steady_clock::now();

    //creating threads for matrix
    for (int i = 0; i < CUR_THREADS; i++) {
        pInfos[i] = (PTHREAD) HeapAlloc(GetProcessHeap(), HEAP_ZERO_MEMORY, sizeof(THREAD));

        if (pInfos[i] == nullptr) {
            cout << "HeapAlloc is failed" << endl;
            ExitProcess(2);
        }

        pInfos[i]->matrix1 = matrix1;
        pInfos[i]->matrix2 = matrix2;
        pInfos[i]->res_matrix = res_matrix;
        pInfos[i]->size_matrix = size_matrix;
        pInfos[i]->pos_thread = current_block;
        pInfos[i]->block_size = default_block_size;
        pInfos[i]->start_program = begin_time;

        if (mod > 0) {
            pInfos[i]->block_size++;
            mod--;
        }
        current_block += pInfos[i]->block_size;


        //integer for timer
        LARGE_INTEGER t1, t2, tc;
        QueryPerformanceFrequency(&tc);
        QueryPerformanceCounter(&t1);

        hThreadArray[i] = CreateThread(
                nullptr,               // default security attributes
                0,                      // use default stack size
                MyThreadFunction,                        // thread function name
                pInfos[i],                     // argument to thread function
                0,                    // use default creation flags
                &dwThreadIndetifire[i]                 // returns the thread identifier
        );

        if (hThreadArray[i] == nullptr) {
            cout << "CreateThread is failed" << endl;
            ExitProcess(3);
        }
        QueryPerformanceCounter(&t2);
        time[i] = (t2.QuadPart - t1.QuadPart) * 1000.0 / tc.QuadPart;
//        if(i==thr){
//            cout << "Time for " << thr << " thread: " << time[i] <<" ms" << endl;
//        }

    }

    for (ll i = 0; i < CUR_THREADS; i++) {
        WaitForSingleObject(hThreadArray[i], INFINITE);
    }

    for (auto &i: hThreadArray) {
        CloseHandle(i);
    }

    CloseHandle(hMutex);

    return res_matrix;
}

void solution(string input, string output) {

    freopen(input.c_str(), "r", stdin);
    int n;
    cin >> n;

    ll *matrix1 = new ll[n * n];
    ll *matrix2 = new ll[n * n];
    ll *result = new ll[n * n];

    for (ll i = 0; i < n; i++) {
        for (ll j = 0; j < n; j++) {
            ll in1;
            cin >> in1;
            matrix1[i * n + j] = in1;
        }
    }

    cin >> n;
    for (ll i = 0; i < n; i++) {
        for (ll j = 0; j < n; j++) {
            ll in2;
            cin >> in2;
            matrix2[i * n + j] = in2;
        }
    }

    freopen("CON", "r", stdin);

    //integer for timer
    LARGE_INTEGER t1, t2, tc;
    QueryPerformanceFrequency(&tc);
    QueryPerformanceCounter(&t1);

    cout << "Calculating " << n << "*" << n << " matrix..." << endl;

    //calculating our result matrix
    result = multi(matrix1, matrix2, n);

    //timer
    QueryPerformanceCounter(&t2);
    double time = (t2.QuadPart - t1.QuadPart) * 1000.0 / tc.QuadPart;
    cout << "Time for " << n << "*" << n << ": " << time << " ms" << endl;

    //input input file
    freopen(output.c_str(), "w", stdout);

    for (ll i = 0; i < n; i++) {
        for (ll j = 0; j < n; j++) {
            cout << result[i * n + j] << " ";
        }
        cout << endl;
    }
    freopen("CON", "w", stdout);


}

void checkingAns(string s1, string s2, string s3) {
    if (!eqFiles(s1, s2)) {
        cout << s3 << " checkingAns is failed" << endl;
    } else {
        cout << s3 << " checkingAns is passed" << endl;
    }
}

int main(int argc, char **argv) {

    cout << endl << "Threads " << CUR_THREADS << ":" << endl << endl;

//    solution("C:\\Test\\test_small.txt", "C:\\Test\\out_small.txt");
//    checkingAns("C:\\Test\\out_small.txt", "C:\\Test\\ans_small.txt", "Small");
//    cout << endl;
//   counter = 0;
//
//    solution("C:\\Test\\test_medium.txt", "C:\\Test\\out_medium.txt");
//    checkingAns("C:\\Test\\out_medium.txt", "C:\\Test\\ans_medium.txt", "Medium");
//    cout << endl;
//   counter = 0;

    solution("C:\\Test\\test_big.txt", "C:\\Test\\out_big.txt");
    checkingAns("C:\\Test\\out_big.txt", "C:\\Test\\ans_big.txt", "Big");
    cout << endl;
    //   counter = 0;

    cout << "Program is done" << endl;
    return 0;
}
