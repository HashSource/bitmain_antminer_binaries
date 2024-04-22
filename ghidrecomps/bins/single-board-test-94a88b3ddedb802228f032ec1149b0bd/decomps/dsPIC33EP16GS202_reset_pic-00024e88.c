
undefined4 dsPIC33EP16GS202_reset_pic(byte param_1)

{
  char cVar1;
  char cVar2;
  FILE *__stream;
  int local_c;
  
  local_c = 0;
  while( true ) {
    if (2 < local_c) {
      return 0;
    }
    T9_plus_write_pic_iic(0,0,0,param_1,0x55);
    T9_plus_write_pic_iic(0,0,0,param_1,0xaa);
    T9_plus_write_pic_iic(0,0,0,param_1,4);
    T9_plus_write_pic_iic(0,0,0,param_1,7);
    T9_plus_write_pic_iic(0,0,0,param_1,0);
    T9_plus_write_pic_iic(0,0,0,param_1,0xb);
    usleep(400000);
    cVar1 = T9_plus_write_pic_iic(1,0,0,param_1,0);
    cVar2 = T9_plus_write_pic_iic(1,0,0,param_1,0);
    usleep(100000);
    if ((cVar1 == '\a') && (cVar2 == '\x01')) break;
    if (3 < log_level) {
      __stream = fopen(log_file,"a+");
      if (__stream != (FILE *)0x0) {
        fprintf(__stream,"%s:%d: %s failed on Chain[%d]!\n","dsPIC33EP16GS202.c",0xa4,
                "dsPIC33EP16GS202_reset_pic",(uint)param_1);
      }
      fclose(__stream);
    }
    sleep(1);
    local_c = local_c + 1;
  }
  sleep(1);
  return 1;
}

