
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void close_green_led(void)

{
  undefined4 local_410;
  undefined4 uStack_40c;
  undefined4 uStack_408;
  undefined4 uStack_404;
  undefined4 local_400;
  undefined local_3fc;
  
  close(green_led_fd);
  if (((use_syslog != '\0') || (opt_log_output != '\0')) || (1 < opt_log_level)) {
    local_410._0_1_ = s_green_led_closed____000346bc[0];
    local_410._1_1_ = s_green_led_closed____000346bc[1];
    local_410._2_1_ = s_green_led_closed____000346bc[2];
    local_410._3_1_ = s_green_led_closed____000346bc[3];
    uStack_40c._0_1_ = s_green_led_closed____000346bc[4];
    uStack_40c._1_1_ = s_green_led_closed____000346bc[5];
    uStack_40c._2_1_ = s_green_led_closed____000346bc[6];
    uStack_40c._3_1_ = s_green_led_closed____000346bc[7];
    uStack_408._0_1_ = s_green_led_closed____000346bc[8];
    uStack_408._1_1_ = s_green_led_closed____000346bc[9];
    uStack_408._2_1_ = s_green_led_closed____000346bc[10];
    uStack_408._3_1_ = s_green_led_closed____000346bc[11];
    uStack_404._0_1_ = s_green_led_closed____000346bc[12];
    uStack_404._1_1_ = s_green_led_closed____000346bc[13];
    uStack_404._2_1_ = s_green_led_closed____000346bc[14];
    uStack_404._3_1_ = s_green_led_closed____000346bc[15];
    local_400._0_1_ = s_green_led_closed____000346bc[16];
    local_400._1_1_ = s_green_led_closed____000346bc[17];
    local_400._2_1_ = s_green_led_closed____000346bc[18];
    local_400._3_1_ = s_green_led_closed____000346bc[19];
    local_3fc = (undefined)ram0x000346d0;
    _applog(2,&local_410,0);
  }
  return;
}

