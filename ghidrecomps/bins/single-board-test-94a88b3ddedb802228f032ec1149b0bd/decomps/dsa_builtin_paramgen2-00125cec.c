
undefined4
dsa_builtin_paramgen2
          (int param_1,int param_2,uint param_3,EVP_MD *param_4,void *param_5,size_t param_6,
          int param_7,void *param_8,int *param_9,uint *param_10,BN_GENCB *param_11)

{
  uint uVar1;
  size_t len;
  uchar *buf;
  BN_CTX *ctx;
  BIGNUM *pBVar2;
  BIGNUM *r;
  BIGNUM *pBVar3;
  BIGNUM *a;
  BIGNUM *rem;
  BIGNUM *r_00;
  int iVar4;
  BIGNUM *pBVar5;
  int iVar6;
  void *__dest;
  int n;
  void *do_trial_division;
  uchar uVar7;
  byte *s;
  int iVar8;
  undefined4 uVar9;
  BIGNUM *ret;
  int iVar10;
  int iVar11;
  BIGNUM *r_01;
  int iVar12;
  bool bVar13;
  BN_MONT_CTX *local_e0;
  int local_d8;
  uint local_d4;
  EVP_MD_CTX EStack_80;
  byte local_68 [68];
  
  EVP_MD_CTX_init(&EStack_80);
  if (param_4 == (EVP_MD *)0x0) {
    if (param_3 == 0xa0) {
      param_4 = EVP_sha1();
    }
    else if (param_3 == 0xe0) {
      param_4 = EVP_sha224();
    }
    else {
      param_4 = EVP_sha256();
    }
  }
  len = EVP_MD_size(param_4);
  if (((*(int *)(param_1 + 0xc) == 0) || (*(int *)(param_1 + 0x10) == 0)) || (-1 < param_7)) {
    if (param_6 == 0) {
      param_6 = len;
    }
    buf = (uchar *)CRYPTO_malloc(param_6,DAT_00125f80,0x1c2);
    __dest = param_8;
    if (param_8 == (void *)0x0) {
      __dest = CRYPTO_malloc(param_6,DAT_00126398,0x1c7);
    }
    if (buf == (uchar *)0x0 || __dest == (void *)0x0) {
      ctx = (BN_CTX *)0x0;
      uVar9 = 0xffffffff;
      local_e0 = (BN_MONT_CTX *)0x0;
      goto LAB_00125dea;
    }
    if (param_5 != (void *)0x0) {
      memcpy(buf,param_5,param_6);
    }
    ctx = BN_CTX_new();
  }
  else {
    __dest = (void *)0x0;
    ctx = BN_CTX_new();
    buf = (uchar *)0x0;
  }
  if (ctx == (BN_CTX *)0x0) {
    uVar9 = 0xffffffff;
    local_e0 = (BN_MONT_CTX *)0x0;
    goto LAB_00125dea;
  }
  local_e0 = BN_MONT_CTX_new();
  if (local_e0 != (BN_MONT_CTX *)0x0) {
    BN_CTX_start(ctx);
    pBVar2 = BN_CTX_get(ctx);
    r = BN_CTX_get(ctx);
    pBVar3 = BN_CTX_get(ctx);
    a = BN_CTX_get(ctx);
    rem = BN_CTX_get(ctx);
    r_00 = BN_CTX_get(ctx);
    r_01 = *(BIGNUM **)(param_1 + 0xc);
    if ((r_01 == (BIGNUM *)0x0) || (ret = *(BIGNUM **)(param_1 + 0x10), ret == (BIGNUM *)0x0)) {
      n = param_2 + -1;
      r_01 = BN_CTX_get(ctx);
      ret = BN_CTX_get(ctx);
      pBVar5 = BN_value_one();
      iVar4 = BN_lshift(r_00,pBVar5,n);
      if (iVar4 != 0) {
        param_3 = param_3 >> 3;
        iVar12 = param_6 - 1;
        iVar4 = 0;
        do_trial_division = param_5;
        if (param_5 != (void *)0x0) {
          do_trial_division = (void *)0x1;
        }
        do {
          while( true ) {
            iVar6 = BN_GENCB_call(param_11,0,iVar4);
            if (((iVar6 == 0) ||
                ((param_5 == (void *)0x0 && (iVar6 = RAND_pseudo_bytes(buf,param_6), iVar6 < 0))))
               || (iVar6 = EVP_Digest(buf,param_6,local_68,(uint *)0x0,param_4,(ENGINE *)0x0),
                  iVar6 == 0)) goto LAB_00125de6;
            s = local_68 + (len - param_3);
            if (((int)len <= (int)param_3) && (s = local_68, (int)len < (int)param_3)) {
              memset(local_68 + len,0,param_3 - len);
              s = local_68;
            }
            *s = *s | 0x80;
            s[param_3 - 1] = s[param_3 - 1] | 1;
            pBVar5 = BN_bin2bn(s,param_3,ret);
            if (pBVar5 == (BIGNUM *)0x0) goto LAB_00125de6;
            iVar6 = BN_is_prime_fasttest_ex(ret,0x32,ctx,(int)do_trial_division,param_11);
            if (iVar6 < 1) break;
            if (param_8 != (void *)0x0) {
              memcpy(param_8,buf,param_6);
            }
            iVar6 = BN_GENCB_call(param_11,2,0);
            if ((iVar6 == 0) || (iVar6 = BN_GENCB_call(param_11,3,0), iVar6 == 0))
            goto LAB_00125de6;
            iVar6 = __aeabi_uidiv(n,len * 8);
            local_d8 = 0;
            while( true ) {
              BN_set_word(pBVar3,0);
              if (-1 < iVar6) {
                iVar10 = 0;
                iVar11 = 0;
                do {
                  if (-1 < iVar12) {
                    uVar7 = buf[iVar12] + '\x01';
                    buf[iVar12] = uVar7;
                    iVar8 = iVar12;
                    while ((uVar7 == '\0' && (bVar13 = iVar8 != 0, iVar8 = iVar8 + -1, bVar13))) {
                      uVar7 = buf[iVar8] + '\x01';
                      buf[iVar8] = uVar7;
                    }
                  }
                  iVar8 = EVP_Digest(buf,param_6,local_68,(uint *)0x0,param_4,(ENGINE *)0x0);
                  if ((iVar8 == 0) ||
                     (pBVar5 = BN_bin2bn(local_68,len,pBVar2), pBVar5 == (BIGNUM *)0x0))
                  goto LAB_00125de6;
                  iVar8 = BN_lshift(pBVar2,pBVar2,iVar10);
                  if (iVar8 == 0) {
                    uVar9 = 0xffffffff;
                    goto LAB_00125dea;
                  }
                  iVar8 = BN_add(pBVar3,pBVar3,pBVar2);
                  if (iVar8 == 0) goto LAB_00125de6;
                  iVar11 = iVar11 + 1;
                  iVar10 = iVar10 + len * 8;
                } while (iVar11 <= iVar6);
              }
              iVar10 = BN_mask_bits(pBVar3,n);
              if ((((iVar10 == 0) || (pBVar5 = BN_copy(a,pBVar3), pBVar5 == (BIGNUM *)0x0)) ||
                  (iVar10 = BN_add(a,a,r_00), iVar10 == 0)) ||
                 ((iVar10 = BN_lshift1(pBVar2,ret), iVar10 == 0 ||
                  (iVar10 = BN_div((BIGNUM *)0x0,rem,a,pBVar2,ctx), iVar10 == 0))))
              goto LAB_00125de6;
              pBVar5 = BN_value_one();
              iVar10 = BN_sub(pBVar2,rem,pBVar5);
              if ((iVar10 == 0) || (iVar10 = BN_sub(r_01,a,pBVar2), iVar10 == 0)) goto LAB_00125de6;
              iVar10 = BN_cmp(r_01,r_00);
              if (-1 < iVar10) {
                iVar10 = BN_is_prime_fasttest_ex(r_01,0x32,ctx,1,param_11);
                if (0 < iVar10) {
                  iVar4 = BN_GENCB_call(param_11,2,1);
                  if (iVar4 != 0) goto LAB_00125dd4;
                  goto LAB_00125de6;
                }
                if (iVar10 != 0) goto LAB_00125de6;
              }
              local_d8 = local_d8 + 1;
              if (param_2 << 2 <= local_d8) break;
              if ((local_d8 != 0) && (iVar10 = BN_GENCB_call(param_11,0,local_d8), iVar10 == 0))
              goto LAB_00125de6;
            }
            iVar4 = iVar4 + 1;
            if (do_trial_division != (void *)0x0) {
              uVar9 = 0;
              ERR_put_error(10,0x7e,0x70,DAT_00126398,0x26d);
              goto LAB_00125dea;
            }
          }
          if (iVar6 != 0) goto LAB_00125de6;
          iVar4 = iVar4 + 1;
        } while (do_trial_division == (void *)0x0);
        ERR_put_error(10,0x7e,0x71,DAT_00126398,0x214);
        uVar9 = 0;
        goto LAB_00125dea;
      }
    }
    else {
      if (param_7 < 0) {
        local_d8 = 0;
      }
      else {
        local_d8 = 0;
        memcpy(__dest,buf,param_6);
      }
LAB_00125dd4:
      pBVar3 = BN_value_one();
      iVar4 = BN_sub(r_00,r_01,pBVar3);
      if ((iVar4 != 0) && (iVar4 = BN_div(pBVar2,(BIGNUM *)0x0,r_00,ret,ctx), iVar4 != 0)) {
        if (param_7 < 0) {
          iVar4 = BN_set_word(r_00,2);
          if (iVar4 == 0) goto LAB_00125de6;
          local_d4 = 2;
        }
        else {
          local_d4 = 1;
        }
        iVar4 = BN_MONT_CTX_set(local_e0,r_01,ctx);
        while (uVar1 = local_d4, iVar4 != 0) {
          while( true ) {
            local_d4 = uVar1 + 1;
            if (-1 < param_7) {
              local_68[0] = (byte)param_7;
              local_68[2] = (byte)uVar1;
              local_68[1] = (byte)(uVar1 >> 8);
              iVar4 = EVP_DigestInit_ex(&EStack_80,param_4,(ENGINE *)0x0);
              if (((((iVar4 == 0) ||
                    (iVar4 = EVP_DigestUpdate(&EStack_80,__dest,param_6), iVar4 == 0)) ||
                   (iVar4 = EVP_DigestUpdate(&EStack_80,DAT_00125f84,4), iVar4 == 0)) ||
                  ((iVar4 = EVP_DigestUpdate(&EStack_80,local_68,3), iVar4 == 0 ||
                   (iVar4 = EVP_DigestFinal_ex(&EStack_80,local_68,(uint *)0x0), iVar4 == 0)))) ||
                 (pBVar3 = BN_bin2bn(local_68,len,r_00), pBVar3 == (BIGNUM *)0x0))
              goto LAB_00125de6;
            }
            iVar4 = BN_mod_exp_mont(r,r_00,pBVar2,r_01,ctx,local_e0);
            if (iVar4 == 0) goto LAB_00125de6;
            if (((r->top != 1) || (*r->d != 1)) || (r->neg != 0)) {
              iVar4 = BN_GENCB_call(param_11,3,1);
              if (iVar4 == 0) goto LAB_00125de6;
              pBVar2 = *(BIGNUM **)(param_1 + 0xc);
              if (r_01 != pBVar2) {
                if (pBVar2 != (BIGNUM *)0x0) {
                  BN_free(pBVar2);
                }
                pBVar2 = BN_dup(r_01);
                *(BIGNUM **)(param_1 + 0xc) = pBVar2;
              }
              pBVar2 = *(BIGNUM **)(param_1 + 0x10);
              if (ret != pBVar2) {
                if (pBVar2 != (BIGNUM *)0x0) {
                  BN_free(pBVar2);
                }
                pBVar2 = BN_dup(ret);
                *(BIGNUM **)(param_1 + 0x10) = pBVar2;
              }
              if (*(BIGNUM **)(param_1 + 0x14) != (BIGNUM *)0x0) {
                BN_free(*(BIGNUM **)(param_1 + 0x14));
              }
              pBVar2 = BN_dup(r);
              *(BIGNUM **)(param_1 + 0x14) = pBVar2;
              if (((*(int *)(param_1 + 0xc) == 0) || (*(int *)(param_1 + 0x10) == 0)) ||
                 (pBVar2 == (BIGNUM *)0x0)) goto LAB_00125de6;
              if (param_9 != (int *)0x0) {
                *param_9 = local_d8;
              }
              uVar9 = 1;
              if (param_10 != (uint *)0x0) {
                *param_10 = uVar1;
                uVar9 = 1;
              }
              goto LAB_00125dea;
            }
            if (param_7 < 0) break;
            uVar1 = local_d4;
            if (0xffff < local_d4) goto LAB_00125de6;
          }
          pBVar3 = BN_value_one();
          iVar4 = BN_add(r_00,r_00,pBVar3);
        }
      }
    }
  }
LAB_00125de6:
  uVar9 = 0xffffffff;
LAB_00125dea:
  if (buf != (uchar *)0x0) {
    CRYPTO_free(buf);
  }
  if (param_8 != __dest) {
    CRYPTO_free(__dest);
  }
  if (ctx != (BN_CTX *)0x0) {
    BN_CTX_end(ctx);
    BN_CTX_free(ctx);
  }
  if (local_e0 != (BN_MONT_CTX *)0x0) {
    BN_MONT_CTX_free(local_e0);
  }
  EVP_MD_CTX_cleanup(&EStack_80);
  return uVar9;
}

