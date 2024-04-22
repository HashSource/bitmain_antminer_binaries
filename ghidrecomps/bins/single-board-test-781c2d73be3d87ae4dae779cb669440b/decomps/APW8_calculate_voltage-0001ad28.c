
/* WARNING: Unknown calling convention */

uchar APW8_calculate_voltage(uint voltage)

{
  uint uVar1;
  double dVar2;
  float fVar3;
  
  if (gHashBoard_BHB91601S) {
LAB_0001ad8c:
    fVar3 = (float)(DAT_0001ae90 - ((double)(ulonglong)voltage * DAT_0001ae88) / DAT_0001ae78);
  }
  else {
    if (!gHashBoard_BHB91601P) {
      if (!gHashBoard_BHB07601) {
        printf("\n!!! %s Please check Hashboard type!\n\n",DAT_0001aeb0);
        uVar1 = 0xff;
        dVar2 = DAT_0001ae98;
        goto LAB_0001adc8;
      }
      goto LAB_0001ad8c;
    }
    dVar2 = (double)(ulonglong)voltage;
    if (BHB91601_ASIC_NUMBER == 0x54) {
      fVar3 = (float)(DAT_0001aea8 - (dVar2 * DAT_0001aea0) / DAT_0001ae78);
    }
    else if (BHB91601_ASIC_NUMBER == 0x3c) {
      fVar3 = (float)(DAT_0001ae80 - (dVar2 * DAT_0001ae70) / DAT_0001ae78);
    }
    else {
      fVar3 = (float)(DAT_0001aea8 - (dVar2 * DAT_0001aea0) / DAT_0001ae78);
      printf("\n!!! %s Use BHB91601 84P power as default!\n\n",DAT_0001aeb0);
    }
  }
  uVar1 = (uint)(0.0 < fVar3) * (int)fVar3 & 0xff;
  if ((int)((uint)(fVar3 < 0.0) << 0x1f) < 0) {
    printf("\n!!! %s: voltage_n = %f, we use N = %d as default\n",DAT_0001aeb0,
           SUB84((double)fVar3,0),(int)((ulonglong)(double)fVar3 >> 0x20),0);
    return '\0';
  }
  dVar2 = (double)fVar3;
LAB_0001adc8:
  printf("\n--- %s: voltage_n = %f, N = %d\n",DAT_0001aeb0,SUB84(dVar2,0),
         (int)((ulonglong)dVar2 >> 0x20),uVar1);
  return (uchar)uVar1;
}

