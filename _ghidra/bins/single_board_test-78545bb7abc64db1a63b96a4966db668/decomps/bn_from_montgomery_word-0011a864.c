
undefined4 bn_from_montgomery_word(undefined4 *param_1,int *param_2,int param_3)

{
  int iVar1;
  int iVar2;
  int iVar3;
  ulong uVar4;
  uint *puVar5;
  int iVar6;
  uint uVar7;
  ulong *puVar8;
  ulong *puVar9;
  ulong *puVar10;
  int iVar11;
  int iVar12;
  ulong *puVar13;
  int iVar14;
  uint *puVar15;
  int num;
  uint uVar16;
  
  num = *(int *)(param_3 + 0x1c);
  if (num == 0) {
    param_1[1] = 0;
    return 1;
  }
  iVar14 = num * 2;
  iVar1 = bn_wexpand(param_2,iVar14);
  if (iVar1 != 0) {
    puVar10 = *(ulong **)(param_3 + 0x18);
    puVar9 = (ulong *)*param_2;
    iVar1 = param_2[1];
    param_2[3] = *(uint *)(param_3 + 0x24) ^ param_2[3];
    if (0 < iVar14) {
      if (iVar14 < 9) {
        iVar12 = 0;
      }
      else {
        iVar6 = -iVar1;
        puVar13 = puVar9 + 0x14;
        iVar2 = 8;
        do {
          iVar12 = iVar2;
          HintPreloadData(puVar13);
          puVar13[-0x14] = puVar13[-0x14] & iVar6 >> 0x1f;
          puVar13[-0x13] = puVar13[-0x13] & iVar6 + 1 >> 0x1f;
          puVar13[-0x12] = puVar13[-0x12] & iVar6 + 2 >> 0x1f;
          puVar13[-0x11] = puVar13[-0x11] & iVar6 + 3 >> 0x1f;
          iVar2 = iVar6 + 5;
          puVar13[-0x10] = puVar13[-0x10] & iVar6 + 4 >> 0x1f;
          iVar3 = iVar6 + 6;
          iVar11 = iVar6 + 7;
          iVar6 = iVar6 + 8;
          puVar13[-0xf] = puVar13[-0xf] & iVar2 >> 0x1f;
          puVar13[-0xe] = puVar13[-0xe] & iVar3 >> 0x1f;
          puVar13[-0xd] = puVar13[-0xd] & iVar11 >> 0x1f;
          puVar13 = puVar13 + 8;
          iVar2 = iVar12 + 8;
        } while (iVar6 != (iVar14 - 9U & 0xfffffff8) + (8 - iVar1));
      }
      puVar5 = puVar9 + iVar12;
      do {
        iVar6 = iVar12 - iVar1;
        iVar12 = iVar12 + 1;
        *puVar5 = *puVar5 & iVar6 >> 0x1f;
        puVar5 = puVar5 + 1;
      } while (iVar12 < iVar14);
    }
    param_2[1] = iVar14;
    iVar1 = *(int *)(param_3 + 0x40);
    if (num < 1) {
      iVar1 = bn_wexpand(param_1,num);
      if (iVar1 != 0) {
        iVar1 = *param_2;
        iVar14 = param_2[3];
        param_1[1] = num;
        param_1[3] = iVar14;
        bn_sub_words((ulong *)*param_1,(ulong *)(iVar1 + num * 4),puVar10,num);
        return 1;
      }
    }
    else {
      if (num < 9) {
        iVar14 = 0;
        iVar12 = 0;
      }
      else {
        iVar14 = 0;
        iVar12 = 0;
        puVar13 = puVar9;
        puVar5 = puVar9 + num + 7;
        puVar8 = puVar9 + 7;
        do {
          HintPreloadData(puVar8);
          iVar14 = iVar14 + 8;
          HintPreloadData(puVar5);
          uVar4 = bn_mul_add_words(puVar13,puVar10,num,*puVar13 * iVar1);
          uVar16 = puVar5[-7];
          uVar7 = uVar4 + iVar12 + uVar16;
          puVar5[-7] = uVar7;
          if (uVar16 != uVar7) {
            iVar12 = 1;
          }
          if (uVar16 < uVar7) {
            iVar12 = 0;
          }
          uVar4 = bn_mul_add_words(puVar13 + 1,puVar10,num,puVar13[1] * iVar1);
          uVar16 = puVar5[-6];
          uVar7 = uVar4 + uVar16 + iVar12;
          puVar5[-6] = uVar7;
          if (uVar16 != uVar7) {
            iVar12 = 1;
          }
          if (uVar16 < uVar7) {
            iVar12 = 0;
          }
          uVar4 = bn_mul_add_words(puVar13 + 2,puVar10,num,puVar13[2] * iVar1);
          uVar16 = puVar5[-5];
          uVar7 = uVar4 + uVar16 + iVar12;
          puVar5[-5] = uVar7;
          if (uVar16 != uVar7) {
            iVar12 = 1;
          }
          if (uVar16 < uVar7) {
            iVar12 = 0;
          }
          uVar4 = bn_mul_add_words(puVar13 + 3,puVar10,num,puVar13[3] * iVar1);
          uVar16 = puVar5[-4];
          uVar7 = uVar4 + uVar16 + iVar12;
          puVar5[-4] = uVar7;
          if (uVar16 != uVar7) {
            iVar12 = 1;
          }
          if (uVar16 < uVar7) {
            iVar12 = 0;
          }
          uVar4 = bn_mul_add_words(puVar13 + 4,puVar10,num,puVar13[4] * iVar1);
          uVar16 = puVar5[-3];
          uVar7 = uVar4 + uVar16 + iVar12;
          puVar5[-3] = uVar7;
          if (uVar16 != uVar7) {
            iVar12 = 1;
          }
          if (uVar16 < uVar7) {
            iVar12 = 0;
          }
          uVar4 = bn_mul_add_words(puVar13 + 5,puVar10,num,puVar13[5] * iVar1);
          uVar16 = puVar5[-2];
          puVar9 = puVar13 + 8;
          uVar7 = uVar4 + uVar16 + iVar12;
          puVar5[-2] = uVar7;
          if (uVar16 != uVar7) {
            iVar12 = 1;
          }
          if (uVar16 < uVar7) {
            iVar12 = 0;
          }
          uVar4 = bn_mul_add_words(puVar13 + 6,puVar10,num,puVar13[6] * iVar1);
          uVar16 = puVar5[-1];
          uVar7 = uVar4 + uVar16 + iVar12;
          puVar5[-1] = uVar7;
          if (uVar16 != uVar7) {
            iVar12 = 1;
          }
          if (uVar16 < uVar7) {
            iVar12 = 0;
          }
          uVar4 = bn_mul_add_words(puVar8,puVar10,num,puVar13[7] * iVar1);
          uVar16 = *puVar5;
          uVar7 = uVar4 + uVar16 + iVar12;
          if (uVar16 != uVar7) {
            iVar12 = 1;
          }
          *puVar5 = uVar7;
          if (uVar16 < uVar7) {
            iVar12 = 0;
          }
          puVar13 = puVar9;
          puVar5 = puVar5 + 8;
          puVar8 = puVar8 + 8;
        } while (iVar14 != (num - 9U & 0xfffffff8) + 8);
      }
      puVar5 = puVar9 + num;
      do {
        iVar14 = iVar14 + 1;
        uVar4 = bn_mul_add_words(puVar9,puVar10,num,*puVar9 * iVar1);
        uVar16 = *puVar5;
        uVar7 = uVar4 + iVar12 + uVar16;
        *puVar5 = uVar7;
        if (uVar16 != uVar7) {
          iVar12 = 1;
        }
        if (uVar16 < uVar7) {
          iVar12 = 0;
        }
        puVar9 = puVar9 + 1;
        puVar5 = puVar5 + 1;
      } while (iVar14 < num);
      iVar1 = bn_wexpand(param_1,num);
      if (iVar1 != 0) {
        puVar9 = (ulong *)*param_1;
        iVar1 = param_2[3];
        puVar13 = (ulong *)(num * 4 + *param_2);
        param_1[1] = num;
        param_1[3] = iVar1;
        uVar4 = bn_sub_words(puVar9,puVar13,puVar10,num);
        uVar7 = iVar12 - uVar4;
        if (num < 9) {
          iVar1 = 0;
        }
        else {
          iVar1 = 0;
          puVar10 = puVar13 + 0x10;
          puVar8 = puVar9 + 0x10;
          do {
            iVar1 = iVar1 + 8;
            HintPreloadData(puVar10);
            HintPreloadData(puVar8);
            puVar8[-0x10] = (puVar8[-0x10] ^ puVar10[-0x10]) & uVar7 ^ puVar8[-0x10];
            puVar10[-0x10] = 0;
            puVar8[-0xf] = (puVar8[-0xf] ^ puVar10[-0xf]) & uVar7 ^ puVar8[-0xf];
            puVar10[-0xf] = 0;
            puVar8[-0xe] = (puVar8[-0xe] ^ puVar10[-0xe]) & uVar7 ^ puVar8[-0xe];
            puVar10[-0xe] = 0;
            puVar8[-0xd] = (puVar8[-0xd] ^ puVar10[-0xd]) & uVar7 ^ puVar8[-0xd];
            puVar10[-0xd] = 0;
            puVar8[-0xc] = (puVar8[-0xc] ^ puVar10[-0xc]) & uVar7 ^ puVar8[-0xc];
            puVar10[-0xc] = 0;
            puVar8[-0xb] = (puVar8[-0xb] ^ puVar10[-0xb]) & uVar7 ^ puVar8[-0xb];
            puVar10[-0xb] = 0;
            puVar8[-10] = (puVar8[-10] ^ puVar10[-10]) & uVar7 ^ puVar8[-10];
            puVar10[-10] = 0;
            puVar8[-9] = (puVar8[-9] ^ puVar10[-9]) & uVar7 ^ puVar8[-9];
            puVar10[-9] = 0;
            puVar10 = puVar10 + 8;
            puVar8 = puVar8 + 8;
          } while (iVar1 != (num - 9U & 0xfffffff8) + 8);
        }
        puVar5 = puVar9 + iVar1;
        puVar15 = puVar13 + iVar1;
        do {
          iVar1 = iVar1 + 1;
          *puVar5 = (*puVar15 ^ *puVar5) & uVar7 ^ *puVar5;
          *puVar15 = 0;
          puVar5 = puVar5 + 1;
          puVar15 = puVar15 + 1;
        } while (iVar1 < num);
        return 1;
      }
    }
  }
  return 0;
}

