
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
    local_410._0_1_ = s_open_red_led_failed____00034198[0];
    local_410._1_1_ = s_open_red_led_failed____00034198[1];
    local_410._2_1_ = s_open_red_led_failed____00034198[2];
    local_410._3_1_ = s_open_red_led_failed____00034198[3];
    uStack_40c._0_1_ = s_open_red_led_failed____00034198[4];
    uStack_40c._1_1_ = s_open_red_led_failed____00034198[5];
    uStack_40c._2_1_ = s_open_red_led_failed____00034198[6];
    uStack_40c._3_1_ = s_open_red_led_failed____00034198[7];
    uStack_408._0_1_ = s_open_red_led_failed____00034198[8];
    uStack_408._1_1_ = s_open_red_led_failed____00034198[9];
    uStack_408._2_1_ = s_open_red_led_failed____00034198[10];
    uStack_408._3_1_ = s_open_red_led_failed____00034198[11];
    uStack_404._0_1_ = s_open_red_led_failed____00034198[12];
    uStack_404._1_1_ = s_open_red_led_failed____00034198[13];
    uStack_404._2_1_ = s_open_red_led_failed____00034198[14];
    uStack_404._3_1_ = s_open_red_led_failed____00034198[15];
    local_400._0_1_ = s_open_red_led_failed____00034198[16];
    local_400._1_1_ = s_open_red_led_failed____00034198[17];
    local_400._2_1_ = s_open_red_led_failed____00034198[18];
    local_400._3_1_ = s_open_red_led_failed____00034198[19];
    uStack_3fc._0_1_ = s_open_red_led_failed____00034198[20];
    uStack_3fc._1_1_ = s_open_red_led_failed____00034198[21];
    uStack_3fc._2_1_ = s_open_red_led_failed____00034198[22];
    uStack_3fc._3_1_ = s_open_red_led_failed____00034198[23];
    _applog(2,&local_410,0);
  }
  return red_led_fd;
}

