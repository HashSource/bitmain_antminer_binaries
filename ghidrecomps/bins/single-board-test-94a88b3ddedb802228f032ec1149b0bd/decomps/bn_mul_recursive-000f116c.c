
void bn_mul_recursive(ulong *param_1,int param_2,int param_3,int param_4,uint param_5,int param_6,
                     ulong *param_7)

{
  int iVar1;
  int iVar2;
  bool bVar3;
  int iVar4;
  int iVar5;
  ulong uVar6;
  ulong uVar7;
  ulong uVar8;
  bool bVar9;
  ulong *puVar10;
  int iVar11;
  int iVar12;
  uint uVar13;
  int iVar14;
  int iVar15;
  
  uVar13 = 1 - param_5;
  if (1 < param_5) {
    uVar13 = 0;
  }
  if (param_4 == 8 && param_5 == 0) {
    if (param_6 == 0) {
      bn_mul_comba8();
      return;
    }
  }
  else if (0xf < param_4) {
    iVar1 = param_4 >> 1;
    iVar2 = -param_5;
    iVar15 = iVar1 + param_5;
    iVar11 = param_2 + iVar1 * 4;
    iVar14 = iVar1 * 4 + param_3;
    iVar12 = param_6 + iVar1;
    iVar4 = bn_cmp_part_words(param_2,iVar11,iVar15,iVar2);
    iVar5 = bn_cmp_part_words(iVar14,param_3,iVar12,param_6);
    switch(iVar5 + iVar4 * 3) {
    case 2:
      bVar3 = true;
      bn_sub_part_words(param_7,param_2,iVar11,iVar15,iVar2);
      bn_sub_part_words(param_7 + iVar1,param_3,iVar14,iVar12,-param_6);
      bVar9 = false;
      break;
    case 4:
      bn_sub_part_words(param_7,param_2,iVar11,iVar15,iVar2);
      bn_sub_part_words(param_7 + iVar1,iVar14,param_3,iVar12,param_6);
      bVar9 = false;
      bVar3 = false;
      break;
    case -4:
      bn_sub_part_words(param_7,iVar11,param_2,iVar15,param_5);
      bn_sub_part_words(param_7 + iVar1,param_3,iVar14,iVar12,-param_6);
    default:
      bVar9 = false;
      bVar3 = false;
      break;
    case -3:
    case -1:
    case 0:
    case 1:
    case 3:
      bVar9 = true;
      bVar3 = false;
      break;
    case -2:
      bVar3 = true;
      bn_sub_part_words(param_7,iVar11,param_2,iVar15,param_5);
      bn_sub_part_words(param_7 + iVar1,iVar14,param_3,iVar12,param_6);
      bVar9 = false;
    }
    if (iVar1 == 8) {
      uVar13 = uVar13 & 1;
    }
    else {
      uVar13 = 0;
    }
    if ((uVar13 == 0) || (param_6 != 0)) {
      puVar10 = param_7 + param_4 * 2;
      if (bVar9) {
        memset(param_7 + param_4,0,param_4 * 4);
      }
      else {
        bn_mul_recursive_constprop_0(param_7 + param_4,param_7,param_7 + iVar1,iVar1,puVar10);
      }
      bn_mul_recursive_constprop_0(param_1,param_2,param_3,iVar1,puVar10);
      bn_mul_recursive(param_1 + param_4,iVar11,iVar14,iVar1,param_5,param_6,puVar10);
    }
    else {
      if (bVar9) {
        memset(param_7 + param_4,0,0x40);
      }
      else {
        bn_mul_comba8(param_7 + param_4,param_7,param_7 + iVar1);
      }
      bn_mul_comba8(param_1,param_2,param_3);
      bn_mul_comba8(param_1 + param_4,iVar11,iVar14);
    }
    puVar10 = param_7 + param_4;
    uVar6 = bn_add_words(param_7,param_1,param_1 + param_4,param_4);
    if (bVar3) {
      uVar7 = bn_sub_words(puVar10,param_7,puVar10,param_4);
      uVar7 = -uVar7;
    }
    else {
      uVar7 = bn_add_words(puVar10,puVar10,param_7,param_4);
    }
    uVar8 = bn_add_words(param_1 + iVar1,param_1 + iVar1,puVar10,param_4);
    uVar13 = uVar8 + uVar6 + uVar7;
    if (uVar13 == 0) {
      return;
    }
    param_4 = param_4 + iVar1;
    uVar6 = param_1[param_4];
    puVar10 = param_1 + param_4;
    param_1[param_4] = uVar13 + uVar6;
    if (uVar13 <= uVar13 + uVar6) {
      return;
    }
    do {
      uVar6 = puVar10[1];
      puVar10 = puVar10 + 1;
      *puVar10 = uVar6 + 1;
    } while (uVar6 + 1 == 0);
    return;
  }
  bn_mul_normal(param_1,param_2,param_4 + param_5,param_3,param_4 + param_6);
  if (-1 < (int)(param_5 + param_6)) {
    return;
  }
  (*(code *)PTR_memset_001941c8)
            (param_1 + param_5 + param_4 * 2 + param_6,0,(param_5 + param_6) * -4);
  return;
}

