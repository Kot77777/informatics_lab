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

struct subforwardlist {

    int data;

    subforwardlist* next;

};
bool init(subforwardlist **sfl){
    *sfl = NULL;
    return true;
}
bool push_back(subforwardlist **sfl, int d){
    if(*sfl != NULL){
        subforwardlist* new_subforwardlist = new subforwardlist;
        new_subforwardlist->data = d;
        new_subforwardlist->next = NULL;
        subforwardlist* tmp;
        tmp = *sfl;
        while(tmp->next!=NULL){
            tmp = tmp->next;
        }
        tmp->next = new_subforwardlist;
    }
    else{
        subforwardlist* new_subforwardlist = new subforwardlist;
        new_subforwardlist->data = d;
        new_subforwardlist->next = NULL;
        *sfl = new_subforwardlist;
    }
    return true;
}
int pop_back(subforwardlist **sfl){
    if(*sfl == NULL){
        return 0;
    }
    if((*sfl)->next == NULL){
        int p = (*sfl)->data;
        delete *sfl;
        *sfl = NULL;
        return p;
    }
    subforwardlist* tmp;
    tmp = *sfl;
    while(tmp->next->next != NULL){
        tmp = tmp->next;
    }
    int k = tmp->next->data;
    delete tmp->next;
    tmp->next = NULL;
    return k;
}
bool push_forward(subforwardlist **sfl, int d){
    subforwardlist* new_subforwardlist = new subforwardlist;
    subforwardlist* tmp;
    tmp = *sfl;
    *sfl = new_subforwardlist;
    new_subforwardlist->data = d;
    new_subforwardlist->next = tmp;
    return true;
}
int pop_forward(subforwardlist **sfl){
    if(*sfl == NULL){
        return 0;
    }
    else{
    subforwardlist* tmp;
    tmp = *sfl;
    *sfl = tmp->next;
    int l = tmp->data;
    delete tmp;
    return l;
    }
}
bool push_where(subforwardlist **sfl, unsigned int where, int d){
    if(where == 0){
        push_forward(sfl, d);
    }
    else{
    unsigned int counter = 0;
    subforwardlist* tmp;
    tmp = *sfl;
    while(counter!=(where-1)){
        tmp = tmp->next;
        counter++;
    }
    subforwardlist* new_subforwardlist = new subforwardlist;
    new_subforwardlist->data = d;
    new_subforwardlist->next = tmp->next;
    tmp->next = new_subforwardlist;}
    return true;
}
int erase_where(subforwardlist **sfl, unsigned int where){
    if(*sfl == NULL){
        return 0;
    }
    else{
        if(where == 0){
            return pop_forward(sfl);
        }
        else{
        unsigned int counter = 0;
        subforwardlist* tmp;
        tmp = *sfl;
        while(counter!=(where-1)){
            tmp = tmp->next;
            counter++;
        }
        unsigned int k = tmp->next->data;
        subforwardlist* tmp1 = tmp->next;
        tmp->next = tmp->next->next;
        delete tmp1;
        return k;}
    }
}
unsigned int size(subforwardlist  **sfl){
    if(*sfl == NULL){
        return 0;
    }
    unsigned int counter = 1;
    subforwardlist* tmp;
    tmp = *sfl;
    while(tmp->next!=NULL){
        tmp = tmp->next;
        counter++;
    }
    return counter;
}
void clear(subforwardlist  **sfl){
    while(*sfl!=NULL){
        int k = pop_back(sfl);
    }
}

void measurePushBackTime(subforwardlist  **sfl, const int num, std::array<unsigned int, 12>& size) {
    std::ofstream file("subforwardlist_push_back_time.txt");

   // std::vector<unsigned int> time_of_push_back(num, 0);
    std::array<std::array<unsigned int, 12>, 2> time_of_push_back;

    for (auto i = 0; i < num; ++i)
    {
        auto random_number = generateRandomNumber() * 10000;
        auto start = steady_clock::now();
        for (int j = 0; j < size[i]; ++j)
        {
                push_back(sfl, random_number);
        }
        auto fin = steady_clock::now();
        auto dur = fin - start;
        clear(sfl);
        file  << duration_cast<nanoseconds>(dur).count()  << std::endl;

    }
    file.close();
}

int main() {
    subforwardlist *sv;
    init(&sv);

    const int num = 12;
    std::array<unsigned int, num> size = {100, 500, 1000, 2000, 3000, 4000, 5000, 6000, 7000, 8000, 9000, 10000};

    measurePushBackTime(&sv, num, size);
   // measureInsertTime(&qv, numElements);
   // measurePopBackTime(&qv, numElements);

    return 0;
}
