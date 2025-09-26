
void bn_mul_high(ulong *param_1,ulong *param_2,ulong *param_3,ulong *param_4,int param_5,
                ulong *param_6)

{
  ulong *puVar1;
  bool bVar2;
  int iVar3;
  int iVar4;
  ulong uVar5;
  ulong uVar6;
  ulong uVar7;
  ulong uVar8;
  ulong uVar9;
  ulong uVar10;
  uint uVar11;
  ulong *puVar12;
  int iVar13;
  int num;
  uint uVar14;
  ulong *puVar15;
  ulong *puVar16;
  ulong *rp;
  ulong *local_30;
  
  num = param_5 / 2;
  puVar16 = param_2 + num;
  puVar12 = param_3 + num;
  iVar3 = bn_cmp_words(param_2,puVar16,num);
  iVar4 = bn_cmp_words(puVar12,param_3,num);
  switch(iVar3 * 3 + iVar4) {
  case 2:
    bn_sub_words(param_1,param_2,puVar16,num);
    bn_sub_words(param_1 + num,param_3,puVar12,num);
    bVar2 = true;
    break;
  case 4:
    bVar2 = false;
    bn_sub_words(param_1,param_2,puVar16,num);
    bn_sub_words(param_1 + num,puVar12,param_3,num);
    break;
  case -4:
    bn_sub_words(param_1,puVar16,param_2,num);
    bn_sub_words(param_1 + num,param_3,puVar12,num);
    bVar2 = false;
    break;
  default:
    bVar2 = false;
    break;
  case -2:
    bn_sub_words(param_1,puVar16,param_2,num);
    bn_sub_words(param_1 + num,puVar12,param_3,num);
    bVar2 = true;
  }
  if (num == 8) {
    local_30 = param_1 + 8;
    bn_mul_comba8(param_6,param_1,local_30);
    bn_mul_comba8(param_1,puVar16,puVar12);
  }
  else {
    local_30 = param_1 + num;
    bn_mul_recursive_constprop_0(param_6,param_1,local_30,num,param_6 + param_5);
    bn_mul_recursive_constprop_0(param_1,puVar16,puVar12,num,param_6 + param_5);
  }
  puVar16 = param_6 + param_5;
  if (param_4 == (ulong *)0x0) {
    rp = param_6 + param_5 + num;
    puVar12 = param_1;
  }
  else {
    rp = param_6 + param_5 + num;
    bn_add_words(rp,param_1,param_4,num);
    puVar12 = rp;
  }
  local_30 = param_1 + num;
  if (bVar2) {
    bn_sub_words(puVar16,puVar12,param_6,num);
  }
  else {
    bn_add_words(puVar16,puVar12,param_6,num);
  }
  if (param_4 == (ulong *)0x0) {
    if (0 < num) {
      if (num < 9) {
        iVar3 = 0;
      }
      else {
        puVar15 = puVar16 + 0x17;
        iVar3 = 0;
        puVar12 = rp;
        do {
          iVar3 = iVar3 + 8;
          HintPreloadData(puVar15);
          *puVar12 = -puVar15[-0x17];
          puVar12[1] = -puVar15[-0x16];
          puVar12[2] = -puVar15[-0x15];
          puVar12[3] = -puVar15[-0x14];
          puVar12[4] = -puVar15[-0x13];
          puVar12[5] = -puVar15[-0x12];
          puVar12[6] = -puVar15[-0x11];
          puVar1 = puVar15 + -0x10;
          puVar15 = puVar15 + 8;
          puVar12[7] = -*puVar1;
          puVar12 = puVar12 + 8;
        } while (iVar3 != (num - 9U & 0xfffffff8) + 8);
      }
      iVar4 = iVar3 * 4;
      iVar13 = 0;
      do {
        iVar3 = iVar3 + 1;
        *(int *)((int)rp + iVar13 + iVar4) = -*(int *)((int)puVar16 + iVar13 + iVar4);
        iVar13 = iVar13 + 4;
      } while (iVar3 < num);
    }
    uVar5 = 0;
    puVar12 = rp;
  }
  else {
    bn_sub_words(rp,param_4 + num,puVar16,num);
    uVar5 = bn_add_words(puVar16,rp,param_4,num);
    puVar12 = puVar16;
  }
  uVar6 = bn_add_words(puVar16,puVar12,param_1,num);
  if (bVar2) {
    uVar7 = bn_sub_words(puVar16,puVar16,param_6,num);
    uVar7 = -uVar7;
    uVar8 = bn_add_words(param_1,param_1,rp,num);
    uVar9 = bn_add_words(param_1,param_1,local_30,num);
    uVar10 = bn_sub_words(param_1,param_1,param_6 + num,num);
    uVar11 = (uVar9 + uVar8) - uVar10;
  }
  else {
    uVar7 = bn_add_words(puVar16,puVar16,param_6,num);
    uVar8 = bn_add_words(param_1,param_1,rp,num);
    uVar9 = bn_add_words(param_1,param_1,local_30,num);
    uVar10 = bn_add_words(param_1,param_1,param_6 + num,num);
    uVar11 = uVar10 + uVar9 + uVar8;
  }
  uVar14 = uVar6 + uVar5 + uVar7;
  if (uVar14 != 0) {
    if ((int)uVar14 < 1) {
      uVar14 = -uVar14;
      do {
        uVar5 = *param_1 - uVar14;
        uVar14 = (uint)(*param_1 < uVar14);
        *param_1 = uVar5;
        param_1 = param_1 + 1;
      } while (uVar14 != 0);
    }
    else {
      do {
        uVar5 = *param_1;
        *param_1 = uVar5 + uVar14;
        uVar14 = (uint)(uVar5 + uVar14 < uVar14);
        param_1 = param_1 + 1;
      } while (uVar14 != 0);
    }
  }
  if (uVar11 != 0) {
    if ((int)uVar11 < 1) {
      uVar11 = -uVar11;
      do {
        uVar14 = *local_30 - uVar11;
        uVar11 = (uint)(*local_30 < uVar11);
        *local_30 = uVar14;
        local_30 = local_30 + 1;
      } while (uVar11 != 0);
    }
    else {
      do {
        uVar14 = *local_30;
        *local_30 = uVar14 + uVar11;
        uVar11 = (uint)(uVar14 + uVar11 < uVar11);
        local_30 = local_30 + 1;
      } while (uVar11 != 0);
    }
  }
  return;
}

