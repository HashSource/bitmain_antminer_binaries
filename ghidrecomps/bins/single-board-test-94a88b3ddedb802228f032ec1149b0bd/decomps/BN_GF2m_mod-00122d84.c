
undefined4 BN_GF2m_mod(BIGNUM *param_1,BIGNUM *param_2,int *param_3)

{
  ulong *puVar1;
  undefined4 uVar2;
  BIGNUM *pBVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  ulong *puVar8;
  int iVar9;
  int *piVar10;
  uint *puVar11;
  int iVar12;
  int iVar13;
  bool bVar14;
  int local_38 [7];
  
  iVar5 = param_3[1];
  if (iVar5 == 0) {
LAB_00122e54:
    ERR_put_error(3,0x83,0x6a,DAT_00122e80,0x1dd);
    return 0;
  }
  iVar12 = iVar5 + -1;
  if (iVar12 < 0) {
    piVar10 = local_38;
  }
  else {
    iVar13 = iVar12 * 0x20;
    iVar9 = 0;
    puVar11 = (uint *)(*param_3 + iVar5 * 4);
    do {
      puVar11 = puVar11 + -1;
      uVar7 = *puVar11;
      if (uVar7 != 0) {
        iVar6 = 0x1f;
        uVar4 = 0x80000000;
        iVar5 = iVar9;
        while( true ) {
          uVar7 = uVar7 & uVar4;
          uVar4 = uVar4 >> 1;
          iVar9 = iVar5;
          if (uVar7 != 0) {
            iVar9 = iVar5 + 1;
            if (iVar5 < 6) {
              local_38[iVar5] = iVar13 + iVar6;
            }
          }
          bVar14 = iVar6 == 0;
          iVar6 = iVar6 + -1;
          if (bVar14) break;
          uVar7 = *puVar11;
          iVar5 = iVar9;
        }
      }
      iVar12 = iVar12 + -1;
      iVar13 = iVar13 + -0x20;
    } while (iVar12 != -1);
    if (5 < iVar9) {
      if (6 < iVar9) goto LAB_00122e54;
      goto joined_r0x00122e48;
    }
    piVar10 = local_38 + iVar9;
  }
  *piVar10 = -1;
joined_r0x00122e48:
  if (local_38[0] == 0) {
    BN_set_word(param_1,0);
    uVar2 = 1;
  }
  else {
    if (param_1 != param_2) {
      iVar5 = param_2->top;
      if (param_1->dmax < iVar5) {
        pBVar3 = bn_expand2(param_1,iVar5);
        if (pBVar3 == (BIGNUM *)0x0) {
          return 0;
        }
        iVar5 = param_2->top;
      }
      if (0 < iVar5) {
        puVar8 = param_1->d;
        iVar9 = 0;
        puVar1 = param_2->d;
        iVar12 = 0;
        do {
          iVar12 = iVar12 + 1;
          *(undefined4 *)((int)puVar8 + iVar9) = *(undefined4 *)((int)puVar1 + iVar9);
          iVar9 = iVar9 + 4;
          iVar5 = param_2->top;
        } while (iVar12 < iVar5);
      }
      param_1->top = iVar5;
    }
    uVar2 = BN_GF2m_mod_arr_part_0(param_1,local_38);
  }
  return uVar2;
}

