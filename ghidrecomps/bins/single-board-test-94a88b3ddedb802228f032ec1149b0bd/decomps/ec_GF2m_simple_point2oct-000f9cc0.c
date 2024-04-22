
uint ec_GF2m_simple_point2oct
               (int *param_1,EC_POINT *param_2,uint param_3,char *param_4,uint param_5,
               BN_CTX *param_6)

{
  undefined4 *puVar1;
  int iVar2;
  int iVar3;
  BIGNUM *a;
  BIGNUM *a_00;
  BIGNUM *pBVar4;
  uint uVar5;
  uint uVar6;
  char *pcVar7;
  uint uVar8;
  char *pcVar9;
  uint uVar10;
  uint uVar11;
  uint uVar12;
  uint uVar13;
  BN_CTX *c;
  uint uVar14;
  int iVar15;
  uint uVar16;
  uint uVar17;
  undefined4 *puVar18;
  
  iVar15 = param_3 - 4;
  if (iVar15 != 0) {
    iVar15 = 1;
  }
  if ((param_3 != 2 && param_3 != 4) && (param_3 != 6)) {
    ERR_put_error(0x10,0xa1,0x68,DAT_000f9fe8,0xba);
    return 0;
  }
  iVar2 = EC_POINT_is_at_infinity((EC_GROUP *)param_1,param_2);
  if (iVar2 != 0) {
    if (param_4 == (char *)0x0) {
      return 1;
    }
    if (param_5 == 0) {
      ERR_put_error(0x10,0xa1,100,DAT_000f9fe8,0xc2);
      return 0;
    }
    *param_4 = '\0';
    return 1;
  }
  iVar3 = EC_GROUP_get_degree((EC_GROUP *)param_1);
  iVar2 = iVar3 + 0xe;
  if (-1 < iVar3 + 7) {
    iVar2 = iVar3 + 7;
  }
  uVar6 = iVar2 >> 3;
  uVar10 = uVar6;
  if (param_3 != 2) {
    uVar10 = uVar6 * 2;
  }
  uVar10 = uVar10 + 1;
  if (param_4 == (char *)0x0) {
    return uVar10;
  }
  if (param_5 < uVar10) {
    ERR_put_error(0x10,0xa1,100,DAT_000f9fe8,0xd3);
    return 0;
  }
  if (param_6 == (BN_CTX *)0x0) {
    c = BN_CTX_new();
    param_6 = c;
    if (c == (BN_CTX *)0x0) {
      return 0;
    }
  }
  else {
    c = (BN_CTX *)0x0;
  }
  BN_CTX_start(param_6);
  a = BN_CTX_get(param_6);
  a_00 = BN_CTX_get(param_6);
  pBVar4 = BN_CTX_get(param_6);
  if ((pBVar4 == (BIGNUM *)0x0) ||
     (iVar2 = EC_POINT_get_affine_coordinates_GF2m(param_1,param_2,a,a_00,param_6), iVar2 == 0))
  goto LAB_000f9f52;
  *param_4 = (char)param_3;
  if ((iVar15 != 0) && (a->top != 0)) {
    iVar15 = (**(code **)(*param_1 + 0x8c))(param_1,pBVar4,a_00,a,param_6);
    if (iVar15 == 0) goto LAB_000f9f52;
    if ((0 < pBVar4->top) && ((int)(*pBVar4->d << 0x1f) < 0)) {
      *param_4 = *param_4 + '\x01';
    }
  }
  iVar2 = BN_num_bits(a);
  iVar15 = iVar2 + 7;
  if (iVar2 + 7 < 0) {
    iVar15 = iVar2 + 0xe;
  }
  uVar16 = uVar6 - (iVar15 >> 3);
  if (uVar6 < uVar16) {
    iVar15 = 0xf4;
  }
  else {
    iVar15 = 1;
    if (uVar16 != 0) {
      uVar17 = ~(uint)param_4 & 3;
      if (uVar16 < (~(uint)param_4 & 3)) {
        uVar17 = uVar16;
      }
      uVar5 = uVar16;
      uVar12 = uVar16;
      if ((uVar16 < 4) || (uVar5 = uVar17, uVar17 != 0)) {
        uVar17 = uVar5;
        iVar15 = 1;
        pcVar9 = param_4;
        do {
          pcVar9 = pcVar9 + 1;
          *pcVar9 = '\0';
          iVar15 = iVar15 + 1;
          uVar12 = uVar12 - 1;
        } while ((uint)((int)pcVar9 - (int)param_4) < uVar17);
        if (uVar16 != uVar17) goto LAB_000f9e0c;
      }
      else {
        iVar15 = 1;
LAB_000f9e0c:
        uVar5 = uVar16 - uVar17;
        uVar13 = uVar5 >> 2;
        uVar8 = uVar5 & 0xfffffffc;
        if (uVar13 != 0) {
          puVar18 = (undefined4 *)(param_4 + uVar17 + 1);
          if (uVar13 < 9) {
            uVar17 = 0;
          }
          else {
            uVar17 = 0;
            puVar1 = puVar18;
            do {
              puVar18 = puVar1 + 8;
              uVar11 = uVar17 + 9;
              uVar17 = uVar17 + 8;
              HintPreloadData(puVar1 + 0x28);
              *puVar1 = 0;
              puVar1[1] = 0;
              puVar1[2] = 0;
              puVar1[3] = 0;
              puVar1[4] = 0;
              puVar1[5] = 0;
              puVar1[6] = 0;
              puVar1[7] = 0;
              puVar1 = puVar18;
            } while (uVar11 < uVar13 - 7);
          }
          do {
            uVar17 = uVar17 + 1;
            *puVar18 = 0;
            puVar18 = puVar18 + 1;
          } while (uVar17 < uVar13);
          iVar15 = iVar15 + uVar8;
          uVar12 = uVar12 - uVar8;
          if (uVar5 == uVar8) goto LAB_000f9f18;
        }
        if (0x1f < uVar12 - 1) {
          pcVar9 = param_4 + iVar15;
          do {
            uVar17 = uVar12 - 0x21;
            uVar12 = uVar12 - 0x20;
            param_4[iVar15] = '\0';
            HintPreloadData(param_4 + iVar15 + 0x22);
            pcVar9[1] = '\0';
            pcVar9[2] = '\0';
            iVar15 = iVar15 + 0x20;
            pcVar9[3] = '\0';
            pcVar9[4] = '\0';
            pcVar9[5] = '\0';
            pcVar9[6] = '\0';
            pcVar9[7] = '\0';
            pcVar9[8] = '\0';
            pcVar9[9] = '\0';
            pcVar9[10] = '\0';
            pcVar9[0xb] = '\0';
            pcVar9[0xc] = '\0';
            pcVar9[0xd] = '\0';
            pcVar9[0xe] = '\0';
            pcVar9[0xf] = '\0';
            pcVar9[0x10] = '\0';
            pcVar9[0x11] = '\0';
            pcVar9[0x12] = '\0';
            pcVar9[0x13] = '\0';
            pcVar9[0x14] = '\0';
            pcVar9[0x15] = '\0';
            pcVar9[0x16] = '\0';
            pcVar9[0x17] = '\0';
            pcVar9[0x18] = '\0';
            pcVar9[0x19] = '\0';
            pcVar9[0x1a] = '\0';
            pcVar9[0x1b] = '\0';
            pcVar9[0x1c] = '\0';
            pcVar9[0x1d] = '\0';
            pcVar9[0x1e] = '\0';
            pcVar9[0x1f] = '\0';
            pcVar9 = pcVar9 + 0x20;
          } while (0x1f < uVar17);
        }
        pcVar9 = param_4 + iVar15;
        do {
          pcVar7 = pcVar9 + 1;
          *pcVar9 = '\0';
          pcVar9 = pcVar7;
        } while (pcVar7 != param_4 + uVar12 + iVar15);
      }
LAB_000f9f18:
      iVar15 = uVar16 + 1;
    }
    iVar2 = BN_bn2bin(a,(uchar *)(param_4 + iVar15));
    uVar16 = uVar6 + 1;
    if (uVar16 == iVar2 + iVar15) {
      if ((param_3 & 0xfffffffd) == 4) {
        iVar2 = BN_num_bits(a_00);
        iVar15 = iVar2 + 0xe;
        if (-1 < iVar2 + 7) {
          iVar15 = iVar2 + 7;
        }
        uVar17 = uVar6 - (iVar15 >> 3);
        if (uVar6 < uVar17) {
          iVar15 = 0x106;
          goto LAB_000f9f44;
        }
        if (uVar17 != 0) {
          pcVar9 = param_4 + uVar6;
          uVar12 = ~(uint)pcVar9 & 3;
          if (uVar17 < (~(uint)pcVar9 & 3)) {
            uVar12 = uVar17;
          }
          pcVar7 = pcVar9;
          uVar5 = uVar16;
          uVar8 = uVar17;
          uVar13 = uVar17;
          if ((uVar17 < 4) || (uVar13 = uVar12, uVar12 != 0)) {
            do {
              uVar12 = uVar13;
              uVar11 = uVar5 - uVar6;
              uVar5 = uVar5 + 1;
              pcVar7[1] = '\0';
              uVar8 = uVar8 - 1;
              pcVar7 = pcVar7 + 1;
              uVar13 = uVar12;
            } while (uVar11 < uVar12);
            if (uVar17 != uVar12) goto LAB_000fa064;
          }
          else {
LAB_000fa064:
            uVar6 = uVar17 - uVar12;
            uVar11 = uVar6 >> 2;
            uVar13 = uVar6 & 0xfffffffc;
            if (uVar11 != 0) {
              puVar18 = (undefined4 *)(pcVar9 + uVar12 + 1);
              if (uVar11 < 9) {
                uVar12 = 0;
              }
              else {
                uVar12 = 0;
                puVar1 = puVar18;
                do {
                  puVar18 = puVar1 + 8;
                  uVar14 = uVar12 + 9;
                  uVar12 = uVar12 + 8;
                  HintPreloadData(puVar1 + 0x28);
                  *puVar1 = 0;
                  puVar1[1] = 0;
                  puVar1[2] = 0;
                  puVar1[3] = 0;
                  puVar1[4] = 0;
                  puVar1[5] = 0;
                  puVar1[6] = 0;
                  puVar1[7] = 0;
                  puVar1 = puVar18;
                } while (uVar14 < uVar11 - 7);
              }
              do {
                uVar12 = uVar12 + 1;
                *puVar18 = 0;
                puVar18 = puVar18 + 1;
              } while (uVar12 < uVar11);
              uVar5 = uVar5 + uVar13;
              uVar8 = uVar8 - uVar13;
              if (uVar6 == uVar13) goto LAB_000fa164;
            }
            if (0x1f < uVar8 - 1) {
              pcVar9 = param_4 + uVar5;
              do {
                uVar6 = uVar8 - 0x21;
                uVar8 = uVar8 - 0x20;
                param_4[uVar5] = '\0';
                HintPreloadData(param_4 + uVar5 + 0x22);
                pcVar9[1] = '\0';
                pcVar9[2] = '\0';
                uVar5 = uVar5 + 0x20;
                pcVar9[3] = '\0';
                pcVar9[4] = '\0';
                pcVar9[5] = '\0';
                pcVar9[6] = '\0';
                pcVar9[7] = '\0';
                pcVar9[8] = '\0';
                pcVar9[9] = '\0';
                pcVar9[10] = '\0';
                pcVar9[0xb] = '\0';
                pcVar9[0xc] = '\0';
                pcVar9[0xd] = '\0';
                pcVar9[0xe] = '\0';
                pcVar9[0xf] = '\0';
                pcVar9[0x10] = '\0';
                pcVar9[0x11] = '\0';
                pcVar9[0x12] = '\0';
                pcVar9[0x13] = '\0';
                pcVar9[0x14] = '\0';
                pcVar9[0x15] = '\0';
                pcVar9[0x16] = '\0';
                pcVar9[0x17] = '\0';
                pcVar9[0x18] = '\0';
                pcVar9[0x19] = '\0';
                pcVar9[0x1a] = '\0';
                pcVar9[0x1b] = '\0';
                pcVar9[0x1c] = '\0';
                pcVar9[0x1d] = '\0';
                pcVar9[0x1e] = '\0';
                pcVar9[0x1f] = '\0';
                pcVar9 = pcVar9 + 0x20;
              } while (0x1f < uVar6);
            }
            pcVar9 = param_4 + uVar5;
            do {
              pcVar7 = pcVar9 + 1;
              *pcVar9 = '\0';
              pcVar9 = pcVar7;
            } while (pcVar7 != param_4 + uVar5 + uVar8);
          }
LAB_000fa164:
          uVar16 = uVar16 + uVar17;
        }
        iVar15 = BN_bn2bin(a_00,(uchar *)(param_4 + uVar16));
        uVar16 = uVar16 + iVar15;
      }
      if (uVar16 == uVar10) {
        BN_CTX_end(param_6);
        if (c != (BN_CTX *)0x0) {
          BN_CTX_free(c);
          return uVar10;
        }
        return uVar10;
      }
      iVar15 = 0x112;
    }
    else {
      iVar15 = 0xfe;
    }
  }
LAB_000f9f44:
  ERR_put_error(0x10,0xa1,0x44,DAT_000f9fe8,iVar15);
LAB_000f9f52:
  BN_CTX_end(param_6);
  if (c == (BN_CTX *)0x0) {
    return 0;
  }
  BN_CTX_free(c);
  return 0;
}

