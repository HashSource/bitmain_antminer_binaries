
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void close_red_led(void)

{
  undefined4 local_410;
  undefined4 uStack_40c;
  undefined4 uStack_408;
  undefined4 uStack_404;
  undefined2 local_400;
  undefined local_3fe;
  
  close(red_led_fd);
  if (((use_syslog != '\0') || (opt_log_output != '\0')) || (1 < opt_log_level)) {
    local_410._0_1_ = s_red_led_closed____00034664[0];
    local_410._1_1_ = s_red_led_closed____00034664[1];
    local_410._2_1_ = s_red_led_closed____00034664[2];
    local_410._3_1_ = s_red_led_closed____00034664[3];
    uStack_40c._0_1_ = s_red_led_closed____00034664[4];
    uStack_40c._1_1_ = s_red_led_closed____00034664[5];
    uStack_40c._2_1_ = s_red_led_closed____00034664[6];
    uStack_40c._3_1_ = s_red_led_closed____00034664[7];
    uStack_408._0_1_ = s_red_led_closed____00034664[8];
    uStack_408._1_1_ = s_red_led_closed____00034664[9];
    uStack_408._2_1_ = s_red_led_closed____00034664[10];
    uStack_408._3_1_ = s_red_led_closed____00034664[11];
    uStack_404._0_1_ = s_red_led_closed____00034664[12];
    uStack_404._1_1_ = s_red_led_closed____00034664[13];
    uStack_404._2_1_ = s_red_led_closed____00034664[14];
    uStack_404._3_1_ = s_red_led_closed____00034664[15];
    local_400 = (undefined2)ram0x00034674;
    local_3fe = (undefined)((uint)ram0x00034674 >> 0x10);
    _applog(2,&local_410,0);
  }
  return;
}

