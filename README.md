# bright
C program to set brightness on Intel laptops because I didn't want to set keybinds.

There's also a wrapper script to make permissions easier to manage.

# usage
As per the help text:
```
set display brightness on intel laptops: bright -s num
options:
	-s num	set numerical brightness value
	-m	display max brightness value
	-c	display current brightness value
	-h	print this message

brightness number must be within range specified in /sys/class/backlight/intel_backlight/max_brightness
keep in mind that you will need sufficient privileges to edit these values. do a setuid or write a wrapper.
created by jason walter because he didn't feel like setting keybinds

```

# license
Licensed GNU GPLv3
