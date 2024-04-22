
/* WARNING: Unknown calling convention */

int open_lcd(void)

{
  char tmp42 [1024];
  
  cgpu.lcd_fd = open("/dev/bitmain-lcd",0x882);
  if ((cgpu.lcd_fd < 1) &&
     (((use_syslog != false || (opt_log_output != false)) || (1 < opt_log_level)))) {
    tmp42[0] = s_open_lcd_failed____00034f38[0];
    tmp42[1] = s_open_lcd_failed____00034f38[1];
    tmp42[2] = s_open_lcd_failed____00034f38[2];
    tmp42[3] = s_open_lcd_failed____00034f38[3];
    tmp42[4] = s_open_lcd_failed____00034f38[4];
    tmp42[5] = s_open_lcd_failed____00034f38[5];
    tmp42[6] = s_open_lcd_failed____00034f38[6];
    tmp42[7] = s_open_lcd_failed____00034f38[7];
    tmp42[8] = s_open_lcd_failed____00034f38[8];
    tmp42[9] = s_open_lcd_failed____00034f38[9];
    tmp42[10] = s_open_lcd_failed____00034f38[10];
    tmp42[11] = s_open_lcd_failed____00034f38[11];
    tmp42[12] = s_open_lcd_failed____00034f38[12];
    tmp42[13] = s_open_lcd_failed____00034f38[13];
    tmp42[14] = s_open_lcd_failed____00034f38[14];
    tmp42[15] = s_open_lcd_failed____00034f38[15];
    tmp42[16] = s_open_lcd_failed____00034f38[16];
    tmp42[17] = s_open_lcd_failed____00034f38[17];
    tmp42[18] = s_open_lcd_failed____00034f38[18];
    tmp42[19] = s_open_lcd_failed____00034f38[19];
    _applog(2,tmp42,false);
  }
  return cgpu.lcd_fd;
}

