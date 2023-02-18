#include <iostream>
#include <vector>
#include "backward.hpp"

int main()
{
	std::vector<int32_t> A;
	A[1] = 1;
	for (auto i = A.begin(); i != A.end(); ++i) {
		std::cout << *i << std::endl;
	}
    return 0;
}

