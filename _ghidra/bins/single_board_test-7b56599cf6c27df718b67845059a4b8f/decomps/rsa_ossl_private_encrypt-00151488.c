
undefined4
rsa_ossl_private_encrypt(int param_1,uchar *param_2,undefined4 param_3,RSA *param_4,int param_5)

{
  BN_CTX *ctx;
  BIGNUM *ret;
  BIGNUM *r;
  int iVar1;
  BIGNUM *pBVar2;
  BN_MONT_CTX *pBVar3;
  undefined4 uVar4;
  int iVar5;
  BN_BLINDING *b;
  uchar *local_38;
  BIGNUM *local_34;
  
  ctx = BN_CTX_new();
  if (ctx == (BN_CTX *)0x0) {
    uVar4 = 0xffffffff;
    iVar5 = 0;
    local_38 = (uchar *)0x0;
    goto LAB_00151512;
  }
  BN_CTX_start(ctx);
  ret = BN_CTX_get(ctx);
  r = BN_CTX_get(ctx);
  iVar1 = BN_num_bits(param_4->n);
  iVar5 = iVar1 + 7;
  if (iVar1 + 7 < 0) {
    iVar5 = iVar1 + 0xe;
  }
  iVar5 = iVar5 >> 3;
  local_38 = (uchar *)CRYPTO_malloc(iVar5,"crypto/rsa/rsa_ossl.c",0xff);
  if (local_38 == (uchar *)0x0 || r == (BIGNUM *)0x0) {
    iVar1 = 0x101;
LAB_00151632:
    ERR_put_error(4,0x66,0x41,"crypto/rsa/rsa_ossl.c",iVar1);
  }
  else {
    if (param_5 == 3) {
      iVar1 = RSA_padding_add_none(local_38,iVar5,param_2,param_1);
    }
    else if (param_5 == 5) {
      iVar1 = RSA_padding_add_X931(local_38,iVar5,param_2,param_1);
    }
    else {
      if (param_5 != 1) {
        uVar4 = 0xffffffff;
        ERR_put_error(4,0x66,0x76,"crypto/rsa/rsa_ossl.c",0x111);
        goto LAB_00151512;
      }
      iVar1 = RSA_padding_add_PKCS1_type_1(local_38,iVar5,param_2,param_1);
    }
    if ((0 < iVar1) && (pBVar2 = BN_bin2bn(local_38,iVar5,ret), pBVar2 != (BIGNUM *)0x0)) {
      iVar1 = BN_ucmp(ret,param_4->n);
      if (-1 < iVar1) {
        uVar4 = 0xffffffff;
        ERR_put_error(4,0x66,0x84,"crypto/rsa/rsa_ossl.c",0x11d);
        goto LAB_00151512;
      }
      pBVar3 = param_4->_method_mod_n;
      if ((int)pBVar3 << 0x1e < 0) {
        pBVar3 = BN_MONT_CTX_set_locked(&param_4->_method_mod_p,param_4[1].version,param_4->n,ctx);
        if (pBVar3 == (BN_MONT_CTX *)0x0) goto LAB_0015163e;
        pBVar3 = param_4->_method_mod_n;
      }
      if ((int)pBVar3 << 0x18 < 0) {
        b = (BN_BLINDING *)0x0;
        local_34 = (BIGNUM *)0x0;
      }
      else {
        CRYPTO_THREAD_write_lock(param_4[1].version);
        b = param_4->mt_blinding;
        if (b == (BN_BLINDING *)0x0) {
          b = RSA_setup_blinding(param_4,ctx);
          param_4->mt_blinding = b;
          if (b != (BN_BLINDING *)0x0) goto LAB_0015166a;
          CRYPTO_THREAD_unlock(param_4[1].version);
LAB_00151722:
          uVar4 = 0xffffffff;
          ERR_put_error(4,0x66,0x44,"crypto/rsa/rsa_ossl.c",0x129);
          goto LAB_00151512;
        }
LAB_0015166a:
        iVar1 = BN_BLINDING_is_current_thread(b);
        if (iVar1 == 0) {
          b = (BN_BLINDING *)param_4[1].pad;
          if (b == (BN_BLINDING *)0x0) {
            b = RSA_setup_blinding(param_4,ctx);
            param_4[1].pad = (int)b;
            CRYPTO_THREAD_unlock(param_4[1].version);
            if (b == (BN_BLINDING *)0x0) goto LAB_00151722;
          }
          else {
            CRYPTO_THREAD_unlock(param_4[1].version);
          }
          local_34 = BN_CTX_get(ctx);
          if (local_34 == (BIGNUM *)0x0) {
            iVar1 = 0x130;
            goto LAB_00151632;
          }
          BN_BLINDING_lock(b);
          iVar1 = BN_BLINDING_convert_ex(ret,local_34,b,ctx);
          BN_BLINDING_unlock(b);
        }
        else {
          local_34 = (BIGNUM *)0x0;
          CRYPTO_THREAD_unlock(param_4[1].version);
          iVar1 = BN_BLINDING_convert_ex(ret,(BIGNUM *)0x0,b,ctx);
        }
        if (iVar1 == 0) goto LAB_0015163e;
        pBVar3 = param_4->_method_mod_n;
      }
      if ((((int)pBVar3 << 0x1a < 0) || (param_4->version == 1)) ||
         (((param_4->p != (BIGNUM *)0x0 &&
           (((param_4->q != (BIGNUM *)0x0 && (param_4->dmp1 != (BIGNUM *)0x0)) &&
            (param_4->dmq1 != (BIGNUM *)0x0)))) && (param_4->iqmp != (BIGNUM *)0x0)))) {
        iVar1 = (*param_4->meth->rsa_mod_exp)(r,ret,param_4,ctx);
        if (iVar1 == 0) goto LAB_0015163e;
      }
      else {
        pBVar2 = BN_new();
        if (pBVar2 == (BIGNUM *)0x0) {
          iVar1 = 0x141;
          goto LAB_00151632;
        }
        if (param_4->d == (BIGNUM *)0x0) {
          uVar4 = 0xffffffff;
          ERR_put_error(4,0x66,0xb3,"crypto/rsa/rsa_ossl.c",0x145);
          BN_free(pBVar2);
          goto LAB_00151512;
        }
        BN_with_flags(pBVar2,param_4->d,4);
        iVar1 = (*param_4->meth->bn_mod_exp)(r,ret,pBVar2,param_4->n,ctx,param_4->_method_mod_p);
        if (iVar1 == 0) {
          uVar4 = 0xffffffff;
          BN_free(pBVar2);
          goto LAB_00151512;
        }
        BN_free(pBVar2);
      }
      if ((b == (BN_BLINDING *)0x0) || (iVar1 = BN_BLINDING_invert_ex(r,local_34,b,ctx), iVar1 != 0)
         ) {
        if (param_5 == 5) {
          iVar1 = BN_sub(ret,param_4->n,r);
          if (iVar1 == 0) goto LAB_0015163e;
          iVar1 = BN_cmp(r,ret);
          if (0 < iVar1) {
            r = ret;
          }
        }
        uVar4 = BN_bn2binpad(r,param_3,iVar5);
        goto LAB_00151512;
      }
    }
  }
LAB_0015163e:
  uVar4 = 0xffffffff;
LAB_00151512:
  BN_CTX_end(ctx);
  BN_CTX_free(ctx);
  CRYPTO_clear_free(local_38,iVar5,"crypto/rsa/rsa_ossl.c",0x16b);
  return uVar4;
}

