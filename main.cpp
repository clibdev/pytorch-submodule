#include <torch/torch.h>

int main() {
    torch::Tensor tensor = torch::linspace(0.00085, 0.012, 1000, torch::TensorOptions().dtype(torch::kFloat64));
    auto data = tensor.data_ptr<double>();
    for (int i = 0; i < tensor.size(0); ++i) {
        std::cout << data[i] << std::endl;
    }

    return 0;
}
