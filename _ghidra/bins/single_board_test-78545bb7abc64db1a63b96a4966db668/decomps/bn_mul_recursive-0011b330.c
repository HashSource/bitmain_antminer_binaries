
void bn_mul_recursive(ulong *param_1,int param_2,int param_3,int param_4,int param_5,int param_6,
                     ulong *param_7)

{
  bool bVar1;
  int iVar2;
  int iVar3;
  ulong uVar4;
  ulong uVar5;
  ulong uVar6;
  uint uVar7;
  int iVar8;
  ulong *puVar9;
  bool bVar10;
  int iVar11;
  int iVar12;
  int iVar13;
  int iVar14;
  undefined4 unaff_lr;
  ulong *local_2c;
  
  if (param_4 == 8 && param_5 == 0) {
    if (param_6 == 0) {
      bn_mul_comba8();
      return;
    }
LAB_0011b364:
    bn_mul_normal(param_1,param_2,param_4 + param_5,param_3,param_4 + param_6);
    if (-1 < param_5 + param_6) {
      return;
    }
    iVar11 = param_6 + param_4 + param_4 + param_5;
    (*(code *)(undefined *)0x0)(param_1 + iVar11,0,(param_5 + param_6) * -4,iVar11,unaff_lr);
    return;
  }
  if (param_4 < 0x10) goto LAB_0011b364;
  iVar11 = param_4 >> 1;
  iVar14 = iVar11 + param_5;
  iVar8 = param_2 + iVar11 * 4;
  iVar13 = param_3 + iVar11 * 4;
  iVar12 = param_6 + iVar11;
  iVar2 = bn_cmp_part_words(param_2,iVar8,iVar14);
  iVar3 = bn_cmp_part_words(iVar13,param_3,iVar12,param_6);
  switch(iVar3 + iVar2 * 3) {
  case 2:
    bn_sub_part_words(param_7,param_2,iVar8,iVar14,-param_5);
    bn_sub_part_words(param_7 + iVar11,param_3,iVar13,iVar12,-param_6);
    bVar1 = true;
    break;
  case 4:
    bn_sub_part_words(param_7,param_2,iVar8,iVar14,-param_5);
    bVar1 = false;
    bn_sub_part_words(param_7 + iVar11,iVar13,param_3,iVar12,param_6);
    break;
  case -4:
    bn_sub_part_words(param_7,iVar8,param_2,iVar14,param_5);
    bn_sub_part_words(param_7 + iVar11,param_3,iVar13,iVar12,-param_6);
    bVar1 = false;
    break;
  case -3:
  case -1:
  case 0:
  case 1:
  case 3:
    if (param_6 == 0 && (iVar11 == 8 && param_5 == 0)) {
      bVar1 = false;
      memset(param_7 + param_4,0,0x40);
      goto LAB_0011b5f4;
    }
    puVar9 = param_7 + param_4 * 2;
    memset(param_7 + param_4,0,param_4 * 4);
    bVar1 = false;
    goto LAB_0011b41c;
  case -2:
    bn_sub_part_words(param_7,iVar8,param_2,iVar14,param_5);
    bVar1 = true;
    bn_sub_part_words(param_7 + iVar11,iVar13,param_3,iVar12,param_6);
    break;
  default:
    bVar1 = false;
  }
  local_2c = param_7 + iVar11;
  bVar10 = param_6 == 0 && (iVar11 == 8 && param_5 == 0);
  if (bVar10) {
    bn_mul_comba8(param_7 + param_4,param_7,local_2c);
LAB_0011b5f4:
    bn_mul_comba8(param_1,param_2,param_3);
    bn_mul_comba8(param_1 + param_4,iVar8,iVar13);
  }
  else {
    puVar9 = param_7 + param_4 * 2;
    bn_mul_recursive(param_7 + param_4,param_7,local_2c,iVar11,0,bVar10,puVar9);
LAB_0011b41c:
    bn_mul_recursive(param_1,param_2,param_3,iVar11,0,0,puVar9);
    bn_mul_recursive(param_1 + param_4,iVar8,iVar13,iVar11,param_5,param_6,puVar9);
  }
  puVar9 = param_7 + param_4;
  uVar4 = bn_add_words(param_7,param_1,param_1 + param_4,param_4);
  if (bVar1) {
    uVar5 = bn_sub_words(puVar9,param_7,puVar9,param_4);
    uVar5 = -uVar5;
  }
  else {
    uVar5 = bn_add_words(puVar9,puVar9,param_7,param_4);
  }
  uVar6 = bn_add_words(param_1 + iVar11,param_1 + iVar11,puVar9,param_4);
  uVar7 = uVar6 + uVar4 + uVar5;
  if (uVar7 != 0) {
    param_4 = param_4 + iVar11;
    uVar4 = param_1[param_4];
    puVar9 = param_1 + param_4;
    param_1[param_4] = uVar4 + uVar7;
    if (uVar4 + uVar7 < uVar7) {
      do {
        puVar9 = puVar9 + 1;
        uVar4 = *puVar9;
        *puVar9 = uVar4 + 1;
      } while (uVar4 + 1 == 0);
      return;
    }
  }
  return;
}

