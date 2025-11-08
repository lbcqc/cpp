# Repository Guidelines

## Project Structure & Module Organization
Top-level `CMakeLists.txt` enables the `src/stdcpp` (C++ feature showcases) and `src/leetcode` (algorithm implementations) trees; `src/demo` and `src/stdc` stay available but are opt-in via uncommenting their `add_subdirectory` entries. Each subfolder under `src/stdcpp` targets a single language feature (for example `src/stdcpp/stdcpp20/coroutine`), while the LeetCode solutions live under category folders such as `src/leetcode/stack` or `src/leetcode/tree`. Reusable third-party recipes are collected in `cmake/*.cmake` (spdlog, fmt, boost, async_simple, gflags). Build artifacts are generated under `build/`, so keep source directories clean and checked in code under `src/**`.

## Build, Test, and Development Commands
Run `cmake -S . -B build -DCMAKE_BUILD_TYPE=Release` once to configure every target that is enabled in the root CMake file. Incremental compiles use `cmake --build build -j` and you can focus on a single target with `cmake --build build --target leetcode-array-binary_search`. Executables land under `build/src/<module>/`, so a quick manual verification looks like `./build/src/leetcode/leetcode-array-binary_search`. If you need demo binaries, add their directory in `CMakeLists.txt` before re-running configure.

## Coding Style & Naming Conventions
All C++ is formatted with the repo’s `.clang-format` (Google style, 120-column limit, left-aligned pointers). Run `clang-format -i <files>` before sending changes. Use 2-space indentation as shown in the existing LeetCode samples, prefer `snake_case` file names, and keep target names in the `module-category-topic` pattern already used (`stdcpp11-atomic`, `leetcode-stack-min_stack`). Includes should remain grouped so the formatter can sort within each block, and add concise comments only where the intent is non-obvious.

## Testing Guidelines
There is no centralized test harness—each problem or feature compiles to its own executable with a small `main`. When adding a new algorithm, keep the driver short, cover typical edge cases, and echo representative input/output so results are easy to diff. If you add a formal test, register it with CTest via `add_test(NAME <name> COMMAND <target>)` and document any required assets in the same folder. Favor deterministic inputs and avoid relying on network or filesystem side effects.

## Commit & Pull Request Guidelines
History favors concise, imperative summaries such as `add full bag`. Keep commits focused on one concept and mention the touched module (`leetcode/stack` or `stdcpp20`). Pull requests should include: a one-paragraph description, a checklist of commands you ran (e.g., `cmake --build build -j` and the executables you exercised), related issue links, and screenshots or logs when behavior changes are user-visible. Highlight any new dependencies or CMake options so reviewers can reproduce your setup quickly.
