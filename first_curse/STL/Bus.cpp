#include <iostream>
#include <vector>
#include <string>
#include <map>

std::vector<std::string> get_words(const std::string& str)
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

void NEW_BUS(const std::vector<std::string>& vec_str, std::map<std::string, std::vector<std::string>>& BUS)
{
	std::vector<std::string> vec;
	for (int i = 3; i < vec_str.size(); i++)
	{
		vec.push_back(vec_str[i]);
	}
	BUS.emplace(vec_str[1], vec);
}

bool find(const std::vector<std::string>& str, const std::string& stop)
{
	for(auto& item : str)
	{
		if(item == stop)
		{
			return true;
		}
	}
	return false;
}

void BUSES_FOR_STOP(const std::vector<std::string>& vec_str, std::map<std::string, std::vector<std::string>>& BUS, std::map<int, std::string>& sort_BUS)
{
	bool A = false;
	for(auto& item : sort_BUS)
	{
		auto it = BUS.find(item.second);
		if(find(it->second, vec_str[1]))
		{
			A = true;
			std::cout << it->first << " ";
		}	

	}
	if(A){
	std::cout << std::endl;}
	if(!A)
	{
		std::cout << "No stop" << std::endl;
	}
}

void STOPS_FOR_BUS(const std::vector<std::string>& vec_str, std::map<std::string, std::vector<std::string>>& BUS, std::map<int, std::string>& sort_BUS)
{
	auto it = BUS.find(vec_str[1]);
	for(auto& item : it->second)
	{
		std::cout << "Stop " << item << ": ";
		bool A = false;
	        for(auto& item2 : sort_BUS)
       		 {
        	        auto it2 = BUS.find(item2.second);
        	        if(find(it2->second, item) && it2->first != it->first)
       		        {
                	        A = true;
                       		std::cout << it2->first << " ";
               		}

       		 }
		 if(A){
      		 std::cout << std::endl;}
       		 if(!A)
       		 {
       		         std::cout << "no interchange" << std::endl;
      		 }
	}
}

int main()
{
        int Q;
        std::cin >> Q;
        std::cin.ignore();
        std::map<std::string, std::vector<std::string>> BUS;
        std::map<int, std::string> sort_BUS;
        std::string str;
        std::vector<std::string> vec_str;
        std::vector<std::vector<std::string>> quest;
        for (int i = 0; i < Q; i++)
        {
                std::getline(std::cin, str);
                vec_str = get_words(str);
                quest.push_back(vec_str);
        }
        for(int i = 0; i < Q; i++)
        {
                if(quest[i][0] == "NEW_BUS")
                {
                        NEW_BUS(quest[i], BUS);
                        sort_BUS.emplace(i, quest[i][1]);
                }
                if(quest[i][0] == "BUSES_FOR_STOP")
                {
                        BUSES_FOR_STOP(quest[i], BUS, sort_BUS);
                }
                if(quest[i][0] == "STOPS_FOR_BUS")
                {
			auto it = BUS.find(quest[i][1]);
			if(it != BUS.end())
			{
                       		STOPS_FOR_BUS(quest[i], BUS, sort_BUS);
			}
			else 
			{
				std::cout << "No bus" << std::endl;
			}
                }
		if(quest[i][0] == "ALL_BUSES")
		{
			if(!BUS.empty()){
				for(const auto& pair : BUS)
				{
					std::cout << "Bus " << pair.first << ": ";
					for(const auto& item : pair.second)
					{	
						std::cout << item << " ";
					}
					std::cout << std::endl;
				}
			}
			else
			{
				std::cout << "No buses" << std::endl;
			}
		}

        }
        return 0;
}
