
double decode_an_voltage_buf(uchar *buf)

{
  uchar uVar1;
  uchar uVar2;
  _Bool _Var3;
  FILE *pFVar4;
  double dVar5;
  uchar *buf_local;
  FILE *pFile;
  FILE *pFile_3;
  double v_10;
  FILE *pFile_2;
  double v_an2;
  FILE *pFile_1;
  uint16_t v_n;
  
  if (buf == (uchar *)0x0) {
    dVar5 = 0.0;
  }
  else {
    _Var3 = check_pic_crc(buf);
    if (_Var3) {
      uVar1 = buf[3];
      uVar2 = buf[4];
      if (5 < log_level) {
        print_crt_time_to_file(log_file,5);
        pFVar4 = fopen(log_file,"a+");
        if (pFVar4 != (FILE *)0x0) {
          fprintf(pFVar4,"%s:%d:%s: voltage = %d\n","power.c",999,"decode_an_voltage_buf",
                  (uint)CONCAT11(uVar1,uVar2));
        }
        fclose(pFVar4);
      }
      dVar5 = ((double)(longlong)(int)(uint)CONCAT11(uVar1,uVar2) * DAT_000388e8) / DAT_000388f0;
      if (5 < log_level) {
        print_crt_time_to_file(log_file,5);
        pFVar4 = fopen(log_file,"a+");
        if (pFVar4 != (FILE *)0x0) {
          fprintf(pFVar4,"%s:%d:%s: v_an2 = %f\n","power.c",0x3ec,"decode_an_voltage_buf");
        }
        fclose(pFVar4);
      }
      dVar5 = dVar5 * DAT_000388f8;
      if (5 < log_level) {
        print_crt_time_to_file(log_file,5);
        pFVar4 = fopen(log_file,"a+");
        if (pFVar4 != (FILE *)0x0) {
          fprintf(pFVar4,"%s:%d:%s: v_10 = %f\n","power.c",0x3ef,"decode_an_voltage_buf");
        }
        fclose(pFVar4);
      }
    }
    else {
      if (3 < log_level) {
        print_crt_time_to_file(log_file,3);
        pFVar4 = fopen(log_file,"a+");
        if (pFVar4 != (FILE *)0x0) {
          fprintf(pFVar4,"%s:%d:%s: crc error!\n","power.c",0x3df,"decode_an_voltage_buf");
        }
        fclose(pFVar4);
      }
      dVar5 = 0.0;
    }
  }
  return dVar5;
}

