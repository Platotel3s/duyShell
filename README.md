# duyShell 🐚

A lightweight, custom Linux command-line shell written in modern C++20, built directly on top of POSIX system calls.

## ✨ Features
- **REPL Loop** with custom colored prompt (`duyShell ~> dir$`)
- **Process Management** via native `fork()`, `execvp()`, and `waitpid()`
- **Built-in Commands**: `cd` (with `$HOME` fallback) and `exit`
- **Signal Handling**: Safely ignores `SIGINT` (`Ctrl+C`) on the parent shell process
- **System-wide Installation** supported via CMake

## 🛠️ Prerequisites
- Linux OS (Tested on Fedora Linux)
- C++20 compatible compiler (`GCC` or `Clang`)
- `CMake` (3.20+) & `Ninja`

## 🚀 Build & Install

```bash
# Configure and build release binary
cmake -B build -G Ninja -DCMAKE_BUILD_TYPE=Release
cmake --build build

# Install system-wide to /usr/local/bin
sudo cmake --install build
```

## 💻 Usage
Run directly from your current terminal:
```bash
duyShell
```

*(Optional)* Register as a valid login shell:
```bash
echo "/usr/local/bin/duyShell" | sudo tee -a /etc/shells
chsh -s \$(which duyShell)
```

## 🗺️ Roadmap
- [x] Basic REPL & external command execution
- [x] Built-in `cd` and `exit`
- [ ] I/O Redirection (`>`, `>>`, `<`)
- [ ] Multi-stage Piping (`|`)
- [ ] Command history & Tab auto-completion

