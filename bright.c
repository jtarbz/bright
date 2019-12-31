#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

/* this guy prints the help message, then exits */
void print_help(void) {
    printf("set display brightness on intel laptops: bright -s num\n \
            options:\n \
                \t-s num\tset numerical brightness value\n \
                \t-m\tdisplay max brightness value\n \
                \t-h\tprint this message\n\n \
            brightness number must be within range specified in /sys/class/backlight/intel_backlight/max_brightness\n \
            keep in mind that you will need sufficient privileges to edit these values. do a setuid or write a wrapper, it's not my problem\n \
            created by jason walter because he didn\'t feel like setting keybinds\n");

    exit(1);
}

/* this guy returns the maximum brightness as defined in /sys/class/backlight/intel_backlight/max_brightness */
int get_max_bright(void) {
    FILE *fp_max_bright;
    int max;

    fp_max_bright = fopen("/sys/class/backlight/intel_backlight/max_brightness", "r");
    fscanf(fp_max_bright, "%d",  &max);     // grab max value
    fclose(fp_max_bright);
    
    return max;
}

int main(int argc, char **argv) {
    int option;	// for getopt()
    int max;	// maximum brightness value
    FILE *fp_sys_bright;
    
    if(argc < 2) print_help();
    
    max = get_max_bright();
    
    /* loop through given options */
    while((option = getopt(argc, argv, ":s:m")) != -1) {
        switch(option) {
            case 's':	// setting numerical value
                /* test against maximum and minimum value */
                if(atoi(optarg) > max || atoi(optarg) < 0) {
                    fprintf(stderr, "brightness value argument %s is not within range 0 -  %d\n", optarg, max);
                    exit(1);
                }    

                fp_sys_bright = fopen("/sys/class/backlight/intel_backlight/brightness", "w");
                fprintf(fp_sys_bright, "%s", optarg);	// write argument to brightness file
                fclose(fp_sys_bright);
                
                break;
            case 'm':
                printf("%d\n", max);
                
                break;           
            default:	// some other thing that we don't care about, or -h
                print_help();
        }	// switch
    }	// while
    
    exit(0);
}