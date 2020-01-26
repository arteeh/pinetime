
# PineTimeOS

This repository contains designs and assets for a UI for the PineTime. The icons I use for apps and symbols are taken from the GNOME Project, more specifically the [Adwaita theme](https://github.com/GNOME/adwaita-icon-theme). No code is included for now. I want to build these ideas on other people's low-level/backend work like:

- [Koen's project running on RIOT, LittleVGL and NimBLE](https://github.com/bosmoment/PineTime-apps)
- [JF's project using FreeRTOS](https://github.com/JF002/Pinetime)

I'm open to work with other firmware as well.


## Icons

I'm providing LittleVGL-style bitmap .h files in the assets folder alongside their png's. In RIOT, these header files could also be distributed on a per-widget basis by placing them in /widgets/your_widget/include.

See [the LittleVGL documentation](https://docs.littlevgl.com/en/html/object-types/img.html) for how to draw images.

To get transparency to work, set LV_COLOR_TRANSP in your lv_conf.h (in apps/your_app to the color 6cfc6a (I'm not sure how: replacing LV_COLOR_LIME with 0x6cfc6a did not work, it needs to be in a different format).

If not using LittleVGL, you can write a function that grabs pixels from a bitmap and draws them using a drawPixel() function. See graphics-library.c for an example.


## UI Layout

1. Main watchface
2. Favourite apps 1, 2, 3 and 4
3. App overview (show a grid of all apps, swipe right to see more apps (if there are more than 6 apps))
4. Notification overview

Every number represents a 240x240 screen shown on the watch.

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

![General mockup](design/mockup.png)

Here's a WIP mockup of what the whole UI should look like. Note that this overview isn't representative of how the UI is actually drawn. This purely shows which screen/app appears when you swipe somewhere. For example, when you swipe upwards from Home, you'll find yourself in the App menu app.

## Apps

Every app except Home shows the time in digital format on the top left, and the battery and bluetooth icons on the top right. These stay even when swiping to other apps. Home only shows the battery (Or at least on the watchfaces I made. Other watchfaces can choose to draw whatever they want.)

Most apps described here are just ideas, and don't need to be built immediately.

### Home

![Analog clock mockup](design/mockup-clock-analog.png)
![Digital clock mockup](design/mockup-clock-digital.png)

The main watchface. Gets shown on button press / on screen enable. Can be either of the two images above or implement a functionality to set the 'home app' at runtime (in Settings->Favourite apps).

### App menu

![App menu mockup](design/mockup-appmenu.png)

Shows a 3x2 grid of app icons (and the title of the app, if there's space for that). If there are more than 6 apps, you can swipe right to see more apps. Make this 2x2 if the buttons are too small. LittleVGL: Maybe use lv_tabview for this? on swipe right event, move to next tab, on swipe left, move to previous tab. Hide the tab buttons using `lv_tabview_set_btns_hidden(tabview,  true);`

### Clock

Stopwatch, timer and alarm app.

### Music

Control music playback of your phone.

### Weather

See a nice overview of the weather. Show the temperature, humidity, etc. This is completely reliant on smartphone app functionality.

### Heartbeat

Show information of the heartbeat sensor. Maybe draw a nice graph of the past hour, or even 24 hours if there's space.

### Step counter

Count your steps. Make an estimation of how many miles/kilometres you have walked/ran. Has a button to reset the counter.

### Settings

This widget is used to customize your watch and connect to your phone with Bluetooth. The widget shows a list (similar to the current menu_tiles, except every item in the list has an icon if possible) of all the settings in which you can scroll up and down. 

Settings are stored by storing variables in flash, so that the settings are not lost on reboot. (Does RIOT have a feature for this?) You could also do without since smartwatches are very rarely rebooted, but it can be a bummer to turn on your watch after it died and you see all your favourite apps and settings set up wrong.

Below is every useful setting I can think of.

#### Brightness

Front end:
- On tap, increase the brightness (or set it to low if currently high)
- On button press, return to Settings
- Draw some kind of visualization (maybe with the battery icon) to indicate the current brightness (and update it on press)

Back end:
- On tap, call setBrightness(). The parameter you give it is (settingGetBrightness()+1) (or if it's 3, do -2).
- This widget can uses the brightness.h icon

Functions to implement:

- setBrightness() - This changes the active brightness. Parameter 1 is low, 2 is mid and 3 is high. Also calls settingsSetBrightness to update the setting in flash.
```c
// Code for RIOT but the implementations are similar elsewhere. This should be in modules/hal/hal.c
void setBrightness(int brightness)
{
	gpio_set(LCD_BACKLIGHT_LOW);
	gpio_set(LCD_BACKLIGHT_MID);
	gpio_set(LCD_BACKLIGHT_HIGH);
	switch(brightness)
	{
		case 1: gpio_clear(LCD_BACKLIGHT_LOW); break;
		case 2: gpio_clear(LCD_BACKLIGHT_MID); break;
		case 3: gpio_clear(LCD_BACKLIGHT_HIGH); break;
	}
	settingSetBrightness(brightness);
}
```
- settingSetBrightness(int brightness) - This stores the brightness integer at a certain spot in flash so it can be retrieved later.
- settingGetBrightness() - This reads the brightness setting from flash and returns it.

#### Favourite apps

This setting allows you to set which watchface is assigned as the default home 'app'. You can also set which app is favourite app 1, 2, 3 and 4 (see UI layout). These will then be shown in order if you swipe right from the home screen. Maybe also add an option to set how many favourite apps you want.

#### Bluetooth

This screen shows Bluetooth settings:
- Connect to device (show pairing code and confirmation buttons here)
- Disconnect from device
- Turn bluetooth on/off

#### Display

This screen lets you choose between the following options:
- Choose when the display turns on:
	- Keep the display always on
	- Turn on the display when holding the watch upwards, or on tap or button press.
	- Turn on the display on tap or button press
	- Turn on the display on button press only
- Time until the display goes back to sleep (options: off, 5s, 10s, 30s)

#### Notifications

This screen shows notification settings, if there is a notification feature.
- Vibrate on incoming notification?
- Switch to notification on incoming notification?
- Turn on display on incoming notification?

#### Reboot

This screen shows a confirmation dialog on whether the user wants to reboot the device. When 'yes' is pressed, reboot the device. On 'no', go back to the settings screen.

## Battery icon information

### Colors used in icons

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
Background | #6cfc6a (Is the designated 'transparent' color, will be skipped when drawing. See 'Drawing images')


### Images to use per battery life percentage

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

