
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
    local_410._0_1_ = s_open_key_failed____00034094[0];
    local_410._1_1_ = s_open_key_failed____00034094[1];
    local_410._2_1_ = s_open_key_failed____00034094[2];
    local_410._3_1_ = s_open_key_failed____00034094[3];
    uStack_40c._0_1_ = s_open_key_failed____00034094[4];
    uStack_40c._1_1_ = s_open_key_failed____00034094[5];
    uStack_40c._2_1_ = s_open_key_failed____00034094[6];
    uStack_40c._3_1_ = s_open_key_failed____00034094[7];
    uStack_408._0_1_ = s_open_key_failed____00034094[8];
    uStack_408._1_1_ = s_open_key_failed____00034094[9];
    uStack_408._2_1_ = s_open_key_failed____00034094[10];
    uStack_408._3_1_ = s_open_key_failed____00034094[11];
    uStack_404._0_1_ = s_open_key_failed____00034094[12];
    uStack_404._1_1_ = s_open_key_failed____00034094[13];
    uStack_404._2_1_ = s_open_key_failed____00034094[14];
    uStack_404._3_1_ = s_open_key_failed____00034094[15];
    local_400._0_1_ = s_open_key_failed____00034094[16];
    local_400._1_1_ = s_open_key_failed____00034094[17];
    local_400._2_1_ = s_open_key_failed____00034094[18];
    local_400._3_1_ = s_open_key_failed____00034094[19];
    _applog(2,&local_410,0);
  }
  return cgpu._44_4_;
}

