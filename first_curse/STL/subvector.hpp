struct subvector {
     int *mas;
     unsigned int top;
     unsigned int capacity;
};

void init(subvector *qv);
void resize(subvector *qv, unsigned int new_capacity);
void push_back(subvector *qv, int d);
