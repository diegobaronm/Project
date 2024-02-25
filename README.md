# Description
This project is a simple example of an application that is navigated using menus printed to the terminal; after selecting a menu item the app executes an action.
This is a project aimed to demonstrate the usage of:
- Some C++ "advanced" feautures.
- The usage of CMake to configure the build and properly organise the source code.
- Github actions to perform multi-platform build tests.
# How to build
You need a compiler that is C++(14) capable and a recent version (>3.25) of CMake.
```
# Clone the project
git clone https://github.com/diegobaronm/Project.git
cd Project

# To build in release mode
cmake -S . -B build -DCMAKE_BUILD_TYPE=Release
cmake --build build

# To build in debug mode
cmake -S . -B build -DCMAKE_BUILD_TYPE=Debug
cmake --build build

# Run the app!
./build/app/run
```
# C++ features demonstrated
- Abstract classes and polymorphism.
- Debug macros.
- Usage of STL containers (Vector,Map)
- Static class members.
- Smart pointers.
- Typedefs.
- Const qualifiers.
- References.
