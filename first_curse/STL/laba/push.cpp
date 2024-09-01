#include <iostream>
#include <vector>
#include <chrono>
#include <algorithm>

int main() {
    std::vector<long> time_of_push_back;
    std::vector<int> vec_sizes = {1000, 10000, 100000, 1000000}; // Размеры векторов для тестирования

    for (int size : vec_sizes) {
        std::vector<int> vec;
        
        auto start_time = std::chrono::high_resolution_clock::now();

        for (int i = 0; i < size; ++i) {
            vec.push_back(i);
        }

        auto end_time = std::chrono::high_resolution_clock::now();
        auto time = std::chrono::duration_cast<std::chrono::milliseconds>(end_time - start_time);

        time_of_push_back.push_back(time.count());
    }

    // Вывод времени добавления элемента в конец для каждого размера вектора
    for (int i = 0; i < vec_sizes.size(); ++i) {
        std::cout << "Time taken for vector size " << vec_sizes[i] << ": " << time_of_push_back[i] << " milliseconds" << std::endl;
    }

    return 0;
}

