
undefined4
dsa_builtin_paramgen2
          (int param_1,uint param_2,uint param_3,EVP_MD *param_4,void *param_5,size_t param_6,
          int param_7,BN_CTX *param_8,int *param_9,uint *param_10,BN_GENCB *param_11)

{
  EVP_MD_CTX *ctx;
  size_t len;
  BN_CTX *ctx_00;
  BIGNUM *pBVar1;
  BIGNUM *r;
  BIGNUM *pBVar2;
  BIGNUM *a;
  BIGNUM *rem;
  BIGNUM *r_00;
  int iVar3;
  BN_CTX *__dest;
  BIGNUM *pBVar4;
  int iVar5;
  BN_CTX *pBVar6;
  int n;
  int iVar7;
  BN_CTX BVar8;
  BN_CTX *buf;
  uint uVar9;
  byte *s;
  void *do_trial_division;
  undefined4 uVar10;
  BIGNUM *r_01;
  int iVar11;
  BIGNUM *ret;
  uint uVar12;
  int iVar13;
  bool bVar14;
  EVP_MD *local_c4;
  BN_MONT_CTX *local_c0;
  int local_b8;
  int local_88;
  byte local_68 [68];
  
  ctx = (EVP_MD_CTX *)EVP_MD_CTX_new();
  if (ctx == (EVP_MD_CTX *)0x0) {
    uVar10 = 0xffffffff;
    ctx_00 = (BN_CTX *)0x0;
    buf = (BN_CTX *)0x0;
    __dest = (BN_CTX *)0x0;
    local_c0 = (BN_MONT_CTX *)0x0;
    goto LAB_001a20bc;
  }
  if (param_2 <= param_3) {
    ctx_00 = (BN_CTX *)0x0;
    ERR_put_error(10,0x7e,0x70,"crypto/dsa/dsa_gen.c",0x14b);
    uVar10 = 0xffffffff;
    local_c0 = (BN_MONT_CTX *)0x0;
    buf = (BN_CTX *)0x0;
    __dest = ctx_00;
    goto LAB_001a20bc;
  }
  local_c4 = param_4;
  if (param_4 == (EVP_MD *)0x0) {
    if (param_3 == 0xa0) {
      local_c4 = EVP_sha1();
    }
    else if (param_3 == 0xe0) {
      local_c4 = EVP_sha224();
    }
    else {
      local_c4 = EVP_sha256();
    }
  }
  len = EVP_MD_size(local_c4);
  if (*(int *)(param_1 + 8) == 0) {
LAB_001a1fe8:
    if (param_6 == 0) {
      param_6 = len;
    }
    buf = (BN_CTX *)CRYPTO_malloc(param_6,"crypto/dsa/dsa_gen.c",0x15e);
    __dest = param_8;
    if (param_8 == (BN_CTX *)0x0) {
      __dest = (BN_CTX *)CRYPTO_malloc(param_6,"crypto/dsa/dsa_gen.c",0x163);
    }
    if (__dest == (BN_CTX *)0x0 || buf == (BN_CTX *)0x0) {
      ctx_00 = (BN_CTX *)0x0;
      uVar10 = 0xffffffff;
      local_c0 = (BN_MONT_CTX *)0x0;
      goto LAB_001a20bc;
    }
    if (param_5 != (void *)0x0) {
      memcpy(buf,param_5,param_6);
    }
    ctx_00 = BN_CTX_new();
  }
  else {
    iVar3 = *(int *)(param_1 + 0xc);
    if (*(int *)(param_1 + 0xc) != 0) {
      iVar3 = param_7;
    }
    if (-1 < iVar3) goto LAB_001a1fe8;
    buf = (BN_CTX *)0x0;
    ctx_00 = BN_CTX_new();
    __dest = buf;
  }
  if (ctx_00 == (BN_CTX *)0x0) {
    uVar10 = 0xffffffff;
    local_c0 = (BN_MONT_CTX *)0x0;
    goto LAB_001a20bc;
  }
  local_c0 = BN_MONT_CTX_new();
  if (local_c0 != (BN_MONT_CTX *)0x0) {
    BN_CTX_start(ctx_00);
    pBVar1 = BN_CTX_get(ctx_00);
    r = BN_CTX_get(ctx_00);
    pBVar2 = BN_CTX_get(ctx_00);
    a = BN_CTX_get(ctx_00);
    rem = BN_CTX_get(ctx_00);
    r_00 = BN_CTX_get(ctx_00);
    if (r_00 != (BIGNUM *)0x0) {
      r_01 = *(BIGNUM **)(param_1 + 8);
      if ((r_01 == (BIGNUM *)0x0) || (ret = *(BIGNUM **)(param_1 + 0xc), ret == (BIGNUM *)0x0)) {
        r_01 = BN_CTX_get(ctx_00);
        ret = BN_CTX_get(ctx_00);
        if (ret != (BIGNUM *)0x0) {
          n = param_2 - 1;
          pBVar4 = BN_value_one();
          iVar3 = BN_lshift(r_00,pBVar4,n);
          if (iVar3 != 0) {
            param_3 = param_3 >> 3;
            iVar3 = param_6 - 1;
            local_88 = 0;
LAB_001a22fe:
            iVar5 = BN_GENCB_call(param_11,0,local_88);
            if ((iVar5 != 0) &&
               (((param_5 != (void *)0x0 || (iVar5 = RAND_bytes((uchar *)buf,param_6), 0 < iVar5))
                && (iVar5 = EVP_Digest(buf,param_6,local_68,(uint *)0x0,local_c4,(ENGINE *)0x0),
                   iVar5 != 0)))) {
              s = local_68 + (len - param_3);
              if (((int)len <= (int)param_3) && (s = local_68, (int)len < (int)param_3)) {
                memset(local_68 + len,0,param_3 - len);
              }
              *s = *s | 0x80;
              s[param_3 - 1] = s[param_3 - 1] | 1;
              pBVar4 = BN_bin2bn(s,param_3,ret);
              if (pBVar4 != (BIGNUM *)0x0) {
                do_trial_division = param_5;
                if (param_5 != (void *)0x0) {
                  do_trial_division = (void *)0x1;
                }
                iVar5 = BN_is_prime_fasttest_ex(ret,0x40,ctx_00,(int)do_trial_division,param_11);
                if (iVar5 < 1) {
                  if (iVar5 == 0) {
                    if (param_5 == (void *)0x0) goto LAB_001a254e;
                    ERR_put_error(10,0x7e,0x71,"crypto/dsa/dsa_gen.c",0x1b4);
                    uVar10 = 0;
                    goto LAB_001a20bc;
                  }
                }
                else {
                  if (param_8 != (BN_CTX *)0x0) {
                    memcpy(param_8,buf,param_6);
                  }
                  iVar5 = BN_GENCB_call(param_11,2,0);
                  if ((iVar5 != 0) && (iVar5 = BN_GENCB_call(param_11,3,0), iVar5 != 0)) {
                    local_b8 = 0;
                    iVar5 = __aeabi_uidiv(n,len * 8);
                    do {
                      BN_set_word(pBVar2,0);
                      if (-1 < iVar5) {
                        iVar11 = 0;
                        iVar13 = 0;
                        do {
                          if ((-1 < iVar3) &&
                             (BVar8 = (BN_CTX)((char)buf[iVar3] + '\x01'), buf[iVar3] = BVar8,
                             BVar8 == (BN_CTX)0x0)) {
                            pBVar6 = buf + (param_6 - 2);
                            iVar7 = iVar3;
                            do {
                              bVar14 = iVar7 == 0;
                              iVar7 = iVar7 + -1;
                              if (bVar14) break;
                              BVar8 = *pBVar6;
                              *pBVar6 = (BN_CTX)((char)BVar8 + '\x01');
                              pBVar6 = pBVar6 + -1;
                            } while ((BN_CTX)((char)BVar8 + '\x01') == (BN_CTX)0x0);
                          }
                          iVar7 = EVP_Digest(buf,param_6,local_68,(uint *)0x0,local_c4,(ENGINE *)0x0
                                            );
                          if ((((iVar7 == 0) ||
                               (pBVar4 = BN_bin2bn(local_68,len,pBVar1), pBVar4 == (BIGNUM *)0x0))
                              || (iVar7 = BN_lshift(pBVar1,pBVar1,iVar11), iVar7 == 0)) ||
                             (iVar7 = BN_add(pBVar2,pBVar2,pBVar1), iVar7 == 0)) goto LAB_001a24f8;
                          iVar13 = iVar13 + 1;
                          iVar11 = iVar11 + len * 8;
                        } while (iVar13 <= iVar5);
                      }
                      iVar11 = BN_mask_bits(pBVar2,n);
                      if (((iVar11 == 0) || (pBVar4 = BN_copy(a,pBVar2), pBVar4 == (BIGNUM *)0x0))
                         || ((iVar11 = BN_add(a,a,r_00), iVar11 == 0 ||
                             ((iVar11 = BN_lshift1(pBVar1,ret), iVar11 == 0 ||
                              (iVar11 = BN_div((BIGNUM *)0x0,rem,a,pBVar1,ctx_00), iVar11 == 0))))))
                      break;
                      pBVar4 = BN_value_one();
                      iVar11 = BN_sub(pBVar1,rem,pBVar4);
                      if ((iVar11 == 0) || (iVar11 = BN_sub(r_01,a,pBVar1), iVar11 == 0)) break;
                      iVar11 = BN_cmp(r_01,r_00);
                      if (-1 < iVar11) {
                        iVar11 = BN_is_prime_fasttest_ex(r_01,0x40,ctx_00,1,param_11);
                        if (0 < iVar11) {
                          iVar3 = BN_GENCB_call(param_11,2,1);
                          if (iVar3 == 0) goto LAB_001a20b8;
                          goto LAB_001a20a6;
                        }
                        if (iVar11 != 0) break;
                      }
                      local_b8 = local_b8 + 1;
                      if ((int)(param_2 << 2) <= local_b8) goto LAB_001a25ec;
                      iVar11 = BN_GENCB_call(param_11,0,local_b8);
                      if (iVar11 == 0) break;
                    } while( true );
                  }
                }
              }
            }
LAB_001a24f8:
            uVar10 = 0xffffffff;
            goto LAB_001a20bc;
          }
        }
      }
      else {
        if (param_7 < 0) {
          local_b8 = 0;
        }
        else {
          local_b8 = 0;
          memcpy(__dest,buf,param_6);
        }
LAB_001a20a6:
        pBVar2 = BN_value_one();
        iVar3 = BN_sub(r_00,r_01,pBVar2);
        if ((iVar3 != 0) && (iVar3 = BN_div(pBVar1,(BIGNUM *)0x0,r_00,ret,ctx_00), iVar3 != 0)) {
          if (param_7 < 0) {
            iVar3 = BN_set_word(r_00,2);
            uVar9 = 2;
            if (iVar3 == 0) goto LAB_001a20b8;
          }
          else {
            uVar9 = 1;
          }
          iVar3 = BN_MONT_CTX_set(local_c0,r_01,ctx_00);
          if (iVar3 != 0) {
            do {
              while( true ) {
                uVar12 = uVar9 + 1;
                if (-1 < param_7) {
                  local_68[2] = (byte)uVar9;
                  local_68[0] = (byte)param_7;
                  local_68[1] = (byte)(uVar9 >> 8);
                  iVar3 = EVP_DigestInit_ex(ctx,local_c4,(ENGINE *)0x0);
                  if (((iVar3 == 0) || (iVar3 = EVP_DigestUpdate(ctx,__dest,param_6), iVar3 == 0))
                     || (iVar3 = EVP_DigestUpdate(ctx,"ggencrypto/dsa/dsa_gen.c",4), iVar3 == 0))
                  goto LAB_001a226e;
                  iVar3 = EVP_DigestUpdate(ctx,local_68,3);
                  if (((iVar3 == 0) ||
                      (iVar3 = EVP_DigestFinal_ex(ctx,local_68,(uint *)0x0), iVar3 == 0)) ||
                     (pBVar2 = BN_bin2bn(local_68,len,r_00), pBVar2 == (BIGNUM *)0x0))
                  goto LAB_001a226e;
                }
                iVar3 = BN_mod_exp_mont(r,r_00,pBVar1,r_01,ctx_00,local_c0);
                if (iVar3 == 0) goto LAB_001a226e;
                iVar3 = BN_is_one(r);
                if (iVar3 == 0) {
                  iVar3 = BN_GENCB_call(param_11,3,1);
                  if (iVar3 == 0) goto LAB_001a20b8;
                  if (r_01 != *(BIGNUM **)(param_1 + 8)) {
                    BN_free(*(BIGNUM **)(param_1 + 8));
                    pBVar1 = BN_dup(r_01);
                    *(BIGNUM **)(param_1 + 8) = pBVar1;
                  }
                  if (ret != *(BIGNUM **)(param_1 + 0xc)) {
                    BN_free(*(BIGNUM **)(param_1 + 0xc));
                    pBVar1 = BN_dup(ret);
                    *(BIGNUM **)(param_1 + 0xc) = pBVar1;
                  }
                  BN_free(*(BIGNUM **)(param_1 + 0x10));
                  pBVar1 = BN_dup(r);
                  *(BIGNUM **)(param_1 + 0x10) = pBVar1;
                  if ((*(int *)(param_1 + 8) == 0) ||
                     (pBVar1 == (BIGNUM *)0x0 || *(int *)(param_1 + 0xc) == 0)) goto LAB_001a20b8;
                  if (param_9 != (int *)0x0) {
                    *param_9 = local_b8;
                  }
                  uVar10 = 1;
                  if (param_10 != (uint *)0x0) {
                    uVar10 = 1;
                    *param_10 = uVar9;
                  }
                  goto LAB_001a20bc;
                }
                uVar9 = uVar12;
                if (-1 < param_7) break;
                pBVar2 = BN_value_one();
                iVar3 = BN_add(r_00,r_00,pBVar2);
                if (iVar3 == 0) goto LAB_001a226e;
              }
            } while (uVar12 < 0x10000);
LAB_001a226e:
            uVar10 = 0xffffffff;
            goto LAB_001a20bc;
          }
        }
      }
    }
  }
LAB_001a20b8:
  uVar10 = 0xffffffff;
LAB_001a20bc:
  CRYPTO_free(buf);
  if (param_8 != __dest) {
    CRYPTO_free(__dest);
  }
  BN_CTX_end(ctx_00);
  BN_CTX_free(ctx_00);
  BN_MONT_CTX_free(local_c0);
  EVP_MD_CTX_free(ctx);
  return uVar10;
LAB_001a25ec:
  if (param_5 != (void *)0x0) {
    uVar10 = 0;
    ERR_put_error(10,0x7e,0x70,"crypto/dsa/dsa_gen.c",0x20d);
    goto LAB_001a20bc;
  }
LAB_001a254e:
  local_88 = local_88 + 1;
  goto LAB_001a22fe;
}

