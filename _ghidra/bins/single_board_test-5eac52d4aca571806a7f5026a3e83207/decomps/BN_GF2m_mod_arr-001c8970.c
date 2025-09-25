
undefined4 BN_GF2m_mod_arr(BIGNUM *param_1,BIGNUM *param_2,uint *param_3)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  ulong *puVar4;
  ulong *puVar5;
  ulong *puVar6;
  uint uVar7;
  int iVar8;
  ulong uVar9;
  uint uVar10;
  ulong *puVar11;
  uint uVar12;
  uint *puVar13;
  uint uVar14;
  uint uVar15;
  bool bVar16;
  
  uVar3 = *param_3;
  if (uVar3 == 0) {
    BN_set_word(param_1,0);
    return 1;
  }
  bVar16 = param_2 <= param_1;
  if (param_1 == param_2) {
    puVar4 = param_1->d;
    uVar14 = param_1->top;
  }
  else {
    iVar2 = bn_wexpand(param_1,param_2->top);
    if (iVar2 == 0) {
      return 0;
    }
    uVar14 = param_2->top;
    bVar16 = true;
    if ((int)uVar14 < 1) {
      puVar4 = param_1->d;
    }
    else {
      puVar11 = param_2->d;
      puVar4 = param_1->d;
      if ((int)uVar14 < 9) {
        uVar3 = 0;
      }
      else {
        uVar3 = 0;
        puVar5 = puVar4;
        puVar6 = puVar11 + 0x19;
        do {
          uVar3 = uVar3 + 8;
          HintPreloadData(puVar6);
          *puVar5 = puVar6[-0x19];
          puVar5[1] = puVar6[-0x18];
          puVar5[2] = puVar6[-0x17];
          puVar5[3] = puVar6[-0x16];
          puVar5[4] = puVar6[-0x15];
          puVar5[5] = puVar6[-0x14];
          puVar5[6] = puVar6[-0x13];
          puVar5[7] = puVar6[-0x12];
          puVar5 = puVar5 + 8;
          puVar6 = puVar6 + 8;
        } while (uVar3 != (uVar14 - 9 & 0xfffffff8) + 8);
      }
      puVar5 = puVar4 + uVar3;
      puVar11 = puVar11 + uVar3;
      do {
        uVar3 = uVar3 + 1;
        bVar16 = uVar3 <= uVar14;
        *puVar5 = *puVar11;
        puVar5 = puVar5 + 1;
        puVar11 = puVar11 + 1;
      } while ((int)uVar3 < (int)uVar14);
    }
    param_1->top = uVar14;
    uVar3 = *param_3;
  }
  iVar2 = uVar14 - 1;
  uVar14 = uVar3 + 0x3f & (int)uVar3 >> 0x20;
  if (!bVar16) {
    uVar14 = uVar3;
  }
  iVar1 = (int)uVar14 >> 6;
  if (iVar1 < iVar2) {
    uVar14 = uVar3 & 0x3f;
    if ((int)uVar3 < 1) {
      uVar14 = -(-uVar3 & 0x3f);
    }
    do {
      while (uVar15 = puVar4[iVar2], uVar15 == 0) {
        iVar2 = iVar2 + -1;
LAB_001c8a5e:
        if (iVar2 <= iVar1) goto LAB_001c8af4;
      }
      uVar7 = param_3[1];
      puVar4[iVar2] = 0;
      puVar13 = param_3 + 1;
      while (uVar7 != 0) {
        uVar7 = uVar3 - uVar7;
        uVar12 = uVar7 & 0x3f;
        if ((int)uVar7 < 1) {
          uVar12 = -(-uVar7 & 0x3f);
        }
        uVar10 = uVar7 & ~((int)uVar7 >> 0x20);
        if ((int)uVar7 < 0) {
          uVar10 = uVar7 + 0x3f;
        }
        iVar8 = iVar2 - ((int)uVar10 >> 6);
        puVar4[iVar8] = puVar4[iVar8] ^ uVar15 >> (uVar12 & 0xff);
        if (uVar12 != 0) {
          puVar4[iVar8 + -1] = puVar4[iVar8 + -1] ^ uVar15 << (0x40 - uVar12 & 0xff);
        }
        puVar13 = puVar13 + 1;
        uVar7 = *puVar13;
      }
      iVar8 = iVar2 - iVar1;
      puVar4[iVar8] = puVar4[iVar8] ^ uVar15 >> (uVar14 & 0xff);
      if (uVar14 == 0) goto LAB_001c8a5e;
      puVar4[iVar8 + -1] = uVar15 << (0x40 - uVar14 & 0xff) ^ puVar4[iVar8 + -1];
    } while (iVar1 < iVar2);
  }
LAB_001c8af4:
  if (iVar1 == iVar2) {
    uVar15 = puVar4[iVar1];
    uVar14 = uVar3 & 0x3f;
    if ((int)uVar3 < 1) {
      uVar14 = -(-uVar3 & 0x3f);
    }
    uVar3 = uVar15 >> (uVar14 & 0xff);
    if (uVar3 != 0) {
      uVar7 = param_3[1];
      do {
        if (uVar14 == 0) {
          uVar9 = 0;
        }
        else {
          uVar9 = (uVar15 << (0x40 - uVar14 & 0xff)) >> (0x40 - uVar14 & 0xff);
        }
        puVar4[iVar1] = uVar9;
        *puVar4 = *puVar4 ^ uVar3;
        if (uVar7 != 0) {
          puVar13 = param_3 + 1;
          uVar15 = uVar7;
          do {
            uVar12 = uVar15 & 0x3f;
            if ((int)uVar15 < 1) {
              uVar12 = -(-uVar15 & 0x3f);
            }
            uVar10 = uVar15 & ~((int)uVar15 >> 0x20);
            if ((int)uVar15 < 0) {
              uVar10 = uVar15 + 0x3f;
            }
            iVar2 = (int)uVar10 >> 6;
            puVar4[iVar2] = puVar4[iVar2] ^ uVar3 << (uVar12 & 0xff);
            if (uVar12 != 0) {
              uVar15 = uVar3 >> (0x40 - uVar12 & 0xff);
              if (uVar15 != 0) {
                puVar4[iVar2 + 1] = puVar4[iVar2 + 1] ^ uVar15;
              }
            }
            puVar13 = puVar13 + 1;
            uVar15 = *puVar13;
          } while (uVar15 != 0);
        }
        uVar15 = puVar4[iVar1];
        uVar3 = uVar15 >> (uVar14 & 0xff);
      } while (uVar3 != 0);
    }
  }
  bn_correct_top(param_1);
  return 1;
}

