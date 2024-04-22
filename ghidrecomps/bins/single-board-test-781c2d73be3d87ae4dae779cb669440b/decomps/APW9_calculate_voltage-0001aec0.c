
/* WARNING: Unknown calling convention */

uchar APW9_calculate_voltage(uint voltage)

{
  uint uVar1;
  float fVar2;
  double dVar3;
  
  if (gHashBoard_BHB07601) {
    dVar3 = DAT_0001af78 - ((double)(ulonglong)voltage * DAT_0001af68) / DAT_0001af70;
    fVar2 = (float)dVar3;
    if ((int)((uint)(fVar2 < 0.0) << 0x1f) < 0) {
      printf("\n!!! %s: voltage_n = %f, we use N = %d as default\n",DAT_0001af88,
             SUB84((double)fVar2,0),(int)((ulonglong)(double)fVar2 >> 0x20),0);
      return '\0';
    }
    uVar1 = (uint)(0.0 < fVar2) * (int)dVar3 & 0xff;
    dVar3 = (double)fVar2;
  }
  else {
    printf("\n!!! %s Please check Hashboard type!\n\n",DAT_0001af88);
    uVar1 = 0xff;
    dVar3 = DAT_0001af80;
  }
  printf("\n--- %s: voltage_n = %f, N = %d\n",DAT_0001af88,SUB84(dVar3,0),
         (int)((ulonglong)dVar3 >> 0x20),uVar1);
  return (uchar)uVar1;
}

