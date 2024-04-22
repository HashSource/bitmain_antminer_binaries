
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
    _Var3 = check_crc(buf);
    if (_Var3) {
      uVar1 = buf[3];
      uVar2 = buf[4];
      if (5 < log_level) {
        print_crt_time_to_file(log_file,5);
        pFVar4 = fopen(log_file,"a+");
        if (pFVar4 != (FILE *)0x0) {
          fprintf(pFVar4,"%s:%d:%s: voltage = %d\n","dspic33ep16gs202.c",0x2cc,
                  "decode_an_voltage_buf",(uint)CONCAT11(uVar1,uVar2));
        }
        fclose(pFVar4);
      }
      dVar5 = ((double)(longlong)(int)(uint)CONCAT11(uVar1,uVar2) * DAT_00071488) / DAT_00071490;
      if (5 < log_level) {
        print_crt_time_to_file(log_file,5);
        pFVar4 = fopen(log_file,"a+");
        if (pFVar4 != (FILE *)0x0) {
          fprintf(pFVar4,"%s:%d:%s: v_an2 = %f\n","dspic33ep16gs202.c",0x2d1,"decode_an_voltage_buf"
                 );
        }
        fclose(pFVar4);
      }
      dVar5 = dVar5 * DAT_00071498;
      if (5 < log_level) {
        print_crt_time_to_file(log_file,5);
        pFVar4 = fopen(log_file,"a+");
        if (pFVar4 != (FILE *)0x0) {
          fprintf(pFVar4,"%s:%d:%s: v_10 = %f\n","dspic33ep16gs202.c",0x2d4,"decode_an_voltage_buf")
          ;
        }
        fclose(pFVar4);
      }
    }
    else {
      if (3 < log_level) {
        print_crt_time_to_file(log_file,3);
        pFVar4 = fopen(log_file,"a+");
        if (pFVar4 != (FILE *)0x0) {
          fprintf(pFVar4,"%s:%d:%s: crc error!\n","dspic33ep16gs202.c",0x2c4,"decode_an_voltage_buf"
                 );
        }
        fclose(pFVar4);
      }
      dVar5 = 0.0;
    }
  }
  return dVar5;
}

