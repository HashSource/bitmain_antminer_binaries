
void check_voltage(int param_1,int param_2)

{
  float fVar1;
  FILE *__stream;
  uint uVar2;
  uint extraout_r3;
  undefined8 in_d0;
  float fVar3;
  float fVar4;
  char acStack_e0 [200];
  
  fVar1 = (float)in_d0;
  fVar3 = (float)((ulonglong)in_d0 >> 0x20);
  uVar2 = log_level;
  if (7 < log_level) {
    __stream = fopen(log_file,"a+");
    if (__stream != (FILE *)0x0) {
      fprintf(__stream,"%s:%d:%s: true_data = %f, i = %d, rule = %f\n","xadc.c",0xa4,"check_voltage"
             );
    }
    fclose(__stream);
    uVar2 = extraout_r3;
  }
  fVar4 = fVar3 * 1.05;
  if ((fVar1 <= fVar4) && (fVar4 = fVar3 * 0.95, -1 < (int)((uint)(fVar1 < fVar4) << 0x1f))) {
    return;
  }
  sprintf(acStack_e0,"WARNING : %s is %f mv, rule is %f\n",*(int *)(param_1 + param_2 * 4) + 0xb,
          uVar2,(double)fVar1,(double)fVar4);
  write_log_file(*(int *)(param_1 + param_2 * 4) + 0xb,acStack_e0);
  return;
}

