
void bn_mul_part_recursive
               (ulong *param_1,int param_2,int param_3,int param_4,int param_5,int param_6,
               ulong *param_7)

{
  bool bVar1;
  int iVar2;
  int iVar3;
  ulong uVar4;
  ulong uVar5;
  ulong uVar6;
  uint uVar7;
  ulong *puVar8;
  ulong *puVar9;
  int iVar10;
  int iVar11;
  int iVar12;
  int iVar13;
  ulong *local_40;
  
  if (param_4 < 8) {
    bn_mul_normal(param_1,param_2,param_4 + param_5,param_3);
    return;
  }
  iVar13 = param_4 - param_5;
  iVar10 = param_2 + param_4 * 4;
  iVar12 = param_6 - param_4;
  iVar11 = param_4 * 4 + param_3;
  iVar2 = bn_cmp_part_words(param_2,iVar10,param_5,iVar13);
  iVar3 = bn_cmp_part_words(iVar11,param_3,param_6,iVar12);
  switch(iVar3 + iVar2 * 3) {
  case 3:
  case 4:
    bn_sub_part_words(param_7,param_2,iVar10,param_5,iVar13);
    bVar1 = false;
    bn_sub_part_words(param_7 + param_4,iVar11,param_3,param_6,iVar12);
    break;
  default:
    bVar1 = false;
    break;
  case -4:
    bn_sub_part_words(param_7,iVar10,param_2,param_5,param_5 - param_4);
    bVar1 = false;
    bn_sub_part_words(param_7 + param_4,param_3,iVar11,param_6,param_4 - param_6);
    break;
  case -3:
  case -2:
    bn_sub_part_words(param_7,iVar10,param_2,param_5,param_5 - param_4);
    bVar1 = true;
    bn_sub_part_words(param_7 + param_4,iVar11,param_3,param_6,iVar12);
    break;
  case -1:
  case 0:
  case 1:
  case 2:
    bn_sub_part_words(param_7,param_2,iVar10,param_5,iVar13);
    bn_sub_part_words(param_7 + param_4,param_3,iVar11,param_6,param_4 - param_6);
    bVar1 = true;
  }
  if (param_4 == 8) {
    local_40 = param_7 + 0x10;
    bn_mul_comba8(local_40,param_7,param_7 + 8);
    puVar9 = param_1 + 0x10;
    bn_mul_comba8(param_1,param_2,param_3);
    bn_mul_normal(puVar9,iVar10,param_5,iVar11,param_6);
  }
  else {
    puVar8 = param_7 + param_4 * 4;
    iVar2 = param_4 >> 1;
    local_40 = param_7 + param_4 * 2;
    bn_mul_recursive_constprop_0(local_40,param_7,param_7 + param_4,param_4,puVar8);
    bn_mul_recursive_constprop_0(param_1,param_2,param_3,param_4,puVar8);
    if (param_6 < param_5) {
      iVar3 = param_5 - iVar2;
    }
    else {
      iVar3 = param_6 - iVar2;
    }
    if (iVar3 == 0) {
      puVar9 = param_1 + param_4 * 2;
      bn_mul_recursive(puVar9,iVar10,iVar11,iVar2,param_5 - iVar2,param_6 - iVar2,puVar8);
      memset(param_1 + param_4 * 2 + iVar2 * 2,0,(param_4 * 2 + iVar2 * -2) * 4);
      goto LAB_000f1578;
    }
    puVar9 = param_1 + param_4 * 2;
    if (iVar3 < 1) {
      memset(puVar9,0,param_4 * 8);
      iVar3 = param_6;
      if (param_6 < 0x10) {
        iVar3 = param_5;
      }
      if (iVar3 < 0x10) {
        bn_mul_normal(puVar9,iVar10,param_5,iVar11,param_6);
      }
      else {
        do {
          iVar2 = iVar2 / 2;
          iVar3 = param_5;
          if (param_5 <= iVar2) {
            iVar3 = param_6;
          }
          if (iVar2 < iVar3) {
            bn_mul_part_recursive(puVar9,iVar10,iVar11,iVar2,param_5 - iVar2,param_6 - iVar2,puVar8)
            ;
            goto LAB_000f1578;
          }
        } while (iVar2 != param_5 && iVar2 != param_6);
        bn_mul_recursive(puVar9,iVar10,iVar11,iVar2,param_5 - iVar2,param_6 - iVar2,puVar8);
      }
      goto LAB_000f1578;
    }
    bn_mul_part_recursive(puVar9,iVar10,iVar11,iVar2,param_5 - iVar2,param_6 - iVar2,puVar8);
  }
  memset(param_1 + param_5 + param_4 * 2 + param_6,0,((param_4 * 2 - param_5) - param_6) * 4);
LAB_000f1578:
  iVar2 = param_4 * 2;
  uVar4 = bn_add_words(param_7,param_1,puVar9,iVar2);
  if (bVar1) {
    uVar5 = bn_sub_words(local_40,param_7,local_40,iVar2);
    uVar5 = -uVar5;
  }
  else {
    uVar5 = bn_add_words(local_40,local_40,param_7,iVar2);
  }
  uVar6 = bn_add_words(param_1 + param_4,param_1 + param_4,local_40,iVar2);
  uVar7 = uVar6 + uVar4 + uVar5;
  if (uVar7 != 0) {
    uVar4 = param_1[param_4 * 3];
    puVar9 = param_1 + param_4 * 3;
    param_1[param_4 * 3] = uVar7 + uVar4;
    if (uVar7 + uVar4 < uVar7) {
      do {
        uVar4 = puVar9[1];
        puVar9 = puVar9 + 1;
        *puVar9 = uVar4 + 1;
      } while (uVar4 + 1 == 0);
    }
  }
  return;
}

