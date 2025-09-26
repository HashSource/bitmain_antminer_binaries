
void X509_VERIFY_PARAM_free(X509_VERIFY_PARAM *param)

{
  char *pcVar1;
  
  if (param != (X509_VERIFY_PARAM *)0x0) {
    param->name = (char *)0x0;
    param->purpose = 0;
    param->trust = 0;
    param->inh_flags = 0;
    param->flags = 0;
    param->depth = -1;
    if (&param->policies->stack != (_STACK *)0x0) {
      sk_pop_free(&param->policies->stack,(func *)0x156099);
      param->policies = (stack_st_ASN1_OBJECT *)0x0;
    }
    pcVar1 = param[1].name;
    if (*(_STACK **)pcVar1 != (_STACK *)0x0) {
      sk_pop_free(*(_STACK **)pcVar1,(func *)0x163de9);
      pcVar1[0] = '\0';
      pcVar1[1] = '\0';
      pcVar1[2] = '\0';
      pcVar1[3] = '\0';
    }
    if (*(void **)(pcVar1 + 8) != (void *)0x0) {
      CRYPTO_free(*(void **)(pcVar1 + 8));
    }
    if (*(void **)(pcVar1 + 0xc) != (void *)0x0) {
      CRYPTO_free(*(void **)(pcVar1 + 0xc));
      pcVar1[0xc] = '\0';
      pcVar1[0xd] = '\0';
      pcVar1[0xe] = '\0';
      pcVar1[0xf] = '\0';
      pcVar1[0x10] = '\0';
      pcVar1[0x11] = '\0';
      pcVar1[0x12] = '\0';
      pcVar1[0x13] = '\0';
    }
    if (*(void **)(pcVar1 + 0x14) != (void *)0x0) {
      CRYPTO_free(*(void **)(pcVar1 + 0x14));
      pcVar1[0x14] = '\0';
      pcVar1[0x15] = '\0';
      pcVar1[0x16] = '\0';
      pcVar1[0x17] = '\0';
      pcVar1[0x18] = '\0';
      pcVar1[0x19] = '\0';
      pcVar1[0x1a] = '\0';
      pcVar1[0x1b] = '\0';
    }
    CRYPTO_free(param[1].name);
    CRYPTO_free(param);
    return;
  }
  return;
}

