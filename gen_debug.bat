rm .\compile_commands.json
cmake -B build -DCMAKE_BUILD_TYPE=Debug -G "Ninja" -DCMAKE_CXX_COMPILER=clang++ -DCMAKE_C_COMPILER=clang
ln .\build\compile_commands.json .\compile_commands.json
