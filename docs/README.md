# NVF2 Software

This repository holds all the modules used to run the NVF2 software.

This project is used in conjection with [NVFSW-PIO](""), as one of its libraries. 

\* This project is still a work in progress.

## Content

The library is organised by:

- Board (and common)
- Packages
- Apps
- Hardware Abstraction

The `Apps` and `Packages` in folders categorised by `Board` is Board specific, those outside a `Board` folder is common to all boards.

### Package

Or as represented by "pkg" shorthand, is defined as the `"main"` function of the board. This will consists of 1 or more [apps](#app). These apps will be like a module that is included in the `pkg`.


### App

Or as represented by "app" shorthand, is defined as 1 feature running on the board. This app will consist of 1 or more [hardware abstracton](#hardware-abstraction). The hardware layer protocols (ie. canbus) is abstracted to [hardware abstracton](#hardware-abstraction) and features that uses canbus to send and receive data (ie. R2D) is performed in `App`, rather than at a higher level, `Pkg` or repeating the nuances of low level hardware functions abstracted by `hardware abstraction`.


### Hardware Abstraction

Does not have a prefix. its name is the peripheral. These abstractions will take care of low level or direct handling with stm32 HAL to provide a simpler API for Apps or packages to use peripherals without repeating the setups and bother about monitoring the hardware.
