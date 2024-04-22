
undefined4 sxnet_i2r(undefined4 param_1,ASN1_INTEGER **param_2,BIO *param_3,undefined4 param_4)

{
  long lVar1;
  ASN1_INTEGER **ppAVar2;
  char *ptr;
  int iVar3;
  int iVar4;
  
  lVar1 = ASN1_INTEGER_get(*param_2);
  BIO_printf(param_3,DAT_000c99d4,param_4,DAT_000c99d8,lVar1 + 1,lVar1);
  iVar4 = 0;
  while( true ) {
    iVar3 = sk_num((_STACK *)param_2[1]);
    if (iVar3 <= iVar4) break;
    ppAVar2 = (ASN1_INTEGER **)sk_value((_STACK *)param_2[1],iVar4);
    ptr = i2s_ASN1_INTEGER((X509V3_EXT_METHOD *)0x0,*ppAVar2);
    BIO_printf(param_3,DAT_000c99dc,param_4,DAT_000c99d8,ptr);
    CRYPTO_free(ptr);
    ASN1_STRING_print(param_3,ppAVar2[1]);
    iVar4 = iVar4 + 1;
  }
  return 1;
}

