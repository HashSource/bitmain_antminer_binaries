
int set_voltage_s11_into_PIC_without_disable(uchar which_chain,uint pic_voltage)

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
  
  cgsleep_ms(500);
  temp_voltage = DAT_00033868 - ((double)(ulonglong)pic_voltage * DAT_00033858) / DAT_00033860;
  if ((int)((uint)(temp_voltage < 0.0) << 0x1f) < 0) {
    temp_voltage = 0.0;
  }
  data = (0.0 < temp_voltage) * (char)(longlong)temp_voltage;
  s11_write_vol_iic(false,true,'\x02','\x01','\0',data);
  usleep(100000);
  if (((use_syslog != false) || (opt_log_output != false)) || (4 < opt_log_level)) {
    snprintf(tmp42,0x800,"\n--- %s chain[%d]ok! pic-vol=%d; vol index=%d\n\n",
             "set_voltage_s11_into_PIC_without_disable",(uint)which_chain,pic_voltage,(uint)data);
    _applog(5,tmp42,false);
  }
  cgsleep_ms(500);
  sleep(1);
  return 1;
}

