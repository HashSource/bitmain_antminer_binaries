
void X509_VERIFY_PARAM_free(X509_VERIFY_PARAM *param)

{
  _STACK **pp_Var1;
  
  if (param != (X509_VERIFY_PARAM *)0x0) {
    param->name = (char *)0x0;
    param->purpose = 0;
    param->trust = 0;
    param->inh_flags = 0;
    param->flags = 0;
    param->depth = -1;
    if (&param->policies->stack != (_STACK *)0x0) {
      sk_pop_free(&param->policies->stack,DAT_000c5df8);
      param->policies = (stack_st_ASN1_OBJECT *)0x0;
    }
    pp_Var1 = (_STACK **)param[1].name;
    if (*pp_Var1 != (_STACK *)0x0) {
      sk_pop_free(*pp_Var1,DAT_000c5dfc);
      *pp_Var1 = (_STACK *)0x0;
    }
    if (pp_Var1[2] != (_STACK *)0x0) {
      CRYPTO_free(pp_Var1[2]);
    }
    if (pp_Var1[3] != (_STACK *)0x0) {
      CRYPTO_free(pp_Var1[3]);
      pp_Var1[3] = (_STACK *)0x0;
      pp_Var1[4] = (_STACK *)0x0;
    }
    if (pp_Var1[5] != (_STACK *)0x0) {
      CRYPTO_free(pp_Var1[5]);
      pp_Var1[5] = (_STACK *)0x0;
      pp_Var1[6] = (_STACK *)0x0;
    }
    CRYPTO_free(param[1].name);
    CRYPTO_free(param);
    return;
  }
  return;
}

