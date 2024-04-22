
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int open_green_led(void)

{
  undefined4 local_410;
  undefined4 uStack_40c;
  undefined4 uStack_408;
  undefined4 uStack_404;
  undefined4 local_400;
  undefined4 uStack_3fc;
  undefined2 local_3f8;
  
  green_led_fd = open("/sys/class/gpio/gpio942/value",0x801);
  if ((green_led_fd < 0) &&
     (((use_syslog != '\0' || (opt_log_output != '\0')) || (1 < opt_log_level)))) {
    local_410._0_1_ = s_open_green_led_failed____000346a0[0];
    local_410._1_1_ = s_open_green_led_failed____000346a0[1];
    local_410._2_1_ = s_open_green_led_failed____000346a0[2];
    local_410._3_1_ = s_open_green_led_failed____000346a0[3];
    uStack_40c._0_1_ = s_open_green_led_failed____000346a0[4];
    uStack_40c._1_1_ = s_open_green_led_failed____000346a0[5];
    uStack_40c._2_1_ = s_open_green_led_failed____000346a0[6];
    uStack_40c._3_1_ = s_open_green_led_failed____000346a0[7];
    uStack_408._0_1_ = s_open_green_led_failed____000346a0[8];
    uStack_408._1_1_ = s_open_green_led_failed____000346a0[9];
    uStack_408._2_1_ = s_open_green_led_failed____000346a0[10];
    uStack_408._3_1_ = s_open_green_led_failed____000346a0[11];
    uStack_404._0_1_ = s_open_green_led_failed____000346a0[12];
    uStack_404._1_1_ = s_open_green_led_failed____000346a0[13];
    uStack_404._2_1_ = s_open_green_led_failed____000346a0[14];
    uStack_404._3_1_ = s_open_green_led_failed____000346a0[15];
    local_400._0_1_ = s_open_green_led_failed____000346a0[16];
    local_400._1_1_ = s_open_green_led_failed____000346a0[17];
    local_400._2_1_ = s_open_green_led_failed____000346a0[18];
    local_400._3_1_ = s_open_green_led_failed____000346a0[19];
    uStack_3fc._0_1_ = s_open_green_led_failed____000346a0[20];
    uStack_3fc._1_1_ = s_open_green_led_failed____000346a0[21];
    uStack_3fc._2_1_ = s_open_green_led_failed____000346a0[22];
    uStack_3fc._3_1_ = s_open_green_led_failed____000346a0[23];
    local_3f8 = (undefined2)ram0x000346b8;
    _applog(2,&local_410,0);
  }
  return green_led_fd;
}

