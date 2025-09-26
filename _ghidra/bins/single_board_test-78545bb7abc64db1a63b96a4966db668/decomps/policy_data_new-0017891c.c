
undefined4 * policy_data_new(undefined4 *param_1,ASN1_OBJECT *param_2,int param_3)

{
  ASN1_OBJECT *a;
  undefined4 *ptr;
  int iVar1;
  
  if (param_1 == (undefined4 *)0x0 && param_2 == (ASN1_OBJECT *)0x0) {
    return (undefined4 *)0x0;
  }
  if (param_2 == (ASN1_OBJECT *)0x0) {
    a = (ASN1_OBJECT *)0x0;
  }
  else {
    a = OBJ_dup(param_2);
    if (a == (ASN1_OBJECT *)0x0) {
      return (undefined4 *)0x0;
    }
  }
  ptr = (undefined4 *)CRYPTO_zalloc(0x10,"crypto/x509v3/pcy_data.c",0x34);
  if (ptr == (undefined4 *)0x0) {
    ERR_put_error(0x22,0xab,0x41,"crypto/x509v3/pcy_data.c",0x36);
    ASN1_OBJECT_free(a);
    return (undefined4 *)0x0;
  }
  iVar1 = OPENSSL_sk_new_null();
  ptr[3] = iVar1;
  if (iVar1 == 0) {
    CRYPTO_free(ptr);
    ASN1_OBJECT_free(a);
    ERR_put_error(0x22,0xab,0x41,"crypto/x509v3/pcy_data.c",0x3e);
    return (undefined4 *)0x0;
  }
  if (param_3 != 0) {
    *ptr = 0x10;
  }
  if (a == (ASN1_OBJECT *)0x0) {
    ptr[1] = *param_1;
    *param_1 = 0;
  }
  else {
    ptr[1] = a;
    if (param_1 == (undefined4 *)0x0) {
      return ptr;
    }
  }
  ptr[2] = param_1[1];
  param_1[1] = 0;
  return ptr;
}

