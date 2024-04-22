
_Bool check_pic_crc(uchar *buf)

{
  FILE *__stream;
  undefined uVar1;
  ushort uVar2;
  bool bVar3;
  uchar *buf_local;
  FILE *pFile;
  uint32_t len;
  uint16_t sum2;
  int i;
  uint16_t sum1;
  
  sum1 = 0;
  if ((buf == (uchar *)0x0) || (*buf < 4)) {
    uVar1 = 0;
  }
  else {
    buf_local = buf;
    for (i = 0; (uint)i < *buf - 2; i = i + 1) {
      sum1 = *buf_local + sum1;
      buf_local = buf_local + 1;
    }
    uVar2 = CONCAT11(*buf_local,buf_local[1]);
    if (5 < log_level) {
      print_crt_time_to_file(log_file,5);
      __stream = fopen(log_file,"a+");
      if (__stream != (FILE *)0x0) {
        fprintf(__stream,"%s:%d:%s: sum1,sum2 = %d,%d\n","power.c",0x3d1,"check_pic_crc",(uint)sum1,
                (uint)uVar2);
      }
      fclose(__stream);
    }
    bVar3 = sum1 == uVar2;
    if (bVar3) {
      uVar2 = 1;
    }
    uVar1 = (undefined)uVar2;
    if (!bVar3) {
      uVar1 = 0;
    }
  }
  return (_Bool)uVar1;
}

