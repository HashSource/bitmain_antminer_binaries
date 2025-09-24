
int DH_generate_parameters_ex(DH *dh,int prime_len,int generator,BN_GENCB *cb)

{
  int iVar1;
  BN_CTX *ctx;
  BIGNUM *a;
  BIGNUM *a_00;
  BIGNUM *pBVar2;
  code *UNRECOVERED_JUMPTABLE;
  int iVar3;
  
  UNRECOVERED_JUMPTABLE = *(code **)((dh->ex_data).dummy + 0x20);
  if (UNRECOVERED_JUMPTABLE != (code *)0x0) {
                    /* WARNING: Could not recover jumptable at 0x001d3014. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    iVar1 = (*UNRECOVERED_JUMPTABLE)();
    return iVar1;
  }
  ctx = BN_CTX_new();
  if (ctx != (BN_CTX *)0x0) {
    BN_CTX_start(ctx);
    a = BN_CTX_get(ctx);
    a_00 = BN_CTX_get(ctx);
    if (a_00 != (BIGNUM *)0x0) {
      if (dh->p == (BIGNUM *)0x0) {
        pBVar2 = BN_new();
        dh->p = pBVar2;
        if (pBVar2 == (BIGNUM *)0x0) goto LAB_001d305e;
      }
      if (dh->g == (BIGNUM *)0x0) {
        pBVar2 = BN_new();
        dh->g = pBVar2;
        if (pBVar2 == (BIGNUM *)0x0) goto LAB_001d305e;
      }
      if (generator < 2) {
        ERR_put_error(5,0x6a,0x65,"crypto/dh/dh_gen.c",0x54);
      }
      else {
        if (generator == 2) {
          iVar1 = BN_set_word(a,0x18);
joined_r0x001d3090:
          if (iVar1 == 0) goto LAB_001d305e;
          iVar1 = BN_set_word(a_00,0xb);
        }
        else {
          if (generator != 5) {
            iVar1 = BN_set_word(a,0xc);
            goto joined_r0x001d3090;
          }
          iVar1 = BN_set_word(a,0x3c);
          if (iVar1 == 0) goto LAB_001d305e;
          iVar1 = BN_set_word(a_00,0x17);
        }
        if (((iVar1 != 0) && (iVar1 = BN_generate_prime_ex(dh->p,prime_len,1,a,a_00,cb), iVar1 != 0)
            ) && (iVar1 = BN_GENCB_call(cb,3,0), iVar1 != 0)) {
          iVar1 = BN_set_word(dh->g,generator);
          iVar3 = 1;
          if (iVar1 != 0) goto LAB_001d3072;
        }
      }
    }
  }
LAB_001d305e:
  iVar3 = 0;
  ERR_put_error(5,0x6a,3,"crypto/dh/dh_gen.c",0x79);
LAB_001d3072:
  BN_CTX_end(ctx);
  BN_CTX_free(ctx);
  return iVar3;
}

