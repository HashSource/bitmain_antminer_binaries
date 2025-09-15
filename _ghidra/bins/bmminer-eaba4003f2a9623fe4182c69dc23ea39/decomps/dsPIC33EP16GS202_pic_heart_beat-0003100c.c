
int dsPIC33EP16GS202_pic_heart_beat(uchar which_iic)

{
  uchar uVar1;
  byte bVar2;
  byte bVar3;
  byte bVar4;
  byte bVar5;
  byte bVar6;
  char cVar7;
  int iVar8;
  uchar which_iic_local;
  char tmp42 [2048];
  char logstr [1024];
  uchar read_back_data [6];
  uchar crc_data [2];
  ushort crc;
  uchar length;
  int retry_count;
  
  retry_count = 0;
  while( true ) {
    iVar8 = retry_count;
    if (2 < retry_count) {
      iVar8 = 0;
    }
    cVar7 = (char)iVar8;
    if (retry_count < 3) {
      cVar7 = '\x01';
    }
    retry_count = retry_count + 1;
    if (cVar7 == '\0') break;
    T9_plus_write_pic_iic(false,false,'\0',which_iic,'U');
    T9_plus_write_pic_iic(false,false,'\0',which_iic,0xaa);
    T9_plus_write_pic_iic(false,false,'\0',which_iic,'\x04');
    T9_plus_write_pic_iic(false,false,'\0',which_iic,'\x16');
    T9_plus_write_pic_iic(false,false,'\0',which_iic,'\0');
    T9_plus_write_pic_iic(false,false,'\0',which_iic,'\x1a');
    usleep(500000);
    uVar1 = T9_plus_write_pic_iic(true,false,'\0',which_iic,'\0');
    bVar2 = T9_plus_write_pic_iic(true,false,'\0',which_iic,'\0');
    bVar3 = T9_plus_write_pic_iic(true,false,'\0',which_iic,'\0');
    read_back_data._0_3_ = CONCAT12(bVar3,(undefined2)CONCAT11(bVar2,uVar1));
    bVar4 = T9_plus_write_pic_iic(true,false,'\0',which_iic,'\0');
    bVar5 = T9_plus_write_pic_iic(true,false,'\0',which_iic,'\0');
    bVar6 = T9_plus_write_pic_iic(true,false,'\0',which_iic,'\0');
    printf("--- %s: read_back_data[0] = 0x%x, read_back_data[1] = 0x%x, read_back_data[2] = 0x%x, read_back_data[3] = 0x%x, read_back_data[4] = 0x%x, read_back_data[5] = 0x%x\n"
           ,"dsPIC33EP16GS202_pic_heart_beat",CONCAT13(0,read_back_data._0_3_) & 0xff,(uint)bVar2,
           (uint)bVar3,(uint)bVar4,(uint)bVar5,(uint)bVar6);
    if ((bVar2 == 0x16) && (bVar3 == 1)) {
      if ((use_syslog != false) || ((opt_log_output != false || (4 < opt_log_level)))) {
        snprintf(tmp42,0x800,"\n--- %s ok, HeartBeatReturnWord = %d\n\n",
                 "dsPIC33EP16GS202_pic_heart_beat",(uint)bVar4);
        _applog(5,tmp42,false);
      }
      return 1;
    }
    if (((use_syslog != false) || (opt_log_output != false)) || (4 < opt_log_level)) {
      snprintf(tmp42,0x800,"%s Heartbeat failed on Chain[%d], retry_count=%d!!!\n",
               "dsPIC33EP16GS202_pic_heart_beat",(uint)which_iic,retry_count);
      _applog(5,tmp42,false);
    }
    sleep(1);
  }
  return 0;
}

