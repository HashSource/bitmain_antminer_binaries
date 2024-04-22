
DSA_SIG * gost_do_sign(int param_1,undefined4 param_2,int param_3)

{
  uchar *puVar1;
  uchar *s;
  BIGNUM *a;
  BN_CTX *ctx;
  DSA_SIG *a_00;
  BIGNUM *rem;
  BIGNUM *rnd;
  BIGNUM *r;
  int len;
  BIGNUM *pBVar2;
  uchar local_40 [32];
  
  puVar1 = (uchar *)(param_1 + -1);
  s = &stack0xffffffe0;
  do {
    puVar1 = puVar1 + 1;
    s = s + -1;
    *s = *puVar1;
  } while (s != local_40);
  if (local_40[0] == '\0') {
    s = local_40;
    len = 0x20;
    do {
      s = s + 1;
      len = len + -1;
      if (*s != '\0') {
        if (len != 0) goto LAB_000dfff8;
        break;
      }
    } while (len != 0);
    a = BN_new();
    BN_set_word(a,0);
  }
  else {
    len = 0x20;
LAB_000dfff8:
    a = BN_bin2bn(s,len,(BIGNUM *)0x0);
  }
  ctx = BN_CTX_new();
  if (ctx == (BN_CTX *)0x0) {
    ERR_GOST_error(0x70,0x41,DAT_000e0174,0x3d);
    BN_free(a);
    a_00 = (DSA_SIG *)0x0;
  }
  else {
    BN_CTX_start(ctx);
    a_00 = DSA_SIG_new();
    if (a_00 == (DSA_SIG *)0x0) {
      ERR_GOST_error(0x70,0x76,DAT_000e0174,0x43);
    }
    else {
      rem = BN_CTX_get(ctx);
      rnd = BN_CTX_get(ctx);
      r = BN_CTX_get(ctx);
      if ((rem == (BIGNUM *)0x0 || rnd == (BIGNUM *)0x0) || (r == (BIGNUM *)0x0)) {
        ERR_GOST_error(0x70,0x41,DAT_000e0174,0x4a);
LAB_000e00b0:
        BN_free(a);
        BN_CTX_end(ctx);
        BN_CTX_free(ctx);
        DSA_SIG_free(a_00);
        return (DSA_SIG *)0x0;
      }
      BN_div((BIGNUM *)0x0,rem,a,*(BIGNUM **)(param_3 + 0x10),ctx);
      if (rem->top == 0) {
        BN_set_word(a,1);
      }
      do {
        do {
          BN_rand_range(rnd,*(BIGNUM **)(param_3 + 0x10));
          BN_mod_exp(rem,*(BIGNUM **)(param_3 + 0x14),rnd,*(BIGNUM **)(param_3 + 0xc),ctx);
          pBVar2 = a_00->r;
          if (pBVar2 == (BIGNUM *)0x0) {
            pBVar2 = BN_new();
            a_00->r = pBVar2;
            if (pBVar2 == (BIGNUM *)0x0) {
              ERR_GOST_error(0x70,0x41,DAT_000e0174,0x5c);
              goto LAB_000e00b0;
            }
          }
          BN_div((BIGNUM *)0x0,pBVar2,rem,*(BIGNUM **)(param_3 + 0x10),ctx);
        } while (a_00->r->top == 0);
        BN_mod_mul(rem,*(BIGNUM **)(param_3 + 0x1c),a_00->r,*(BIGNUM **)(param_3 + 0x10),ctx);
        BN_mod_mul(r,rnd,a,*(BIGNUM **)(param_3 + 0x10),ctx);
        pBVar2 = a_00->s;
        if (pBVar2 == (BIGNUM *)0x0) {
          pBVar2 = BN_new();
          a_00->s = pBVar2;
          if (pBVar2 == (BIGNUM *)0x0) {
            ERR_GOST_error(0x70,0x41,DAT_000e0174,0x69);
            goto LAB_000e00b0;
          }
        }
        BN_mod_add(pBVar2,rem,r,*(BIGNUM **)(param_3 + 0x10),ctx);
      } while (a_00->s->top == 0);
    }
    BN_free(a);
    BN_CTX_end(ctx);
    BN_CTX_free(ctx);
  }
  return a_00;
}

