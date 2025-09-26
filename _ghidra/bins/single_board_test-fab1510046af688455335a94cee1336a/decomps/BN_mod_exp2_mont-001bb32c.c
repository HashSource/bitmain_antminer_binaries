
int BN_mod_exp2_mont(BIGNUM *r,BIGNUM *a1,BIGNUM *p1,BIGNUM *a2,BIGNUM *p2,BIGNUM *m,BN_CTX *ctx,
                    BN_MONT_CTX *m_ctx)

{
  bool bVar1;
  int iVar2;
  int iVar3;
  BIGNUM *pBVar4;
  BIGNUM *r_00;
  BIGNUM *pBVar5;
  BIGNUM *rem;
  int iVar6;
  int iVar7;
  BIGNUM *b;
  int iVar8;
  BIGNUM **ppBVar9;
  uint uVar10;
  uint local_158;
  BN_MONT_CTX *local_150;
  int local_14c;
  int local_148;
  int local_144;
  int local_140;
  BIGNUM *local_128 [32];
  BIGNUM *local_a8 [33];
  
  if ((*m->d & 1) == 0) {
    ERR_put_error(3,0x76,0x66,"bn_exp2.c",0x8a);
    return 0;
  }
  iVar2 = BN_num_bits(p1);
  iVar3 = BN_num_bits(p2);
  if (iVar3 == 0 && iVar2 == 0) {
    iVar2 = BN_set_word(r,1);
    return iVar2;
  }
  BN_CTX_start(ctx);
  pBVar4 = BN_CTX_get(ctx);
  r_00 = BN_CTX_get(ctx);
  pBVar5 = BN_CTX_get(ctx);
  local_128[0] = pBVar5;
  rem = BN_CTX_get(ctx);
  local_a8[0] = rem;
  if (((pBVar4 == (BIGNUM *)0x0 || r_00 == (BIGNUM *)0x0) || (pBVar5 == (BIGNUM *)0x0)) ||
     (rem == (BIGNUM *)0x0)) {
LAB_001bb3de:
    iVar2 = 0;
    goto LAB_001bb3e0;
  }
  if (m_ctx == (BN_MONT_CTX *)0x0) {
    local_150 = BN_MONT_CTX_new();
    if (local_150 == (BN_MONT_CTX *)0x0) goto LAB_001bb3de;
    iVar6 = BN_MONT_CTX_set(local_150,m,ctx);
    if (iVar6 != 0) goto LAB_001bb3b0;
    iVar2 = 0;
  }
  else {
    local_150 = m_ctx;
LAB_001bb3b0:
    if (iVar2 < 0x2a0) {
      if (iVar2 < 0xf0) {
        if (iVar2 < 0x50) {
          if (iVar2 < 0x18) {
            local_148 = 1;
            local_14c = 1;
          }
          else {
            local_148 = 4;
            local_14c = 3;
          }
        }
        else {
          local_148 = 8;
          local_14c = 4;
        }
      }
      else {
        local_148 = 0x10;
        local_14c = 5;
      }
    }
    else {
      local_148 = 0x20;
      local_14c = 6;
    }
    if (iVar3 < 0x2a0) {
      if (iVar3 < 0xf0) {
        if (iVar3 < 0x50) {
          if (iVar3 < 0x18) {
            local_144 = 1;
            local_140 = 1;
          }
          else {
            local_144 = 4;
            local_140 = 3;
          }
        }
        else {
          local_144 = 8;
          local_140 = 4;
        }
      }
      else {
        local_144 = 0x10;
        local_140 = 5;
      }
    }
    else {
      local_144 = 0x20;
      local_140 = 6;
    }
    if (((a1->neg == 0) && (iVar6 = BN_ucmp(a1,m), iVar6 < 0)) ||
       (iVar6 = BN_div((BIGNUM *)0x0,pBVar5,a1,m,ctx), a1 = pBVar5, iVar6 != 0)) {
      pBVar5 = local_128[0];
      if (a1->top != 0) {
        b = &local_150->RR;
        iVar6 = BN_mod_mul_montgomery(local_128[0],a1,b,local_150,ctx);
        if (iVar6 != 0) {
          if (local_14c != 1) {
            iVar6 = BN_mod_mul_montgomery(pBVar4,pBVar5,pBVar5,local_150,ctx);
            if (iVar6 == 0) goto LAB_001bb550;
            if (local_148 != 1) {
              iVar6 = 1;
              ppBVar9 = local_128;
              do {
                iVar6 = iVar6 + 1;
                pBVar5 = BN_CTX_get(ctx);
                ppBVar9[1] = pBVar5;
                if ((pBVar5 == (BIGNUM *)0x0) ||
                   (iVar7 = BN_mod_mul_montgomery(pBVar5,*ppBVar9,pBVar4,local_150,ctx), iVar7 == 0)
                   ) goto LAB_001bb550;
                ppBVar9 = ppBVar9 + 1;
              } while (iVar6 != local_148);
            }
          }
          if (((a2->neg == 0) && (iVar6 = BN_ucmp(a2,m), iVar6 < 0)) ||
             (iVar6 = BN_div((BIGNUM *)0x0,rem,a2,m,ctx), a2 = rem, iVar6 != 0)) {
            pBVar5 = local_a8[0];
            if (a2->top == 0) goto LAB_001bb562;
            iVar6 = BN_mod_mul_montgomery(local_a8[0],a2,b,local_150,ctx);
            if (iVar6 != 0) {
              if (local_140 != 1) {
                iVar6 = BN_mod_mul_montgomery(pBVar4,pBVar5,pBVar5,local_150,ctx);
                if (iVar6 == 0) goto LAB_001bb550;
                if (local_144 != 1) {
                  iVar6 = 1;
                  ppBVar9 = local_a8;
                  do {
                    iVar6 = iVar6 + 1;
                    pBVar5 = BN_CTX_get(ctx);
                    ppBVar9[1] = pBVar5;
                    if ((pBVar5 == (BIGNUM *)0x0) ||
                       (iVar7 = BN_mod_mul_montgomery(pBVar5,*ppBVar9,pBVar4,local_150,ctx),
                       iVar7 == 0)) goto LAB_001bb550;
                    ppBVar9 = ppBVar9 + 1;
                  } while (iVar6 != local_144);
                }
              }
              pBVar4 = BN_value_one();
              iVar6 = BN_mod_mul_montgomery(r_00,pBVar4,b,local_150,ctx);
              if (iVar6 != 0) {
                if (iVar2 <= iVar3) {
                  iVar2 = iVar3;
                }
                if (0 < iVar2) {
                  iVar2 = iVar2 + -2;
                  iVar3 = 0;
                  uVar10 = 0;
                  local_148 = 0;
                  local_144 = 0;
                  bVar1 = true;
                  do {
                    iVar6 = iVar2 + 1;
                    if (uVar10 == 0) {
                      iVar7 = BN_is_bit_set(p1,iVar6);
                      if (iVar7 == 0) {
                        local_158 = 0;
                      }
                      else {
                        local_144 = (2 - local_14c) + iVar2;
                        while (iVar7 = BN_is_bit_set(p1,local_144), iVar7 == 0) {
                          local_144 = local_144 + 1;
                        }
                        if (iVar2 < local_144) {
                          uVar10 = 1;
                          local_158 = (uint)(iVar6 == local_144);
                        }
                        else {
                          uVar10 = 1;
                          iVar7 = iVar2;
                          do {
                            iVar8 = iVar7 + -1;
                            uVar10 = uVar10 * 2;
                            iVar7 = BN_is_bit_set(p1,iVar7);
                            if (iVar7 != 0) {
                              uVar10 = uVar10 + 1;
                            }
                            iVar7 = iVar8;
                          } while (local_144 <= iVar8);
                          local_158 = uVar10;
                          if (uVar10 != 0) {
                            local_158 = 1;
                          }
                          if (iVar6 != local_144) {
                            local_158 = 0;
                          }
                        }
                      }
                    }
                    else {
                      local_158 = (uint)(iVar6 == local_144);
                    }
                    if ((iVar3 == 0) && (iVar7 = BN_is_bit_set(p2,iVar6), iVar7 != 0)) {
                      local_148 = (2 - local_140) + iVar2;
                      while (iVar3 = BN_is_bit_set(p2,local_148), iVar3 == 0) {
                        local_148 = local_148 + 1;
                      }
                      if (iVar2 < local_148) {
                        iVar3 = 1;
                      }
                      else {
                        iVar3 = 1;
                        iVar7 = iVar2;
                        do {
                          iVar8 = iVar7 + -1;
                          iVar3 = iVar3 * 2;
                          iVar7 = BN_is_bit_set(p2,iVar7);
                          if (iVar7 != 0) {
                            iVar3 = iVar3 + 1;
                          }
                          iVar7 = iVar8;
                        } while (local_148 <= iVar8);
                      }
                    }
                    if (local_158 != 0) {
                      iVar7 = BN_mod_mul_montgomery
                                        (r_00,r_00,local_128[(int)uVar10 >> 1],local_150,ctx);
                      if (iVar7 == 0) goto LAB_001bb550;
                      uVar10 = 0;
                      bVar1 = false;
                    }
                    if (iVar3 == 0 || local_148 != iVar6) {
                      if (iVar2 == -1) break;
                      if (!bVar1) goto LAB_001bb770;
                    }
                    else {
                      iVar3 = BN_mod_mul_montgomery(r_00,r_00,local_a8[iVar3 >> 1],local_150,ctx);
                      if (iVar3 == 0) goto LAB_001bb550;
                      if (iVar2 == -1) break;
                      iVar3 = 0;
                      bVar1 = false;
LAB_001bb770:
                      iVar6 = BN_mod_mul_montgomery(r_00,r_00,r_00,local_150,ctx);
                      if (iVar6 == 0) goto LAB_001bb550;
                    }
                    iVar2 = iVar2 + -1;
                  } while( true );
                }
                iVar2 = BN_from_montgomery(r,r_00,local_150,ctx);
                if (iVar2 != 0) {
                  iVar2 = 1;
                }
                goto LAB_001bb552;
              }
            }
          }
        }
        goto LAB_001bb550;
      }
LAB_001bb562:
      BN_set_word(r,0);
      iVar2 = 1;
    }
    else {
LAB_001bb550:
      iVar2 = 0;
    }
LAB_001bb552:
    if (m_ctx != (BN_MONT_CTX *)0x0) goto LAB_001bb3e0;
  }
  BN_MONT_CTX_free(local_150);
LAB_001bb3e0:
  BN_CTX_end(ctx);
  return iVar2;
}

