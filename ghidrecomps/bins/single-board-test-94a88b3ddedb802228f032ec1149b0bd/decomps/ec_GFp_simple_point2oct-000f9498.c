
uint ec_GFp_simple_point2oct
               (EC_GROUP *param_1,EC_POINT *param_2,uint param_3,char *param_4,uint param_5,
               BN_CTX *param_6)

{
  undefined4 *puVar1;
  int iVar2;
  int iVar3;
  BIGNUM *x;
  BIGNUM *y;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  char *pcVar7;
  char cVar8;
  uint uVar9;
  char *pcVar10;
  uint uVar11;
  BN_CTX *c;
  uint uVar12;
  uint uVar13;
  uint uVar14;
  uint uVar15;
  undefined4 *puVar16;
  uint uVar17;
  
  if ((param_3 != 4 && param_3 != 2) && (param_3 != 6)) {
    ERR_put_error(0x10,0x68,0x68,DAT_000f9798,0xdf);
    return 0;
  }
  iVar2 = EC_POINT_is_at_infinity(param_1,param_2);
  if (iVar2 != 0) {
    if (param_4 == (char *)0x0) {
      return 1;
    }
    if (param_5 == 0) {
      ERR_put_error(0x10,0x68,100,DAT_000f9798,0xe7);
      return 0;
    }
    *param_4 = '\0';
    return 1;
  }
  iVar3 = BN_num_bits((BIGNUM *)(param_1 + 0x48));
  iVar2 = iVar3 + 0xe;
  if (-1 < iVar3 + 7) {
    iVar2 = iVar3 + 7;
  }
  uVar6 = iVar2 >> 3;
  uVar11 = uVar6;
  if (param_3 != 2) {
    uVar11 = uVar6 * 2;
  }
  uVar11 = uVar11 + 1;
  if (param_4 == (char *)0x0) {
    return uVar11;
  }
  if (param_5 < uVar11) {
    ERR_put_error(0x10,0x68,100,DAT_000f9798,0xf8);
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
  x = BN_CTX_get(param_6);
  y = BN_CTX_get(param_6);
  if ((y == (BIGNUM *)0x0) ||
     (iVar2 = EC_POINT_get_affine_coordinates_GFp(param_1,param_2,x,y,param_6), iVar2 == 0))
  goto LAB_000f972c;
  cVar8 = (char)param_3;
  if (((param_3 & 0xfffffffb) == 2) && ((0 < y->top && ((int)(*y->d << 0x1f) < 0)))) {
    cVar8 = cVar8 + '\x01';
  }
  *param_4 = cVar8;
  iVar3 = BN_num_bits(x);
  iVar2 = iVar3 + 7;
  if (iVar3 + 7 < 0) {
    iVar2 = iVar3 + 0xe;
  }
  uVar4 = uVar6 - (iVar2 >> 3);
  if (uVar6 < uVar4) {
    iVar2 = 0x116;
  }
  else {
    iVar2 = 1;
    if (uVar4 != 0) {
      uVar13 = ~(uint)param_4 & 3;
      if (uVar4 < (~(uint)param_4 & 3)) {
        uVar13 = uVar4;
      }
      uVar5 = uVar4;
      uVar17 = uVar4;
      if ((uVar4 < 4) || (uVar5 = uVar13, uVar13 != 0)) {
        uVar13 = uVar5;
        iVar2 = 1;
        pcVar10 = param_4;
        do {
          pcVar10 = pcVar10 + 1;
          *pcVar10 = '\0';
          iVar2 = iVar2 + 1;
          uVar17 = uVar17 - 1;
        } while ((uint)((int)pcVar10 - (int)param_4) < uVar13);
        if (uVar4 != uVar13) goto LAB_000f95e0;
      }
      else {
        iVar2 = 1;
LAB_000f95e0:
        uVar5 = uVar4 - uVar13;
        uVar15 = uVar5 >> 2;
        uVar9 = uVar5 & 0xfffffffc;
        if (uVar15 != 0) {
          puVar16 = (undefined4 *)(param_4 + uVar13 + 1);
          if (uVar15 < 9) {
            uVar13 = 0;
          }
          else {
            uVar13 = 0;
            puVar1 = puVar16;
            do {
              puVar16 = puVar1 + 8;
              uVar12 = uVar13 + 9;
              uVar13 = uVar13 + 8;
              HintPreloadData(puVar1 + 0x28);
              *puVar1 = 0;
              puVar1[1] = 0;
              puVar1[2] = 0;
              puVar1[3] = 0;
              puVar1[4] = 0;
              puVar1[5] = 0;
              puVar1[6] = 0;
              puVar1[7] = 0;
              puVar1 = puVar16;
            } while (uVar12 < uVar15 - 7);
          }
          do {
            uVar13 = uVar13 + 1;
            *puVar16 = 0;
            puVar16 = puVar16 + 1;
          } while (uVar13 < uVar15);
          iVar2 = iVar2 + uVar9;
          uVar17 = uVar17 - uVar9;
          if (uVar5 == uVar9) goto LAB_000f96ee;
        }
        if (0x1f < uVar17 - 1) {
          pcVar10 = param_4 + iVar2;
          do {
            uVar13 = uVar17 - 0x21;
            uVar17 = uVar17 - 0x20;
            param_4[iVar2] = '\0';
            HintPreloadData(param_4 + iVar2 + 0x22);
            pcVar10[1] = '\0';
            pcVar10[2] = '\0';
            iVar2 = iVar2 + 0x20;
            pcVar10[3] = '\0';
            pcVar10[4] = '\0';
            pcVar10[5] = '\0';
            pcVar10[6] = '\0';
            pcVar10[7] = '\0';
            pcVar10[8] = '\0';
            pcVar10[9] = '\0';
            pcVar10[10] = '\0';
            pcVar10[0xb] = '\0';
            pcVar10[0xc] = '\0';
            pcVar10[0xd] = '\0';
            pcVar10[0xe] = '\0';
            pcVar10[0xf] = '\0';
            pcVar10[0x10] = '\0';
            pcVar10[0x11] = '\0';
            pcVar10[0x12] = '\0';
            pcVar10[0x13] = '\0';
            pcVar10[0x14] = '\0';
            pcVar10[0x15] = '\0';
            pcVar10[0x16] = '\0';
            pcVar10[0x17] = '\0';
            pcVar10[0x18] = '\0';
            pcVar10[0x19] = '\0';
            pcVar10[0x1a] = '\0';
            pcVar10[0x1b] = '\0';
            pcVar10[0x1c] = '\0';
            pcVar10[0x1d] = '\0';
            pcVar10[0x1e] = '\0';
            pcVar10[0x1f] = '\0';
            pcVar10 = pcVar10 + 0x20;
          } while (0x1f < uVar13);
        }
        pcVar10 = param_4 + iVar2;
        do {
          pcVar7 = pcVar10 + 1;
          *pcVar10 = '\0';
          pcVar10 = pcVar7;
        } while (pcVar7 != param_4 + uVar17 + iVar2);
      }
LAB_000f96ee:
      iVar2 = uVar4 + 1;
    }
    iVar3 = BN_bn2bin(x,(uchar *)(param_4 + iVar2));
    uVar4 = uVar6 + 1;
    if (uVar4 == iVar3 + iVar2) {
      if ((param_3 & 0xfffffffd) == 4) {
        iVar3 = BN_num_bits(y);
        iVar2 = iVar3 + 0xe;
        if (-1 < iVar3 + 7) {
          iVar2 = iVar3 + 7;
        }
        uVar13 = uVar6 - (iVar2 >> 3);
        if (uVar6 < uVar13) {
          iVar2 = 0x128;
          goto LAB_000f971e;
        }
        if (uVar13 != 0) {
          pcVar10 = param_4 + uVar6;
          uVar17 = ~(uint)pcVar10 & 3;
          if (uVar13 < (~(uint)pcVar10 & 3)) {
            uVar17 = uVar13;
          }
          pcVar7 = pcVar10;
          uVar5 = uVar4;
          uVar9 = uVar13;
          uVar15 = uVar13;
          if ((uVar13 < 4) || (uVar15 = uVar17, uVar17 != 0)) {
            do {
              uVar17 = uVar15;
              uVar12 = uVar5 - uVar6;
              uVar5 = uVar5 + 1;
              pcVar7[1] = '\0';
              uVar9 = uVar9 - 1;
              pcVar7 = pcVar7 + 1;
              uVar15 = uVar17;
            } while (uVar12 < uVar17);
            if (uVar13 != uVar17) goto LAB_000f9802;
          }
          else {
LAB_000f9802:
            uVar15 = uVar13 - uVar17;
            uVar12 = uVar15 >> 2;
            uVar6 = uVar15 & 0xfffffffc;
            if (uVar12 != 0) {
              puVar16 = (undefined4 *)(pcVar10 + uVar17 + 1);
              if (uVar12 < 9) {
                uVar17 = 0;
              }
              else {
                uVar17 = 0;
                puVar1 = puVar16;
                do {
                  puVar16 = puVar1 + 8;
                  uVar14 = uVar17 + 9;
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
                  puVar1 = puVar16;
                } while (uVar14 < uVar12 - 7);
              }
              do {
                uVar17 = uVar17 + 1;
                *puVar16 = 0;
                puVar16 = puVar16 + 1;
              } while (uVar17 < uVar12);
              uVar5 = uVar5 + uVar6;
              uVar9 = uVar9 - uVar6;
              if (uVar15 == uVar6) goto LAB_000f9904;
            }
            if (0x1f < uVar9 - 1) {
              pcVar10 = param_4 + uVar5;
              do {
                uVar6 = uVar9 - 0x21;
                uVar9 = uVar9 - 0x20;
                param_4[uVar5] = '\0';
                HintPreloadData(param_4 + uVar5 + 0x22);
                pcVar10[1] = '\0';
                pcVar10[2] = '\0';
                uVar5 = uVar5 + 0x20;
                pcVar10[3] = '\0';
                pcVar10[4] = '\0';
                pcVar10[5] = '\0';
                pcVar10[6] = '\0';
                pcVar10[7] = '\0';
                pcVar10[8] = '\0';
                pcVar10[9] = '\0';
                pcVar10[10] = '\0';
                pcVar10[0xb] = '\0';
                pcVar10[0xc] = '\0';
                pcVar10[0xd] = '\0';
                pcVar10[0xe] = '\0';
                pcVar10[0xf] = '\0';
                pcVar10[0x10] = '\0';
                pcVar10[0x11] = '\0';
                pcVar10[0x12] = '\0';
                pcVar10[0x13] = '\0';
                pcVar10[0x14] = '\0';
                pcVar10[0x15] = '\0';
                pcVar10[0x16] = '\0';
                pcVar10[0x17] = '\0';
                pcVar10[0x18] = '\0';
                pcVar10[0x19] = '\0';
                pcVar10[0x1a] = '\0';
                pcVar10[0x1b] = '\0';
                pcVar10[0x1c] = '\0';
                pcVar10[0x1d] = '\0';
                pcVar10[0x1e] = '\0';
                pcVar10[0x1f] = '\0';
                pcVar10 = pcVar10 + 0x20;
              } while (0x1f < uVar6);
            }
            pcVar10 = param_4 + uVar5;
            do {
              pcVar7 = pcVar10 + 1;
              *pcVar10 = '\0';
              pcVar10 = pcVar7;
            } while (pcVar7 != param_4 + uVar5 + uVar9);
          }
LAB_000f9904:
          uVar4 = uVar4 + uVar13;
        }
        iVar2 = BN_bn2bin(y,(uchar *)(param_4 + uVar4));
        uVar4 = uVar4 + iVar2;
      }
      if (uVar4 == uVar11) {
        BN_CTX_end(param_6);
        if (c != (BN_CTX *)0x0) {
          BN_CTX_free(c);
          return uVar11;
        }
        return uVar11;
      }
      iVar2 = 0x134;
    }
    else {
      iVar2 = 0x120;
    }
  }
LAB_000f971e:
  ERR_put_error(0x10,0x68,0x44,DAT_000f9798,iVar2);
LAB_000f972c:
  BN_CTX_end(param_6);
  if (c == (BN_CTX *)0x0) {
    return 0;
  }
  BN_CTX_free(c);
  return 0;
}

