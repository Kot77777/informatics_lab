#include <iostream>
#include <fstream>
#include <vector>
#include <forward_list>
#include <chrono>
#include <random>
#include <string>
#include <array>
#include <list>
#include <map>

using namespace std;
using namespace std::chrono;

double generateRandomNumber() {
	//generate random number from zero to one
	std::random_device rd;
	std::mt19937 random_number(rd());
	std::uniform_real_distribution<double> dis(0.0, 1.0);

	return dis(random_number); // We generate and return a random number from 0 to 1
}

template<typename T>
std::array<unsigned, 12> push_back(T container, const int num, std::array<unsigned int, 12>& size)
{
    std::array<unsigned int, 12> time_of_push_back;

    for (auto i = 0; i < num; ++i)
    {
	auto random_number = generateRandomNumber() * 10000;
	auto start = steady_clock::now();
	for (int j = 0; j < size[i]; ++j)
	{
		container.push_back(random_number);
	}
	auto fin = steady_clock::now();
        auto dur = fin - start;
	time_of_push_back[i] = duration_cast<nanoseconds>(dur).count();
        
       /*uto start1 = steady_clock::now();
        for (int j = 0; j < size[i]; ++j)
        {
                container.pop_back();
        }
        auto fin1 = steady_clock::now();
        auto dur1 = fin1 - start1;
        time_of_push_back[1][i] = duration_cast<nanoseconds>(dur1).count();
   */
    }
    return time_of_push_back;
}

template<typename T>
std::array<unsigned, 12> emplace(T container, const int num, std::array<unsigned int, 12>& size)
{
    std::array<unsigned int, 12> time_of_push_back;

    for (auto i = 0; i < num; ++i)
    {
        auto random_number = generateRandomNumber() * 10000;
        auto start = steady_clock::now();
        for (int j = 0; j < size[i]; ++j)
        {
                container.emplace(random_number, i);
        }
        auto fin = steady_clock::now();
        auto dur = fin - start;
        time_of_push_back[i] = duration_cast<nanoseconds>(dur).count();

       /*uto start1 = steady_clock::now();
        for (int j = 0; j < size[i]; ++j)
        {
                container.pop_back();
        }
        auto fin1 = steady_clock::now();
        auto dur1 = fin1 - start1;
        time_of_push_back[1][i] = duration_cast<nanoseconds>(dur1).count();
   */
    }
    return time_of_push_back;
}


template<typename T>
std::vector<unsigned int> push_front_timer(T container, unsigned int repeats)
{
    auto n = 1000;

    std::vector<unsigned int> time_of_push_back(n, 0);

    for (auto i = 0; i < repeats; ++i)
    {
        container.clear();
        for (auto j = 0; j < n; ++j) //adding elements
        {
            auto random_number = generateRandomNumber() * 10000;
            auto start = std::chrono::high_resolution_clock::now();
            container.push_front(random_number);
            auto end = std::chrono::high_resolution_clock::now();
            auto time = end - start;
            time_of_push_back[j] += time.count(); //we should devide it by n but we won't
        }

    }
    return time_of_push_back;
}

template<typename T>
std::vector<unsigned int> pop_back_timer(T container, unsigned int repeats)
{
    auto n = 1000;

    std::vector<unsigned int> time_of_push_back(n, 0);
    
    for (auto i = 0; i < repeats; ++i) 
    {
        container.clear();
        for (auto k = 0; k < n; ++k) //adding el
        {
            auto random_number = generateRandomNumber() * 10000;
            container.push_back(random_number);
        }
        for (auto j = 0; j < n; ++j) //deleting el
        {
            auto start = std::chrono::high_resolution_clock::now();
            container.pop_back();
            auto end = std::chrono::high_resolution_clock::now();
            auto time = end - start;
            time_of_push_back[j] += time.count(); //we should devide it by n but we won't
        }

    }
    return time_of_push_back;
}

template<typename T>
std::vector<unsigned int> pop_front_timer(T container, unsigned int repeats)
{
    auto n = 1000;

    std::vector<unsigned int> time_of_push_back(n, 0);
    
    for (auto i = 0; i < repeats; ++i) 
    {
        container.clear();
        for (auto k = 0; k < n; ++k) //adding el
        {
            unsigned int random_number = generateRandomNumber() * 10000;
            container.push_front(random_number);
        }
        for (auto j = 0; j < n; ++j) //deleting el
        {
            auto start = std::chrono::high_resolution_clock::now();
            container.pop_front();
            auto end = std::chrono::high_resolution_clock::now();
            auto time = end - start;
            time_of_push_back[j] += time.count(); //we should devide it by n but we won't
        }

    }
    return time_of_push_back;
}

template<typename T>
std::vector<unsigned int> insert_timer(T container, unsigned int repeats)
{
    auto n = 1000;

    std::vector<unsigned int> time_of_push_back(n, 0);
    
    for (auto i = 0; i < repeats; ++i) 
    {
        container.clear();
        container.reserve(n);
        for (auto k = 0; k < repeats; ++k) //adding el
        {
            auto random_number = generateRandomNumber() * 10000;
            container[k] = random_number;
        }
        for (auto j = 0; j < n; ++j) //inserting 666
        {
            auto it = container.begin() + j;
            auto start = std::chrono::high_resolution_clock::now();
            container.insert(it, 666);
            auto end = std::chrono::high_resolution_clock::now();
            auto time = end - start;
            time_of_push_back[j] += time.count(); //we should devide it by n but we won't
        }

    }
    return time_of_push_back;
}

template<typename T>
std::vector<unsigned int> insert_after_timer(T container, unsigned int repeats)
{
    auto n = 1000;

    std::vector<unsigned int> time_of_push_back(n, 0);
    
    for (auto i = 0; i < repeats; ++i) 
    {
        container.clear();
        for (auto k = 0; k < repeats; ++k) //adding el
        {
            auto random_number = generateRandomNumber() * 10000;
            container.push_front(random_number);
        }
        for (auto j = 0; j < n; ++j) //inserting 666
        {
            auto it = container.begin();
            for (auto h = 0; h <= j; h++)
            {
                ++it;
            }
            auto start = std::chrono::high_resolution_clock::now();
            container.insert_after(it, 666);
            auto end = std::chrono::high_resolution_clock::now();
            auto time = end - start;
            time_of_push_back[j] += time.count(); //we should devide it by n but we won't
        }
    }
    return time_of_push_back;
}

int main()
{
    setlocale(LC_ALL, "ru");
    const int num = 12;

    std::array<unsigned int, num> size = {100, 500, 1000, 2000, 3000, 4000, 5000, 6000, 7000, 8000, 9000, 10000};
    
    //===============MAP EMPLACE==================//
    std::string vector_push_back_path = "map-emplace.txt";
    std::ofstream fout1;

    fout1.open(vector_push_back_path);

    if (!fout1.is_open())
    {
        std::cout << "error" << std::endl;
    }
    else
    {
        std::cout << "map emplace file is opened" << std::endl;
        std::map<unsigned int, unsigned int> vec1;
        auto time_array1 = emplace(vec1, num, size);
        for (auto i = 0; i < num; ++i)
        {
            fout1 << time_array1[0] << std::endl;
        }
    }
    //===========VECTOR PUSH BACK======================//
   /* std::string vector_push_back_path = "vector-push-back.txt";
    std::ofstream fout1;

    fout1.open(vector_push_back_path);

    std::string vector_pop_back_path = "vector-pop-back.txt";
    std::ofstream fout2;

    fout2.open(vector_pop_back_path);

    if (!fout1.is_open())
    {
        std::cout << "error" << std::endl;
    }
    else
    {
        std::cout << "vector push_back file is opened" << std::endl;
        std::vector<unsigned int> vec1;
        auto time_array1 = push_back_timer(vec1, num, size);
        for (auto i = 0; i < num; ++i)
        {
            fout1 << time_array1[0][i] << std::endl;
	    fout2 << time_array1[1][i] << std::endl;
        }
    }*/
   //============VECTOR POP BACK======================//
   /* std::string vector_pop_back_path = "vector-pop-back.txt";
    std::ofstream fout2;

    fout2.open(vector_pop_back_path);

    if (!fout2.is_open())
    {
        std::cout << "error" << std::endl;
    }
    else
    {
        std::cout << "vector pop_back file is opened" << std::endl;
        auto time_array2 = pop_back_timer(vec1, num);
        for (auto i = 0; i < repeats; ++i)
        {
            fout2 << time_array2[i] << std::endl;
        }
    }*/
    /*
    //==============FORWARD LIST INSERT AFTER======================//
    std::string forward_list_insert = "forward-list-insert.txt";
    std::ofstream fout7;

    fout7.open(forward_list_insert);

    if (!fout7.is_open())
    {
        std::cout << "error" << std::endl;
    }
    else
    {
        std::cout << "forward list insert file is opened" << std::endl;
        std::forward_list<unsigned int> forward_list3;
        auto time_array7 = insert_after_timer(forward_list3, repeats);
        for (auto i = 0; i < repeats; ++i)
        {
            fout7 << time_array7[i] << std::endl;
        }
    }
    //==============VECTOR INSERT======================//
    std::string vector_insert = "vector-insert.txt";
    std::ofstream fout8;

    fout8.open(vector_insert);

    if (!fout8.is_open())
    {
        std::cout << "error" << std::endl;
    }
    else
    {
        std::cout << "vector insert file is opened" << std::endl;
        std::vector<unsigned int> vector5;
        auto time_array8 = insert_timer(vector5, repeats);
        for (auto i = 0; i < repeats; ++i)
        {
            fout8 << time_array8[i] << std::endl;
        }
    }
    
    //==============FORWARD LIST PUSH FRONT======================//
    std::string vector_push_back_path = "list-push-back.txt";
    std::ofstream fout1;

    fout1.open(vector_push_back_path);

    if (!fout1.is_open())
    {
        std::cout << "error" << std::endl;
    }
    else
    {
        std::cout << "vector push_back file is opened" << std::endl;
        std::list<unsigned int> vec1;
        auto time_array1 = push_back(vec1, num, size);
        for (auto i = 0; i < num; ++i)
        {
            fout1 << time_array1[0] << std::endl;
        }
    }
    
    /==============FORWARD LIST POP FRONT======================//
    std::string forward_list_pop_front = "forward-list-pop-front.txt";
    std::ofstream fout10;

    fout10.open(forward_list_pop_front);

    if (!fout10.is_open())
    {
        std::cout << "error" << std::endl;
    }
    else
    {
        std::cout << "forward list pop front file is opened" << std::endl;
        std::forward_list<unsigned int> forward_list5;
        auto time_array10 = pop_front_timer(forward_list5, repeats);
        for (auto i = 0; i < repeats; ++i)
        {
            fout10 << time_array10[i] << std::endl;
        }
    }*/
    return 0;
}
