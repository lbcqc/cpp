include(FetchContent)
FetchContent_Declare(boost
        GIT_REPOSITORY https://github.com/boostorg/boost.git
        GIT_TAG boost-1.85.0
)
FetchContent_MakeAvailable(boost)
