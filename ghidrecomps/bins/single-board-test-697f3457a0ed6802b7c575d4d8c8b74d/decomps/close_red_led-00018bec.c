
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* WARNING: Unknown calling convention */

void close_red_led(void)

{
  char tmp42 [1024];
  
  close(red_led_fd);
  if (((use_syslog != false) || (opt_log_output != false)) || (1 < opt_log_level)) {
    tmp42[0] = s_red_led_closed____00034ff0[0];
    tmp42[1] = s_red_led_closed____00034ff0[1];
    tmp42[2] = s_red_led_closed____00034ff0[2];
    tmp42[3] = s_red_led_closed____00034ff0[3];
    tmp42[4] = s_red_led_closed____00034ff0[4];
    tmp42[5] = s_red_led_closed____00034ff0[5];
    tmp42[6] = s_red_led_closed____00034ff0[6];
    tmp42[7] = s_red_led_closed____00034ff0[7];
    tmp42[8] = s_red_led_closed____00034ff0[8];
    tmp42[9] = s_red_led_closed____00034ff0[9];
    tmp42[10] = s_red_led_closed____00034ff0[10];
    tmp42[11] = s_red_led_closed____00034ff0[11];
    tmp42[12] = s_red_led_closed____00034ff0[12];
    tmp42[13] = s_red_led_closed____00034ff0[13];
    tmp42[14] = s_red_led_closed____00034ff0[14];
    tmp42[15] = s_red_led_closed____00034ff0[15];
    tmp42._16_2_ = (undefined2)ram0x00035000;
    tmp42[18] = (char)((uint)ram0x00035000 >> 0x10);
    _applog(2,tmp42,false);
  }
  return;
}

