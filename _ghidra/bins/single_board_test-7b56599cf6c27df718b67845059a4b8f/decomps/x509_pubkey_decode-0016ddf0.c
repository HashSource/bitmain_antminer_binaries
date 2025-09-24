
undefined4 x509_pubkey_decode(undefined4 *param_1,undefined4 *param_2)

{
  EVP_PKEY *pkey;
  int iVar1;
  
  pkey = EVP_PKEY_new();
  if (pkey == (EVP_PKEY *)0x0) {
    ERR_put_error(0xb,0x94,0x41,"crypto/x509/x_pubkey.c",0x6d);
    return 0xffffffff;
  }
  iVar1 = OBJ_obj2nid(*(ASN1_OBJECT **)*param_2);
  iVar1 = EVP_PKEY_set_type(pkey,iVar1);
  if (iVar1 == 0) {
    ERR_put_error(0xb,0x94,0x6f,"crypto/x509/x_pubkey.c",0x72);
  }
  else if (*(code **)(pkey->ameth + 0x14) == (code *)0x0) {
    ERR_put_error(0xb,0x94,0x7c,"crypto/x509/x_pubkey.c",0x81);
  }
  else {
    iVar1 = (**(code **)(pkey->ameth + 0x14))(pkey,param_2);
    if (iVar1 != 0) {
      *param_1 = pkey;
      return 1;
    }
    ERR_put_error(0xb,0x94,0x7d,"crypto/x509/x_pubkey.c",0x7d);
  }
  EVP_PKEY_free(pkey);
  return 0;
}

