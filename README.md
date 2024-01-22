# Description
This project is a simple of example of an app that can be navigated using menus; after selecting a menu item the app executes an action.
This is a project is aimed to show the usage of some C++ "advanced" feautures, along with the usage of CMake to configure the build.
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