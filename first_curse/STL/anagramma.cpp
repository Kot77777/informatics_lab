#include <iostream>
#include <string>
#include <map>

int main()
{
	std::string word1, word2;
	std::multimap<int, char> myMap1;
	std::multimap<int, char> myMap2;
	std::cin >> word1;
	std::cin >> word2;
	
	for(int i = 0; i < word1.size(); ++i)
	{
		myMap1.emplace(word1[i], i);
	}

	for(int i = 0; i < word2.size(); ++i)
        {
                myMap2.emplace(word2[i], i);
        }
	std::cout << (myMap1 == myMap2);
	for (auto it = myMap1.begin(); it != myMap1.end(); ++it) {
        int key = it->first;
        std::cout << "Key: " << key << std::endl;
    	}
	for (auto it = myMap2.begin(); it != myMap2.end(); ++it) {
        int key = it->first;
        std::cout << "Key: " << key << std::endl;
    	}
	        if(word2.size() != word1.size())
        {
                std::cout << "NO" << std::endl;
        }

	else
	{
		bool A = true;
		auto it1 = myMap2.begin();
		for (auto it = myMap1.begin(); it != myMap1.end(); ++it)
		{
			std::cout << it->first << " " << it1->first << std::endl;
			if(it->first != it1->first)
			{
				A = false;
				break;
			}
			it1++;
		}
		if(A)
		{
			std::cout << "YES" << std::endl;
		}
		else
		{
			std::cout << "NO" << std::endl;
		}
	}
	return 0;
}

