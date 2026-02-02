#include <iostream>
#include <vector>
#include <initializer_list>

static inline int numel(const std::vector<int> &shape) {
    int total = 1;
    for (auto i : shape) {
        total *= i;
    }
    return total;
}

class Tensor {
    std::vector<int> shape_;
    float* data_;

public:
    Tensor(const std::vector<int> &shape) : shape_(shape), data_(static_cast<float*>(malloc(sizeof(float) * numel(shape)))) {}
    Tensor(const std::initializer_list<int> &s) : Tensor(std::vector<int>(s)) {}
    ~Tensor();

    int ndim() const;
    const std::vector<int>& shape() const;
    float* data() const;
};

std::ostream& operator<<(std::ostream& os, const Tensor& t);