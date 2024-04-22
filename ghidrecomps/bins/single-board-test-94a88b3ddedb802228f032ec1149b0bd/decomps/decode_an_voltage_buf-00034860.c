
double decode_an_voltage_buf(int param_1)

{
  char cVar1;
  FILE *pFVar2;
  ushort uVar3;
  double dVar4;
  undefined4 local_38;
  undefined4 uStack_34;
  undefined4 local_28;
  undefined4 uStack_24;
  
  if (param_1 == 0) {
    dVar4 = 0.0;
  }
  else {
    cVar1 = check_pic_crc(param_1);
    if (cVar1 == '\x01') {
      uVar3 = CONCAT11(*(undefined *)(param_1 + 3),*(undefined *)(param_1 + 4));
      if (5 < log_level) {
        pFVar2 = fopen(log_file,"a+");
        if (pFVar2 != (FILE *)0x0) {
          fprintf(pFVar2,"%s:%d: voltage = %d\n","power.c",0x1eb,(uint)uVar3);
        }
        fclose(pFVar2);
      }
      dVar4 = ((double)(longlong)(int)(uint)uVar3 * DAT_00034a50) / DAT_00034a58;
      if (5 < log_level) {
        pFVar2 = fopen(log_file,"a+");
        if (pFVar2 != (FILE *)0x0) {
          local_28 = SUB84(dVar4,0);
          uStack_24 = (undefined4)((ulonglong)dVar4 >> 0x20);
          fprintf(pFVar2,"%s:%d: v_an2 = %f\n","power.c",0x1f0,local_28,uStack_24);
        }
        fclose(pFVar2);
      }
      dVar4 = dVar4 * 4.0;
      local_38 = SUB84(dVar4,0);
      uStack_34 = (undefined4)((ulonglong)dVar4 >> 0x20);
      if (5 < log_level) {
        pFVar2 = fopen(log_file,"a+");
        if (pFVar2 != (FILE *)0x0) {
          fprintf(pFVar2,"%s:%d: v_10 = %f\n","power.c",499,local_38,uStack_34);
        }
        fclose(pFVar2);
      }
    }
    else {
      if (3 < log_level) {
        pFVar2 = fopen(log_file,"a+");
        if (pFVar2 != (FILE *)0x0) {
          fprintf(pFVar2,"%s:%d: crc error!\n","power.c",0x1e3);
        }
        fclose(pFVar2);
      }
      dVar4 = 0.0;
    }
  }
  return dVar4;
}

