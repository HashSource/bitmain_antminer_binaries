
double decode_an_voltage_buf(int param_1)

{
  int iVar1;
  FILE *pFVar2;
  uint uVar3;
  double dVar4;
  
  if (param_1 == 0) {
    return DAT_00041c80;
  }
  iVar1 = check_pic_crc();
  if (iVar1 != 0) {
    uVar3 = (uint)CONCAT11(*(undefined *)(param_1 + 3),*(undefined *)(param_1 + 4));
    if (log_level < 6) {
      dVar4 = (double)(longlong)(int)uVar3 * DAT_00041c70 * DAT_00041c78 * 4.0;
    }
    else {
      pFVar2 = fopen(log_file,(char *)&DAT_0005e760);
      if (pFVar2 != (FILE *)0x0) {
        fprintf(pFVar2,"%s:%d:%s: voltage = %d\n","power.c",0x1ea,DAT_00041c88,uVar3);
      }
      fclose(pFVar2);
      dVar4 = (double)(longlong)(int)uVar3 * DAT_00041c70 * DAT_00041c78;
      if (log_level < 6) {
        dVar4 = dVar4 * 4.0;
      }
      else {
        pFVar2 = fopen(log_file,(char *)&DAT_0005e760);
        if (pFVar2 != (FILE *)0x0) {
          fprintf(pFVar2,"%s:%d:%s: v_an2 = %f\n","power.c",0x1ef,DAT_00041c88);
        }
        fclose(pFVar2);
        dVar4 = dVar4 * 4.0;
        if (5 < log_level) {
          pFVar2 = fopen(log_file,(char *)&DAT_0005e760);
          if (pFVar2 != (FILE *)0x0) {
            fprintf(pFVar2,"%s:%d:%s: v_10 = %f\n","power.c",0x1f2,DAT_00041c88);
          }
          fclose(pFVar2);
          return dVar4;
        }
      }
    }
    return dVar4;
  }
  if (3 < log_level) {
    pFVar2 = fopen(log_file,(char *)&DAT_0005e760);
    if (pFVar2 != (FILE *)0x0) {
      fprintf(pFVar2,"%s:%d:%s: crc error!\n","power.c",0x1e2,DAT_00041c88);
    }
    fclose(pFVar2);
  }
  return DAT_00041c80;
}

