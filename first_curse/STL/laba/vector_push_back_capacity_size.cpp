#include <iostream>
#include <vector>
#include <fstream>
#include <chrono>

using namespace std::chrono;

/*struct subvector {
     int *mas;
     unsigned int top;
     unsigned int capacity;
};
void init(subvector *qv){
    qv->top = 0;
    qv->capacity = 0;
    qv->mas = NULL;

}
void resize(subvector *qv, unsigned int new_capacity){
    if (new_capacity < qv->top){
        qv->top = new_capacity;
    }
    int *new_mas = new int[new_capacity];
    for(unsigned int i = 0; i < qv->top; i++){
        new_mas[i] = (qv)->mas[i];
    }
    delete [] (qv)->mas;
    (qv)->mas = new_mas;
    (qv)->capacity = new_capacity;
}
void push_back(subvector *qv, int d){
    if((qv)->capacity < ((qv)->top + 1)){
        resize(qv, (qv)->top + 1);
    }
    ((qv)->mas)[(qv)->top] = d;
    ((qv)->top)++;
    }*/

int main()
{
	const int n = 100000;
	//time for vector: push_back
	std::string vector_push_back = "vector_push_back_capacity_size.txt";
	std::ofstream fout1;

	fout1.open(vector_push_back);

	if (!fout1.is_open())
	{
    		std::cout << "error" << std::endl;
   	}
	else
   	{
   		std::cout << "vector_push_back_capacity_size file is opened" << std::endl;
   		std::vector<unsigned int> vec1;
		for(int i = 1; i <= n; i++)
       		{
			vec1.push_back(i);
			fout1 << vec1.capacity() << " " << vec1.size()<< std::endl;

	        }
	}
	/*
	subvector sv;
	init(&sv);
	std::string subvector_insert = "subvector_insert_size.txt";
        std::ofstream fout2;
        fout2.open(subvector_insert);
	double total1 = 0;
	for (int i = 0; i < n; i++)
   	{
		auto start = steady_clock::now();
		push_bac(&sv, i);
		auto fin = steady_clock::now();	
		auto dur = fin - start;
		total+=dur
		fout2 << duration_cast<milliseconds>(dur).count()  << " " << i+1 << std::endl;
   	}

        std::string vector_insert = "vector_insert_size.txt";
        std::ofstream fout3;
	fout3.open(vector_insert);

	std::vector<int> vec3;
	for (int i = 0; i < n; i++)
        {
		auto start = steady_clock::now();
                vec3.push_back(i);
		auto fin = steady_clock::now();                         
                auto dur = fin - start;
                fout3 << duration_cast<milliseconds>(dur).count()  << " " << i+1 << std::endl;
        }	*/
		
	return 0;
}
