#include <iostream>
#include <string>
#include <cassert>

#include <llmfs/tensor.h>

int Tensor::ndim() const {
    return shape_.size();
}

float* Tensor::data() const {
    return data_;
}

const std::vector<int>& Tensor::shape() const {
    return shape_;
}

static inline int n_previous(const std::vector<int> &dim, const std::vector<int> &pos) {
    assert(dim.size() == pos.size());
    int cnt = 0;
    int current_dim = 0;

    for (auto i : pos) {
        int n_this_dim = 1;
        for (auto j = dim.begin() + current_dim + 1; j != dim.end(); j++) {
            n_this_dim *= *j;
        }
        cnt += i * n_this_dim;
        current_dim++;
    }

    return cnt;
}

void print_tensor(std::ostream &os, const Tensor &t, std::vector<int> &dim_pos) {
    int ndim = t.ndim();
    int previous_dims = dim_pos.size() - 1;


    if (previous_dims == ndim - 1) {
        // This is the last dim;
        std::cout << std::string(previous_dims, ' ') << '[';

        auto shape = t.shape();

        int n_print = shape.back();

        int i_begin = n_previous(t.shape(), dim_pos);
        int i_end = i_begin + n_print;

        for (int i = i_begin; i < i_end; i++) {
            os << t.data()[i];
            if (i != i_end - 1) {
                os << ", ";
            }
        }

        std::cout << ']';
    } else {
        // Not the last dim;
        std::cout << std::string(previous_dims, ' ') << '[' << std::endl;

        int shape_at_dim = t.shape()[previous_dims];
        for (int i = 0; i < shape_at_dim; i++) {
            dim_pos.push_back(i);
            print_tensor(os, t, dim_pos);
            dim_pos.pop_back();
        }

        std::cout << std::string(previous_dims, ' ') << ']';
    }


    if (previous_dims != 0) {
        std::cout << std::endl;
    }
}

std::ostream& operator<<(std::ostream& os, const Tensor& t) {

    // Ok, this will be nasty, we will to this recursively.
    std::vector<int> dim_pos{0};
    print_tensor(os, t, dim_pos);
    return os;
}

Tensor::~Tensor() {
    free(this->data_);
}