git submodule add https://github.com/google/googletest.git external/googletest
rm -rf build/
mkdir -p build/
cd build
cmake ..
make