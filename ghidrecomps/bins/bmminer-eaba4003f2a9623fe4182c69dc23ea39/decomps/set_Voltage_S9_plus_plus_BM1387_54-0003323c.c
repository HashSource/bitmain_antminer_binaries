
int set_Voltage_S9_plus_plus_BM1387_54(uchar which_iic,uchar pic_voltage)

{
  uchar uVar1;
  uchar uVar2;
  char cVar3;
  int iVar4;
  uchar pic_voltage_local;
  uchar which_iic_local;
  char tmp42 [2048];
  char logstr [1024];
  uchar read_back_data [2];
  uchar crc_data [2];
  uchar voltage3;
  uchar voltage2;
  uchar voltage1;
  ushort crc;
  uchar length;
  double temp_voltage;
  int retry_count;
  
  retry_count = 0;
  dsPIC33EP16GS202_enable_pic_dc_dc(which_iic,'\0');
  cgsleep_ms(500);
  if ((char)pic_voltage < '\0') {
    iVar4 = 0;
  }
  else {
    while( true ) {
      iVar4 = retry_count;
      if (2 < retry_count) {
        iVar4 = 0;
      }
      cVar3 = (char)iVar4;
      if (retry_count < 3) {
        cVar3 = '\x01';
      }
      retry_count = retry_count + 1;
      if (cVar3 == '\0') {
        return 0;
      }
      T9_plus_write_pic_iic(false,false,'\0',which_iic,'U');
      T9_plus_write_pic_iic(false,false,'\0',which_iic,0xaa);
      T9_plus_write_pic_iic(false,false,'\0',which_iic,'\a');
      T9_plus_write_pic_iic(false,false,'\0',which_iic,'\x10');
      T9_plus_write_pic_iic(false,false,'\0',which_iic,pic_voltage);
      T9_plus_write_pic_iic(false,false,'\0',which_iic,'\0');
      T9_plus_write_pic_iic(false,false,'\0',which_iic,'\0');
      T9_plus_write_pic_iic(false,false,'\0',which_iic,(uchar)((ushort)(pic_voltage + 0x17) >> 8));
      T9_plus_write_pic_iic(false,false,'\0',which_iic,(uchar)(pic_voltage + 0x17));
      usleep(100000);
      uVar1 = T9_plus_write_pic_iic(true,false,'\0',which_iic,'\0');
      uVar2 = T9_plus_write_pic_iic(true,false,'\0',which_iic,'\0');
      if ((uVar1 == '\x10') && (uVar2 == '\x01')) break;
      if (((use_syslog != false) || (opt_log_output != false)) || (4 < opt_log_level)) {
        snprintf(tmp42,0x800,"%s failed on Chain[%d]!\n\n","set_Voltage_S9_plus_plus_BM1387_54",
                 (uint)which_iic);
        _applog(5,tmp42,false);
      }
      sleep(1);
    }
    printf("\n--- %s ok!\n\n","set_Voltage_S9_plus_plus_BM1387_54",(uint)pic_voltage);
    cgsleep_ms(500);
    dsPIC33EP16GS202_enable_pic_dc_dc(which_iic,'\x01');
    sleep(1);
    iVar4 = 1;
  }
  return iVar4;
}

