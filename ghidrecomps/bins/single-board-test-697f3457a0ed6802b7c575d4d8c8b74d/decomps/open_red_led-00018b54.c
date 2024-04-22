
/* WARNING: Unknown calling convention */

int open_red_led(void)

{
  char tmp42 [1024];
  
  red_led_fd = open("/sys/class/gpio/gpio941/value",0x801);
  if ((red_led_fd < 0) &&
     (((use_syslog != false || (opt_log_output != false)) || (1 < opt_log_level)))) {
    tmp42[0] = s_open_red_led_failed____00034fd8[0];
    tmp42[1] = s_open_red_led_failed____00034fd8[1];
    tmp42[2] = s_open_red_led_failed____00034fd8[2];
    tmp42[3] = s_open_red_led_failed____00034fd8[3];
    tmp42[4] = s_open_red_led_failed____00034fd8[4];
    tmp42[5] = s_open_red_led_failed____00034fd8[5];
    tmp42[6] = s_open_red_led_failed____00034fd8[6];
    tmp42[7] = s_open_red_led_failed____00034fd8[7];
    tmp42[8] = s_open_red_led_failed____00034fd8[8];
    tmp42[9] = s_open_red_led_failed____00034fd8[9];
    tmp42[10] = s_open_red_led_failed____00034fd8[10];
    tmp42[11] = s_open_red_led_failed____00034fd8[11];
    tmp42[12] = s_open_red_led_failed____00034fd8[12];
    tmp42[13] = s_open_red_led_failed____00034fd8[13];
    tmp42[14] = s_open_red_led_failed____00034fd8[14];
    tmp42[15] = s_open_red_led_failed____00034fd8[15];
    tmp42[16] = s_open_red_led_failed____00034fd8[16];
    tmp42[17] = s_open_red_led_failed____00034fd8[17];
    tmp42[18] = s_open_red_led_failed____00034fd8[18];
    tmp42[19] = s_open_red_led_failed____00034fd8[19];
    tmp42[20] = s_open_red_led_failed____00034fd8[20];
    tmp42[21] = s_open_red_led_failed____00034fd8[21];
    tmp42[22] = s_open_red_led_failed____00034fd8[22];
    tmp42[23] = s_open_red_led_failed____00034fd8[23];
    _applog(2,tmp42,false);
  }
  return red_led_fd;
}

