
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
  BIGNUM *r_01;
  int iVar7;
  int iVar8;
  int iVar9;
  BIGNUM **ppBVar10;
  int n;
  int n_00;
  int n_01;
  BIGNUM *local_15c;
  BN_MONT_CTX *local_154;
  int local_144;
  int local_140;
  int local_13c;
  int local_138;
  BIGNUM *local_128 [32];
  BIGNUM *local_a8 [33];
  
  iVar2 = BN_is_odd(m);
  if (iVar2 == 0) {
    ERR_put_error(3,0x76,0x66,"crypto/bn/bn_exp2.c",0x24);
    return 0;
  }
  iVar3 = BN_num_bits(p1);
  iVar2 = BN_num_bits(p2);
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
  if (rem == (BIGNUM *)0x0) {
    r_01 = (BIGNUM *)0x0;
    local_154 = (BN_MONT_CTX *)0x0;
LAB_00194212:
    if (m_ctx != (BN_MONT_CTX *)0x0) goto LAB_00194218;
  }
  else {
    if (m_ctx != (BN_MONT_CTX *)0x0) {
      local_154 = m_ctx;
LAB_001940b2:
      if (iVar3 < 0x2a0) {
        if (iVar3 < 0xf0) {
          if (iVar3 < 0x50) {
            if (iVar3 < 0x18) {
              local_140 = 1;
              local_144 = 1;
            }
            else {
              local_140 = 4;
              local_144 = 3;
            }
          }
          else {
            local_140 = 8;
            local_144 = 4;
          }
        }
        else {
          local_140 = 0x10;
          local_144 = 5;
        }
      }
      else {
        local_140 = 0x20;
        local_144 = 6;
      }
      if (iVar2 < 0x2a0) {
        if (iVar2 < 0xf0) {
          if (iVar2 < 0x50) {
            if (iVar2 < 0x18) {
              local_138 = 1;
              local_13c = 1;
            }
            else {
              local_138 = 4;
              local_13c = 3;
            }
          }
          else {
            local_138 = 8;
            local_13c = 4;
          }
        }
        else {
          local_138 = 0x10;
          local_13c = 5;
        }
      }
      else {
        local_138 = 0x20;
        local_13c = 6;
      }
      if (((a1->neg == 0) && (iVar6 = BN_ucmp(a1,m), iVar6 < 0)) ||
         (r_01 = (BIGNUM *)BN_div((BIGNUM *)0x0,pBVar5,a1,m,ctx), a1 = pBVar5, r_01 != (BIGNUM *)0x0
         )) {
        iVar6 = BN_is_zero(a1);
        if (iVar6 == 0) {
          r_01 = (BIGNUM *)BN_to_montgomery(pBVar5,a1,local_154,ctx);
          if (r_01 != (BIGNUM *)0x0) {
            if (local_144 != 1) {
              r_01 = (BIGNUM *)BN_mod_mul_montgomery(pBVar4,pBVar5,pBVar5,local_154,ctx);
              if (r_01 == (BIGNUM *)0x0) goto LAB_00194212;
              iVar6 = 1;
              ppBVar10 = local_128;
              do {
                iVar6 = iVar6 + 1;
                r_01 = BN_CTX_get(ctx);
                ppBVar10[1] = r_01;
                if (r_01 == (BIGNUM *)0x0) goto LAB_00194212;
                pBVar5 = *ppBVar10;
                ppBVar10 = ppBVar10 + 1;
                r_01 = (BIGNUM *)BN_mod_mul_montgomery(r_01,pBVar5,pBVar4,local_154,ctx);
                if (r_01 == (BIGNUM *)0x0) goto LAB_00194212;
              } while (iVar6 < local_140);
            }
            if (((a2->neg == 0) && (iVar6 = BN_ucmp(a2,m), local_15c = a2, iVar6 < 0)) ||
               (r_01 = (BIGNUM *)BN_div((BIGNUM *)0x0,rem,a2,m,ctx), local_15c = rem,
               r_01 != (BIGNUM *)0x0)) {
              iVar6 = BN_is_zero(local_15c);
              if (iVar6 != 0) goto LAB_00194230;
              r_01 = (BIGNUM *)BN_to_montgomery(rem,local_15c,local_154,ctx);
              if (r_01 != (BIGNUM *)0x0) {
                if (local_13c != 1) {
                  r_01 = (BIGNUM *)BN_mod_mul_montgomery(pBVar4,rem,rem,local_154,ctx);
                  if (r_01 == (BIGNUM *)0x0) goto LAB_00194212;
                  ppBVar10 = local_a8;
                  iVar6 = 1;
                  do {
                    iVar6 = iVar6 + 1;
                    r_01 = BN_CTX_get(ctx);
                    ppBVar10[1] = r_01;
                    if (r_01 == (BIGNUM *)0x0) goto LAB_00194212;
                    pBVar5 = *ppBVar10;
                    ppBVar10 = ppBVar10 + 1;
                    r_01 = (BIGNUM *)BN_mod_mul_montgomery(r_01,pBVar5,pBVar4,local_154,ctx);
                    if (r_01 == (BIGNUM *)0x0) goto LAB_00194212;
                  } while (iVar6 < local_138);
                }
                pBVar4 = BN_value_one();
                r_01 = (BIGNUM *)BN_to_montgomery(r_00,pBVar4,local_154,ctx);
                if (r_01 != (BIGNUM *)0x0) {
                  if (iVar2 < iVar3) {
                    iVar2 = iVar3;
                  }
                  if (0 < iVar2) {
                    n = 0;
                    iVar2 = iVar2 + -2;
                    iVar6 = 0;
                    iVar3 = 0;
                    n_00 = 0;
                    bVar1 = true;
                    do {
                      n_01 = iVar2 + 1;
                      if (iVar3 == 0) {
                        iVar8 = BN_is_bit_set(p1,n_01);
                        if (iVar8 != 0) {
                          n = (2 - local_144) + iVar2;
                          while (iVar3 = BN_is_bit_set(p1,n), iVar3 == 0) {
                            n = n + 1;
                          }
                          iVar3 = 1;
                          if (n <= iVar2) {
                            iVar3 = 1;
                            iVar8 = iVar2;
                            do {
                              iVar7 = iVar8 + -1;
                              iVar3 = iVar3 * 2;
                              iVar8 = BN_is_bit_set(p1,iVar8);
                              if (iVar8 != 0) {
                                iVar3 = iVar3 + 1;
                              }
                              iVar8 = iVar7;
                            } while (n <= iVar7);
                          }
                          goto LAB_00194352;
                        }
                        if (iVar6 == 0) goto LAB_00194444;
                      }
                      else {
LAB_00194352:
                        if (iVar6 == 0) {
LAB_00194444:
                          iVar6 = BN_is_bit_set(p2,n_01);
                          if (iVar6 != 0) {
                            n_00 = (2 - local_13c) + iVar2;
                            while (iVar6 = BN_is_bit_set(p2,n_00), iVar6 == 0) {
                              n_00 = n_00 + 1;
                            }
                            iVar6 = 1;
                            iVar8 = iVar2;
                            while (n_00 <= iVar8) {
                              iVar9 = iVar8 + -1;
                              iVar6 = iVar6 * 2;
                              iVar7 = BN_is_bit_set(p2,iVar8);
                              iVar8 = iVar9;
                              if (iVar7 != 0) {
                                iVar6 = iVar6 + 1;
                              }
                            }
                          }
                        }
                        iVar8 = iVar3;
                        if (iVar3 != 0) {
                          iVar8 = 1;
                        }
                        if (n_01 != n) {
                          iVar8 = 0;
                        }
                        if (iVar8 != 0) {
                          r_01 = (BIGNUM *)
                                 BN_mod_mul_montgomery
                                           (r_00,r_00,local_128[iVar3 >> 1],local_154,ctx);
                          if (r_01 == (BIGNUM *)0x0) goto LAB_00194212;
                          iVar3 = 0;
                          bVar1 = false;
                        }
                      }
                      iVar8 = iVar6;
                      if (iVar6 != 0) {
                        iVar8 = 1;
                      }
                      if (n_01 != n_00) {
                        iVar8 = 0;
                      }
                      if (iVar8 == 0) {
                        if (iVar2 == -1) break;
                        if (!bVar1) goto LAB_00194400;
                        bVar1 = true;
                      }
                      else {
                        r_01 = (BIGNUM *)
                               BN_mod_mul_montgomery(r_00,r_00,local_a8[iVar6 >> 1],local_154,ctx);
                        if (r_01 == (BIGNUM *)0x0) goto LAB_00194212;
                        if (iVar2 == -1) break;
                        iVar6 = 0;
LAB_00194400:
                        r_01 = (BIGNUM *)BN_mod_mul_montgomery(r_00,r_00,r_00,local_154,ctx);
                        if (r_01 == (BIGNUM *)0x0) goto LAB_00194212;
                        bVar1 = false;
                      }
                      iVar2 = iVar2 + -1;
                    } while( true );
                  }
                  r_01 = (BIGNUM *)BN_from_montgomery(r,r_00,local_154,ctx);
                  if (r_01 != (BIGNUM *)0x0) {
                    r_01 = (BIGNUM *)0x1;
                  }
                }
              }
            }
          }
        }
        else {
LAB_00194230:
          BN_set_word(r,0);
          r_01 = (BIGNUM *)0x1;
        }
      }
      goto LAB_00194212;
    }
    local_154 = BN_MONT_CTX_new();
    if ((local_154 != (BN_MONT_CTX *)0x0) && (iVar6 = BN_MONT_CTX_set(local_154,m,ctx), iVar6 != 0))
    goto LAB_001940b2;
    r_01 = (BIGNUM *)0x0;
  }
  BN_MONT_CTX_free(local_154);
LAB_00194218:
  BN_CTX_end(ctx);
  return (int)r_01;
}

