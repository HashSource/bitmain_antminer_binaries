
undefined4 BN_GF2m_mod_arr_part_0(uint **param_1,uint *param_2)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  uint *puVar4;
  uint *puVar5;
  uint uVar6;
  uint uVar7;
  int iVar8;
  
  uVar3 = *param_2;
  uVar6 = uVar3 & ~((int)uVar3 >> 0x20);
  if ((int)uVar3 < 0) {
    uVar6 = uVar3 + 0x1f;
  }
  puVar5 = *param_1;
  iVar1 = (int)uVar6 >> 5;
  iVar8 = (int)param_1[1] + -1;
  while (iVar1 < iVar8) {
    while (uVar6 = puVar5[iVar8], uVar6 == 0) {
      iVar8 = iVar8 + -1;
      if (iVar8 <= iVar1) goto LAB_00122b22;
    }
    puVar4 = param_2 + 1;
    puVar5[iVar8] = 0;
    uVar3 = param_2[1];
    while (uVar3 != 0) {
      uVar3 = *param_2 - uVar3;
      uVar7 = uVar3 + 0x1f & (int)uVar3 >> 0x20;
      if (((int)uVar3 >> 0x1e & 1U) == 0) {
        uVar7 = uVar3;
      }
      iVar2 = iVar8 - ((int)uVar7 >> 5);
      uVar3 = (int)uVar3 % 0x20;
      puVar5[iVar2] = puVar5[iVar2] ^ uVar6 >> (uVar3 & 0xff);
      if (uVar3 != 0) {
        puVar5[iVar2 + -1] = puVar5[iVar2 + -1] ^ uVar6 << (0x20 - uVar3 & 0xff);
      }
      puVar4 = puVar4 + 1;
      uVar3 = *puVar4;
    }
    iVar2 = iVar8 - iVar1;
    uVar3 = (int)*param_2 % 0x20;
    puVar5[iVar2] = puVar5[iVar2] ^ uVar6 >> (uVar3 & 0xff);
    if (uVar3 != 0) {
      puVar5[iVar2 + -1] = puVar5[iVar2 + -1] ^ uVar6 << (0x20 - uVar3 & 0xff);
    }
  }
LAB_00122b22:
  if (iVar1 == iVar8) {
    uVar3 = *param_2;
    uVar6 = puVar5[iVar1];
    while( true ) {
      uVar3 = (int)uVar3 % 0x20;
      uVar7 = uVar6 >> (uVar3 & 0xff);
      if (uVar7 == 0) break;
      if (uVar3 != 0) {
        uVar3 = (uVar6 << (0x20 - uVar3 & 0xff)) >> (0x20 - uVar3 & 0xff);
      }
      puVar5[iVar1] = uVar3;
      *puVar5 = *puVar5 ^ uVar7;
      uVar6 = param_2[1];
      if (uVar6 != 0) {
        puVar4 = param_2 + 1;
        do {
          uVar3 = uVar6 + 0x1f & (int)uVar6 >> 0x20;
          if (((int)uVar6 >> 0x1e & 1U) == 0) {
            uVar3 = uVar6;
          }
          iVar8 = (int)uVar3 >> 5;
          uVar6 = (int)uVar6 % 0x20;
          puVar5[iVar8] = puVar5[iVar8] ^ uVar7 << (uVar6 & 0xff);
          if (uVar6 != 0) {
            uVar6 = uVar7 >> (0x20 - uVar6 & 0xff);
            if (uVar6 != 0) {
              puVar5[iVar8 + 1] = puVar5[iVar8 + 1] ^ uVar6;
            }
          }
          puVar4 = puVar4 + 1;
          uVar6 = *puVar4;
        } while (uVar6 != 0);
      }
      uVar3 = *param_2;
      uVar6 = puVar5[iVar1];
    }
  }
  puVar4 = param_1[1];
  if (0 < (int)puVar4) {
    puVar5 = puVar5 + (int)puVar4 + -1;
    do {
      if (*puVar5 != 0) break;
      puVar4 = (uint *)((int)puVar4 + -1);
      puVar5 = puVar5 + -1;
    } while (puVar4 != (uint *)0x0);
    param_1[1] = puVar4;
  }
  return 1;
}

