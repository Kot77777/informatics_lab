#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

std::vector<int> first_foo(const std::vector<int>& v, const int number)
{
	int k;
	std::vector<int> v1;
	for(int i = 0; i < v.size(); i++)
	{
		if(v[i] > number)
		{
			k = i;
			break;
		}
	}
	for(int i = 0; i < k; i++)
	{
		v1.push_back(v[i]);
	}
	std::reverse(v1.begin(), v1.end());
	return v1;
}	

std::vector<std::string> second_foo(const std::string& str)
{
    auto char_counter = 0;
    auto word_number = 0;
    auto last_space_num = 0;
    std::vector<std::string> word_array;
    std::string word;
    for (char c : str)
    {
        if (c != ' ')
        {
            word += c;
        }
        else
        {
                if(!word.empty())
                {
                        word_array.push_back(word);
                        word.clear();
                }
        }
    }

    if(!word.empty())
    {
            word_array.push_back(word);
    }
    return word_array;
}

template<typename T>
std::vector<T> third_foo(std::set<T> s, T elem)
{
    std::vector<T> answer;
    auto it = s.begin();
    for (it; it != s.end(); ++it)
    {
        if (*it > elem) { answer.push_back(*it); }
    }
    std::reverse(answer.begin(), answer.end());
    return answer;
}

int main()
{
	std::vector<int> v;
	int number;
	int n, m;
	std::cin >> n;
	std::cin >> number;
	for (int i = 0; i < n; i++)
	{
		std::cin >> m;
		v.push_back(m);
	}
	std::vector<int> v1 = first_foo(v, number);
	for (int i = 0; i < v1.size(); ++i)
	{
		std::cout << v1[i] << " ";
	}
	std::cout << std::endl;
	std::cin.ignore();
	std::string str;
	std::getline(std::cin, str);
	std::vector<std::string> v2 = second_foo(str);
	for (int i = 0; i < v2.size(); ++i)
        {
                std::cout << v2[i] << " ";
        }
	std::cout << std::endl;

	std::set<int> mySet;
	for (int i = 0; i < 10; ++i)
	{
		mySet.insert(i);
	}
	std::vector<int> v3 = third_foo(mySet, 5);
	for (int i = 0; i < v3.size(); ++i)
	{
		std::cout << v3[i] << " ";
	}
	std::cout << std::endl;
	return 0;
}
