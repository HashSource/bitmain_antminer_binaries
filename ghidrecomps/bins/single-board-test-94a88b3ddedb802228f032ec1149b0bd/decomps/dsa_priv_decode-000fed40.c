
undefined4 dsa_priv_decode(EVP_PKEY *param_1,PKCS8_PRIV_KEY_INFO *param_2)

{
  int iVar1;
  ASN1_INTEGER *ai;
  int *piVar2;
  int *piVar3;
  DSA *r;
  _STACK *st;
  BIGNUM *ctx;
  uchar *local_30;
  long local_2c;
  int local_28;
  long *local_24;
  X509_ALGOR *local_20;
  uchar *local_1c;
  
  iVar1 = PKCS8_pkey_get0((ASN1_OBJECT **)0x0,&local_30,&local_2c,&local_20,param_2);
  if (iVar1 == 0) {
    return 0;
  }
  X509_ALGOR_get0((ASN1_OBJECT **)0x0,&local_28,&local_24,local_20);
  if (*local_30 == '0') {
    st = &d2i_ASN1_SEQUENCE_ANY((ASN1_SEQUENCE_ANY **)0x0,&local_30,local_2c)->stack;
    if (st == (_STACK *)0x0) {
      ai = (ASN1_INTEGER *)0x0;
    }
    else {
      iVar1 = sk_num(st);
      if (iVar1 == 2) {
        piVar2 = (int *)sk_value(st,0);
        piVar3 = (int *)sk_value(st,1);
        if (*piVar2 == 0x10) {
          param_2->broken = 2;
          local_24 = (long *)piVar2[1];
        }
        else {
          if (local_28 != 0x10) goto LAB_000fee78;
          param_2->broken = 3;
        }
        if (*piVar3 == 2) {
          ai = (ASN1_INTEGER *)piVar3[1];
          goto LAB_000fee00;
        }
      }
LAB_000fee78:
      ai = (ASN1_INTEGER *)0x0;
    }
  }
  else {
    local_1c = local_30;
    ai = d2i_ASN1_INTEGER((ASN1_INTEGER **)0x0,&local_30,local_2c);
    if (ai == (ASN1_INTEGER *)0x0) {
LAB_000fee96:
      ai = (ASN1_INTEGER *)0x0;
    }
    else {
      if (ai->type == 0x102) {
        param_2->broken = 4;
        ASN1_STRING_clear_free();
        ai = d2i_ASN1_UINTEGER((ASN1_INTEGER **)0x0,&local_1c,local_2c);
        if (ai == (ASN1_INTEGER *)0x0) goto LAB_000fee96;
      }
      if (local_28 == 0x10) {
        st = (_STACK *)0x0;
LAB_000fee00:
        local_1c = (uchar *)local_24[2];
        r = d2i_DSAparams((DSA **)0x0,&local_1c,*local_24);
        if (r == (DSA *)0x0) goto LAB_000fed9c;
        ctx = ASN1_INTEGER_to_BN(ai,(BIGNUM *)0x0);
        iVar1 = 0xf6;
        r->priv_key = ctx;
        if (ctx == (BIGNUM *)0x0) {
LAB_000fee56:
          ERR_put_error(10,0x73,0x6d,DAT_000feee4,iVar1);
        }
        else {
          ctx = BN_new();
          iVar1 = 0xfb;
          r->pub_key = ctx;
          if (ctx != (BIGNUM *)0x0) {
            ctx = (BIGNUM *)BN_CTX_new();
            if (ctx != (BIGNUM *)0x0) {
              iVar1 = BN_mod_exp(r->pub_key,r->g,r->priv_key,r->p,(BN_CTX *)ctx);
              if (iVar1 != 0) {
                EVP_PKEY_assign(param_1,0x74,r);
                BN_CTX_free((BN_CTX *)ctx);
                if (st != (_STACK *)0x0) {
                  sk_pop_free(st,DAT_000feee8);
                  return 1;
                }
                ASN1_STRING_clear_free(ai);
                return 1;
              }
              iVar1 = 0x104;
              goto LAB_000fee56;
            }
            iVar1 = 0xff;
          }
          ERR_put_error(10,0x73,0x41,DAT_000feee4,iVar1);
        }
        goto LAB_000fedb2;
      }
    }
    st = (_STACK *)0x0;
  }
LAB_000fed9c:
  r = (DSA *)0x0;
  ctx = (BIGNUM *)0x0;
  ERR_put_error(10,0x73,0x72,DAT_000feee4,0x112);
LAB_000fedb2:
  BN_CTX_free((BN_CTX *)ctx);
  if (ai != (ASN1_INTEGER *)0x0) {
    ASN1_STRING_clear_free(ai);
  }
  sk_pop_free(st,DAT_000feee8);
  DSA_free(r);
  return 0;
}

