
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void close_key(void)

{
  undefined4 local_410;
  undefined4 uStack_40c;
  undefined4 uStack_408;
  undefined2 local_404;
  undefined local_402;
  
  close(cgpu._44_4_);
  if (((use_syslog != '\0') || (opt_log_output != '\0')) || (1 < opt_log_level)) {
    local_410._0_1_ = s_key_closed____0003455c[0];
    local_410._1_1_ = s_key_closed____0003455c[1];
    local_410._2_1_ = s_key_closed____0003455c[2];
    local_410._3_1_ = s_key_closed____0003455c[3];
    uStack_40c._0_1_ = s_key_closed____0003455c[4];
    uStack_40c._1_1_ = s_key_closed____0003455c[5];
    uStack_40c._2_1_ = s_key_closed____0003455c[6];
    uStack_40c._3_1_ = s_key_closed____0003455c[7];
    uStack_408._0_1_ = s_key_closed____0003455c[8];
    uStack_408._1_1_ = s_key_closed____0003455c[9];
    uStack_408._2_1_ = s_key_closed____0003455c[10];
    uStack_408._3_1_ = s_key_closed____0003455c[11];
    local_404 = (undefined2)ram0x00034568;
    local_402 = (undefined)((uint)ram0x00034568 >> 0x10);
    _applog(2,&local_410,0);
  }
  return;
}

