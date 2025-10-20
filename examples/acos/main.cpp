#include <torch/torch.h>

// Docs: https://docs.pytorch.org/docs/stable/generated/torch.acos.html
// AVX2/AVX512/NEON: xacosf_u1 (pytorch-submodule/pytorch/third_party/sleef/src/libm/sleefsimdsp.c)
int main() {
    const torch::Tensor in = torch::tensor(
        {
            -1.0f, -0.9f, -0.8f, -0.7f, -0.6f, -0.5f, -0.4f, -0.3f, -0.2f,
            -0.1f, 0.0f, 0.1f, 0.2f, 0.3f, 0.4f, 0.5f, 0.7f, 1.0f,
        },
        torch::kFloat32
    );
    const torch::Tensor out = torch::acos(in);

    const auto data = out.data_ptr<float>();
    for (int i = 0; i < out.size(0); ++i) {
        std::cout << data[i] << std::endl;
    }

    return 0;
}
