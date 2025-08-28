
undefined4 decode_an_voltage_buf(int param_1)

{
  int iVar1;
  FILE *pFVar2;
  uint uVar3;
  undefined4 uVar4;
  double dVar5;
  
  if (param_1 == 0) {
    return 0;
  }
  iVar1 = check_pic_crc();
  if (iVar1 != 0) {
    uVar3 = (uint)CONCAT11(*(undefined1 *)(param_1 + 3),*(undefined1 *)(param_1 + 4));
    if (log_level < 6) {
      uVar4 = SUB84((double)(longlong)(int)uVar3 * 3.3 * 0.000244140625 * 4.0,0);
    }
    else {
      pFVar2 = fopen(log_file,"a+");
      if (pFVar2 != (FILE *)0x0) {
        fprintf(pFVar2,"%s:%d:%s: voltage = %d\n","power.c",0x1ea,"decode_an_voltage_buf",uVar3);
      }
      fclose(pFVar2);
      dVar5 = (double)(longlong)(int)uVar3 * 3.3 * 0.000244140625;
      if (log_level < 6) {
        uVar4 = SUB84(dVar5 * 4.0,0);
      }
      else {
        pFVar2 = fopen(log_file,"a+");
        if (pFVar2 != (FILE *)0x0) {
          fprintf(pFVar2,"%s:%d:%s: v_an2 = %f\n","power.c",0x1ef,"decode_an_voltage_buf");
        }
        fclose(pFVar2);
        uVar4 = SUB84(dVar5 * 4.0,0);
        if (5 < log_level) {
          pFVar2 = fopen(log_file,"a+");
          if (pFVar2 != (FILE *)0x0) {
            fprintf(pFVar2,"%s:%d:%s: v_10 = %f\n","power.c",0x1f2,"decode_an_voltage_buf");
          }
          fclose(pFVar2);
          return uVar4;
        }
      }
    }
    return uVar4;
  }
  if (3 < log_level) {
    pFVar2 = fopen(log_file,"a+");
    if (pFVar2 != (FILE *)0x0) {
      fprintf(pFVar2,"%s:%d:%s: crc error!\n","power.c",0x1e2,"decode_an_voltage_buf");
    }
    fclose(pFVar2);
  }
  return 0;
}

