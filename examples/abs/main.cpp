#include <torch/torch.h>

// Docs: https://docs.pytorch.org/docs/stable/generated/torch.abs.html
// Scalar: abs_impl (pytorch/aten/src/ATen/native/Math.h)
// AVX2: abs() (pytorch/aten/src/ATen/cpu/vec/vec256/vec256_float.h)
// AVX512: abs() (pytorch-submodule/pytorch/aten/src/ATen/cpu/vec/vec512/vec512_float.h)
// NEON: abs() (pytorch/aten/src/ATen/cpu/vec/vec128/vec128_float_neon.h)
int main() {
    const torch::Tensor in = torch::tensor(
        {
            -1.5f, 0.0f, 1.0f, -1.5f, 2.0f, -2.5f, 3.0f, -3.5f, 4.0f,
            -5.0f, 6.0f, -7.0f, 8.0f, -9.0f, 10.0f, -11.0f, 12.0f, -13.0f,
        },
        torch::kFloat32
    );
    const torch::Tensor out = torch::abs(in);

    const auto data = out.data_ptr<float>();
    for (int i = 0; i < out.size(0); ++i) {
        std::cout << data[i] << std::endl;
    }

    return 0;
}
