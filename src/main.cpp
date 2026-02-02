#include <iostream>

#include <llmfs/tensor.h>

int main() {
    Tensor t{2, 7};
    std::cout << t << std::endl;

    return 0;
}