# RexyTexy
OS for arduino, esp for controlling screens
## Controling not in real time
### Programming with Python
#### Template #1 - Box
```python3

import pyRexyTexy as rt

scr = rt.Screen(input("> "))

dots = [
  [0, 0], [1, 1],
  [0, 1], [1, 0]
]

for dot in dots:
  scr
  draw(dot[0], dot[1])
```
## Controling in real time
### Accessing screen with CMD
1. Open port controller (In Arduino IDE)
2. Use this commands to control:
```
XY 0.5 0.5 1; //first 0.5 is X second is Y and last is state (0 - Off, 1 - On)
TEXT GitHub; //display the text on screen
```
