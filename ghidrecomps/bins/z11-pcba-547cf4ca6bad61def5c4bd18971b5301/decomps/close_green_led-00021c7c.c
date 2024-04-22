
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
    local_410._0_1_ = s_green_led_closed____00034208[0];
    local_410._1_1_ = s_green_led_closed____00034208[1];
    local_410._2_1_ = s_green_led_closed____00034208[2];
    local_410._3_1_ = s_green_led_closed____00034208[3];
    uStack_40c._0_1_ = s_green_led_closed____00034208[4];
    uStack_40c._1_1_ = s_green_led_closed____00034208[5];
    uStack_40c._2_1_ = s_green_led_closed____00034208[6];
    uStack_40c._3_1_ = s_green_led_closed____00034208[7];
    uStack_408._0_1_ = s_green_led_closed____00034208[8];
    uStack_408._1_1_ = s_green_led_closed____00034208[9];
    uStack_408._2_1_ = s_green_led_closed____00034208[10];
    uStack_408._3_1_ = s_green_led_closed____00034208[11];
    uStack_404._0_1_ = s_green_led_closed____00034208[12];
    uStack_404._1_1_ = s_green_led_closed____00034208[13];
    uStack_404._2_1_ = s_green_led_closed____00034208[14];
    uStack_404._3_1_ = s_green_led_closed____00034208[15];
    local_400._0_1_ = s_green_led_closed____00034208[16];
    local_400._1_1_ = s_green_led_closed____00034208[17];
    local_400._2_1_ = s_green_led_closed____00034208[18];
    local_400._3_1_ = s_green_led_closed____00034208[19];
    local_3fc = (undefined)ram0x0003421c;
    _applog(2,&local_410,0);
  }
  return;
}

