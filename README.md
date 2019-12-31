# bright
dumb c program to set brightness on intel laptops because i didn't want to set keybinds

there's also a wrapper script in here because i was feeling generous

# usage
as per the help text:
```
set display brightness on intel laptops: bright -s num
options:
	-s num	set numerical brightness value
	-m	display max brightness value
	-h	print this message

brightness number must be within range specified in /sys/class/backlight/intel_backlight/max_brightness
keep in mind that you will need sufficient privileges to edit these values. do a setuid or write a wrapper, it's not my problem
created by jason walter because he didn't feel like setting keybinds

```

#license
licensed gnu gplv3
