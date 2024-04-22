
DSA_SIG * dsa_do_sign(uchar *param_1,int param_2,DSA *param_3)

{
  bool bVar1;
  BIGNUM *ctx_in;
  int iVar2;
  int iVar3;
  BIGNUM *pBVar4;
  BIGNUM *pBVar5;
  DSA_SIG *pDVar6;
  BIGNUM *r;
  BIGNUM *local_58;
  BIGNUM *local_54;
  BIGNUM BStack_50;
  BIGNUM BStack_3c;
  
  pDVar6 = (DSA_SIG *)0x0;
  local_58 = (BIGNUM *)0x0;
  local_54 = (BIGNUM *)0x0;
  BN_init(&BStack_50);
  BN_init(&BStack_3c);
  r = param_3->p;
  if (((r == (BIGNUM *)0x0) || (r = param_3->q, r == (BIGNUM *)0x0)) ||
     (r = param_3->g, r == (BIGNUM *)0x0)) {
    iVar3 = 0x65;
    ctx_in = r;
LAB_000fe8d6:
    ERR_put_error(10,0x70,iVar3,DAT_000fe90c,0xd1);
    BN_free(local_54);
    BN_free(r);
    if (ctx_in == (BIGNUM *)0x0) {
      pDVar6 = (DSA_SIG *)0x0;
      goto LAB_000fe86a;
    }
    pDVar6 = (DSA_SIG *)0x0;
  }
  else {
    r = BN_new();
    if (r == (BIGNUM *)0x0) {
      iVar3 = 3;
      ctx_in = (BIGNUM *)0x0;
      goto LAB_000fe8d6;
    }
    ctx_in = (BIGNUM *)BN_CTX_new();
    if (ctx_in == (BIGNUM *)0x0) {
LAB_000fe8f6:
      iVar3 = 3;
      goto LAB_000fe8d6;
    }
    do {
      pBVar5 = param_3->kinv;
      if ((pBVar5 == (BIGNUM *)0x0) || (pBVar4 = param_3->r, pBVar4 == (BIGNUM *)0x0)) {
        iVar3 = DSA_sign_setup(param_3,(BN_CTX *)ctx_in,&local_58,&local_54);
        if (iVar3 != 0) {
          bVar1 = false;
          goto LAB_000fe7d8;
        }
LAB_000fe8b0:
        if (pDVar6 == (DSA_SIG *)0x0) {
          ERR_put_error(10,0x70,3,DAT_000fe90c,0xd1);
          BN_free(local_54);
          BN_free(r);
        }
        break;
      }
      bVar1 = true;
      param_3->kinv = (BIGNUM *)0x0;
      param_3->r = (BIGNUM *)0x0;
      local_58 = pBVar5;
      local_54 = pBVar4;
LAB_000fe7d8:
      iVar2 = BN_num_bits(param_3->q);
      iVar3 = iVar2 + 7;
      if (iVar2 + 7 < 0) {
        iVar3 = iVar2 + 0xe;
      }
      if (iVar3 >> 3 < param_2) {
        iVar3 = BN_num_bits(param_3->q);
        param_2 = iVar3 + 0xe;
        if (-1 < iVar3 + 7) {
          param_2 = iVar3 + 7;
        }
        param_2 = param_2 >> 3;
      }
      pBVar5 = BN_bin2bn(param_1,param_2,&BStack_50);
      if (((pBVar5 == (BIGNUM *)0x0) ||
          (iVar3 = BN_mod_mul(&BStack_3c,param_3->priv_key,local_54,param_3->q,(BN_CTX *)ctx_in),
          iVar3 == 0)) ||
         ((iVar3 = BN_add(r,&BStack_3c,&BStack_50), iVar3 == 0 ||
          (((iVar3 = BN_cmp(r,param_3->q), 0 < iVar3 && (iVar3 = BN_sub(r,r,param_3->q), iVar3 == 0)
            ) || (iVar3 = BN_mod_mul(r,r,local_58,param_3->q,(BN_CTX *)ctx_in), iVar3 == 0))))))
      goto LAB_000fe8b0;
      pDVar6 = DSA_SIG_new();
      if (pDVar6 == (DSA_SIG *)0x0) goto LAB_000fe8f6;
      if ((local_54->top != 0) && (r->top != 0)) {
        pDVar6->r = local_54;
        pDVar6->s = r;
        break;
      }
    } while (!bVar1);
  }
  BN_CTX_free((BN_CTX *)ctx_in);
LAB_000fe86a:
  BN_clear_free(&BStack_50);
  BN_clear_free(&BStack_3c);
  if (local_58 != (BIGNUM *)0x0) {
    BN_clear_free(local_58);
  }
  return pDVar6;
}

