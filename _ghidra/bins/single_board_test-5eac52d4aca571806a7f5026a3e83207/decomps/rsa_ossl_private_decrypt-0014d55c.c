
uint rsa_ossl_private_decrypt
               (int param_1,uchar *param_2,uchar *param_3,RSA *param_4,undefined4 param_5)

{
  BN_CTX *ctx;
  BIGNUM *ret;
  BIGNUM *r;
  int iVar1;
  int iVar2;
  uchar *f;
  BIGNUM *pBVar3;
  uint __n;
  BIGNUM *a;
  BN_MONT_CTX *pBVar4;
  BIGNUM *b;
  
  ctx = BN_CTX_new();
  if (ctx == (BN_CTX *)0x0) {
    __n = 0xffffffff;
    iVar2 = 0;
    f = (uchar *)0x0;
    goto LAB_0014d748;
  }
  BN_CTX_start(ctx);
  ret = BN_CTX_get(ctx);
  r = BN_CTX_get(ctx);
  iVar1 = BN_num_bits(param_4->n);
  iVar2 = iVar1 + 7;
  if (iVar1 + 7 < 0) {
    iVar2 = iVar1 + 0xe;
  }
  iVar2 = iVar2 >> 3;
  f = (uchar *)CRYPTO_malloc(iVar2,"crypto/rsa/rsa_ossl.c",0x185);
  b = (BIGNUM *)(uint)(f == (uchar *)0x0 || r == (BIGNUM *)0x0);
  if (f == (uchar *)0x0 || r == (BIGNUM *)0x0) {
    iVar1 = 0x187;
LAB_0014d7c8:
    ERR_put_error(4,0x65,0x41,"crypto/rsa/rsa_ossl.c",iVar1);
  }
  else {
    pBVar3 = BN_bin2bn(param_2,param_1,ret);
    if (pBVar3 != (BIGNUM *)0x0) {
      iVar1 = BN_ucmp(ret,param_4->n);
      if (-1 < iVar1) {
        ERR_put_error(4,0x65,0x84,"crypto/rsa/rsa_ossl.c",0x19b);
        __n = 0xffffffff;
        goto LAB_0014d748;
      }
      pBVar4 = param_4->_method_mod_n;
      pBVar3 = b;
      if (-1 < (int)pBVar4 << 0x18) {
        CRYPTO_THREAD_write_lock(param_4[1].version);
        b = (BIGNUM *)param_4->mt_blinding;
        if (b == (BIGNUM *)0x0) {
          b = (BIGNUM *)RSA_setup_blinding(param_4,ctx);
          param_4->mt_blinding = (BN_BLINDING *)b;
          if (b != (BIGNUM *)0x0) goto LAB_0014d6b4;
          CRYPTO_THREAD_unlock(param_4[1].version);
LAB_0014d82e:
          __n = 0xffffffff;
          ERR_put_error(4,0x65,0x44,"crypto/rsa/rsa_ossl.c",0x1a2);
          goto LAB_0014d748;
        }
LAB_0014d6b4:
        iVar1 = BN_BLINDING_is_current_thread(b);
        if (iVar1 == 0) {
          b = (BIGNUM *)param_4[1].pad;
          if (b == (BIGNUM *)0x0) {
            b = (BIGNUM *)RSA_setup_blinding(param_4,ctx);
            param_4[1].pad = (int)b;
            CRYPTO_THREAD_unlock(param_4[1].version);
            if (b == (BIGNUM *)0x0) goto LAB_0014d82e;
          }
          else {
            CRYPTO_THREAD_unlock(param_4[1].version);
          }
          pBVar3 = BN_CTX_get(ctx);
          if (pBVar3 == (BIGNUM *)0x0) {
            iVar1 = 0x1a9;
            goto LAB_0014d7c8;
          }
          BN_BLINDING_lock(b);
          iVar1 = BN_BLINDING_convert_ex(ret,pBVar3,(BN_BLINDING *)b,ctx);
          BN_BLINDING_unlock(b);
        }
        else {
          pBVar3 = (BIGNUM *)0x0;
          CRYPTO_THREAD_unlock(param_4[1].version);
          iVar1 = BN_BLINDING_convert_ex(ret,(BIGNUM *)0x0,(BN_BLINDING *)b,ctx);
        }
        if (iVar1 == 0) goto LAB_0014d7d4;
        pBVar4 = param_4->_method_mod_n;
      }
      if ((((int)pBVar4 << 0x1a < 0) || (param_4->version == 1)) ||
         ((param_4->p != (BIGNUM *)0x0 &&
          ((((param_4->q != (BIGNUM *)0x0 && (param_4->dmp1 != (BIGNUM *)0x0)) &&
            (param_4->dmq1 != (BIGNUM *)0x0)) && (param_4->iqmp != (BIGNUM *)0x0)))))) {
        iVar1 = (*param_4->meth->rsa_mod_exp)(r,ret,param_4,ctx);
        if (iVar1 == 0) goto LAB_0014d7d4;
      }
      else {
        a = BN_new();
        if (a == (BIGNUM *)0x0) {
          iVar1 = 0x1bb;
          goto LAB_0014d7c8;
        }
        if (param_4->d == (BIGNUM *)0x0) {
          __n = 0xffffffff;
          ERR_put_error(4,0x65,0xb3,"crypto/rsa/rsa_ossl.c",0x1bf);
          BN_free(a);
          goto LAB_0014d748;
        }
        BN_with_flags(a,param_4->d,4);
        if ((((int)param_4->_method_mod_n << 0x1e < 0) &&
            (pBVar4 = BN_MONT_CTX_set_locked
                                (&param_4->_method_mod_p,param_4[1].version,param_4->n,ctx),
            pBVar4 == (BN_MONT_CTX *)0x0)) ||
           (iVar1 = (*param_4->meth->bn_mod_exp)(r,ret,a,param_4->n,ctx,param_4->_method_mod_p),
           iVar1 == 0)) {
          __n = 0xffffffff;
          BN_free(a);
          goto LAB_0014d748;
        }
        BN_free(a);
      }
      if ((b == (BIGNUM *)0x0) ||
         (iVar1 = BN_BLINDING_invert_ex(r,pBVar3,(BN_BLINDING *)b,ctx), iVar1 != 0)) {
        __n = BN_bn2binpad(r,f,iVar2);
        switch(param_5) {
        case 1:
          __n = RSA_padding_check_PKCS1_type_2(param_3,iVar2,f,__n,iVar2);
          break;
        case 2:
          __n = RSA_padding_check_SSLv23(param_3,iVar2,f,__n,iVar2);
          break;
        case 3:
          memcpy(param_3,f,__n);
          break;
        case 4:
          __n = RSA_padding_check_PKCS1_OAEP(param_3,iVar2,f,__n,iVar2,(uchar *)0x0,0);
          break;
        default:
          __n = 0xffffffff;
          ERR_put_error(4,0x65,0x76,"crypto/rsa/rsa_ossl.c",0x1e8);
          goto LAB_0014d748;
        }
        ERR_put_error(4,0x65,0x72,"crypto/rsa/rsa_ossl.c",0x1eb);
        err_clear_last_constant_time(~__n >> 0x1f);
        goto LAB_0014d748;
      }
    }
  }
LAB_0014d7d4:
  __n = 0xffffffff;
LAB_0014d748:
  BN_CTX_end(ctx);
  BN_CTX_free(ctx);
  CRYPTO_clear_free(f,iVar2,"crypto/rsa/rsa_ossl.c",0x1f1);
  return __n;
}

