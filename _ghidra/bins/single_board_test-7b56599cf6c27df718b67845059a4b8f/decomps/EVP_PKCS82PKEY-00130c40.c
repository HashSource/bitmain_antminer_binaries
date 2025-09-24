
EVP_PKEY * EVP_PKCS82PKEY(PKCS8_PRIV_KEY_INFO *p8)

{
  EVP_PKEY *pEVar1;
  int iVar2;
  ASN1_OBJECT *local_64;
  char acStack_60 [84];
  
  pEVar1 = (EVP_PKEY *)PKCS8_pkey_get0(&local_64,(uchar **)0x0,(int *)0x0,(X509_ALGOR **)0x0,p8);
  if (pEVar1 != (EVP_PKEY *)0x0) {
    pEVar1 = EVP_PKEY_new();
    if (pEVar1 == (EVP_PKEY *)0x0) {
      ERR_put_error(6,0x6f,0x41,"crypto/evp/evp_pkey.c",0x1f);
      pEVar1 = (EVP_PKEY *)0x0;
    }
    else {
      iVar2 = OBJ_obj2nid(local_64);
      iVar2 = EVP_PKEY_set_type(pEVar1,iVar2);
      if (iVar2 == 0) {
        ERR_put_error(6,0x6f,0x76,"crypto/evp/evp_pkey.c",0x24);
        i2t_ASN1_OBJECT(acStack_60,0x50,local_64);
        ERR_add_error_data(2,&DAT_0020fbd8,acStack_60);
      }
      else if (*(code **)(pEVar1->ameth + 0x24) == (code *)0x0) {
        ERR_put_error(6,0x6f,0x90,"crypto/evp/evp_pkey.c",0x30);
      }
      else {
        iVar2 = (**(code **)(pEVar1->ameth + 0x24))(pEVar1,p8);
        if (iVar2 != 0) {
          return pEVar1;
        }
        ERR_put_error(6,0x6f,0x91,"crypto/evp/evp_pkey.c",0x2c);
      }
      EVP_PKEY_free(pEVar1);
      pEVar1 = (EVP_PKEY *)0x0;
    }
  }
  return pEVar1;
}

