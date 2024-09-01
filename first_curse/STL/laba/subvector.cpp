#include <iostream>
#include <fstream>
#include <vector>
#include <chrono>
#include <array>
#include <random>

using namespace std;
using namespace std::chrono;

double generateRandomNumber() {
        //generate random number from zero to one
        std::random_device rd;
        std::mt19937 random_number(rd());
        std::uniform_real_distribution<double> dis(0.0, 1.0);

        return dis(random_number); // We generate and return a random number from 0 to 1
}

struct subvector {
    int* mas;
    unsigned int top;
    unsigned int capacity;
};

bool init(subvector* qv) {
    (*qv).top = 0;
    (*qv).mas = nullptr;
    (*qv).capacity = 0;
    return true;
}

bool resize(subvector* qv, unsigned int new_capacity) {
    if (new_capacity < (*qv).top) {
        (*qv).top = new_capacity;
    }
    int* arr = new int[new_capacity];
    for (unsigned int i = 0; i < (*qv).top; i++) {
        *(arr + i) = *((*qv).mas + i);
    }
    delete[](*qv).mas;
    (*qv).mas = arr;
    (*qv).capacity = new_capacity;
    return true;
}

bool push_back(subvector* qv, int d) {
    if ((*qv).top + 1 > (*qv).capacity) {
        resize(qv, (*qv).top + 1);
    }
    (*qv).mas[(*qv).top] = d;
    (*qv).top++;
    return true;
}

int pop_back(subvector* qv) {
    if ((*qv).top == 0) return 0;
    (*qv).top--;
    return (*qv).mas[(*qv).top];
}

void clear(subvector *qv){
      resize(qv, 0);
}

void measurePushBackTime(subvector* qv, const int num, std::array<unsigned int, 12>& size) {
    std::ofstream file("subvector_push_back_time.txt");

   // std::vector<unsigned int> time_of_push_back(num, 0);
    std::array<std::array<unsigned int, 12>, 2> time_of_push_back;

    for (auto i = 0; i < num; ++i)
    {
        auto random_number = generateRandomNumber() * 10000;
        auto start = steady_clock::now();
        for (int j = 0; j < size[i]; ++j)
        {
                push_back(qv, i);
        }
        auto fin = steady_clock::now();
        auto dur = fin - start;
        clear(qv);
	file  << duration_cast<nanoseconds>(dur).count()  << std::endl;  

    }
    file.close();
}

void measureInsertTime(subvector* qv, unsigned int numElements) {
    std::ofstream file("/home/path/insert_time.txt");
    auto start = std::chrono::high_resolution_clock::now();
    
    for (unsigned int i = 0; i < numElements; i++) {
        (*qv).mas[i] = i;
        (*qv).top++;
    }
    
    auto end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();
    
    file << "Number of elements: " << numElements << ", Time taken: " << duration << " microsecondsn";
    
    file.close();
}

void measurePopBackTime(subvector* qv, unsigned int num, std::array<unsigned int, 12>& size) {
    std::ofstream file("subvector_pop_back_time.txt");
    
    std::array<std::array<unsigned int, 12>, 2> time_of_push_back;

    for (auto i = 0; i < num; ++i)
    {
    	for (int j = 0; j < size[i]; ++j)
        {
                push_back(qv, i);
        }
        //auto random_number = generateRandomNumber() * 10000;
        auto start = steady_clock::now();
        for (int j = 0; j < size[i]; ++j)
        {
                pop_back(qv);
        }
        auto fin = steady_clock::now();
        auto dur = fin - start;
        //clear(qv);
	file  << duration_cast<nanoseconds>(dur).count()  << std::endl;  
    }
    file.close();    
}

int main() {
    subvector qv;
    init(&qv);
    
    const int num = 12;
    std::array<unsigned int, num> size = {100, 500, 1000, 2000, 3000, 4000, 5000, 6000, 7000, 8000, 9000, 10000};
    
    measurePopBackTime(&qv, num, size);
   // measureInsertTime(&qv, numElements);
   // measurePopBackTime(&qv, numElements);
    
    return 0;
}

