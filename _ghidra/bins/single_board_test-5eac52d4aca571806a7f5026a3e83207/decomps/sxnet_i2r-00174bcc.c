
undefined4 sxnet_i2r(undefined4 param_1,undefined4 *param_2,BIO *param_3,undefined4 param_4)

{
  int iVar1;
  undefined4 *puVar2;
  char *ptr;
  int iVar3;
  uint local_30;
  int iStack_2c;
  
  iVar1 = ASN1_INTEGER_get_int64(&local_30,*param_2);
  if ((iVar1 == 0) || (iStack_2c + (uint)(0x7fffffff < local_30) != 0 || local_30 == 0x7fffffff)) {
    BIO_printf(param_3,"%*sVersion: <unsupported>",param_4,"");
  }
  else {
    BIO_printf(param_3,"%*sVersion: %ld (0x%lX)",param_4,"",local_30 + 1,local_30);
  }
  iVar1 = 0;
  while( true ) {
    iVar3 = OPENSSL_sk_num(param_2[1]);
    if (iVar3 <= iVar1) {
      return 1;
    }
    puVar2 = (undefined4 *)OPENSSL_sk_value(param_2[1],iVar1);
    ptr = i2s_ASN1_INTEGER((X509V3_EXT_METHOD *)0x0,(ASN1_INTEGER *)*puVar2);
    if (ptr == (char *)0x0) break;
    BIO_printf(param_3,"\n%*sZone: %s, User: ",param_4,"",ptr);
    CRYPTO_free(ptr);
    ASN1_STRING_print(param_3,(ASN1_STRING *)puVar2[1]);
    iVar1 = iVar1 + 1;
  }
  return 0;
}

