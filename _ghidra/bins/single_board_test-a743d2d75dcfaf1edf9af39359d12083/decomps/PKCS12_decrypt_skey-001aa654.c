
PKCS8_PRIV_KEY_INFO * PKCS12_decrypt_skey(PKCS12_SAFEBAG *bag,char *pass,int passlen)

{
  PKCS8_PRIV_KEY_INFO *pPVar1;
  
  pPVar1 = PKCS8_decrypt((bag->value).shkeybag,pass,passlen);
  return pPVar1;
}

