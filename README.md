# Interference-Optics

The code in this repository applies concepts of optical physics, and currently operates without user-input.
(Interference with Thin Films will be added soon)

## Overview

This program covers Interference Optics and calculates the minimal thicknesses of a liquid layer (given seven color wavelengths) needed to achieve constructive and destructive interference in a combination of three solutions. All mechanics are based on the Linked List data structure, but to keep things simple, I have placed a limit of three liquids at a time.

**Process of Program**
1. An array of wavelengths is created. Each item in the array is a random wavelength from each color.
2. Beaker object/linked list is made with three layers
3. The minimal thickness of the layer (most of the time second) to achieve constructive interference with the given wavelength is calculated.
4. The same procedure is done for destructive interference.

