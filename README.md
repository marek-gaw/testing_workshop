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

## Code

Cats and Mice: cat tries to catch a mouse. Cat does not know where a mouse is, but knows in which direction mouse moves.
Mouse starts at random position, cat start at the corner of a plane of a size of 10x10. Cats and moice always move for one step.
Mouse moves randomly, cat - towards mouse.
Chase is over if cat is at the same place as mouse, or 10 rounds passed.

Functions to be implemented:
1. Generation of random position of a mouse (mouse cannot start at the position of other mouse and in the corner)
2. Generation of random position of a cat (with constraint)
3. Generation of movement vector of a mouse
4. Calculation in which direction cat should move.s

## References

[1](https://cpp-polska.pl/post/testy-jednostkowe-z-googletest)
[2](https://stackoverflow.com/questions/42162014/gtest-installed-with-conan-undefined-reference)
