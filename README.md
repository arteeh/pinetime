
# Smartwatch UI design proposal

![Digital clock mockup](drawings/digital.png)
![Analog clock mockup](drawings/analog.png)  
![App menu mockup](drawings/appgrid.png)

![Showcase animation of all mockups](drawings/showcase/PineTimeOS-UI.gif)

[Try the above demo here](https://www.figma.com/proto/Emex60mfx1WePSyYDGaAoB/PineTime-UI-Proposal?node-id=1%3A7&scaling=min-zoom)

This repository contains designs and assets for a GNOME smartwatch. The icons I use for apps and symbols are taken from the [Adwaita icon theme](https://gitlab.gnome.org/GNOME/adwaita-icon-theme).

## UI navigation

![General mockup](drawings/mockup.png)

Here's a mockup of what the whole UI should look like. This image shows which screen appears when you swipe somewhere. For example, when you swipe up from Home, you'll go down and find yourself in the app grid.

Every app except Home shows the time in digital format on the top left, and the battery and bluetooth icons on the top right. These stay even when swiping to other apps. Home only shows the battery (or at least on the watchfaces I made. Other watchfaces can choose to draw whatever they want).

### Home

![Digital clock mockup](drawings/mockup-clock-digital.png)
![Analog clock mockup](drawings/mockup-clock-analog.png)

The main watchface. Gets shown on button press / on screen enable. The above images are examples of what Home may look like. Ideally the user can set their own watchface by selecting a Home app at runtime (in Settings->Favourite apps).

### App grid

![App menu mockup](os-drawings/appgrid.png)

Shows a 3 by 2 grid of app icons. If there are more than 6 apps, you can swipe to the right to see more apps.

(LVGL: Maybe use lv_tabview for this? on swipe right event, move to next tab, on swipe left, move to previous tab. Hide the tab buttons using `lv_tabview_set_btns_hidden(tabview,  true);`)

### Notifications

![Notifications mockup](os-drawings/notifications.png)

Go up from your home screen and you'll see your notifications. If there's more than one notification, swipe to the right to see the next one. Tap on a notification to get rid of it.

### Apps

**Clock**  
Stopwatch, timer and alarm app.

**Music**  
Control music playback of your phone through bluetooth.

**Weather**  
See a nice overview of the weather. Show the temperature, humidity, etc. This is completely reliant on smartphone app functionality.

**Heartbeat**  
Show information of the heartbeat sensor. Maybe draw a nice graph of the past hour, or even 24 hours if there's space.

**Step counter**  
Count your steps. Make an estimation of how many miles/kilometres you have walked/ran. Has a button to reset the counter.

**Settings**  
![Settings menu mockup - what's shown on the screen](drawings/mockup-settings-cut.png)
![Settings menu mockup - all settings](drawings/mockup-settings.png)

This app is used to customize your watch and connect to your phone with Bluetooth. The app shows a list of all the settings in which you can scroll up and down.

Settings are stored by placing variables in flash, so that the settings are not lost on reboot. You could also do without since smartwatches are very rarely rebooted, but it can be a bummer to turn on your watch after it died and you see all your favourite apps and settings set up wrong.

Below is every useful setting + its mockup that I can think of.

*Brightness*

![Brightness setting mockup](drawings/mockup-settings-brightness.png)

Change the brightness of the screen. On tap, the brightness changes (LOW->MID, MID->HIGH, HIGH->LOW).

*Bluetooth*

This screen shows Bluetooth settings:
- Connect to device (show pairing code and confirmation buttons here)
- Disconnect from device
- Turn bluetooth on/off

*Favourite apps*

This setting allows you to set which watchface is assigned as the default home 'app'. You can also set which app is favourite app 1, 2, 3 and 4 (see UI layout). These will then be shown in order if you swipe right from the home screen. Maybe also add an option to set how many favourite apps you want.

*Notifications*

This screen shows notification settings, if there is a notification feature.
- Vibrate on incoming notification?
- Switch to notification on incoming notification?
- Turn on display on incoming notification?

*Display*

This screen lets you choose between the following options:
- Choose when the display turns on:
	- Keep the display always on
	- Turn on the display when holding the watch upwards, or on tap or button press.
	- Turn on the display on tap or button press
	- Turn on the display on button press only
- Time until the display goes back to sleep (options: 5s, 10s, 30s, off)

*Restart this device*

This shows a confirmation dialog on whether the user wants to reboot the device. When 'yes' is pressed, reboot the device. On 'no', go back to the settings screen.

## Icons

I'm providing LVGL-style bitmap .c files in the assets folder alongside their original images. See [the LVGL documentation](https://docs.lvgl.io/latest/en/html/widgets/img.html) for information on how to draw images. For transparency, set LV_COLOR_TRANSP in your lv_conf.h to the color #6cfc6a.

To prepare a GNOME SVG icon for use in LVGL, follow these steps:
- Open the .svg file in GIMP. App icons should be set to 64x64, system icons should be 32x32.
- In GIMP, go to Layer > Transparency > Threshold Alpha, set the slider to a spot to look good
- Add a layer, fill it with #6cfc6a and drag the slider below the icon (to do this faster in bulk, create the layer once, copy it and paste it to all other icons)
- Export the image as a .png file
- Convert the image(s) to C code using [LVGL's image converter](https://lvgl.io/tools/imageconverter). For app icons set 'Color format' to "Indexed 16 colors". For system icons set it to "Indexed 4 colors".


## Colors

Notification background color: #404040
Notification body text color: #	
LVGL transparency color for icons: #6cfc6a

