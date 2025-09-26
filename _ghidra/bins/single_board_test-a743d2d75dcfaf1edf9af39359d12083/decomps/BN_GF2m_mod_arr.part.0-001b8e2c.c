
undefined4 BN_GF2m_mod_arr_part_0(undefined4 *param_1,uint *param_2)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  uint *puVar4;
  uint uVar5;
  uint uVar6;
  int iVar7;
  uint *puVar8;
  
  uVar2 = *param_2;
  uVar5 = uVar2 & ~((int)uVar2 >> 0x20);
  if ((int)uVar2 < 0) {
    uVar5 = uVar2 + 0x1f;
  }
  puVar4 = (uint *)*param_1;
  iVar3 = (int)uVar5 >> 5;
  iVar7 = param_1[1] + -1;
  while (iVar3 < iVar7) {
    while (uVar5 = puVar4[iVar7], uVar5 == 0) {
      iVar7 = iVar7 + -1;
      if (iVar7 <= iVar3) goto LAB_001b8e62;
    }
    puVar8 = param_2 + 1;
    puVar4[iVar7] = 0;
    uVar2 = param_2[1];
    while (uVar2 != 0) {
      uVar2 = *param_2 - uVar2;
      uVar6 = uVar2 + 0x1f & (int)uVar2 >> 0x20;
      if (((int)uVar2 >> 0x1e & 1U) == 0) {
        uVar6 = uVar2;
      }
      iVar1 = iVar7 - ((int)uVar6 >> 5);
      uVar2 = (int)uVar2 % 0x20;
      puVar4[iVar1] = puVar4[iVar1] ^ uVar5 >> (uVar2 & 0xff);
      if (uVar2 != 0) {
        puVar4[iVar1 + -1] = puVar4[iVar1 + -1] ^ uVar5 << (0x20 - uVar2 & 0xff);
      }
      puVar8 = puVar8 + 1;
      uVar2 = *puVar8;
    }
    iVar1 = iVar7 - iVar3;
    uVar2 = (int)*param_2 % 0x20;
    puVar4[iVar1] = puVar4[iVar1] ^ uVar5 >> (uVar2 & 0xff);
    if (uVar2 != 0) {
      puVar4[iVar1 + -1] = puVar4[iVar1 + -1] ^ uVar5 << (0x20 - uVar2 & 0xff);
    }
  }
LAB_001b8e62:
  if (iVar3 == iVar7) {
    uVar2 = *param_2;
    uVar5 = puVar4[iVar3];
    while( true ) {
      uVar2 = (int)uVar2 % 0x20;
      uVar6 = uVar5 >> (uVar2 & 0xff);
      if (uVar6 == 0) break;
      if (uVar2 != 0) {
        uVar2 = (uVar5 << (0x20 - uVar2 & 0xff)) >> (0x20 - uVar2 & 0xff);
      }
      puVar4[iVar3] = uVar2;
      *puVar4 = *puVar4 ^ uVar6;
      uVar5 = param_2[1];
      if (uVar5 != 0) {
        puVar8 = param_2 + 1;
        do {
          uVar2 = uVar5 + 0x1f & (int)uVar5 >> 0x20;
          if (((int)uVar5 >> 0x1e & 1U) == 0) {
            uVar2 = uVar5;
          }
          iVar7 = (int)uVar2 >> 5;
          uVar5 = (int)uVar5 % 0x20;
          puVar4[iVar7] = puVar4[iVar7] ^ uVar6 << (uVar5 & 0xff);
          if (uVar5 != 0) {
            uVar5 = uVar6 >> (0x20 - uVar5 & 0xff);
            if (uVar5 != 0) {
              puVar4[iVar7 + 1] = puVar4[iVar7 + 1] ^ uVar5;
            }
          }
          puVar8 = puVar8 + 1;
          uVar5 = *puVar8;
        } while (uVar5 != 0);
      }
      uVar2 = *param_2;
      uVar5 = puVar4[iVar3];
    }
  }
  iVar3 = param_1[1];
  if (0 < iVar3) {
    puVar4 = puVar4 + iVar3 + -1;
    do {
      if (*puVar4 != 0) break;
      iVar3 = iVar3 + -1;
      puVar4 = puVar4 + -1;
    } while (iVar3 != 0);
    param_1[1] = iVar3;
  }
  return 1;
}

