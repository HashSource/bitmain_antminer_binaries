
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
    local_410._0_1_ = s_key_closed____000340a8[0];
    local_410._1_1_ = s_key_closed____000340a8[1];
    local_410._2_1_ = s_key_closed____000340a8[2];
    local_410._3_1_ = s_key_closed____000340a8[3];
    uStack_40c._0_1_ = s_key_closed____000340a8[4];
    uStack_40c._1_1_ = s_key_closed____000340a8[5];
    uStack_40c._2_1_ = s_key_closed____000340a8[6];
    uStack_40c._3_1_ = s_key_closed____000340a8[7];
    uStack_408._0_1_ = s_key_closed____000340a8[8];
    uStack_408._1_1_ = s_key_closed____000340a8[9];
    uStack_408._2_1_ = s_key_closed____000340a8[10];
    uStack_408._3_1_ = s_key_closed____000340a8[11];
    local_404 = (undefined2)ram0x000340b4;
    local_402 = (undefined)((uint)ram0x000340b4 >> 0x10);
    _applog(2,&local_410,0);
  }
  return;
}

