
int BN_GF2m_mod_mul_arr(undefined4 param_1,int *param_2,int *param_3,undefined4 param_4,
                       BN_CTX *param_5)

{
  BIGNUM *pBVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  int iVar10;
  uint uVar11;
  uint *puVar12;
  uint uVar13;
  int local_12c;
  uint *local_124;
  uint local_120;
  uint local_118;
  uint local_114;
  uint local_110;
  uint local_10c;
  uint local_108;
  uint local_104;
  int local_8c;
  int local_88;
  int local_84;
  uint local_68 [15];
  uint local_2c;
  
  if (param_2 == param_3) {
    iVar2 = BN_GF2m_mod_sqr_arr(param_1,param_2,param_4,param_5);
    return iVar2;
  }
  BN_CTX_start(param_5);
  pBVar1 = BN_CTX_get(param_5);
  if (pBVar1 != (BIGNUM *)0x0) {
    iVar10 = param_3[1] + param_2[1] + 4;
    iVar2 = bn_wexpand(pBVar1,iVar10);
    if (iVar2 != 0) {
      pBVar1->top = iVar10;
      if (0 < iVar10) {
        memset(pBVar1->d,0,iVar10 * 4);
      }
      iVar2 = param_3[1];
      if (0 < iVar2) {
        local_8c = 0;
        local_88 = *param_3 + 0xc;
        local_84 = 0;
        iVar10 = param_2[1];
        do {
          uVar4 = *(uint *)(local_88 + -0xc);
          if (local_84 + 1 == iVar2) {
            uVar6 = 0;
          }
          else {
            HintPreloadData(local_88);
            uVar6 = *(uint *)(local_88 + -8);
          }
          if (0 < iVar10) {
            local_124 = (uint *)*param_2;
            uVar8 = uVar6 ^ uVar4;
            local_118 = *(uint *)((int)pBVar1->d + local_8c);
            puVar12 = (uint *)((int)pBVar1->d + local_8c);
            local_12c = 0;
            do {
              uVar5 = *local_124;
              if (iVar10 == local_12c + 1) {
                local_68[8] = 0;
                local_104 = 0;
                local_108 = 0;
                local_10c = 0;
                local_110 = 0;
                local_114 = 0;
                local_120 = 0;
                local_68[2] = local_68[8];
                local_2c = local_68[8];
                local_68[4] = local_68[8];
                local_68[5] = local_68[8];
                local_68[6] = local_68[8];
                local_68[3] = local_68[8];
                local_68[1] = local_68[8];
                local_68[7] = local_68[8];
              }
              else {
                local_68[1] = local_124[1];
                local_68[2] = local_68[1] << 1;
                local_68[8] = local_68[1] << 3;
                local_68[4] = local_68[1] << 2;
                local_68[3] = local_68[1] ^ local_68[2];
                local_110 = local_68[8] ^ local_68[3];
                local_68[5] = local_68[1] ^ local_68[4];
                local_68[6] = local_68[2] ^ local_68[4];
                local_108 = local_68[8] ^ local_68[5];
                local_68[7] = local_68[4] ^ local_68[3];
                local_104 = local_68[8] ^ local_68[6];
                local_120 = local_68[1] ^ local_68[8];
                local_2c = local_68[8] ^ local_68[7];
                local_114 = local_68[2] ^ local_68[8];
                local_10c = local_68[4] ^ local_68[8];
              }
              uVar9 = uVar5 << 1;
              uVar3 = uVar5 << 2;
              uVar11 = uVar5 ^ uVar9;
              local_12c = local_12c + 2;
              local_68[0] = 0;
              local_68[8] = uVar5 << 3;
              local_68[9] = local_120;
              local_124 = local_124 + 2;
              local_68[10] = local_114;
              uVar13 = local_68[1] ^ uVar5;
              local_68[0xb] = local_110;
              local_68[0xc] = local_10c;
              local_68[0xd] = local_108;
              local_68[0xe] = local_104;
              local_68[7] = uVar3 ^ uVar11;
              local_68[4] = uVar3;
              local_68[2] = uVar9;
              local_68[1] = uVar5;
              local_68[3] = uVar11;
              local_68[6] = uVar9 ^ uVar3;
              local_68[0xe] = local_68[8] ^ uVar9 ^ uVar3;
              local_68[4] = uVar13 << 2;
              local_2c = local_68[8] ^ uVar3 ^ uVar11;
              local_68[0xc] = uVar3 ^ local_68[8];
              uVar7 = uVar13 << 3;
              local_68[5] = uVar5 ^ uVar3;
              local_68[0xb] = uVar11 ^ local_68[8];
              local_68[0xd] = local_68[8] ^ uVar5 ^ uVar3;
              local_68[2] = uVar13 << 1;
              local_68[3] = local_68[2] ^ uVar13;
              local_68[9] = uVar5 ^ local_68[8];
              local_68[10] = uVar9 ^ local_68[8];
              uVar11 = local_68[uVar6 & 0xf] ^ local_68[uVar6 >> 0x1c] << 0x1c ^
                       local_68[(uVar6 << 0x18) >> 0x1c] << 4 ^
                       local_68[(uVar6 << 0x14) >> 0x1c] << 8 ^
                       local_68[(uVar6 << 0x10) >> 0x1c] << 0xc ^
                       local_68[(uVar6 << 0xc) >> 0x1c] << 0x10 ^
                       local_68[(uVar6 << 8) >> 0x1c] << 0x14 ^
                       local_68[(uVar6 << 4) >> 0x1c] << 0x18;
              local_68[1] = uVar13;
              local_68[9] = uVar13 ^ uVar7;
              local_68[8] = uVar7;
              local_68[10] = local_68[2] ^ uVar7;
              local_68[5] = uVar13 ^ local_68[4];
              local_68[7] = local_68[4] ^ local_68[3];
              uVar9 = local_68[uVar4 & 0xf] ^ local_68[uVar4 >> 0x1c] << 0x1c ^
                      local_68[(uVar4 << 0x18) >> 0x1c] << 4 ^
                      local_68[(uVar4 << 0x14) >> 0x1c] << 8 ^
                      local_68[(uVar4 << 0x10) >> 0x1c] << 0xc ^
                      local_68[(uVar4 << 0xc) >> 0x1c] << 0x10 ^
                      local_68[(uVar4 << 8) >> 0x1c] << 0x14 ^
                      local_68[(uVar4 << 4) >> 0x1c] << 0x18;
              local_68[0xc] = local_68[4] ^ uVar7;
              local_68[6] = local_68[2] ^ local_68[4];
              local_68[0xb] = uVar7 ^ local_68[3];
              local_68[0xd] = uVar7 ^ uVar13 ^ local_68[4];
              local_2c = uVar7 ^ local_68[4] ^ local_68[3];
              local_68[0xe] = uVar7 ^ local_68[2] ^ local_68[4];
              uVar5 = local_68[uVar8 & 0xf];
              uVar7 = local_68[(uVar8 << 0x18) >> 0x1c];
              uVar3 = local_68[uVar8 >> 0x1c];
              *puVar12 = local_118 ^ uVar9;
              local_118 = puVar12[2] ^ uVar11;
              puVar12[1] = uVar9 ^ uVar5 ^ uVar3 << 0x1c ^ uVar7 << 4 ^
                           local_68[(uVar8 << 0x14) >> 0x1c] << 8 ^
                           local_68[(uVar8 << 0x10) >> 0x1c] << 0xc ^
                           local_68[(uVar8 << 0xc) >> 0x1c] << 0x10 ^
                           local_68[(uVar8 << 8) >> 0x1c] << 0x14 ^
                           local_68[(uVar8 << 4) >> 0x1c] << 0x18 ^ uVar11 ^ puVar12[1];
              puVar12 = puVar12 + 2;
              *puVar12 = local_118;
            } while (local_12c < iVar10);
          }
          local_8c = local_8c + 8;
          local_84 = local_84 + 2;
          local_88 = local_88 + 8;
        } while (local_84 < iVar2);
      }
      bn_correct_top(pBVar1);
      iVar2 = BN_GF2m_mod_arr(param_1,pBVar1,param_4);
      if (iVar2 != 0) {
        iVar2 = 1;
      }
      goto LAB_001c9236;
    }
  }
  iVar2 = 0;
LAB_001c9236:
  BN_CTX_end(param_5);
  return iVar2;
}

