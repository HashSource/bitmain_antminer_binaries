
/* WARNING: Unknown calling convention */

void set_BM1397_freq(uchar which_chain,uchar chip_addr,uint freq,_Bool mode)

{
  int iVar1;
  ulonglong uVar2;
  double dVar3;
  float fVar4;
  float fVar5;
  byte bVar6;
  uint8_t pll_div;
  _Bool need_recal;
  uint uVar7;
  uint uVar8;
  uint8_t postdiv1;
  uint8_t postdiv2;
  uint uVar9;
  uint uVar10;
  uint8_t postdiv;
  uint uVar11;
  bool bVar12;
  bool bVar13;
  float pll_vco_choice;
  double dVar14;
  uint uVar15;
  uint32_t pll_out_div_i;
  float fVar16;
  float in_s13;
  float extraout_s13;
  float extraout_s13_00;
  float pll_vco_step;
  float postdiv_f;
  float postdiv_f_1;
  float fVar17;
  float pll_out_div_f;
  float decimals;
  uint uVar18;
  uint32_t postdiv_i;
  float pll_vco;
  float decimals_last;
  
  fVar5 = DAT_0002668c;
  fVar4 = DAT_00026688;
  dVar3 = DAT_00026678;
  dVar14 = DAT_00026670;
  uVar2 = (ulonglong)freq;
  bVar12 = false;
  uVar11 = 0;
  uVar10 = 0;
  uVar9 = 0;
  decimals_last = 25.0;
  pll_vco = DAT_00026684;
  pll_vco_choice = DAT_00026680;
  do {
    while( true ) {
      iVar1 = (uint)(pll_vco < fVar4) << 0x1f;
      pll_vco_step = 12.5;
      if (iVar1 < 0) {
        freq = 2;
      }
      if (-1 < iVar1) {
        freq = 1;
        in_s13 = 1.0;
      }
      if (iVar1 < 0) {
        in_s13 = 2.0;
      }
      if (-1 < iVar1) {
        pll_vco_step = 25.0;
      }
      if (bVar12) {
        pll_vco = pll_vco_choice - pll_vco_step;
        decimals_last = 25.0;
      }
      fVar17 = pll_vco / (float)uVar2;
      uVar15 = (uint)(0.0 < fVar17) * (int)fVar17;
      pll_out_div_i = (uint32_t)(float)(ulonglong)uVar15;
      fVar17 = fVar17 - (float)pll_out_div_i;
      if ((int)((uint)(fVar17 < decimals_last) << 0x1f) < 0) break;
LAB_00026452:
      pll_vco = pll_vco - pll_vco_step;
      uVar15 = uVar11;
      if (pll_vco < fVar5 != (NAN(pll_vco) || NAN(fVar5))) goto LAB_00026466;
      bVar12 = false;
    }
    uVar11 = uVar15 & 0xff;
    fVar16 = (pll_vco * in_s13) / 25.0;
    in_s13 = (float)((uint)(0.0 < fVar16) * (int)fVar16);
    uVar9 = (uint)in_s13 & 0xff;
    uVar10 = freq;
    uVar15 = uVar11;
    pll_vco_choice = pll_vco;
    decimals_last = fVar17;
    if (-1 < (int)((uint)((double)fVar17 < dVar3) << 0x1f)) goto LAB_00026452;
LAB_00026466:
    pll_vco = pll_vco_choice;
    if (uVar15 < 0x11) {
      uVar11 = 1;
      uVar7 = 0x10;
      uVar18 = uVar11;
      goto LAB_00026504;
    }
    uVar18 = 0xf;
    do {
      uVar7 = uVar18 & 0xff;
      freq = uVar18 - 1;
      fVar17 = (float)(ulonglong)uVar15 / (float)(longlong)(int)uVar18;
      if ((int)((uint)((double)(fVar17 - (float)(ulonglong)((uint)(0.0 < fVar17) * (int)fVar17)) <
                      dVar14) << 0x1f) < 0) {
        bVar6 = __udivsi3(uVar15,uVar7);
        uVar11 = (uint)bVar6;
        break;
      }
      uVar18 = freq;
      uVar7 = uVar7 - 1 & 0xff;
      uVar11 = uVar15;
    } while (freq != 1);
    uVar15 = uVar7;
    if ((uVar15 == 2) && ((uVar11 & 1) != 0)) {
      printf("\n--- %s: need recal 1\n",DAT_00026690);
      in_s13 = extraout_s13;
      if (pll_vco == fVar5 || pll_vco < fVar5 != (NAN(pll_vco) || NAN(fVar5))) {
        uVar18 = 0xc0780111;
        uVar8 = 0xe;
        printf("\n--- %s: !!!!!!!!!!!!!!!Set freq don\'t ok!!!!!!!!!! using 200M pll\n",DAT_00026690
              );
        goto LAB_00010ad8;
      }
    }
    else {
      if (uVar11 < 8) {
        uVar7 = uVar11 << 4;
        uVar18 = 1;
        goto LAB_00026504;
      }
      uVar7 = 6;
      while( true ) {
        freq = uVar7 - 1;
        fVar17 = (float)(ulonglong)uVar11 / (float)(longlong)(int)uVar7;
        uVar18 = (uint)(0.0 < fVar17) * (int)fVar17;
        postdiv_i = (uint32_t)(float)(ulonglong)uVar18;
        if ((int)((uint)((double)(fVar17 - (float)postdiv_i) < dVar14) << 0x1f) < 0) break;
        uVar7 = freq & 0xff;
        if (uVar7 == 0xff) {
          uVar18 = 1;
          uVar8 = 0xff;
          goto LAB_000264fa;
        }
      }
      uVar18 = uVar18 & 0xff;
      bVar13 = 6 < uVar18;
      bVar12 = uVar18 == 7;
      if (uVar18 < 8) {
        bVar13 = uVar7 <= uVar18;
        bVar12 = uVar18 == uVar7;
      }
      if ((!bVar13 || bVar12) ||
         (printf("\n--- %s: need recal 2\n",DAT_00026690), in_s13 = extraout_s13_00,
         pll_vco == fVar5 || pll_vco < fVar5 != (NAN(pll_vco) || NAN(fVar5)))) break;
    }
    bVar12 = true;
    pll_vco_choice = pll_vco;
  } while( true );
  uVar8 = uVar18 * uVar7;
LAB_000264fa:
  if (uVar11 == uVar8) {
    uVar7 = uVar7 << 4;
LAB_00026504:
    dVar14 = (double)uVar2;
    uVar8 = uVar15 - 1;
    uVar18 = uVar7 | uVar18 | uVar9 << 0x10 | uVar10 << 8 | 0xc0000000;
    printf("\n--- %s: Want freq %f  real freq %f\n",DAT_00026690,SUB84(dVar14,0),
           (int)((ulonglong)dVar14 >> 0x20),
           (double)(((25.0 / (float)(longlong)(int)uVar10) * (float)(longlong)(int)uVar9) /
                   (float)(longlong)(int)(uVar11 * uVar15)));
  }
  else {
    printf("\n--- %s: Don\'t find postdiv1 %d * postdiv2 %d = postdiv %d\n",DAT_00026690,uVar7,
           uVar18,uVar11);
    printf("\n--- %s: !!!!!!!!!!!!!!!Set freq don\'t ok!!!!!!!!!! using 200M pll\n",DAT_00026690);
    uVar18 = 0xc0780111;
    uVar8 = 0xe;
  }
LAB_00010ad8:
  BM1397_set_config(which_chain,chip_addr,'\b',uVar18,mode);
  usleep(10000);
  BM1397_set_config(which_chain,chip_addr,'p',uVar8,mode);
  usleep(10000);
  BM1397_set_config(which_chain,chip_addr,'\b',uVar18,mode);
  (*(code *)PTR_usleep_00030148)(10000);
  return;
}

