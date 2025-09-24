
int EVP_PKEY_asn1_add0(EVP_PKEY_ASN1_METHOD *ameth)

{
  int iVar1;
  undefined4 local_a0 [36];
  
  memset(local_a0,0,0x90);
  if (*(int *)(ameth + 0xc) == 0) {
    if (-1 < *(int *)(ameth + 8) << 0x1f) goto LAB_001058de;
  }
  else if (*(int *)(ameth + 8) << 0x1f < 0) {
LAB_001058de:
    ERR_put_error(6,0xbc,7,"crypto/asn1/ameth_lib.c",0x9b);
    return 0;
  }
  if ((app_methods != 0) || (app_methods = OPENSSL_sk_new(0x1056fd), app_methods != 0)) {
    local_a0[0] = *(undefined4 *)ameth;
    iVar1 = OPENSSL_sk_find(app_methods,local_a0);
    if (iVar1 < 0) {
      iVar1 = OPENSSL_sk_push(app_methods,ameth);
      if (iVar1 != 0) {
        OPENSSL_sk_sort(app_methods);
        return 1;
      }
    }
    else {
      ERR_put_error(6,0xbc,0xb3,"crypto/asn1/ameth_lib.c",0xa8);
    }
  }
  return 0;
}

