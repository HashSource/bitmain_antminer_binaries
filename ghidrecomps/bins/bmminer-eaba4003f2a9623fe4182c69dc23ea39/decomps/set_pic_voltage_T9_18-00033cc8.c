
void set_pic_voltage_T9_18(uchar chain)

{
  uchar vol_pic_00;
  int iVar1;
  int iVar2;
  uchar chain_local;
  char tmp42 [2048];
  char logstr [1024];
  uchar vol_pic;
  
  vol_pic_00 = getHighestVoltagePIC((uint)chain);
  if (((use_syslog != false) || (opt_log_output != false)) || (4 < opt_log_level)) {
    iVar1 = getVolValueFromPICvoltage(chain_voltage_pic[chain]);
    iVar2 = getVolValueFromPICvoltage(vol_pic_00);
    snprintf(tmp42,0x800,"set voltage=%d on chain[%d], the real voltage=%d\n",iVar1,(uint)chain,
             iVar2);
    _applog(5,tmp42,false);
  }
  set_voltage_T9_18_into_PIC(chain,vol_pic_00);
  return;
}

