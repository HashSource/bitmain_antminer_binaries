
uint get_power_iic_value_from_voltage(int *param_1)

{
  int iVar1;
  FILE *__stream;
  uint unaff_r4;
  double in_d0;
  double dVar2;
  uint uVar3;
  
  if (*param_1 == 2) {
    dVar2 = DAT_00041ab8 - in_d0 * DAT_00041ab0;
    if (dVar2 == DAT_00041ac0 || dVar2 < DAT_00041ac0 != (NAN(dVar2) || NAN(DAT_00041ac0))) {
      iVar1 = (uint)(dVar2 < 0.0) << 0x1f;
      if (-1 < iVar1) {
        dVar2 = (double)((ulonglong)((uint)(0.0 < dVar2) * (int)(longlong)dVar2) << 0x20);
      }
      if (iVar1 < 0) {
        unaff_r4 = 0;
      }
      if (-1 < iVar1) {
        unaff_r4 = (uint)((ulonglong)dVar2 >> 0x20) & 0xff;
      }
    }
    else {
      unaff_r4 = 0xff;
    }
  }
  else {
    in_d0 = in_d0 * DAT_00041a88;
    dVar2 = (in_d0 * DAT_00041a98 - DAT_00041aa0) / (DAT_00041aa8 - in_d0 * DAT_00041a90);
    uVar3 = (uint)(0.0 < dVar2) * (int)(longlong)dVar2;
    unaff_r4 = uVar3 & 0xff;
    if ((uVar3 & 0x80) != 0) {
      unaff_r4 = 0x7f;
    }
  }
  if (log_level < 4) {
    return unaff_r4;
  }
  __stream = fopen(log_file,(char *)&DAT_0005e760);
  if (__stream != (FILE *)0x0) {
    fprintf(__stream,"%s:%d:%s: iic_index for voltage[%d] = %d\n","power.c",0x15d,DAT_00041ac8,
            unaff_r4,(int)(longlong)in_d0);
  }
  fclose(__stream);
  return unaff_r4;
}

