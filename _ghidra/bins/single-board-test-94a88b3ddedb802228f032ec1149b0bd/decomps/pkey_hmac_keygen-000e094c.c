
undefined4 pkey_hmac_keygen(int param_1,EVP_PKEY *param_2)

{
  ASN1_STRING *key;
  
  if ((*(int *)(*(int *)(param_1 + 0x14) + 0xc) != 0) &&
     (key = ASN1_OCTET_STRING_dup((ASN1_STRING *)(*(int *)(param_1 + 0x14) + 4)),
     key != (ASN1_STRING *)0x0)) {
    EVP_PKEY_assign(param_2,0x357,key);
    return 1;
  }
  return 0;
}

