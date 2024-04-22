
int BN_nist_mod_521(BIGNUM *r,BIGNUM *a,BIGNUM *p,BN_CTX *ctx)

{
  uint uVar1;
  ulong *puVar2;
  int iVar3;
  BIGNUM *pBVar4;
  int iVar5;
  ulong uVar6;
  ulong *puVar7;
  ulong *puVar8;
  uint *puVar9;
  ulong *rp;
  ulong *puVar10;
  int iVar11;
  int iVar12;
  uint local_6c [11];
  uint local_40;
  uint local_3c;
  uint local_38;
  uint local_34;
  uint local_30;
  uint local_2c;
  
  puVar10 = a->d;
  iVar11 = a->top;
  if ((a->neg != 0) || (iVar3 = BN_ucmp(a,DAT_001297c8), -1 < iVar3)) {
    iVar11 = BN_nnmod(r,a,DAT_001297cc,ctx);
    return iVar11;
  }
  iVar3 = BN_ucmp(DAT_001297cc,a);
  if (iVar3 == 0) {
    BN_set_word(r,0);
    return 1;
  }
  if (0 < iVar3) {
    if (r == a) {
      return 1;
    }
    pBVar4 = BN_copy(r,a);
    if (pBVar4 == (BIGNUM *)0x0) {
      return 0;
    }
    return 1;
  }
  rp = puVar10;
  if (r != a) {
    if ((r->dmax < 0x11) && (pBVar4 = bn_expand2(r,0x11), pBVar4 == (BIGNUM *)0x0)) {
      return 0;
    }
    rp = r->d;
    *rp = *puVar10;
    rp[1] = puVar10[1];
    rp[2] = puVar10[2];
    rp[3] = puVar10[3];
    rp[4] = puVar10[4];
    rp[5] = puVar10[5];
    rp[6] = puVar10[6];
    rp[7] = puVar10[7];
    rp[8] = puVar10[8];
    rp[9] = puVar10[9];
    rp[10] = puVar10[10];
    rp[0xb] = puVar10[0xb];
    rp[0xc] = puVar10[0xc];
    rp[0xd] = puVar10[0xd];
    rp[0xe] = puVar10[0xe];
    rp[0xf] = puVar10[0xf];
    rp[0x10] = puVar10[0x10];
  }
  iVar3 = iVar11 + -0x10;
  if (iVar3 < 1) {
    iVar3 = 0;
LAB_001298b8:
    puVar9 = local_6c + iVar3;
    iVar11 = (8U - iVar3 & 0xfffffff8) + iVar3;
    do {
      iVar3 = iVar3 + 8;
      HintPreloadData(puVar9 + 0x22);
      *puVar9 = 0;
      puVar9[1] = 0;
      puVar9[2] = 0;
      puVar9[3] = 0;
      puVar9[4] = 0;
      puVar9[5] = 0;
      puVar9[6] = 0;
      puVar9[7] = 0;
      puVar9 = puVar9 + 8;
    } while (iVar3 != iVar11 + 8);
  }
  else {
    if (iVar11 < 0x19) {
      iVar5 = 0;
    }
    else {
      puVar8 = puVar10 + 0x29;
      puVar7 = local_6c + 1;
      iVar5 = 0;
      do {
        iVar5 = iVar5 + 8;
        HintPreloadData(puVar8);
        puVar7[-1] = puVar8[-0x19];
        *puVar7 = puVar8[-0x18];
        puVar7[1] = puVar8[-0x17];
        puVar7[2] = puVar8[-0x16];
        puVar7[3] = puVar8[-0x15];
        puVar7[4] = puVar8[-0x14];
        puVar7[5] = puVar8[-0x13];
        puVar2 = puVar8 + -0x12;
        puVar8 = puVar8 + 8;
        puVar7[6] = *puVar2;
        puVar7 = puVar7 + 8;
      } while (iVar5 != (iVar11 - 0x19U & 0xfffffff8) + 8);
    }
    iVar12 = iVar5 * 4;
    iVar11 = 0;
    do {
      iVar5 = iVar5 + 1;
      *(undefined4 *)((int)local_6c + iVar11 + iVar12) =
           *(undefined4 *)((int)puVar10 + iVar11 + iVar12 + 0x40);
      iVar11 = iVar11 + 4;
    } while (iVar5 < iVar3);
    if (0x10 < iVar3) goto LAB_001298fa;
    if (iVar3 < 9) goto LAB_001298b8;
  }
  puVar9 = local_6c + iVar3 + -1;
  do {
    iVar3 = iVar3 + 1;
    puVar9 = puVar9 + 1;
    *puVar9 = 0;
  } while (iVar3 < 0x11);
LAB_001298fa:
  uVar1 = local_6c[2] << 0x17;
  local_6c[2] = local_6c[2] >> 9 | local_6c[3] << 0x17;
  local_6c[0] = local_6c[0] >> 9 | local_6c[1] << 0x17;
  local_6c[3] = local_6c[3] >> 9 | local_6c[4] << 0x17;
  local_6c[4] = local_6c[4] >> 9 | local_6c[5] << 0x17;
  local_6c[5] = local_6c[5] >> 9 | local_6c[6] << 0x17;
  local_6c[6] = local_6c[6] >> 9 | local_6c[7] << 0x17;
  local_6c[7] = local_6c[7] >> 9 | local_6c[8] << 0x17;
  local_6c[8] = local_6c[8] >> 9 | local_6c[9] << 0x17;
  local_6c[9] = local_6c[9] >> 9 | local_6c[10] << 0x17;
  local_6c[10] = local_6c[10] >> 9 | local_40 << 0x17;
  local_40 = local_40 >> 9 | local_3c << 0x17;
  local_3c = local_3c >> 9 | local_38 << 0x17;
  local_38 = local_38 >> 9 | local_34 << 0x17;
  local_34 = local_34 >> 9 | local_30 << 0x17;
  local_30 = local_30 >> 9 | local_2c << 0x17;
  local_2c = local_2c >> 9;
  rp[0x10] = rp[0x10] & 0x1ff;
  local_6c[1] = local_6c[1] >> 9 | uVar1;
  bn_add_words(rp,rp,local_6c,0x11);
  uVar6 = bn_sub_words(local_6c,rp,DAT_00129b28,0x11);
  puVar10 = (ulong *)((uint)local_6c & ~-uVar6 | -uVar6 & (uint)rp);
  *rp = *puVar10;
  rp[1] = puVar10[1];
  rp[2] = puVar10[2];
  rp[3] = puVar10[3];
  rp[4] = puVar10[4];
  rp[5] = puVar10[5];
  rp[6] = puVar10[6];
  rp[7] = puVar10[7];
  rp[8] = puVar10[8];
  rp[9] = puVar10[9];
  rp[10] = puVar10[10];
  rp[0xb] = puVar10[0xb];
  rp[0xc] = puVar10[0xc];
  rp[0xd] = puVar10[0xd];
  rp[0xe] = puVar10[0xe];
  rp[0xf] = puVar10[0xf];
  rp[0x10] = puVar10[0x10];
  puVar10 = r->d;
  r->top = 0x11;
  if (puVar10[0x10] == 0) {
    if (puVar10[0xf] == 0) {
      if (puVar10[0xe] == 0) {
        if (puVar10[0xd] == 0) {
          if (puVar10[0xc] == 0) {
            if (puVar10[0xb] == 0) {
              if (puVar10[10] == 0) {
                if (puVar10[9] == 0) {
                  if (puVar10[8] == 0) {
                    if (puVar10[7] == 0) {
                      if (puVar10[6] == 0) {
                        if (puVar10[5] == 0) {
                          if (puVar10[4] == 0) {
                            if (puVar10[3] == 0) {
                              if (puVar10[2] == 0) {
                                if (puVar10[1] == 0) {
                                  uVar6 = *puVar10;
                                  if (uVar6 != 0) {
                                    uVar6 = 1;
                                  }
                                }
                                else {
                                  uVar6 = 2;
                                }
                              }
                              else {
                                uVar6 = 3;
                              }
                            }
                            else {
                              uVar6 = 4;
                            }
                          }
                          else {
                            uVar6 = 5;
                          }
                        }
                        else {
                          uVar6 = 6;
                        }
                      }
                      else {
                        uVar6 = 7;
                      }
                    }
                    else {
                      uVar6 = 8;
                    }
                  }
                  else {
                    uVar6 = 9;
                  }
                }
                else {
                  uVar6 = 10;
                }
              }
              else {
                uVar6 = 0xb;
              }
            }
            else {
              uVar6 = 0xc;
            }
          }
          else {
            uVar6 = 0xd;
          }
        }
        else {
          uVar6 = 0xe;
        }
      }
      else {
        uVar6 = 0xf;
      }
    }
    else {
      uVar6 = 0x10;
    }
  }
  else {
    uVar6 = 0x11;
  }
  r->top = uVar6;
  return 1;
}

