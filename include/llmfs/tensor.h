#include <vector>

static inline int numel(const std::vector<int> &shape) {
    int total = 1;
    for (auto i : shape) {
        total *= i;
    }
    return total;
}

class Tensor {
    std::vector<int> shape;
    std::vector<float> data;

public:
    Tensor(const std::vector<int> &shape) : shape(shape), data(numel(shape), 0.0f) {}
};