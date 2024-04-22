
void check_voltage(int param_1,int param_2)

{
  float fVar1;
  FILE *__stream;
  undefined8 in_d0;
  float fVar2;
  float fVar3;
  char acStack_e0 [200];
  
  fVar1 = (float)in_d0;
  fVar2 = (float)((ulonglong)in_d0 >> 0x20);
  if (7 < log_level) {
    __stream = fopen(log_file,(char *)&DAT_0005e760);
    if (__stream != (FILE *)0x0) {
      fprintf(__stream,"%s:%d:%s: true_data = %f, i = %d, rule = %f\n","xadc.c",0xa4,"check_voltage"
             );
    }
    fclose(__stream);
  }
  fVar3 = fVar2 * DAT_0004bb6c;
  if ((fVar1 == fVar3 || fVar1 < fVar3 != (NAN(fVar1) || NAN(fVar3))) &&
     (-1 < (int)((uint)(fVar1 < fVar2 * DAT_0004bb70) << 0x1f))) {
    return;
  }
  sprintf(acStack_e0,"WARNING : %s is %f mv, rule is %f\n",*(int *)(param_1 + param_2 * 4) + 0xb);
  write_log_file(*(int *)(param_1 + param_2 * 4) + 0xb,acStack_e0);
  return;
}

