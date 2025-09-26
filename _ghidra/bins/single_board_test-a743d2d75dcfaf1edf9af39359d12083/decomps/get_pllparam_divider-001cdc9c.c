
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
  int iVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  float fVar11;
  int iVar12;
  float vco;
  float fVar13;
  
  iVar6 = 0;
  iVar7 = 0;
  uVar9 = 0;
  uVar10 = 0;
  uVar8 = 0;
  uVar2 = 2;
  fVar11 = 10.0;
  do {
    uVar4 = 1;
    do {
      uVar5 = uVar4 & 0xff;
      do {
        iVar12 = (int)(longlong)
                      (((float)(longlong)(int)uVar5 * (float)(longlong)(int)uVar4 * freq *
                       (float)(longlong)(int)uVar2) / 25.0 + 0.5);
        if (((iVar12 - 0x10U < 0xeb) &&
            (((fVar13 = (float)(longlong)iVar12 * (25.0 / (float)(longlong)(int)uVar2), uVar2 != 1
              || (fVar13 <= 3125.0)) && (fVar13 <= 3200.0)))) &&
           ((-1 < (int)((uint)(fVar13 < 2000.0) << 0x1f) &&
            (fVar13 = ABS(freq - fVar13 / (float)(longlong)(int)(uVar5 * uVar4)), fVar13 < fVar11)))
           ) {
          iVar7 = 1;
          iVar6 = iVar12;
          uVar8 = uVar2 & 0xff;
          uVar9 = uVar4 & 0xff;
          uVar10 = uVar5;
          fVar11 = fVar13;
        }
        uVar5 = uVar5 + 1 & 0xff;
      } while (uVar5 != 8);
      uVar4 = uVar4 + 1;
    } while (uVar4 != 8);
    uVar2 = uVar2 - 1;
  } while (uVar2 != 0);
  if (iVar6 == 0) {
    puts("find div fail, use default value");
    iVar3 = -1;
  }
  else {
    if (pll_freq != (float *)0x0) {
      *pll_freq = ((25.0 / (float)(longlong)(int)uVar8) * (float)(longlong)iVar6) /
                  (float)(longlong)(iVar7 * (int)(short)uVar10 * (int)(short)uVar9);
    }
    printf("final refdiv: %d, fbdiv: %d, postdiv1: %d, postdiv2: %d, usr divider: %d, min diff value: %f\n"
           ,uVar8,iVar6,uVar10,uVar9,iVar7,(double)fVar11);
    printf("Want freq: %f, Real freq: %f\n");
    iVar3 = 0;
    pll_param->postdiv1 = (uint8_t)uVar10;
    pll_param->postdiv2 = (uint8_t)uVar9;
    pll_param->refdiv = (uint8_t)uVar8;
    pll_param->fbdiv = (uint16_t)iVar6;
    uVar1 = (uint8_t)iVar7;
    userdivider->userdivider0 = uVar1;
    userdivider->userdivider1 = uVar1;
    userdivider->userdivider2 = uVar1;
    userdivider->userdivider3 = uVar1;
  }
  return iVar3;
}

