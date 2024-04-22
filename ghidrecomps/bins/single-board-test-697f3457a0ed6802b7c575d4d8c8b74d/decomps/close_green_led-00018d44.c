
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* WARNING: Unknown calling convention */

void close_green_led(void)

{
  char tmp42 [1024];
  
  close(green_led_fd);
  if (((use_syslog != false) || (opt_log_output != false)) || (1 < opt_log_level)) {
    tmp42[0] = s_green_led_closed____00035048[0];
    tmp42[1] = s_green_led_closed____00035048[1];
    tmp42[2] = s_green_led_closed____00035048[2];
    tmp42[3] = s_green_led_closed____00035048[3];
    tmp42[4] = s_green_led_closed____00035048[4];
    tmp42[5] = s_green_led_closed____00035048[5];
    tmp42[6] = s_green_led_closed____00035048[6];
    tmp42[7] = s_green_led_closed____00035048[7];
    tmp42[8] = s_green_led_closed____00035048[8];
    tmp42[9] = s_green_led_closed____00035048[9];
    tmp42[10] = s_green_led_closed____00035048[10];
    tmp42[11] = s_green_led_closed____00035048[11];
    tmp42[12] = s_green_led_closed____00035048[12];
    tmp42[13] = s_green_led_closed____00035048[13];
    tmp42[14] = s_green_led_closed____00035048[14];
    tmp42[15] = s_green_led_closed____00035048[15];
    tmp42[16] = s_green_led_closed____00035048[16];
    tmp42[17] = s_green_led_closed____00035048[17];
    tmp42[18] = s_green_led_closed____00035048[18];
    tmp42[19] = s_green_led_closed____00035048[19];
    tmp42[20] = (char)ram0x0003505c;
    _applog(2,tmp42,false);
  }
  return;
}

