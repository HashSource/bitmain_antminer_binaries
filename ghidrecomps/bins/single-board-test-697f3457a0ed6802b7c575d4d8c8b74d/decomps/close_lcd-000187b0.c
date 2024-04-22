
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* WARNING: Unknown calling convention */

int close_lcd(void)

{
  int iVar1;
  char tmp42 [1024];
  int ret;
  
  iVar1 = close(cgpu.lcd_fd);
  if (iVar1 == 0) {
    if (((use_syslog != false) || (opt_log_output != false)) || (1 < opt_log_level)) {
      tmp42[0] = s_lcd_closed____00034f4c[0];
      tmp42[1] = s_lcd_closed____00034f4c[1];
      tmp42[2] = s_lcd_closed____00034f4c[2];
      tmp42[3] = s_lcd_closed____00034f4c[3];
      tmp42[4] = s_lcd_closed____00034f4c[4];
      tmp42[5] = s_lcd_closed____00034f4c[5];
      tmp42[6] = s_lcd_closed____00034f4c[6];
      tmp42[7] = s_lcd_closed____00034f4c[7];
      tmp42[8] = s_lcd_closed____00034f4c[8];
      tmp42[9] = s_lcd_closed____00034f4c[9];
      tmp42[10] = s_lcd_closed____00034f4c[10];
      tmp42[11] = s_lcd_closed____00034f4c[11];
      tmp42._12_3_ = (undefined3)ram0x00034f58;
      _applog(2,tmp42,false);
    }
  }
  else if (((use_syslog != false) || (opt_log_output != false)) || (1 < opt_log_level)) {
    tmp42[0] = s_lcd_close_failed____00034f5c[0];
    tmp42[1] = s_lcd_close_failed____00034f5c[1];
    tmp42[2] = s_lcd_close_failed____00034f5c[2];
    tmp42[3] = s_lcd_close_failed____00034f5c[3];
    tmp42[4] = s_lcd_close_failed____00034f5c[4];
    tmp42[5] = s_lcd_close_failed____00034f5c[5];
    tmp42[6] = s_lcd_close_failed____00034f5c[6];
    tmp42[7] = s_lcd_close_failed____00034f5c[7];
    tmp42[8] = s_lcd_close_failed____00034f5c[8];
    tmp42[9] = s_lcd_close_failed____00034f5c[9];
    tmp42[10] = s_lcd_close_failed____00034f5c[10];
    tmp42[11] = s_lcd_close_failed____00034f5c[11];
    tmp42[12] = s_lcd_close_failed____00034f5c[12];
    tmp42[13] = s_lcd_close_failed____00034f5c[13];
    tmp42[14] = s_lcd_close_failed____00034f5c[14];
    tmp42[15] = s_lcd_close_failed____00034f5c[15];
    tmp42[16] = s_lcd_close_failed____00034f5c[16];
    tmp42[17] = s_lcd_close_failed____00034f5c[17];
    tmp42[18] = s_lcd_close_failed____00034f5c[18];
    tmp42[19] = s_lcd_close_failed____00034f5c[19];
    tmp42[20] = (char)ram0x00034f70;
    _applog(2,tmp42,false);
  }
  return iVar1;
}

