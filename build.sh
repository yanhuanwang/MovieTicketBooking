# git submodule update --init --force
rm -rf build/
mkdir -p build/
cd build
cmake ..
make