
uint ec_GFp_simple_point2oct
               (EC_GROUP *param_1,EC_POINT *param_2,uint param_3,char *param_4,uint param_5,
               BN_CTX *param_6)

{
  int iVar1;
  int iVar2;
  BIGNUM *x;
  BIGNUM *y;
  uint uVar3;
  uint uVar4;
  char *pcVar5;
  char cVar6;
  uint uVar7;
  BN_CTX *c;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  char *pcVar12;
  uint uVar13;
  uint uVar14;
  
  if ((param_3 != 4 && param_3 != 2) && (param_3 != 6)) {
    ERR_put_error(0x10,0x68,0x68,"ecp_oct.c",0xdf);
    return 0;
  }
  iVar1 = EC_POINT_is_at_infinity(param_1,param_2);
  if (iVar1 != 0) {
    if (param_4 == (char *)0x0) {
      return 1;
    }
    if (param_5 == 0) {
      ERR_put_error(0x10,0x68,100,"ecp_oct.c",0xe7);
      return 0;
    }
    *param_4 = '\0';
    return 1;
  }
  iVar2 = BN_num_bits((BIGNUM *)(param_1 + 0x48));
  iVar1 = iVar2 + 0xe;
  if (-1 < iVar2 + 7) {
    iVar1 = iVar2 + 7;
  }
  uVar9 = iVar1 >> 3;
  uVar7 = uVar9;
  if (param_3 != 2) {
    uVar7 = uVar9 * 2;
  }
  uVar7 = uVar7 + 1;
  if (param_4 == (char *)0x0) {
    return uVar7;
  }
  if (param_5 < uVar7) {
    ERR_put_error(0x10,0x68,100,"ecp_oct.c",0xf8);
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
     (iVar1 = EC_POINT_get_affine_coordinates_GFp(param_1,param_2,x,y,param_6), iVar1 == 0))
  goto LAB_000f972c;
  cVar6 = (char)param_3;
  if (((param_3 & 0xfffffffb) == 2) && ((0 < y->top && ((int)(*y->d << 0x1f) < 0)))) {
    cVar6 = cVar6 + '\x01';
  }
  *param_4 = cVar6;
  iVar2 = BN_num_bits(x);
  iVar1 = iVar2 + 7;
  if (iVar2 + 7 < 0) {
    iVar1 = iVar2 + 0xe;
  }
  uVar3 = uVar9 - (iVar1 >> 3);
  if (uVar9 < uVar3) {
    iVar1 = 0x116;
  }
  else {
    iVar1 = 1;
    if (uVar3 != 0) {
      uVar13 = ~(uint)param_4 & 3;
      if (uVar3 < (~(uint)param_4 & 3)) {
        uVar13 = uVar3;
      }
      uVar11 = uVar3;
      uVar14 = uVar3;
      if ((uVar3 < 4) || (uVar11 = uVar13, uVar13 != 0)) {
        uVar13 = uVar11;
        iVar1 = 1;
        pcVar12 = param_4;
        do {
          pcVar12 = pcVar12 + 1;
          *pcVar12 = '\0';
          iVar1 = iVar1 + 1;
          uVar14 = uVar14 - 1;
        } while ((uint)((int)pcVar12 - (int)param_4) < uVar13);
        if (uVar3 != uVar13) goto LAB_000f95e0;
      }
      else {
        iVar1 = 1;
LAB_000f95e0:
        uVar11 = uVar3 - uVar13 >> 2;
        if (uVar11 != 0) {
          pcVar12 = param_4 + uVar13 + 1;
          if (uVar11 < 9) {
            uVar10 = 0;
          }
          else {
            uVar10 = 0;
            pcVar5 = pcVar12;
            do {
              pcVar12 = pcVar5 + 0x20;
              uVar8 = uVar10 + 9;
              uVar10 = uVar10 + 8;
              HintPreloadData(pcVar5 + 0xa0);
              pcVar5[0] = '\0';
              pcVar5[1] = '\0';
              pcVar5[2] = '\0';
              pcVar5[3] = '\0';
              pcVar5[4] = '\0';
              pcVar5[5] = '\0';
              pcVar5[6] = '\0';
              pcVar5[7] = '\0';
              pcVar5[8] = '\0';
              pcVar5[9] = '\0';
              pcVar5[10] = '\0';
              pcVar5[0xb] = '\0';
              pcVar5[0xc] = '\0';
              pcVar5[0xd] = '\0';
              pcVar5[0xe] = '\0';
              pcVar5[0xf] = '\0';
              pcVar5[0x10] = '\0';
              pcVar5[0x11] = '\0';
              pcVar5[0x12] = '\0';
              pcVar5[0x13] = '\0';
              pcVar5[0x14] = '\0';
              pcVar5[0x15] = '\0';
              pcVar5[0x16] = '\0';
              pcVar5[0x17] = '\0';
              pcVar5[0x18] = '\0';
              pcVar5[0x19] = '\0';
              pcVar5[0x1a] = '\0';
              pcVar5[0x1b] = '\0';
              pcVar5[0x1c] = '\0';
              pcVar5[0x1d] = '\0';
              pcVar5[0x1e] = '\0';
              pcVar5[0x1f] = '\0';
              pcVar5 = pcVar12;
            } while (uVar8 < uVar11 - 7);
          }
          do {
            uVar10 = uVar10 + 1;
            pcVar12[0] = '\0';
            pcVar12[1] = '\0';
            pcVar12[2] = '\0';
            pcVar12[3] = '\0';
            pcVar12 = pcVar12 + 4;
          } while (uVar10 < uVar11);
          iVar1 = iVar1 + uVar11 * 4;
          uVar14 = uVar14 + uVar11 * -4;
          if (uVar3 - uVar13 == uVar11 * 4) goto LAB_000f96ee;
        }
        if (0x1f < uVar14 - 1) {
          pcVar12 = param_4 + iVar1;
          do {
            uVar13 = uVar14 - 0x21;
            uVar14 = uVar14 - 0x20;
            param_4[iVar1] = '\0';
            HintPreloadData(param_4 + iVar1 + 0x22);
            pcVar12[1] = '\0';
            pcVar12[2] = '\0';
            iVar1 = iVar1 + 0x20;
            pcVar12[3] = '\0';
            pcVar12[4] = '\0';
            pcVar12[5] = '\0';
            pcVar12[6] = '\0';
            pcVar12[7] = '\0';
            pcVar12[8] = '\0';
            pcVar12[9] = '\0';
            pcVar12[10] = '\0';
            pcVar12[0xb] = '\0';
            pcVar12[0xc] = '\0';
            pcVar12[0xd] = '\0';
            pcVar12[0xe] = '\0';
            pcVar12[0xf] = '\0';
            pcVar12[0x10] = '\0';
            pcVar12[0x11] = '\0';
            pcVar12[0x12] = '\0';
            pcVar12[0x13] = '\0';
            pcVar12[0x14] = '\0';
            pcVar12[0x15] = '\0';
            pcVar12[0x16] = '\0';
            pcVar12[0x17] = '\0';
            pcVar12[0x18] = '\0';
            pcVar12[0x19] = '\0';
            pcVar12[0x1a] = '\0';
            pcVar12[0x1b] = '\0';
            pcVar12[0x1c] = '\0';
            pcVar12[0x1d] = '\0';
            pcVar12[0x1e] = '\0';
            pcVar12[0x1f] = '\0';
            pcVar12 = pcVar12 + 0x20;
          } while (0x1f < uVar13);
        }
        pcVar12 = param_4 + iVar1;
        do {
          pcVar5 = pcVar12 + 1;
          *pcVar12 = '\0';
          pcVar12 = pcVar5;
        } while (pcVar5 != param_4 + uVar14 + iVar1);
      }
LAB_000f96ee:
      iVar1 = uVar3 + 1;
    }
    iVar2 = BN_bn2bin(x,(uchar *)(param_4 + iVar1));
    uVar3 = uVar9 + 1;
    if (uVar3 == iVar2 + iVar1) {
      if ((param_3 & 0xfffffffd) == 4) {
        iVar2 = BN_num_bits(y);
        iVar1 = iVar2 + 0xe;
        if (-1 < iVar2 + 7) {
          iVar1 = iVar2 + 7;
        }
        uVar13 = uVar9 - (iVar1 >> 3);
        if (uVar9 < uVar13) {
          iVar1 = 0x128;
          goto LAB_000f971e;
        }
        if (uVar13 != 0) {
          pcVar12 = param_4 + uVar9;
          uVar14 = ~(uint)pcVar12 & 3;
          if (uVar13 < (~(uint)pcVar12 & 3)) {
            uVar14 = uVar13;
          }
          pcVar5 = pcVar12;
          uVar11 = uVar3;
          uVar10 = uVar13;
          uVar8 = uVar13;
          if ((uVar13 < 4) || (uVar8 = uVar14, uVar14 != 0)) {
            do {
              uVar14 = uVar8;
              uVar4 = uVar11 - uVar9;
              uVar11 = uVar11 + 1;
              pcVar5[1] = '\0';
              uVar10 = uVar10 - 1;
              pcVar5 = pcVar5 + 1;
              uVar8 = uVar14;
            } while (uVar4 < uVar14);
            if (uVar13 != uVar14) goto LAB_000f9802;
          }
          else {
LAB_000f9802:
            uVar9 = uVar13 - uVar14 >> 2;
            if (uVar9 != 0) {
              pcVar12 = pcVar12 + uVar14 + 1;
              if (uVar9 < 9) {
                uVar8 = 0;
              }
              else {
                uVar8 = 0;
                pcVar5 = pcVar12;
                do {
                  pcVar12 = pcVar5 + 0x20;
                  uVar4 = uVar8 + 9;
                  uVar8 = uVar8 + 8;
                  HintPreloadData(pcVar5 + 0xa0);
                  pcVar5[0] = '\0';
                  pcVar5[1] = '\0';
                  pcVar5[2] = '\0';
                  pcVar5[3] = '\0';
                  pcVar5[4] = '\0';
                  pcVar5[5] = '\0';
                  pcVar5[6] = '\0';
                  pcVar5[7] = '\0';
                  pcVar5[8] = '\0';
                  pcVar5[9] = '\0';
                  pcVar5[10] = '\0';
                  pcVar5[0xb] = '\0';
                  pcVar5[0xc] = '\0';
                  pcVar5[0xd] = '\0';
                  pcVar5[0xe] = '\0';
                  pcVar5[0xf] = '\0';
                  pcVar5[0x10] = '\0';
                  pcVar5[0x11] = '\0';
                  pcVar5[0x12] = '\0';
                  pcVar5[0x13] = '\0';
                  pcVar5[0x14] = '\0';
                  pcVar5[0x15] = '\0';
                  pcVar5[0x16] = '\0';
                  pcVar5[0x17] = '\0';
                  pcVar5[0x18] = '\0';
                  pcVar5[0x19] = '\0';
                  pcVar5[0x1a] = '\0';
                  pcVar5[0x1b] = '\0';
                  pcVar5[0x1c] = '\0';
                  pcVar5[0x1d] = '\0';
                  pcVar5[0x1e] = '\0';
                  pcVar5[0x1f] = '\0';
                  pcVar5 = pcVar12;
                } while (uVar4 < uVar9 - 7);
              }
              do {
                uVar8 = uVar8 + 1;
                pcVar12[0] = '\0';
                pcVar12[1] = '\0';
                pcVar12[2] = '\0';
                pcVar12[3] = '\0';
                pcVar12 = pcVar12 + 4;
              } while (uVar8 < uVar9);
              uVar11 = uVar11 + uVar9 * 4;
              uVar10 = uVar10 + uVar9 * -4;
              if (uVar13 - uVar14 == uVar9 * 4) goto LAB_000f9904;
            }
            if (0x1f < uVar10 - 1) {
              pcVar12 = param_4 + uVar11;
              do {
                uVar9 = uVar10 - 0x21;
                uVar10 = uVar10 - 0x20;
                param_4[uVar11] = '\0';
                HintPreloadData(param_4 + uVar11 + 0x22);
                pcVar12[1] = '\0';
                pcVar12[2] = '\0';
                uVar11 = uVar11 + 0x20;
                pcVar12[3] = '\0';
                pcVar12[4] = '\0';
                pcVar12[5] = '\0';
                pcVar12[6] = '\0';
                pcVar12[7] = '\0';
                pcVar12[8] = '\0';
                pcVar12[9] = '\0';
                pcVar12[10] = '\0';
                pcVar12[0xb] = '\0';
                pcVar12[0xc] = '\0';
                pcVar12[0xd] = '\0';
                pcVar12[0xe] = '\0';
                pcVar12[0xf] = '\0';
                pcVar12[0x10] = '\0';
                pcVar12[0x11] = '\0';
                pcVar12[0x12] = '\0';
                pcVar12[0x13] = '\0';
                pcVar12[0x14] = '\0';
                pcVar12[0x15] = '\0';
                pcVar12[0x16] = '\0';
                pcVar12[0x17] = '\0';
                pcVar12[0x18] = '\0';
                pcVar12[0x19] = '\0';
                pcVar12[0x1a] = '\0';
                pcVar12[0x1b] = '\0';
                pcVar12[0x1c] = '\0';
                pcVar12[0x1d] = '\0';
                pcVar12[0x1e] = '\0';
                pcVar12[0x1f] = '\0';
                pcVar12 = pcVar12 + 0x20;
              } while (0x1f < uVar9);
            }
            pcVar12 = param_4 + uVar11;
            do {
              pcVar5 = pcVar12 + 1;
              *pcVar12 = '\0';
              pcVar12 = pcVar5;
            } while (pcVar5 != param_4 + uVar11 + uVar10);
          }
LAB_000f9904:
          uVar3 = uVar3 + uVar13;
        }
        iVar1 = BN_bn2bin(y,(uchar *)(param_4 + uVar3));
        uVar3 = uVar3 + iVar1;
      }
      if (uVar3 == uVar7) {
        BN_CTX_end(param_6);
        if (c != (BN_CTX *)0x0) {
          BN_CTX_free(c);
          return uVar7;
        }
        return uVar7;
      }
      iVar1 = 0x134;
    }
    else {
      iVar1 = 0x120;
    }
  }
LAB_000f971e:
  ERR_put_error(0x10,0x68,0x44,"ecp_oct.c",iVar1);
LAB_000f972c:
  BN_CTX_end(param_6);
  if (c == (BN_CTX *)0x0) {
    return 0;
  }
  BN_CTX_free(c);
  return 0;
}

