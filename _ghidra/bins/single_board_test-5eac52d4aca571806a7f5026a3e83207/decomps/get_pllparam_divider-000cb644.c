
/* WARNING: Unknown calling convention */

int32_t get_pllparam_divider
                  (float freq,pllparameter_t *pll_param,pll_userdivider_t *userdivider,
                  float *pll_freq)

{
  uint8_t uVar1;
  uint uVar2;
  int32_t iVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  int iVar10;
  float fVar11;
  int iVar12;
  float vco;
  float fVar13;
  
  iVar6 = 0;
  iVar10 = 0;
  uVar7 = 0;
  uVar8 = 0;
  uVar9 = 0;
  uVar5 = 2;
  fVar11 = 10.0;
  do {
    uVar4 = 1;
    do {
      uVar2 = uVar4 & 0xff;
      do {
        iVar12 = (int)(longlong)
                      (((float)(longlong)(int)uVar2 * (float)(longlong)(int)uVar4 * freq *
                       (float)(longlong)(int)uVar5) / 25.0 + 0.5);
        if (((iVar12 - 0x10U < 0xeb) &&
            (((fVar13 = (float)(longlong)iVar12 * (25.0 / (float)(longlong)(int)uVar5), uVar5 != 1
              || (fVar13 <= 3125.0)) && (fVar13 <= 3200.0)))) &&
           ((-1 < (int)((uint)(fVar13 < 2000.0) << 0x1f) &&
            (fVar13 = ABS(freq - fVar13 / (float)(longlong)(int)(uVar2 * uVar4)), fVar13 < fVar11)))
           ) {
          iVar10 = 1;
          iVar6 = iVar12;
          uVar7 = uVar4 & 0xff;
          uVar8 = uVar2;
          uVar9 = uVar5 & 0xff;
          fVar11 = fVar13;
        }
        uVar2 = uVar2 + 1 & 0xff;
      } while (uVar2 != 8);
      uVar4 = uVar4 + 1;
    } while (uVar4 != 8);
    uVar5 = uVar5 - 1;
  } while (uVar5 != 0);
  if (iVar6 == 0) {
    puts("find div fail, use default value");
    iVar3 = -1;
  }
  else {
    if (pll_freq != (float *)0x0) {
      *pll_freq = ((25.0 / (float)(longlong)(int)uVar9) * (float)(longlong)iVar6) /
                  (float)(longlong)(iVar10 * (int)(short)uVar8 * (int)(short)uVar7);
    }
    iVar3 = 0;
    pll_param->postdiv1 = (uint8_t)uVar8;
    pll_param->postdiv2 = (uint8_t)uVar7;
    pll_param->refdiv = (uint8_t)uVar9;
    pll_param->fbdiv = (uint16_t)iVar6;
    uVar1 = (uint8_t)iVar10;
    userdivider->userdivider0 = uVar1;
    userdivider->userdivider1 = uVar1;
    userdivider->userdivider2 = uVar1;
    userdivider->userdivider3 = uVar1;
  }
  return iVar3;
}

