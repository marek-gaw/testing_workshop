# Gtest boilerplate

GTest & GMock preliminary workshop before Code Retreat

## Conan installation

```
sudo apt install python3-pip
pip3 install --upgrade setuptools
pip3 install wheel
pip3 install conan
```

## Project setup

```
mkdir build
cd build
conan install .. --build missing -s compiler=gcc -s compiler.version=7.4 -s compiler.libcxx=libstdc++11
```

## Visual Studio Code

### Extensions

* https://marketplace.visualstudio.com/items?itemName=hbenl.vscode-test-explorer
* 

## References

[1](https://cpp-polska.pl/post/testy-jednostkowe-z-googletest)
[2](https://stackoverflow.com/questions/42162014/gtest-installed-with-conan-undefined-reference)
