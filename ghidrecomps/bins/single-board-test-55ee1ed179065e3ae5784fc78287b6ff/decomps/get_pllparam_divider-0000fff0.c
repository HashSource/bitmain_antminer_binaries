
undefined4 get_pllparam_divider(float param_1,uint *param_2,byte *param_3,float *param_4)

{
  byte bVar1;
  byte bVar2;
  undefined4 uVar3;
  bool bVar4;
  double dVar5;
  float fVar6;
  uint uVar7;
  float fVar8;
  float local_28;
  byte local_22;
  byte local_21;
  byte local_20;
  byte local_1f;
  byte local_1e;
  byte local_1d;
  float local_1c;
  float local_18;
  float local_14;
  
  local_28 = 25.0;
  bVar4 = false;
  local_14 = 2500.0;
LAB_0001003a:
  if ((int)((uint)(local_14 < DAT_000103c8) << 0x1f) < 0) {
    local_1c = 12.5;
  }
  else {
    local_1c = 25.0;
  }
  if (bVar4) {
    local_14 = local_18 - local_1c;
    bVar4 = false;
    local_28 = 25.0;
  }
  bVar1 = (0.0 < 25.0 / local_1c) * (char)(int)(25.0 / local_1c);
  fVar6 = ((float)(longlong)(int)(uint)bVar1 * local_14) / 25.0;
  bVar2 = (0.0 < fVar6) * (char)(int)fVar6;
  fVar6 = local_14 / param_1;
  uVar7 = (uint)(0.0 < fVar6) * (int)fVar6;
  fVar6 = fVar6 - (float)(ulonglong)uVar7;
  if (-1 < (int)((uint)(fVar6 < local_28) << 0x1f)) goto LAB_00010148;
  local_22 = (byte)uVar7;
  local_18 = local_14;
  local_28 = fVar6;
  local_1e = bVar1;
  local_1d = bVar2;
  if (-1 < (int)((uint)((double)fVar6 < DAT_000103b8) << 0x1f)) goto LAB_00010148;
  goto LAB_00010170;
LAB_00010148:
  local_14 = local_14 - local_1c;
  if (local_14 < 1400.0 != NAN(local_14)) {
LAB_00010170:
    if (local_22 < 0x11) {
      local_21 = local_22;
      local_20 = 1;
      local_1f = 1;
      goto LAB_0001042e;
    }
    local_21 = 0x10;
    do {
      bVar4 = local_21 < 3;
      local_21 = local_21 - 1;
      if (bVar4) goto LAB_0001024e;
      fVar6 = (float)(ulonglong)local_22 / (float)(longlong)(int)(uint)local_21;
      fVar8 = fVar6 - (float)(ulonglong)((uint)(0.0 < fVar6) * (int)fVar6);
      dVar5 = (double)fVar8;
      printf("--- %s: pll_div decimals %f postdiv_f %f","get_pllparam_divider",SUB84(dVar5,0),
             (int)((ulonglong)dVar5 >> 0x20),(double)fVar6);
    } while (-1 < (int)((uint)((double)fVar8 < DAT_000103c0) << 0x1f));
    local_22 = __udivsi3(local_22,local_21);
LAB_0001024e:
    if ((local_21 == 2) && ((local_22 & 1) != 0)) {
      printf("--- %s: need recal 1","get_pllparam_divider");
      if (local_18 == 1400.0 || local_18 < 1400.0 != NAN(local_18)) {
        printf("--- %s: !!!!!!!!!!!!!!!Set freq don\'t ok!!!!!!!!!! using 200M pll",
               "get_pllparam_divider");
        *param_2 = 0x780111;
        *param_3 = 0xf;
        return 0xffffffff;
      }
      local_14 = local_18;
      bVar4 = true;
    }
    else {
      if (local_22 < 8) {
        local_1f = local_22;
        local_20 = 1;
        goto LAB_0001042e;
      }
      local_1f = 7;
      local_20 = 1;
      do {
        bVar4 = local_1f == 0;
        local_1f = local_1f - 1;
        if (bVar4) goto LAB_0001036e;
        fVar6 = (float)(ulonglong)local_22 / (float)(longlong)(int)(uint)local_1f;
      } while (-1 < (int)((uint)((double)(fVar6 - (float)(ulonglong)
                                                         ((uint)(0.0 < fVar6) * (int)fVar6)) <
                                DAT_000103c0) << 0x1f));
      local_20 = (0.0 < fVar6) * (char)(int)fVar6;
LAB_0001036e:
      if (((local_20 <= local_1f) && (local_20 < 8)) ||
         (printf("--- %s: need recal 2","get_pllparam_divider"),
         local_18 == 1400.0 || local_18 < 1400.0 != NAN(local_18))) {
        if ((uint)local_22 == (uint)local_20 * (uint)local_1f) {
LAB_0001042e:
          if (param_4 != (float *)0x0) {
            *param_4 = ((25.0 / (float)(longlong)(int)(uint)local_1e) *
                       (float)(longlong)(int)(uint)local_1d) /
                       (float)(longlong)(int)((uint)local_20 * (uint)local_1f);
          }
          *param_2 = (uint)local_20 |
                     (uint)local_1d << 0x10 | (uint)local_1e << 8 | (uint)local_1f << 4;
          *param_3 = local_21;
          printf("--- %s: Want freq %f  real freq %f","get_pllparam_divider",
                 SUB84((double)param_1,0),(int)((ulonglong)(double)param_1 >> 0x20),
                 (double)(((25.0 / (float)(longlong)(int)(uint)local_1e) *
                          (float)(longlong)(int)(uint)local_1d) /
                         (float)(longlong)(int)((uint)local_21 * (uint)local_20 * (uint)local_1f)));
          printf("--- %s: pll_vco %f, fbdiv %#x refdiv %#x postdiv1 %#x postdiv2 %#x, pll_divider %d ,{pll_value %#x}"
                 ,"get_pllparam_divider",SUB84((double)local_18,0),
                 (int)((ulonglong)(double)local_18 >> 0x20),(uint)local_1d,(uint)local_1e,
                 (uint)local_1f,(uint)local_20,(uint)*param_3,*param_2);
          uVar3 = 0;
        }
        else {
          printf("--- %s: Don\'t find postdiv1 %d * postdiv2 %d = postdiv %d","get_pllparam_divider"
                 ,(uint)local_1f,(uint)local_20,(uint)local_22);
          *param_2 = 0x780111;
          *param_3 = 0xf;
          printf("--- %s: !!!!!!!!!!!!!!!Set freq don\'t ok!!!!!!!!!! using 200M pll",
                 "get_pllparam_divider");
          uVar3 = 0xffffffff;
        }
        return uVar3;
      }
      local_14 = local_18;
      bVar4 = true;
    }
  }
  goto LAB_0001003a;
}

