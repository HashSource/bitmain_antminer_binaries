
/* WARNING: Unknown calling convention */

int32_t get_pllparam_divider
                  (float freq,pllparameter_t *pll_param,pll_userdivider_t *userdivider,
                  float *pll_freq)

{
  uint8_t uVar1;
  uint uVar2;
  int32_t iVar3;
  uint uVar4;
  byte bVar5;
  int iVar6;
  uint uVar7;
  uint uVar8;
  byte bVar9;
  int iVar10;
  float fVar11;
  int iVar12;
  float vco;
  float fVar13;
  
  iVar6 = 0;
  iVar10 = 0;
  uVar7 = 0;
  uVar8 = 0;
  bVar9 = 0;
  bVar5 = 2;
  fVar11 = 10.0;
  while( true ) {
    uVar4 = 1;
    do {
      uVar2 = uVar4 & 0xff;
      do {
        iVar12 = (int)(longlong)
                      (((float)bVar5 *
                       freq * (float)(longlong)(int)uVar4 * (float)(longlong)(int)uVar2) / 25.0 +
                      0.5);
        if (((iVar12 - 0x10U < 0xeb) &&
            (((fVar13 = (25.0 / (float)bVar5) * (float)(longlong)iVar12, bVar5 != 1 ||
              (fVar13 <= 3125.0)) && (fVar13 <= 3200.0)))) &&
           ((-1 < (int)((uint)(fVar13 < 2000.0) << 0x1f) &&
            (fVar13 = ABS(freq - fVar13 / (float)(longlong)(int)(uVar4 * uVar2)), fVar13 < fVar11)))
           ) {
          iVar10 = 1;
          iVar6 = iVar12;
          uVar7 = uVar4 & 0xff;
          uVar8 = uVar2;
          fVar11 = fVar13;
          bVar9 = bVar5;
        }
        uVar2 = uVar2 + 1 & 0xff;
      } while (uVar2 != 8);
      uVar4 = uVar4 + 1;
    } while (uVar4 != 8);
    if (bVar5 == 1) break;
    bVar5 = 1;
  }
  if (iVar6 == 0) {
    puts("find div fail, use default value");
    iVar3 = -1;
  }
  else {
    if (pll_freq != (float *)0x0) {
      *pll_freq = ((25.0 / (float)bVar9) * (float)(longlong)iVar6) /
                  (float)(longlong)(iVar10 * (int)(short)uVar8 * (int)(short)uVar7);
    }
    iVar3 = 0;
    pll_param->postdiv1 = (uint8_t)uVar8;
    pll_param->postdiv2 = (uint8_t)uVar7;
    pll_param->refdiv = bVar9;
    pll_param->fbdiv = (uint16_t)iVar6;
    uVar1 = (uint8_t)iVar10;
    userdivider->userdivider0 = uVar1;
    userdivider->userdivider1 = uVar1;
    userdivider->userdivider2 = uVar1;
    userdivider->userdivider3 = uVar1;
  }
  return iVar3;
}

