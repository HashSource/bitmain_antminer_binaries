
int dsPIC33EP16GS202_enable_pic_fix_voltage(uchar which_iic,uchar enable)

{
  uchar uVar1;
  uchar uVar2;
  char cVar3;
  int iVar4;
  uchar enable_local;
  uchar which_iic_local;
  char tmp42 [2048];
  char logstr [1024];
  uchar read_back_data [2];
  uchar crc_data [2];
  ushort crc;
  uchar length;
  int retry_count;
  
  retry_count = 0;
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
    if (cVar3 == '\0') break;
    T9_plus_write_pic_iic(false,false,'\0',which_iic,'U');
    T9_plus_write_pic_iic(false,false,'\0',which_iic,0xaa);
    T9_plus_write_pic_iic(false,false,'\0',which_iic,'\x05');
    T9_plus_write_pic_iic(false,false,'\0',which_iic,'0');
    T9_plus_write_pic_iic(false,false,'\0',which_iic,enable);
    T9_plus_write_pic_iic(false,false,'\0',which_iic,(uchar)((ushort)(enable + 0x35) >> 8));
    T9_plus_write_pic_iic(false,false,'\0',which_iic,(uchar)(enable + 0x35));
    usleep(10000);
    uVar1 = T9_plus_write_pic_iic(true,false,'\0',which_iic,'\0');
    uVar2 = T9_plus_write_pic_iic(true,false,'\0',which_iic,'\0');
    if ((uVar1 == '0') && (uVar2 == '\x01')) {
      if ((use_syslog != false) || ((opt_log_output != false || (4 < opt_log_level)))) {
        snprintf(tmp42,0x800,"%s [%d] ok, i2c=%d!\n","dsPIC33EP16GS202_enable_pic_fix_voltage",
                 (uint)enable,(uint)which_iic);
        _applog(5,tmp42,false);
      }
      return 1;
    }
    if (((use_syslog != false) || (opt_log_output != false)) || (4 < opt_log_level)) {
      snprintf(tmp42,0x800,"%s failed on Chain[%d]!\n","dsPIC33EP16GS202_enable_pic_fix_voltage",
               (uint)which_iic);
      _applog(5,tmp42,false);
    }
    sleep(1);
  }
  return 0;
}

