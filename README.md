# PineTimeOS

My work on the softare for the PineTime smartwatch. Below are notes and design stuff I made for myself.

![Analog clock mockup](design/mockup-clock-analog.png)
![Digital clock mockup](design/mockup-clock-digital.png)
![App menu mockup](design/mockup-appmenu.png)

![General mockup](design/mockup.png)

(The arrows indicate the screen that will be shown when swiped to that area)


## Links

PNG to C bitmap converter: 
http://rinkydinkelectronics.com/t_imageconverter565.php

Graphics library inspiration: 
https://github.com/adafruit/Adafruit-GFX-Library/blob/master/Adafruit_GFX.cpp

## Gnome icons to port

- Battery
- Bluetooth
- Brightness
- Loading (spinner)
- Screen
- Clock
- Message (notification)


## Battery icon colors

Color | Hex
------|-----
White	| #ffffff
Light grey| #e6e6e6
Dark grey| #c0c0c0
Orange| #f57900
Dark orange| #a25000
Red | #e01b24
Dark red | #801b24
Green | #
Dark green | #
Background | #6cfc6a (Is the designated 'transparent' color, will be skipped when drawing)

## Images to use per battery life percentage

Battery life | Icon | Icon when charging
-------------|------|---------------------
100 to 90 | battery100 | batterycharging100
90 to 80 | battery90 | batterycharging90
80 to 70 | battery80 | batterycharging80
70 to 60 | battery70 | batterycharging70
60 to 50 | battery60 | batterycharging60
50 to 40 | battery50 | batterycharging50
40 to 30 | battery40 | batterycharging40
30 to 20 | battery30 | batterycharging30
20 to 10 | battery20 | batterycharging20
10 to 5 | battery10 | batterycharging10
5 to 0 | battery5 | batterycharging5

## UI Layout

1. Main watchface
2. Important apps
3. App overview
4. Notification overview

Every number is a 240x240 screen.

```
-------------------------
| 3 | 3 | 3 | 3 | 3 | 3 |
-------------------------
| 4 | 1 | 2 | 2 | 2 | 2 |
-------------------------
| 4 |
-----
| 4 |
-----
```

When entering 3 and 4, fade in and show the battery and time on a top bar.
When a notification comes in, automatically switch to 4 (and turn on the display if set).

## App ideas

- Weather (Temperature, humidity, etc.)
- Clock (stopwatch, timer, alarm)
- Music (control music that plays on your phone)
- Heartbeat sensor
- Step counter
- Compass
- Settings

## Settings to include in the Settings app

- Brightness (low, medium, high)
- Important apps (apps to show when swipe right from watchface, set order as well)
- Bluetooth
- Display on/off, (keep display always on? turn on when holding the watch upwards?)
- Set Main watchface
- Customize watchfaces?
- Notifications (On incoming notification, vibrate? Switch to notif screen?)

## How animations will work

Build a large image of all 'screens' and store in memory.
Then grab the 240x240 part that will be drawn on the screen.
On swipe, move the drawn part to the swiped direction.
Redraw every 60 hertz (16.67ms) (more or less depending on performance/battery life)

Alternatively: Don't make a big rectangle map: only draw the active screen, and either:
- every screen around it, so they can be swiped towards and already be loaded
- Draw the to-be-active screen on swipe action.
