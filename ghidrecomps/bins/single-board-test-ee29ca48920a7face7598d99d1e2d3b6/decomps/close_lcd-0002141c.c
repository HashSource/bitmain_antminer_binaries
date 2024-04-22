
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
      local_414._0_1_ = s_lcd_closed____000345c0[0];
      local_414._1_1_ = s_lcd_closed____000345c0[1];
      local_414._2_1_ = s_lcd_closed____000345c0[2];
      local_414._3_1_ = s_lcd_closed____000345c0[3];
      uStack_410._0_1_ = s_lcd_closed____000345c0[4];
      uStack_410._1_1_ = s_lcd_closed____000345c0[5];
      uStack_410._2_1_ = s_lcd_closed____000345c0[6];
      uStack_410._3_1_ = s_lcd_closed____000345c0[7];
      uStack_40c._0_1_ = s_lcd_closed____000345c0[8];
      uStack_40c._1_1_ = s_lcd_closed____000345c0[9];
      uStack_40c._2_1_ = s_lcd_closed____000345c0[10];
      uStack_40c._3_1_ = s_lcd_closed____000345c0[11];
      _applog(2,&local_414,0);
    }
  }
  else if (((use_syslog != '\0') || (opt_log_output != '\0')) || (1 < opt_log_level)) {
    local_414._0_1_ = s_lcd_close_failed____000345d0[0];
    local_414._1_1_ = s_lcd_close_failed____000345d0[1];
    local_414._2_1_ = s_lcd_close_failed____000345d0[2];
    local_414._3_1_ = s_lcd_close_failed____000345d0[3];
    uStack_410._0_1_ = s_lcd_close_failed____000345d0[4];
    uStack_410._1_1_ = s_lcd_close_failed____000345d0[5];
    uStack_410._2_1_ = s_lcd_close_failed____000345d0[6];
    uStack_410._3_1_ = s_lcd_close_failed____000345d0[7];
    uStack_40c._0_1_ = s_lcd_close_failed____000345d0[8];
    uStack_40c._1_1_ = s_lcd_close_failed____000345d0[9];
    uStack_40c._2_1_ = s_lcd_close_failed____000345d0[10];
    uStack_40c._3_1_ = s_lcd_close_failed____000345d0[11];
    local_408._0_1_ = s_lcd_close_failed____000345d0[12];
    local_408._1_1_ = s_lcd_close_failed____000345d0[13];
    local_408._2_1_ = s_lcd_close_failed____000345d0[14];
    local_408._3_1_ = s_lcd_close_failed____000345d0[15];
    local_404._0_1_ = s_lcd_close_failed____000345d0[16];
    local_404._1_1_ = s_lcd_close_failed____000345d0[17];
    local_404._2_1_ = s_lcd_close_failed____000345d0[18];
    local_404._3_1_ = s_lcd_close_failed____000345d0[19];
    local_400 = (undefined)ram0x000345e4;
    _applog(2,&local_414,0);
  }
  return local_14;
}

