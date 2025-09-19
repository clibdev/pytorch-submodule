# PyTorch as Submodule

## Instructions

* Install dependencies:

```shell
sudo apt install -y g++ cmake ninja-build python3-six
```

* Clone repository:

```shell
git clone https://github.com/clibdev/pytorch-submodule.git && cd pytorch-submodule
```

* Clone PyTorch

```shell
git clone --recursive https://github.com/pytorch/pytorch.git --branch=v2.8.0
```

* Build program:

```shell
rm -rf build
cmake -S . -B build -G Ninja -DCMAKE_BUILD_TYPE=Release -DBUILD_PYTHON=OFF -DCMAKE_POLICY_VERSION_MINIMUM=3.5
cmake --build build -j$(nproc)
```

* Run program:

```shell
./build/pytorch_submodule
```

* (Optional) Apply patches:

```shell
git apply patches/linspace_kernel.patch --directory pytorch
```
