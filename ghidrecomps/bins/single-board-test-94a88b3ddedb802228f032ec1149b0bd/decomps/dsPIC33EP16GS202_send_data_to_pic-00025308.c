
undefined4 dsPIC33EP16GS202_send_data_to_pic(byte param_1,undefined *param_2)

{
  char cVar1;
  char cVar2;
  FILE *__stream;
  int local_10;
  short local_c;
  byte local_9;
  
  local_10 = 0;
  local_c = 0x16;
  for (local_9 = 0; local_9 < 0x10; local_9 = local_9 + 1) {
    local_c = local_c + (ushort)(byte)param_2[local_9];
  }
  while( true ) {
    if (2 < local_10) {
      return 0;
    }
    T9_plus_write_pic_iic(0,0,0,param_1,0x55);
    T9_plus_write_pic_iic(0,0,0,param_1,0xaa);
    T9_plus_write_pic_iic(0,0,0,param_1,0x14);
    T9_plus_write_pic_iic(0,0,0,param_1,2);
    T9_plus_write_pic_iic(0,0,0,param_1,*param_2);
    T9_plus_write_pic_iic(0,0,0,param_1,param_2[1]);
    T9_plus_write_pic_iic(0,0,0,param_1,param_2[2]);
    T9_plus_write_pic_iic(0,0,0,param_1,param_2[3]);
    T9_plus_write_pic_iic(0,0,0,param_1,param_2[4]);
    T9_plus_write_pic_iic(0,0,0,param_1,param_2[5]);
    T9_plus_write_pic_iic(0,0,0,param_1,param_2[6]);
    T9_plus_write_pic_iic(0,0,0,param_1,param_2[7]);
    T9_plus_write_pic_iic(0,0,0,param_1,param_2[8]);
    T9_plus_write_pic_iic(0,0,0,param_1,param_2[9]);
    T9_plus_write_pic_iic(0,0,0,param_1,param_2[10]);
    T9_plus_write_pic_iic(0,0,0,param_1,param_2[0xb]);
    T9_plus_write_pic_iic(0,0,0,param_1,param_2[0xc]);
    T9_plus_write_pic_iic(0,0,0,param_1,param_2[0xd]);
    T9_plus_write_pic_iic(0,0,0,param_1,param_2[0xe]);
    T9_plus_write_pic_iic(0,0,0,param_1,param_2[0xf]);
    T9_plus_write_pic_iic(0,0,0,param_1,(char)((ushort)local_c >> 8));
    T9_plus_write_pic_iic(0,0,0,param_1,(char)local_c);
    usleep(200000);
    cVar1 = T9_plus_write_pic_iic(1,0,0,param_1,0);
    cVar2 = T9_plus_write_pic_iic(1,0,0,param_1,0);
    usleep(100000);
    if ((cVar1 == '\x02') && (cVar2 == '\x01')) break;
    if (3 < log_level) {
      __stream = fopen(log_file,"a+");
      if (__stream != (FILE *)0x0) {
        fprintf(__stream,"%s:%d: %s failed on Chain[%d]!\n","dsPIC33EP16GS202.c",0x13b,
                "dsPIC33EP16GS202_send_data_to_pic",(uint)param_1);
      }
      fclose(__stream);
    }
    sleep(1);
    local_10 = local_10 + 1;
  }
  return 1;
}

