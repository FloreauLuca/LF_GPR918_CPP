#include <iostream>
#include <memory>

void swap(int* a, int* b)
{
    //This function swaps the values contained in the two pointers
    int* c = a;
    a = b;
    b = c;

}

void print_values(std::unique_ptr<int> c, int* b)
{
    //This function shows the values and their pointer
    std::cout << "The value a is: "<< *c << " and is contained in address: "<< c <<"\n";
    std::cout << "The value b is: "<< *b << " and is contained in address: "<< b <<"\n";
}

int main(const char* argv, int argc)
{
    int a = 4;
    int b = 3;
	std::unique_ptr<int> c = std::make_unique<int>(4);
	a = 6;

	int * q = &a;
    print_values(std::move(c), &b);

    swap(&a, &b);

    print_values(std::move(c),&b);

    //Windows specific
    system("pause");
    return 0;
}
