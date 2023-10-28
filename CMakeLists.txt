cmake_minimum_required (VERSION 3.8)

# Enable Hot Reload for MSVC compilers if supported.
if (POLICY CMP0141)
  cmake_policy(SET CMP0141 NEW)
  set(CMAKE_MSVC_DEBUG_INFORMATION_FORMAT "$<IF:$<AND:$<C_COMPILER_ID:MSVC>,$<CXX_COMPILER_ID:MSVC>>,$<$<CONFIG:Debug,RelWithDebInfo>:EditAndContinue>,$<$<CONFIG:Debug,RelWithDebInfo>:ProgramDatabase>>")
endif()

project ("Renderer")

include_directories(include)

# Add source files.
file(GLOB SOURCES "src/*.cpp")

add_executable (Renderer WIN32 ${SOURCES} app.rc)

set(CPP_LIBRARIES_DIR "C:/Program Files/Cpp Libraries")

# Connect SFML library.
set(SFML_STATIC_LIBRARIES TRUE)
set(SFML_DIR "${CPP_LIBRARIES_DIR}/SFML-2.6.0/lib/cmake/SFML")
find_package(SFML 2.6.0 REQUIRED graphics network audio window system)

# Connect Fly Engine.
find_package(FLY REQUIRED PATHS "${CPP_LIBRARIES_DIR}/Fly Engine/lib/cmake")

# Link libraries.
target_link_libraries(Renderer sfml-graphics fly-engine)

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET Renderer PROPERTY CXX_STANDARD 17)
endif()