
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
    local_410._0_1_ = s_red_led_closed____000341b0[0];
    local_410._1_1_ = s_red_led_closed____000341b0[1];
    local_410._2_1_ = s_red_led_closed____000341b0[2];
    local_410._3_1_ = s_red_led_closed____000341b0[3];
    uStack_40c._0_1_ = s_red_led_closed____000341b0[4];
    uStack_40c._1_1_ = s_red_led_closed____000341b0[5];
    uStack_40c._2_1_ = s_red_led_closed____000341b0[6];
    uStack_40c._3_1_ = s_red_led_closed____000341b0[7];
    uStack_408._0_1_ = s_red_led_closed____000341b0[8];
    uStack_408._1_1_ = s_red_led_closed____000341b0[9];
    uStack_408._2_1_ = s_red_led_closed____000341b0[10];
    uStack_408._3_1_ = s_red_led_closed____000341b0[11];
    uStack_404._0_1_ = s_red_led_closed____000341b0[12];
    uStack_404._1_1_ = s_red_led_closed____000341b0[13];
    uStack_404._2_1_ = s_red_led_closed____000341b0[14];
    uStack_404._3_1_ = s_red_led_closed____000341b0[15];
    local_400 = (undefined2)ram0x000341c0;
    local_3fe = (undefined)((uint)ram0x000341c0 >> 0x10);
    _applog(2,&local_410,0);
  }
  return;
}

