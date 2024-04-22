
undefined4 dsPIC33EP16GS202_get_pic_sw_version(byte param_1,byte *param_2)

{
  char cVar1;
  char cVar2;
  byte bVar3;
  char cVar4;
  char cVar5;
  FILE *__stream;
  int local_c;
  
  local_c = 0;
  *param_2 = 0xff;
  while( true ) {
    while( true ) {
      if (2 < local_c) {
        return 0;
      }
      T9_plus_write_pic_iic(0,0,0,param_1,0x55);
      T9_plus_write_pic_iic(0,0,0,param_1,0xaa);
      T9_plus_write_pic_iic(0,0,0,param_1,4);
      T9_plus_write_pic_iic(0,0,0,param_1,0x17);
      T9_plus_write_pic_iic(0,0,0,param_1,0);
      T9_plus_write_pic_iic(0,0,0,param_1,0x1b);
      usleep(100000);
      cVar1 = T9_plus_write_pic_iic(1,0,0,param_1,0);
      cVar2 = T9_plus_write_pic_iic(1,0,0,param_1,0);
      bVar3 = T9_plus_write_pic_iic(1,0,0,param_1,0);
      cVar4 = T9_plus_write_pic_iic(1,0,0,param_1,0);
      cVar5 = T9_plus_write_pic_iic(1,0,0,param_1,0);
      usleep(100000);
      if ((cVar2 == '\x17') && (cVar1 == '\x05')) break;
      if (3 < log_level) {
        __stream = fopen(log_file,"a+");
        if (__stream != (FILE *)0x0) {
          fprintf(__stream,"%s:%d: %s failed on Chain[%d]!\n","dsPIC33EP16GS202.c",0x3d,
                  "dsPIC33EP16GS202_get_pic_sw_version",(uint)param_1);
        }
        fclose(__stream);
      }
      sleep(1);
      local_c = local_c + 1;
    }
    if (((char)((ushort)(bVar3 + 0x1c) >> 8) == cVar4) && ((char)(bVar3 + 0x1c) == cVar5)) break;
    sleep(1);
    local_c = local_c + 1;
  }
  *param_2 = bVar3;
  return 1;
}

