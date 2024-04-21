include(FetchContent)
FetchContent_Declare(async_simple
        GIT_REPOSITORY https://github.com/alibaba/async_simple.git
        GIT_TAG v1.3
)
FetchContent_MakeAvailable(async_simple)