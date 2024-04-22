
void bn_mul_recursive_constprop_0
               (ulong *param_1,ulong *param_2,ulong *param_3,int param_4,ulong *param_5)

{
  int num;
  bool bVar1;
  bool bVar2;
  bool bVar3;
  int iVar4;
  int iVar5;
  ulong uVar6;
  ulong uVar7;
  ulong uVar8;
  uint uVar9;
  int iVar10;
  ulong *puVar11;
  ulong *rp;
  ulong *ap;
  ulong *puVar12;
  ulong *ap_00;
  ulong *ap_01;
  ulong *ap_02;
  ulong *local_3c;
  
  if (param_4 == 8) {
    bn_mul_comba8();
    return;
  }
  if (param_4 < 0x10) {
    bn_mul_normal(param_1,param_2,param_4,param_3);
    return;
  }
  num = param_4 >> 1;
  ap_01 = param_2 + num;
  puVar11 = param_3 + num;
  iVar4 = bn_cmp_part_words(param_2,ap_01,num,0);
  iVar5 = bn_cmp_part_words(puVar11,param_3,num,0);
  switch(iVar5 + iVar4 * 3) {
  case 2:
    bn_sub_part_words(param_5,param_2,ap_01,num,0);
    bVar2 = true;
    bn_sub_part_words(param_5 + num,param_3,puVar11,num,0);
    break;
  case 4:
    bVar2 = false;
    bn_sub_part_words(param_5,param_2,ap_01,num,0);
LAB_000f0ea4:
    bn_sub_words(param_5 + num,puVar11,param_3,num);
    break;
  default:
    if (num != 8) {
      bVar1 = false;
      bVar2 = false;
      goto LAB_000f0dc6;
    }
    bVar2 = false;
    goto LAB_000f0d26;
  case -4:
    bn_sub_words(param_5,ap_01,param_2,num);
    bVar2 = false;
    bn_sub_part_words(param_5 + num,param_3,puVar11,num,0);
    break;
  case -3:
  case -1:
  case 0:
  case 1:
  case 3:
    if (num == 8) {
      bVar2 = false;
      memset(param_5 + param_4,0,0x40);
      goto LAB_000f0d40;
    }
    bVar1 = true;
    bVar2 = false;
    goto LAB_000f0dc6;
  case -2:
    bVar2 = true;
    bn_sub_words(param_5,ap_01,param_2,num);
    goto LAB_000f0ea4;
  }
  if (num == 8) {
LAB_000f0d26:
    bn_mul_comba8(param_5 + param_4,param_5,param_5 + num);
LAB_000f0d40:
    bn_mul_comba8(param_1,param_2,param_3);
    bn_mul_comba8(param_1 + param_4,ap_01,puVar11);
    goto LAB_000f0d58;
  }
  bVar1 = false;
LAB_000f0dc6:
  rp = param_5 + param_4 * 2;
  if (bVar1) {
    memset(param_5 + param_4,0,param_4 * 4);
  }
  else {
    bn_mul_recursive_constprop_0(param_5 + param_4,param_5,param_5 + num,num,rp);
  }
  ap_00 = param_1 + param_4;
  bn_mul_recursive_constprop_0(param_1,param_2,param_3,num,rp);
  if (num < 0x10) {
    bn_mul_normal(ap_00,ap_01,num,puVar11,num);
    goto LAB_000f0d58;
  }
  iVar4 = param_4 >> 2;
  ap_02 = ap_01 + iVar4;
  ap = puVar11 + iVar4;
  iVar5 = bn_cmp_part_words(ap_01,ap_02,iVar4,0);
  iVar10 = bn_cmp_part_words(ap,puVar11,iVar4,0);
  switch(iVar10 + iVar5 * 3) {
  case 2:
    bn_sub_part_words(rp,ap_01,ap_02,iVar4,0);
    bVar3 = true;
    bn_sub_part_words(rp + iVar4,puVar11,ap,iVar4,0);
    break;
  case 4:
    bVar3 = false;
    bn_sub_part_words(rp,ap_01,ap_02,iVar4,0);
LAB_000f10cc:
    bn_sub_words(rp + iVar4,ap,puVar11,iVar4);
    break;
  default:
    bVar1 = false;
    bVar3 = false;
    if (iVar4 != 8) goto LAB_000f1060;
    goto LAB_000f0f90;
  case -4:
    bn_sub_words(rp,ap_02,ap_01,iVar4);
    bVar3 = false;
    bn_sub_part_words(rp + iVar4,puVar11,ap,iVar4,0);
    break;
  case -3:
  case -1:
  case 0:
  case 1:
  case 3:
    if (iVar4 == 8) {
      bVar3 = false;
      memset(rp + num,0,0x40);
      goto LAB_000f0fa0;
    }
    bVar1 = true;
    bVar3 = false;
    goto LAB_000f1060;
  case -2:
    bVar3 = true;
    bn_sub_words(rp,ap_02,ap_01,iVar4);
    goto LAB_000f10cc;
  }
  if (iVar4 == 8) {
LAB_000f0f90:
    bn_mul_comba8(rp + num,rp,rp + iVar4);
LAB_000f0fa0:
    bn_mul_comba8(ap_00,ap_01,puVar11);
    bn_mul_comba8(ap_00 + num,ap_02,ap);
  }
  else {
    bVar1 = false;
LAB_000f1060:
    puVar12 = rp + num * 2;
    if (bVar1) {
      memset(rp + num,0,num * 4);
    }
    else {
      bn_mul_recursive_constprop_0(rp + num,rp,rp + iVar4,iVar4,puVar12);
    }
    bn_mul_recursive_constprop_0(ap_00,ap_01,puVar11,iVar4,puVar12);
    bn_mul_recursive_constprop_0(ap_00 + num,ap_02,ap,iVar4,puVar12);
  }
  local_3c = rp + num;
  uVar6 = bn_add_words(rp,ap_00,ap_00 + num,num);
  if (bVar3) {
    uVar7 = bn_sub_words(local_3c,rp,local_3c,num);
    uVar7 = -uVar7;
  }
  else {
    uVar7 = bn_add_words(local_3c,local_3c,rp,num);
  }
  uVar8 = bn_add_words(ap_00 + iVar4,ap_00 + iVar4,local_3c,num);
  uVar9 = uVar8 + uVar6 + uVar7;
  if (uVar9 != 0) {
    iVar4 = num + iVar4;
    uVar6 = ap_00[iVar4];
    puVar11 = ap_00 + iVar4;
    ap_00[iVar4] = uVar9 + uVar6;
    if (uVar9 + uVar6 < uVar9) {
      do {
        uVar6 = puVar11[1];
        puVar11 = puVar11 + 1;
        *puVar11 = uVar6 + 1;
      } while (uVar6 + 1 == 0);
    }
  }
LAB_000f0d58:
  puVar11 = param_5 + param_4;
  uVar6 = bn_add_words(param_5,param_1,param_1 + param_4,param_4);
  if (bVar2) {
    uVar7 = bn_sub_words(puVar11,param_5,puVar11,param_4);
    uVar7 = -uVar7;
  }
  else {
    uVar7 = bn_add_words(puVar11,puVar11,param_5,param_4);
  }
  uVar8 = bn_add_words(param_1 + num,param_1 + num,puVar11,param_4);
  uVar9 = uVar8 + uVar6 + uVar7;
  if (uVar9 != 0) {
    param_4 = param_4 + num;
    uVar6 = param_1[param_4];
    puVar11 = param_1 + param_4;
    param_1[param_4] = uVar9 + uVar6;
    if (uVar9 + uVar6 < uVar9) {
      do {
        uVar6 = puVar11[1];
        puVar11 = puVar11 + 1;
        *puVar11 = uVar6 + 1;
      } while (uVar6 + 1 == 0);
    }
  }
  return;
}

