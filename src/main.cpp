#include <iostream>

#include <llmfs/tensor.h>

int main() {
    std::cout << "hello, world" << std::endl;
    Tensor t{2, 3};
    std::cout << t;
    return 0;
}