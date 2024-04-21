include(FetchContent)
FetchContent_Declare(flag
        GIT_REPOSITORY https://github.com/gflags/gflags.git
        GIT_TAG v2.2.2
)
FetchContent_MakeAvailable(flag)