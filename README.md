# Console Snake

Lei Mao

## Introduction

The Console Snake game with background music was implemented using C++ and the libraries `libncurses` and `libcplayer`. `libncurses` (new curses) is a programming library providing an application programming interface (API) that allows the programmer to write text-based user interfaces in a terminal-independent manner. [`libcplayer`](https://github.com/leimao/Console_Player)(console player) is a C++ library for playing background audios asynchronously in C++ programs.

## Dependencies

* CMake 3.13.0+
* libncurses 6.1+
* [`libsndfile`](https://github.com/erikd/libsndfile)
* [`libasound`](https://github.com/alsa-project/alsa-lib)
* [`libcplayer`](https://github.com/leimao/Console_Player)

## Installation

### Installation of CMake

Check out [the installation guide from Kitware](https://apt.kitware.com/).

### Installation of Dependencies

```bash
$ sudo apt-get install libncurses-dev libsndfile-dev libasound2-dev
```

### Installation of the Game

Because the installation requires to use `git submodule`, please `git clone` instead of `download` the repository.

```bash
$ git clone https://github.com/leimao/Console_Snake.git
$ cd Console_Snake
$ git submodule update --init --recursive
$ mkdir -p build
$ cd build
$ cmake ..
$ make
$ make install
```

## Usages

### Game Rules

Control the snake to eat food as much as possible. You get one point for every food your snake eat. The level of difficulty would increase every 5 points you get.

### Playing the Game Using Default BGM

```bash
$ cd bin/
$ ./main
```

### Playing the Game Using Custom BGM

The user is also allowed to use custom BGMs.

```bash
$ cd bin/
$ ./main [bgm_sound_file]
```

Currently the game only supports `wav`, `ogg`, and `flac` audio formats.


## Demo

[![Console Snake Demo](demo/console_snake_demo.gif)](https://www.youtube.com/watch?v=6eUeRn3Mdg4 "Console Snake Demo")

For full demo with sound, please click the demo image and watch the YouTube video.

## Feedbacks

If you have encountered any bug, or have any suggestions for improvements, please open an issue ticket in the repository.


## References

* [CMake Dependency Handling](https://foonathan.net/2016/07/cmake-dependency-handling/)
* [Royalty Free Game BGM - Better Sounds](https://opengameart.org/content/better-sounds-nes-version)

## To-Do List

- [ ] Add record board
- [x] Add background music
