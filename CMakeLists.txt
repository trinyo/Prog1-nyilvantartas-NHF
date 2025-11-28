# 1. Minimum required version of CMake
cmake_minimum_required(VERSION 3.16)

# 2. Define the project name and enable C language support
# Assuming this is a C project based on the .c and .h extensions
project(Prog1-nyilvantartas-NHF C)

# 3. Define the C standard (optional, but highly recommended)
set(CMAKE_C_STANDARD 11) # Use 11 or 17 for newer standards
set(CMAKE_C_STANDARD_REQUIRED True)

# ... (Sections for cmake_minimum_required, project, and CMAKE_C_STANDARD) ...

# 4. Define the executable target name and list ALL source files
add_executable(
        MyCProject
        src/adatkezeles.c
        src/fajlkezeles.c
        src/main.c
        src/menuElemek.c
        src/strukturak.c

        # Check if 'debugmalloc.c' exists and needs to be added, though often it's header-only.
)

# 5. Tell the compiler where to find the header files (if your headers are in 'include/')
target_include_directories(
        MyCProject
        PRIVATE
        ${CMAKE_SOURCE_DIR}/include
)
target_compile_options(
        MyCProject
        PRIVATE
        -Wall
        -Werror
)
# Note: The headers inside 'src' (like debugmalloc.h) don't need a special path,
# as the compiler usually searches the source directory by default,
# but it's cleaner to keep all headers in 'include'.k