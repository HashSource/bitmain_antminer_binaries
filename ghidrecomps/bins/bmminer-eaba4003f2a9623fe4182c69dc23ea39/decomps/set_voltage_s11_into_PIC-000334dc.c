
int set_voltage_s11_into_PIC(uchar which_chain,uint pic_voltage)

{
  byte data;
  uint pic_voltage_local;
  uchar which_chain_local;
  char tmp42 [2048];
  char logstr [1024];
  uchar read_back_data [2];
  uchar crc_data [2];
  int retry_count;
  uchar voltage3;
  uchar voltage2;
  uchar voltage1;
  ushort crc;
  uchar length;
  double temp_voltage;
  
  dsPIC33EP16GS202_enable_pic_dc_dc(which_chain,'\0');
  cgsleep_ms(500);
  temp_voltage = DAT_000336e0 - ((double)(ulonglong)pic_voltage * DAT_000336d0) / DAT_000336d8;
  if ((int)((uint)(temp_voltage < 0.0) << 0x1f) < 0) {
    temp_voltage = 0.0;
  }
  data = (0.0 < temp_voltage) * (char)(longlong)temp_voltage;
  if (((use_syslog != false) || (opt_log_output != false)) || (4 < opt_log_level)) {
    snprintf(tmp42,0x800,"%s,pic vol = %d ,temp vol = %d","set_voltage_s11_into_PIC",pic_voltage);
    _applog(5,tmp42,false);
  }
  s11_write_vol_iic(false,true,'\x02','\x01','\0',data);
  usleep(100000);
  if (((use_syslog != false) || (opt_log_output != false)) || (4 < opt_log_level)) {
    snprintf(tmp42,0x800,"\n--- %s chain[%d]ok! pic-vol=%d; vol index=%d\n\n",
             "set_voltage_s11_into_PIC",(uint)which_chain,pic_voltage,(uint)data);
    _applog(5,tmp42,false);
  }
  cgsleep_ms(500);
  dsPIC33EP16GS202_enable_pic_dc_dc(which_chain,'\x01');
  sleep(1);
  return 1;
}

