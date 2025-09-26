
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
  int iVar8;
  ulong *puVar9;
  int iVar10;
  int iVar11;
  ulong *bp;
  bool bVar12;
  ulong *local_44;
  ulong *local_30;
  
  if (param_4 < 8) {
    bn_mul_normal(param_1,param_2,param_4 + param_5,param_3);
    return;
  }
  iVar8 = param_2 + param_4 * 4;
  iVar10 = param_4 * 4 + param_3;
  iVar11 = param_6 - param_4;
  iVar2 = bn_cmp_part_words(param_2,iVar8,param_5);
  iVar3 = bn_cmp_part_words(iVar10,param_3,param_6,iVar11);
  switch(iVar3 + iVar2 * 3) {
  case 3:
  case 4:
    bn_sub_part_words(param_7,param_2,iVar8,param_5,param_4 - param_5);
    bVar1 = false;
    bn_sub_part_words(param_7 + param_4,iVar10,param_3,param_6,iVar11);
    break;
  case -4:
    bn_sub_part_words(param_7,iVar8,param_2,param_5,param_5 - param_4);
    bVar1 = false;
    bn_sub_part_words(param_7 + param_4,param_3,iVar10,param_6,param_4 - param_6);
    if (param_4 != 8) goto LAB_0011b6da;
    goto LAB_0011b7f4;
  case -3:
  case -2:
    bn_sub_part_words(param_7,iVar8,param_2,param_5,param_5 - param_4);
    bVar1 = true;
    bn_sub_part_words(param_7 + param_4,iVar10,param_3,param_6,iVar11);
    break;
  case -1:
  case 0:
  case 1:
  case 2:
    bn_sub_part_words(param_7,param_2,iVar8,param_5,param_4 - param_5);
    bn_sub_part_words(param_7 + param_4,param_3,iVar10,param_6,param_4 - param_6);
    bVar1 = true;
    break;
  default:
    bVar1 = false;
  }
  if (param_4 == 8) {
LAB_0011b7f4:
    local_30 = param_7 + param_4;
    local_44 = param_7 + 0x10;
    bn_mul_comba8(local_44,param_7,local_30);
    bp = param_1 + 0x10;
    bn_mul_comba8(param_1,param_2,param_3);
    bn_mul_normal(bp,iVar8,param_5,iVar10,param_6);
  }
  else {
LAB_0011b6da:
    local_30 = param_7 + param_4;
    iVar2 = param_4 >> 1;
    puVar9 = param_7 + param_4 * 4;
    local_44 = param_7 + param_4 * 2;
    bn_mul_recursive(local_44,param_7,local_30,param_4,0,0,puVar9);
    bn_mul_recursive(param_1,param_2,param_3,param_4,0,0,puVar9);
    if (param_6 < param_5) {
      iVar3 = param_5 - iVar2;
    }
    else {
      iVar3 = param_6 - iVar2;
    }
    if (iVar3 == 0) {
      bp = param_1 + param_4 * 2;
      bn_mul_recursive(bp,iVar8,iVar10,iVar2,param_5 - iVar2,param_6 - iVar2,puVar9);
      memset(param_1 + param_4 * 2 + iVar2 * 2,0,(param_4 * 2 + iVar2 * -2) * 4);
      goto LAB_0011b762;
    }
    if (iVar3 < 1) {
      bp = param_1 + param_4 * 2;
      memset(bp,0,param_4 * 8);
      iVar3 = param_5;
      if (param_5 < 0x10) {
        iVar3 = param_6;
      }
      if (iVar3 < 0x10) {
        bn_mul_normal(bp,iVar8,param_5,iVar10,param_6);
      }
      else {
        do {
          iVar2 = iVar2 / 2;
          iVar3 = param_6 - iVar2;
          bVar12 = param_6 == iVar2;
          iVar11 = param_6;
          if (param_6 <= iVar2) {
            iVar3 = param_5 - iVar2;
            bVar12 = param_5 == iVar2;
            iVar11 = param_5;
          }
          if (!bVar12 && iVar3 < 0 == SBORROW4(iVar11,iVar2)) {
            bn_mul_part_recursive(bp,iVar8,iVar10,iVar2,param_5 - iVar2,param_6 - iVar2,puVar9);
            goto LAB_0011b762;
          }
        } while (param_6 != iVar2 && param_5 != iVar2);
        bn_mul_recursive(bp,iVar8,iVar10,iVar2,param_5 - iVar2,param_6 - iVar2,puVar9);
      }
      goto LAB_0011b762;
    }
    bp = param_1 + param_4 * 2;
    bn_mul_part_recursive(bp,iVar8,iVar10,iVar2,param_5 - iVar2,param_6 - iVar2,puVar9);
  }
  memset(param_1 + param_4 * 2 + param_5 + param_6,0,((param_4 * 2 - param_5) - param_6) * 4);
LAB_0011b762:
  iVar2 = param_4 * 2;
  uVar4 = bn_add_words(param_7,param_1,bp,iVar2);
  if (bVar1) {
    uVar5 = bn_sub_words(local_44,param_7,local_44,iVar2);
    uVar5 = -uVar5;
  }
  else {
    uVar5 = bn_add_words(local_44,local_44,param_7,iVar2);
  }
  uVar6 = bn_add_words(param_1 + param_4,param_1 + param_4,local_44,iVar2);
  uVar7 = uVar6 + uVar4 + uVar5;
  if (uVar7 != 0) {
    uVar4 = param_1[param_4 * 3];
    puVar9 = param_1 + param_4 * 3;
    param_1[param_4 * 3] = uVar4 + uVar7;
    if (uVar4 + uVar7 < uVar7) {
      do {
        puVar9 = puVar9 + 1;
        uVar4 = *puVar9;
        *puVar9 = uVar4 + 1;
      } while (uVar4 + 1 == 0);
    }
  }
  return;
}

