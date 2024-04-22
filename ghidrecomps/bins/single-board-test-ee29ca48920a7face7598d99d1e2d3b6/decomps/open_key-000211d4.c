
undefined4 open_key(void)

{
  undefined4 local_410;
  undefined4 uStack_40c;
  undefined4 uStack_408;
  undefined4 uStack_404;
  undefined4 local_400;
  
  cgpu._44_4_ = open("/sys/class/gpio/gpio943/value",0x800);
  if (((int)cgpu._44_4_ < 0) &&
     (((use_syslog != '\0' || (opt_log_output != '\0')) || (1 < opt_log_level)))) {
    local_410._0_1_ = s_open_key_failed____00034548[0];
    local_410._1_1_ = s_open_key_failed____00034548[1];
    local_410._2_1_ = s_open_key_failed____00034548[2];
    local_410._3_1_ = s_open_key_failed____00034548[3];
    uStack_40c._0_1_ = s_open_key_failed____00034548[4];
    uStack_40c._1_1_ = s_open_key_failed____00034548[5];
    uStack_40c._2_1_ = s_open_key_failed____00034548[6];
    uStack_40c._3_1_ = s_open_key_failed____00034548[7];
    uStack_408._0_1_ = s_open_key_failed____00034548[8];
    uStack_408._1_1_ = s_open_key_failed____00034548[9];
    uStack_408._2_1_ = s_open_key_failed____00034548[10];
    uStack_408._3_1_ = s_open_key_failed____00034548[11];
    uStack_404._0_1_ = s_open_key_failed____00034548[12];
    uStack_404._1_1_ = s_open_key_failed____00034548[13];
    uStack_404._2_1_ = s_open_key_failed____00034548[14];
    uStack_404._3_1_ = s_open_key_failed____00034548[15];
    local_400._0_1_ = s_open_key_failed____00034548[16];
    local_400._1_1_ = s_open_key_failed____00034548[17];
    local_400._2_1_ = s_open_key_failed____00034548[18];
    local_400._3_1_ = s_open_key_failed____00034548[19];
    _applog(2,&local_410,0);
  }
  return cgpu._44_4_;
}

