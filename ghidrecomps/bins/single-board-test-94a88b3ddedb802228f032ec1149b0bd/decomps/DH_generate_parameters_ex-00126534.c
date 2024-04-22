
int DH_generate_parameters_ex(DH *dh,int prime_len,int generator,BN_GENCB *cb)

{
  int iVar1;
  BN_CTX *ctx;
  BIGNUM *a;
  BIGNUM *a_00;
  BIGNUM *pBVar2;
  _func_1848 *p_Var3;
  
  p_Var3 = dh->meth->generate_params;
  if (p_Var3 != (_func_1848 *)0x0) {
    iVar1 = (*p_Var3)(dh,prime_len,generator,cb);
    return iVar1;
  }
  ctx = BN_CTX_new();
  if (ctx != (BN_CTX *)0x0) {
    BN_CTX_start(ctx);
    a = BN_CTX_get(ctx);
    a_00 = BN_CTX_get(ctx);
    if (a != (BIGNUM *)0x0 && a_00 != (BIGNUM *)0x0) {
      if (dh->p == (BIGNUM *)0x0) {
        pBVar2 = BN_new();
        dh->p = pBVar2;
        if (pBVar2 == (BIGNUM *)0x0) goto LAB_001265f6;
      }
      if (dh->g == (BIGNUM *)0x0) {
        pBVar2 = BN_new();
        dh->g = pBVar2;
        if (pBVar2 == (BIGNUM *)0x0) goto LAB_001265f6;
      }
      if (generator < 2) {
        ERR_put_error(5,0x6a,0x65,DAT_00126664,0x91);
        ERR_put_error(5,0x6a,3,DAT_00126664,0xc3);
        iVar1 = 0;
        goto LAB_001265d4;
      }
      if (generator == 2) {
        iVar1 = BN_set_word(a,0x18);
        if (iVar1 != 0) {
          iVar1 = BN_set_word(a_00,0xb);
          goto joined_r0x00126624;
        }
      }
      else if (generator == 5) {
        iVar1 = BN_set_word(a,10);
        if (iVar1 != 0) {
          iVar1 = BN_set_word(a_00,3);
          goto joined_r0x00126624;
        }
      }
      else {
        iVar1 = BN_set_word(a,2);
        if (iVar1 != 0) {
          iVar1 = BN_set_word(a_00,1);
joined_r0x00126624:
          if ((((iVar1 != 0) &&
               (iVar1 = BN_generate_prime_ex(dh->p,prime_len,1,a,a_00,cb), iVar1 != 0)) &&
              (iVar1 = BN_GENCB_call(cb,3,0), iVar1 != 0)) &&
             (iVar1 = BN_set_word(dh->g,generator), iVar1 != 0)) {
            iVar1 = 1;
            goto LAB_001265d4;
          }
        }
      }
    }
  }
LAB_001265f6:
  ERR_put_error(5,0x6a,3,DAT_00126664,0xc3);
  iVar1 = 0;
  if (ctx == (BN_CTX *)0x0) {
    return 0;
  }
LAB_001265d4:
  BN_CTX_end(ctx);
  BN_CTX_free(ctx);
  return iVar1;
}

