
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* WARNING: Unknown calling convention */

int open_green_led(void)

{
  char tmp42 [1024];
  
  green_led_fd = open("/sys/class/gpio/gpio942/value",0x801);
  if ((green_led_fd < 0) &&
     (((use_syslog != false || (opt_log_output != false)) || (1 < opt_log_level)))) {
    tmp42[0] = s_open_green_led_failed____0003502c[0];
    tmp42[1] = s_open_green_led_failed____0003502c[1];
    tmp42[2] = s_open_green_led_failed____0003502c[2];
    tmp42[3] = s_open_green_led_failed____0003502c[3];
    tmp42[4] = s_open_green_led_failed____0003502c[4];
    tmp42[5] = s_open_green_led_failed____0003502c[5];
    tmp42[6] = s_open_green_led_failed____0003502c[6];
    tmp42[7] = s_open_green_led_failed____0003502c[7];
    tmp42[8] = s_open_green_led_failed____0003502c[8];
    tmp42[9] = s_open_green_led_failed____0003502c[9];
    tmp42[10] = s_open_green_led_failed____0003502c[10];
    tmp42[11] = s_open_green_led_failed____0003502c[11];
    tmp42[12] = s_open_green_led_failed____0003502c[12];
    tmp42[13] = s_open_green_led_failed____0003502c[13];
    tmp42[14] = s_open_green_led_failed____0003502c[14];
    tmp42[15] = s_open_green_led_failed____0003502c[15];
    tmp42[16] = s_open_green_led_failed____0003502c[16];
    tmp42[17] = s_open_green_led_failed____0003502c[17];
    tmp42[18] = s_open_green_led_failed____0003502c[18];
    tmp42[19] = s_open_green_led_failed____0003502c[19];
    tmp42[20] = s_open_green_led_failed____0003502c[20];
    tmp42[21] = s_open_green_led_failed____0003502c[21];
    tmp42[22] = s_open_green_led_failed____0003502c[22];
    tmp42[23] = s_open_green_led_failed____0003502c[23];
    tmp42._24_2_ = (undefined2)ram0x00035044;
    _applog(2,tmp42,false);
  }
  return green_led_fd;
}

