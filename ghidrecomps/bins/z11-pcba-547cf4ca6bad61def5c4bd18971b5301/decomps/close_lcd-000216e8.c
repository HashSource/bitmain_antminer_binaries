
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int close_lcd(void)

{
  undefined4 local_414;
  undefined4 uStack_410;
  undefined4 uStack_40c;
  undefined4 local_408;
  undefined4 local_404;
  undefined local_400;
  int local_14;
  
  local_14 = 0xffffffff;
  local_14 = close(cgpu._36_4_);
  if (local_14 == 0) {
    if (((use_syslog != '\0') || (opt_log_output != '\0')) || (1 < opt_log_level)) {
      local_414._0_1_ = s_lcd_closed____0003410c[0];
      local_414._1_1_ = s_lcd_closed____0003410c[1];
      local_414._2_1_ = s_lcd_closed____0003410c[2];
      local_414._3_1_ = s_lcd_closed____0003410c[3];
      uStack_410._0_1_ = s_lcd_closed____0003410c[4];
      uStack_410._1_1_ = s_lcd_closed____0003410c[5];
      uStack_410._2_1_ = s_lcd_closed____0003410c[6];
      uStack_410._3_1_ = s_lcd_closed____0003410c[7];
      uStack_40c._0_1_ = s_lcd_closed____0003410c[8];
      uStack_40c._1_1_ = s_lcd_closed____0003410c[9];
      uStack_40c._2_1_ = s_lcd_closed____0003410c[10];
      uStack_40c._3_1_ = s_lcd_closed____0003410c[11];
      _applog(2,&local_414,0);
    }
  }
  else if (((use_syslog != '\0') || (opt_log_output != '\0')) || (1 < opt_log_level)) {
    local_414._0_1_ = s_lcd_close_failed____0003411c[0];
    local_414._1_1_ = s_lcd_close_failed____0003411c[1];
    local_414._2_1_ = s_lcd_close_failed____0003411c[2];
    local_414._3_1_ = s_lcd_close_failed____0003411c[3];
    uStack_410._0_1_ = s_lcd_close_failed____0003411c[4];
    uStack_410._1_1_ = s_lcd_close_failed____0003411c[5];
    uStack_410._2_1_ = s_lcd_close_failed____0003411c[6];
    uStack_410._3_1_ = s_lcd_close_failed____0003411c[7];
    uStack_40c._0_1_ = s_lcd_close_failed____0003411c[8];
    uStack_40c._1_1_ = s_lcd_close_failed____0003411c[9];
    uStack_40c._2_1_ = s_lcd_close_failed____0003411c[10];
    uStack_40c._3_1_ = s_lcd_close_failed____0003411c[11];
    local_408._0_1_ = s_lcd_close_failed____0003411c[12];
    local_408._1_1_ = s_lcd_close_failed____0003411c[13];
    local_408._2_1_ = s_lcd_close_failed____0003411c[14];
    local_408._3_1_ = s_lcd_close_failed____0003411c[15];
    local_404._0_1_ = s_lcd_close_failed____0003411c[16];
    local_404._1_1_ = s_lcd_close_failed____0003411c[17];
    local_404._2_1_ = s_lcd_close_failed____0003411c[18];
    local_404._3_1_ = s_lcd_close_failed____0003411c[19];
    local_400 = (undefined)ram0x00034130;
    _applog(2,&local_414,0);
  }
  return local_14;
}

