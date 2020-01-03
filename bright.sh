#!/bin/bash
# stupid wrapper. edit this to your preferences so it's comfy in your $PATH
# notice that i've changed the name of the executable to bright1; this way i could rename this script to "bright" 
# also this isn't licensed because that would be mega stupid

if [ "$1" = "-s" ]; then
	sudo sh -c "/usr/bin/bright1 $1 $2"
else
	sh -c "/usr/bin/bright1 $1 $2"
fi
