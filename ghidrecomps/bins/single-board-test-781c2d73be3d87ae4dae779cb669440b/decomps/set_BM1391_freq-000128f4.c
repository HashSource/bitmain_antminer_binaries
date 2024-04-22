
/* WARNING: Unknown calling convention */

void set_BM1391_freq(uchar which_chain,uchar chip_addr,uint freq,_Bool mode)

{
  int iVar1;
  longlong lVar2;
  bool bVar3;
  double dVar4;
  float fVar5;
  float fVar6;
  undefined4 uVar7;
  byte bVar8;
  _Bool need_recal;
  uint uVar9;
  uint8_t postdiv1;
  uint uVar10;
  uint8_t pll_div;
  uint uVar11;
  uint8_t postdiv2;
  uint uVar12;
  uint uVar13;
  uint8_t postdiv;
  uint uVar14;
  double dVar15;
  float pll_vco_choice;
  undefined4 uVar16;
  float fVar17;
  undefined8 in_d6;
  float pll_vco_step;
  undefined8 extraout_d6;
  undefined8 extraout_d6_00;
  uint uVar18;
  uint32_t pll_out_div_i;
  uint32_t postdiv_i;
  float fVar19;
  float pll_out_div_f;
  float decimals;
  float postdiv_f;
  float postdiv_f_1;
  double dVar20;
  float pll_vco;
  float decimals_last;
  uint local_74;
  uint local_6c;
  
  fVar6 = DAT_00012c8c;
  fVar5 = DAT_00012c88;
  dVar4 = DAT_00012c78;
  dVar15 = DAT_00012c70;
  uVar9 = (uint)mode;
  bVar3 = false;
  uVar14 = 0;
  uVar13 = 0;
  uVar12 = 0;
  decimals_last = 25.0;
  pll_vco_choice = DAT_00012c80;
  pll_vco = DAT_00012c84;
  do {
    while( true ) {
      uVar7 = DAT_00012c90;
      iVar1 = (uint)(pll_vco < fVar5) << 0x1f;
      uVar16 = (undefined4)in_d6;
      if (iVar1 < 0) {
        uVar9 = 2;
      }
      if (-1 < iVar1) {
        uVar9 = 1;
        uVar16 = 0x3f800000;
      }
      if (iVar1 < 0) {
        uVar16 = 0x40000000;
      }
      in_d6 = CONCAT44(0x41480000,uVar16);
      if (-1 < iVar1) {
        in_d6 = CONCAT44(0x41c80000,uVar16);
      }
      pll_vco_step = (float)((ulonglong)in_d6 >> 0x20);
      if (bVar3) {
        pll_vco = pll_vco_choice - pll_vco_step;
        decimals_last = 25.0;
      }
      fVar19 = pll_vco / (float)(ulonglong)freq;
      uVar18 = (uint)(0.0 < fVar19) * (int)fVar19;
      pll_out_div_i = (uint32_t)(float)(ulonglong)uVar18;
      fVar19 = fVar19 - (float)pll_out_div_i;
      if ((int)((uint)(fVar19 < decimals_last) << 0x1f) < 0) break;
LAB_000129bc:
      pll_vco = pll_vco - (float)((ulonglong)in_d6 >> 0x20);
      uVar18 = uVar14;
      if (pll_vco < fVar6 != (NAN(pll_vco) || NAN(fVar6))) goto LAB_000129d0;
      bVar3 = false;
    }
    fVar17 = pll_vco * (float)in_d6;
    in_d6 = CONCAT44(pll_vco_step,fVar17);
    uVar14 = uVar18 & 0xff;
    fVar17 = fVar17 / 25.0;
    uVar12 = (uint)(0.0 < fVar17) * (int)fVar17 & 0xff;
    uVar13 = uVar9;
    uVar18 = uVar14;
    pll_vco_choice = pll_vco;
    decimals_last = fVar19;
    if (-1 < (int)((uint)((double)fVar19 < dVar4) << 0x1f)) goto LAB_000129bc;
LAB_000129d0:
    if (uVar18 < 0x11) {
      uVar14 = 1;
      uVar11 = 1;
      uVar9 = 0x10;
      uVar10 = uVar14;
      goto LAB_00012a94;
    }
    uVar10 = 0xf;
    do {
      lVar2 = (longlong)(int)uVar10;
      uVar11 = uVar10 & 0xff;
      uVar10 = uVar10 - 1;
      fVar19 = (float)(ulonglong)uVar18 / (float)lVar2;
      dVar20 = (double)(fVar19 - (float)(ulonglong)((uint)(0.0 < fVar19) * (int)fVar19));
      printf("\n--- %s: pll_div decimals %f postdiv_f %f\n",uVar7,SUB84(dVar20,0),
             (int)((ulonglong)dVar20 >> 0x20),(double)fVar19);
      uVar9 = uVar11 - 1;
      if ((int)((uint)(dVar20 < dVar15) << 0x1f) < 0) {
        bVar8 = __udivsi3(uVar18,uVar11);
        uVar14 = (uint)bVar8;
        break;
      }
      uVar11 = uVar9 & 0xff;
      uVar14 = uVar18;
    } while (uVar10 != 1);
    uVar18 = uVar11;
    if ((uVar18 == 2) && ((uVar14 & 1) != 0)) {
      printf("\n--- %s: need recal 1\n",DAT_00012c90);
      in_d6 = extraout_d6;
      if (pll_vco_choice == fVar6 || pll_vco_choice < fVar6 != (NAN(pll_vco_choice) || NAN(fVar6)))
      {
        local_74 = 0xc0780111;
        local_6c = 0xe;
        uVar9 = 0x780111;
        printf("\n--- %s: !!!!!!!!!!!!!!!Set freq don\'t ok!!!!!!!!!! using 200M pll\n",DAT_00012c90
              );
        uVar18 = 0xf;
        goto LAB_00010ad8;
      }
    }
    else {
      if (uVar14 < 8) {
        uVar9 = uVar14 << 4;
        uVar10 = 1;
        uVar11 = uVar14;
        goto LAB_00012a94;
      }
      uVar11 = 6;
      while( true ) {
        fVar19 = (float)(ulonglong)uVar14 / (float)(longlong)(int)uVar11;
        uVar10 = (uint)(0.0 < fVar19) * (int)fVar19;
        postdiv_i = (uint32_t)(float)(ulonglong)uVar10;
        if ((int)((uint)((double)(fVar19 - (float)postdiv_i) < dVar15) << 0x1f) < 0) break;
        uVar11 = uVar11 - 1 & 0xff;
        if (uVar11 == 0xff) {
          uVar10 = 1;
          uVar9 = 0xff;
          goto LAB_00012a8a;
        }
      }
      uVar10 = uVar10 & 0xff;
      uVar9 = (uint)(7 < uVar10);
      if (uVar11 < uVar10) {
        uVar9 = 1;
      }
      if ((uVar9 == 0) ||
         (printf("\n--- %s: need recal 2\n",DAT_00012c90), in_d6 = extraout_d6_00,
         pll_vco_choice == fVar6 || pll_vco_choice < fVar6 != (NAN(pll_vco_choice) || NAN(fVar6))))
      break;
    }
    bVar3 = true;
    pll_vco = pll_vco_choice;
  } while( true );
  uVar9 = uVar10 * uVar11;
LAB_00012a8a:
  if (uVar14 == uVar9) {
    uVar9 = uVar11 << 4;
LAB_00012a94:
    uVar9 = uVar9 | uVar10 | uVar12 << 0x10 | uVar13 << 8;
    local_74 = uVar9 | 0xc0000000;
    dVar15 = (double)(ulonglong)freq;
    local_6c = uVar18 - 1;
    printf("\n--- %s: Want freq %f  real freq %f\n",DAT_00012c90,SUB84(dVar15,0),
           (int)((ulonglong)dVar15 >> 0x20),
           (double)(((25.0 / (float)(longlong)(int)uVar13) * (float)(longlong)(int)uVar12) /
                   (float)(longlong)(int)(uVar14 * uVar18)));
    printf("\n--- %s: pll_vco %f, fbdiv %#x refdiv %#x postdiv1 %#x postdiv2 %#x, pll_divider %d ,{pll_value %#x}\n"
           ,DAT_00012c90,SUB84((double)pll_vco_choice,0),
           (int)((ulonglong)(double)pll_vco_choice >> 0x20),uVar12,uVar13,uVar11,uVar10,uVar18,uVar9
          );
  }
  else {
    printf("\n--- %s: Don\'t find postdiv1 %d * postdiv2 %d = postdiv %d\n",DAT_00012c90,uVar11,
           uVar10,uVar14);
    local_74 = 0xc0780111;
    uVar9 = 0x780111;
    printf("\n--- %s: !!!!!!!!!!!!!!!Set freq don\'t ok!!!!!!!!!! using 200M pll\n",DAT_00012c90);
    uVar18 = 0xf;
    local_6c = 0xe;
  }
LAB_00010ad8:
  printf("\n--- %s: freq = %d, pll_param = 0x%08x, divider = %d\n",DAT_00012c94,freq,uVar9,uVar18);
  BM1391_set_config(which_chain,chip_addr,'\b',local_74,mode);
  usleep(10000);
  BM1391_set_config(which_chain,chip_addr,'p',local_6c,mode);
  usleep(10000);
  BM1391_set_config(which_chain,chip_addr,'\b',local_74,mode);
  (*(code *)PTR_usleep_00030148)(10000);
  return;
}

