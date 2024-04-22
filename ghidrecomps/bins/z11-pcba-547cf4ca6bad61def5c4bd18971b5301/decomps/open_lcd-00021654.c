
undefined4 open_lcd(void)

{
  undefined4 local_410;
  undefined4 uStack_40c;
  undefined4 uStack_408;
  undefined4 uStack_404;
  undefined4 local_400;
  
  cgpu._36_4_ = open("/dev/bitmain-lcd",0x882);
  if (((int)cgpu._36_4_ < 1) &&
     (((use_syslog != '\0' || (opt_log_output != '\0')) || (1 < opt_log_level)))) {
    local_410._0_1_ = s_open_lcd_failed____000340f8[0];
    local_410._1_1_ = s_open_lcd_failed____000340f8[1];
    local_410._2_1_ = s_open_lcd_failed____000340f8[2];
    local_410._3_1_ = s_open_lcd_failed____000340f8[3];
    uStack_40c._0_1_ = s_open_lcd_failed____000340f8[4];
    uStack_40c._1_1_ = s_open_lcd_failed____000340f8[5];
    uStack_40c._2_1_ = s_open_lcd_failed____000340f8[6];
    uStack_40c._3_1_ = s_open_lcd_failed____000340f8[7];
    uStack_408._0_1_ = s_open_lcd_failed____000340f8[8];
    uStack_408._1_1_ = s_open_lcd_failed____000340f8[9];
    uStack_408._2_1_ = s_open_lcd_failed____000340f8[10];
    uStack_408._3_1_ = s_open_lcd_failed____000340f8[11];
    uStack_404._0_1_ = s_open_lcd_failed____000340f8[12];
    uStack_404._1_1_ = s_open_lcd_failed____000340f8[13];
    uStack_404._2_1_ = s_open_lcd_failed____000340f8[14];
    uStack_404._3_1_ = s_open_lcd_failed____000340f8[15];
    local_400._0_1_ = s_open_lcd_failed____000340f8[16];
    local_400._1_1_ = s_open_lcd_failed____000340f8[17];
    local_400._2_1_ = s_open_lcd_failed____000340f8[18];
    local_400._3_1_ = s_open_lcd_failed____000340f8[19];
    _applog(2,&local_410,0);
  }
  return cgpu._36_4_;
}

