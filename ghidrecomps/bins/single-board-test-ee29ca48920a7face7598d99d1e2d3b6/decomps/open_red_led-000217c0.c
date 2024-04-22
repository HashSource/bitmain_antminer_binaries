
int open_red_led(void)

{
  undefined4 local_410;
  undefined4 uStack_40c;
  undefined4 uStack_408;
  undefined4 uStack_404;
  undefined4 local_400;
  undefined4 uStack_3fc;
  
  red_led_fd = open("/sys/class/gpio/gpio941/value",0x801);
  if ((red_led_fd < 0) &&
     (((use_syslog != '\0' || (opt_log_output != '\0')) || (1 < opt_log_level)))) {
    local_410._0_1_ = s_open_red_led_failed____0003464c[0];
    local_410._1_1_ = s_open_red_led_failed____0003464c[1];
    local_410._2_1_ = s_open_red_led_failed____0003464c[2];
    local_410._3_1_ = s_open_red_led_failed____0003464c[3];
    uStack_40c._0_1_ = s_open_red_led_failed____0003464c[4];
    uStack_40c._1_1_ = s_open_red_led_failed____0003464c[5];
    uStack_40c._2_1_ = s_open_red_led_failed____0003464c[6];
    uStack_40c._3_1_ = s_open_red_led_failed____0003464c[7];
    uStack_408._0_1_ = s_open_red_led_failed____0003464c[8];
    uStack_408._1_1_ = s_open_red_led_failed____0003464c[9];
    uStack_408._2_1_ = s_open_red_led_failed____0003464c[10];
    uStack_408._3_1_ = s_open_red_led_failed____0003464c[11];
    uStack_404._0_1_ = s_open_red_led_failed____0003464c[12];
    uStack_404._1_1_ = s_open_red_led_failed____0003464c[13];
    uStack_404._2_1_ = s_open_red_led_failed____0003464c[14];
    uStack_404._3_1_ = s_open_red_led_failed____0003464c[15];
    local_400._0_1_ = s_open_red_led_failed____0003464c[16];
    local_400._1_1_ = s_open_red_led_failed____0003464c[17];
    local_400._2_1_ = s_open_red_led_failed____0003464c[18];
    local_400._3_1_ = s_open_red_led_failed____0003464c[19];
    uStack_3fc._0_1_ = s_open_red_led_failed____0003464c[20];
    uStack_3fc._1_1_ = s_open_red_led_failed____0003464c[21];
    uStack_3fc._2_1_ = s_open_red_led_failed____0003464c[22];
    uStack_3fc._3_1_ = s_open_red_led_failed____0003464c[23];
    _applog(2,&local_410,0);
  }
  return red_led_fd;
}

