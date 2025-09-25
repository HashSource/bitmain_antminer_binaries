
int eckey_pub_decode(EVP_PKEY *param_1,X509_PUBKEY *param_2)

{
  int iVar1;
  EC_KEY *pEVar2;
  uchar *local_28;
  void *local_24;
  int local_20;
  long local_1c;
  EC_KEY *local_18;
  X509_ALGOR *local_14;
  
  local_28 = (uchar *)0x0;
  local_18 = (EC_KEY *)0x0;
  iVar1 = X509_PUBKEY_get0_param((ASN1_OBJECT **)0x0,&local_28,&local_1c,&local_14,param_2);
  if (iVar1 != 0) {
    X509_ALGOR_get0((ASN1_OBJECT **)0x0,&local_20,&local_24,local_14);
    local_18 = (EC_KEY *)eckey_type2param(local_20,local_24);
    if (local_18 == (EC_KEY *)0x0) {
      ERR_put_error(0x10,0xd7,0x10,"crypto/ec/ec_ameth.c",0xa8);
      iVar1 = 0;
    }
    else {
      pEVar2 = o2i_ECPublicKey(&local_18,&local_28,local_1c);
      if (pEVar2 != (EC_KEY *)0x0) {
        EVP_PKEY_assign(param_1,0x198,local_18);
        return 1;
      }
      ERR_put_error(0x10,0xd7,0x8e,"crypto/ec/ec_ameth.c",0xae);
      EC_KEY_free(local_18);
      iVar1 = 0;
    }
  }
  return iVar1;
}

