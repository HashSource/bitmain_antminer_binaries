
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
    local_410._0_1_ = s_open_green_led_failed____000341ec[0];
    local_410._1_1_ = s_open_green_led_failed____000341ec[1];
    local_410._2_1_ = s_open_green_led_failed____000341ec[2];
    local_410._3_1_ = s_open_green_led_failed____000341ec[3];
    uStack_40c._0_1_ = s_open_green_led_failed____000341ec[4];
    uStack_40c._1_1_ = s_open_green_led_failed____000341ec[5];
    uStack_40c._2_1_ = s_open_green_led_failed____000341ec[6];
    uStack_40c._3_1_ = s_open_green_led_failed____000341ec[7];
    uStack_408._0_1_ = s_open_green_led_failed____000341ec[8];
    uStack_408._1_1_ = s_open_green_led_failed____000341ec[9];
    uStack_408._2_1_ = s_open_green_led_failed____000341ec[10];
    uStack_408._3_1_ = s_open_green_led_failed____000341ec[11];
    uStack_404._0_1_ = s_open_green_led_failed____000341ec[12];
    uStack_404._1_1_ = s_open_green_led_failed____000341ec[13];
    uStack_404._2_1_ = s_open_green_led_failed____000341ec[14];
    uStack_404._3_1_ = s_open_green_led_failed____000341ec[15];
    local_400._0_1_ = s_open_green_led_failed____000341ec[16];
    local_400._1_1_ = s_open_green_led_failed____000341ec[17];
    local_400._2_1_ = s_open_green_led_failed____000341ec[18];
    local_400._3_1_ = s_open_green_led_failed____000341ec[19];
    uStack_3fc._0_1_ = s_open_green_led_failed____000341ec[20];
    uStack_3fc._1_1_ = s_open_green_led_failed____000341ec[21];
    uStack_3fc._2_1_ = s_open_green_led_failed____000341ec[22];
    uStack_3fc._3_1_ = s_open_green_led_failed____000341ec[23];
    local_3f8 = (undefined2)ram0x00034204;
    _applog(2,&local_410,0);
  }
  return green_led_fd;
}

