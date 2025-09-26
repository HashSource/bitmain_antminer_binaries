
uint ec_GF2m_simple_point2oct
               (EC_GROUP *param_1,EC_POINT *param_2,uint param_3,char *param_4,uint param_5,
               BN_CTX *param_6)

{
  int iVar1;
  int iVar2;
  BIGNUM *a;
  BIGNUM *a_00;
  BIGNUM *pBVar3;
  uint uVar4;
  char *pcVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  BN_CTX *c;
  int iVar11;
  uint uVar12;
  uint uVar13;
  char *pcVar14;
  uint uVar15;
  
  iVar11 = param_3 - 4;
  if (iVar11 != 0) {
    iVar11 = 1;
  }
  if ((param_3 != 2 && param_3 != 4) && (param_3 != 6)) {
    ERR_put_error(0x10,0xa1,0x68,"ec2_oct.c",0xba);
    return 0;
  }
  iVar1 = EC_POINT_is_at_infinity(param_1,param_2);
  if (iVar1 != 0) {
    if (param_4 == (char *)0x0) {
      return 1;
    }
    if (param_5 == 0) {
      ERR_put_error(0x10,0xa1,100,"ec2_oct.c",0xc2);
      return 0;
    }
    *param_4 = '\0';
    return 1;
  }
  iVar2 = EC_GROUP_get_degree(param_1);
  iVar1 = iVar2 + 0xe;
  if (-1 < iVar2 + 7) {
    iVar1 = iVar2 + 7;
  }
  uVar10 = iVar1 >> 3;
  uVar6 = uVar10;
  if (param_3 != 2) {
    uVar6 = uVar10 * 2;
  }
  uVar6 = uVar6 + 1;
  if (param_4 == (char *)0x0) {
    return uVar6;
  }
  if (param_5 < uVar6) {
    ERR_put_error(0x10,0xa1,100,"ec2_oct.c",0xd3);
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
  pBVar3 = BN_CTX_get(param_6);
  if ((pBVar3 == (BIGNUM *)0x0) ||
     (iVar1 = EC_POINT_get_affine_coordinates_GF2m(param_1,param_2,a,a_00,param_6), iVar1 == 0))
  goto LAB_001951f2;
  *param_4 = (char)param_3;
  if ((iVar11 != 0) && (a->top != 0)) {
    iVar11 = (**(code **)(*(int *)param_1 + 0x8c))(param_1,pBVar3,a_00,a,param_6);
    if (iVar11 == 0) goto LAB_001951f2;
    if ((0 < pBVar3->top) && ((int)(*pBVar3->d << 0x1f) < 0)) {
      *param_4 = *param_4 + '\x01';
    }
  }
  iVar1 = BN_num_bits(a);
  iVar11 = iVar1 + 7;
  if (iVar1 + 7 < 0) {
    iVar11 = iVar1 + 0xe;
  }
  uVar12 = uVar10 - (iVar11 >> 3);
  if (uVar10 < uVar12) {
    iVar11 = 0xf4;
  }
  else {
    iVar11 = 1;
    if (uVar12 != 0) {
      uVar15 = ~(uint)param_4 & 3;
      if (uVar12 < (~(uint)param_4 & 3)) {
        uVar15 = uVar12;
      }
      uVar9 = uVar12;
      uVar8 = uVar12;
      if ((uVar12 < 4) || (uVar9 = uVar15, uVar15 != 0)) {
        uVar15 = uVar9;
        iVar11 = 1;
        pcVar14 = param_4;
        do {
          pcVar14 = pcVar14 + 1;
          *pcVar14 = '\0';
          iVar11 = iVar11 + 1;
          uVar8 = uVar8 - 1;
        } while ((uint)((int)pcVar14 - (int)param_4) < uVar15);
        if (uVar12 != uVar15) goto LAB_001950ac;
      }
      else {
        iVar11 = 1;
LAB_001950ac:
        uVar9 = uVar12 - uVar15 >> 2;
        if (uVar9 != 0) {
          pcVar14 = param_4 + uVar15 + 1;
          if (uVar9 < 9) {
            uVar13 = 0;
          }
          else {
            uVar13 = 0;
            pcVar5 = pcVar14;
            do {
              pcVar14 = pcVar5 + 0x20;
              uVar7 = uVar13 + 9;
              uVar13 = uVar13 + 8;
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
              pcVar5 = pcVar14;
            } while (uVar7 < uVar9 - 7);
          }
          do {
            uVar13 = uVar13 + 1;
            pcVar14[0] = '\0';
            pcVar14[1] = '\0';
            pcVar14[2] = '\0';
            pcVar14[3] = '\0';
            pcVar14 = pcVar14 + 4;
          } while (uVar13 < uVar9);
          iVar11 = iVar11 + uVar9 * 4;
          uVar8 = uVar8 + uVar9 * -4;
          if (uVar12 - uVar15 == uVar9 * 4) goto LAB_001951b8;
        }
        if (0x1f < uVar8 - 1) {
          pcVar14 = param_4 + iVar11;
          do {
            uVar15 = uVar8 - 0x21;
            uVar8 = uVar8 - 0x20;
            param_4[iVar11] = '\0';
            HintPreloadData(param_4 + iVar11 + 0x22);
            pcVar14[1] = '\0';
            pcVar14[2] = '\0';
            iVar11 = iVar11 + 0x20;
            pcVar14[3] = '\0';
            pcVar14[4] = '\0';
            pcVar14[5] = '\0';
            pcVar14[6] = '\0';
            pcVar14[7] = '\0';
            pcVar14[8] = '\0';
            pcVar14[9] = '\0';
            pcVar14[10] = '\0';
            pcVar14[0xb] = '\0';
            pcVar14[0xc] = '\0';
            pcVar14[0xd] = '\0';
            pcVar14[0xe] = '\0';
            pcVar14[0xf] = '\0';
            pcVar14[0x10] = '\0';
            pcVar14[0x11] = '\0';
            pcVar14[0x12] = '\0';
            pcVar14[0x13] = '\0';
            pcVar14[0x14] = '\0';
            pcVar14[0x15] = '\0';
            pcVar14[0x16] = '\0';
            pcVar14[0x17] = '\0';
            pcVar14[0x18] = '\0';
            pcVar14[0x19] = '\0';
            pcVar14[0x1a] = '\0';
            pcVar14[0x1b] = '\0';
            pcVar14[0x1c] = '\0';
            pcVar14[0x1d] = '\0';
            pcVar14[0x1e] = '\0';
            pcVar14[0x1f] = '\0';
            pcVar14 = pcVar14 + 0x20;
          } while (0x1f < uVar15);
        }
        pcVar14 = param_4 + iVar11;
        do {
          pcVar5 = pcVar14 + 1;
          *pcVar14 = '\0';
          pcVar14 = pcVar5;
        } while (pcVar5 != param_4 + uVar8 + iVar11);
      }
LAB_001951b8:
      iVar11 = uVar12 + 1;
    }
    iVar1 = BN_bn2bin(a,(uchar *)(param_4 + iVar11));
    uVar12 = uVar10 + 1;
    if (uVar12 == iVar1 + iVar11) {
      if ((param_3 & 0xfffffffd) == 4) {
        iVar1 = BN_num_bits(a_00);
        iVar11 = iVar1 + 0xe;
        if (-1 < iVar1 + 7) {
          iVar11 = iVar1 + 7;
        }
        uVar15 = uVar10 - (iVar11 >> 3);
        if (uVar10 < uVar15) {
          iVar11 = 0x106;
          goto LAB_001951e4;
        }
        if (uVar15 != 0) {
          pcVar14 = param_4 + uVar10;
          uVar8 = ~(uint)pcVar14 & 3;
          if (uVar15 < (~(uint)pcVar14 & 3)) {
            uVar8 = uVar15;
          }
          pcVar5 = pcVar14;
          uVar9 = uVar12;
          uVar13 = uVar15;
          uVar7 = uVar15;
          if ((uVar15 < 4) || (uVar7 = uVar8, uVar8 != 0)) {
            do {
              uVar8 = uVar7;
              uVar4 = uVar9 - uVar10;
              uVar9 = uVar9 + 1;
              pcVar5[1] = '\0';
              uVar13 = uVar13 - 1;
              pcVar5 = pcVar5 + 1;
              uVar7 = uVar8;
            } while (uVar4 < uVar8);
            if (uVar15 != uVar8) goto LAB_00195304;
          }
          else {
LAB_00195304:
            uVar10 = uVar15 - uVar8 >> 2;
            if (uVar10 != 0) {
              pcVar14 = pcVar14 + uVar8 + 1;
              if (uVar10 < 9) {
                uVar7 = 0;
              }
              else {
                uVar7 = 0;
                pcVar5 = pcVar14;
                do {
                  pcVar14 = pcVar5 + 0x20;
                  uVar4 = uVar7 + 9;
                  uVar7 = uVar7 + 8;
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
                  pcVar5 = pcVar14;
                } while (uVar4 < uVar10 - 7);
              }
              do {
                uVar7 = uVar7 + 1;
                pcVar14[0] = '\0';
                pcVar14[1] = '\0';
                pcVar14[2] = '\0';
                pcVar14[3] = '\0';
                pcVar14 = pcVar14 + 4;
              } while (uVar7 < uVar10);
              uVar9 = uVar9 + uVar10 * 4;
              uVar13 = uVar13 + uVar10 * -4;
              if (uVar15 - uVar8 == uVar10 * 4) goto LAB_00195404;
            }
            if (0x1f < uVar13 - 1) {
              pcVar14 = param_4 + uVar9;
              do {
                uVar10 = uVar13 - 0x21;
                uVar13 = uVar13 - 0x20;
                param_4[uVar9] = '\0';
                HintPreloadData(param_4 + uVar9 + 0x22);
                pcVar14[1] = '\0';
                pcVar14[2] = '\0';
                uVar9 = uVar9 + 0x20;
                pcVar14[3] = '\0';
                pcVar14[4] = '\0';
                pcVar14[5] = '\0';
                pcVar14[6] = '\0';
                pcVar14[7] = '\0';
                pcVar14[8] = '\0';
                pcVar14[9] = '\0';
                pcVar14[10] = '\0';
                pcVar14[0xb] = '\0';
                pcVar14[0xc] = '\0';
                pcVar14[0xd] = '\0';
                pcVar14[0xe] = '\0';
                pcVar14[0xf] = '\0';
                pcVar14[0x10] = '\0';
                pcVar14[0x11] = '\0';
                pcVar14[0x12] = '\0';
                pcVar14[0x13] = '\0';
                pcVar14[0x14] = '\0';
                pcVar14[0x15] = '\0';
                pcVar14[0x16] = '\0';
                pcVar14[0x17] = '\0';
                pcVar14[0x18] = '\0';
                pcVar14[0x19] = '\0';
                pcVar14[0x1a] = '\0';
                pcVar14[0x1b] = '\0';
                pcVar14[0x1c] = '\0';
                pcVar14[0x1d] = '\0';
                pcVar14[0x1e] = '\0';
                pcVar14[0x1f] = '\0';
                pcVar14 = pcVar14 + 0x20;
              } while (0x1f < uVar10);
            }
            pcVar14 = param_4 + uVar9;
            do {
              pcVar5 = pcVar14 + 1;
              *pcVar14 = '\0';
              pcVar14 = pcVar5;
            } while (pcVar5 != param_4 + uVar9 + uVar13);
          }
LAB_00195404:
          uVar12 = uVar12 + uVar15;
        }
        iVar11 = BN_bn2bin(a_00,(uchar *)(param_4 + uVar12));
        uVar12 = uVar12 + iVar11;
      }
      if (uVar12 == uVar6) {
        BN_CTX_end(param_6);
        if (c != (BN_CTX *)0x0) {
          BN_CTX_free(c);
          return uVar6;
        }
        return uVar6;
      }
      iVar11 = 0x112;
    }
    else {
      iVar11 = 0xfe;
    }
  }
LAB_001951e4:
  ERR_put_error(0x10,0xa1,0x44,"ec2_oct.c",iVar11);
LAB_001951f2:
  BN_CTX_end(param_6);
  if (c == (BN_CTX *)0x0) {
    return 0;
  }
  BN_CTX_free(c);
  return 0;
}

