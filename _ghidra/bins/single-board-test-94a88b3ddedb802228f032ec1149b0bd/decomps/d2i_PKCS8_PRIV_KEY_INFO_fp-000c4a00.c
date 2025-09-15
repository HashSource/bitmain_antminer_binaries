
PKCS8_PRIV_KEY_INFO * d2i_PKCS8_PRIV_KEY_INFO_fp(FILE *fp,PKCS8_PRIV_KEY_INFO **p8inf)

{
  PKCS8_PRIV_KEY_INFO *pPVar1;
  
  pPVar1 = (PKCS8_PRIV_KEY_INFO *)ASN1_d2i_fp((xnew *)0xbd819,(undefined1 *)0xbd801,fp,p8inf);
  return pPVar1;
}

