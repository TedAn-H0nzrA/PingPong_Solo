# Ping Pong Game 🏓

## Description

A classic Ping Pong game implemented in C++ using SFML (Simple and Fast Multimedia Library). The game features a paddle that can move horizontally to bounce a ball and prevent it from falling.

## Features

- Smooth paddle movement
- Ball physics with realistic bouncing
- Window boundary collision detection
- Customizable game constants

## Prerequisites

### Dependencies

- SFML Library
- CMake (version 3.10 or higher)
- C++ Compiler supporting C++11 or later

### Supported Platforms

- Linux
- macOS
- Windows

## Installation

### Dependencies Installation

#### Ubuntu/Debian

```bash
sudo apt-get update
sudo apt-get install libsfml-dev cmake g++
```

#### macOS (using Homebrew)

```bash
brew install sfml cmake
```

#### Windows

- Download SFML from official website
- Install Visual Studio with C++ support
- Configure SFML in your development environment

## Compilation

### Using CMake

```bash
# Clone the repository
git clone https://github.com/TedAn-H0nzrA/PingPong_Solo.git
cd PingPong_Solo

# Create build directory
mkdir build
cd build

# Generate build files
cmake ..

# Build the project
make
```

## Controls

- `Left Arrow`: Move paddle left
- `Right Arrow`: Move paddle right
- `Escape`: Pause/Exit game (to be implemented)

## Project Structure

```
ping-pong-game/
│
├── src/
│   ├── Game.cpp
│   ├── Palette.cpp
│   ├── Balle.cpp
│   └── main.cpp
│
├── include/
│   ├── Game.hpp
│   ├── Palette.hpp
│   ├── Balle.hpp
│   └── Constant.hpp
│
├── CMakeLists.txt
└── README.md
```

## Game Configuration

You can modify game parameters in `include/Constant.hpp`:

- Screen dimensions
- Ball speed and size
- Paddle size and speed
- Frame rate

## Planned Improvements

- Score tracking
- Multiple difficulty levels
- Sound effects
- Main menu
- Game over screen

## Troubleshooting

- Ensure SFML is correctly installed
- Check CMake configuration
- Verify compiler compatibility

<!-- ## Contributing

1. Fork the repository
2. Create your feature branch (`git checkout -b feature/AmazingFeature`)
3. Commit your changes (`git commit -m 'Add some AmazingFeature'`)
4. Push to the branch (`git push origin feature/AmazingFeature`)
5. Open a Pull Request -->

## Contact

TedAn H0nzrA - <tedan.h0nzra@gmail.com>

Project Link: [Ping Pong Game](https://github.com/TedAn-H0nzrA/PingPong_Solo.git)
