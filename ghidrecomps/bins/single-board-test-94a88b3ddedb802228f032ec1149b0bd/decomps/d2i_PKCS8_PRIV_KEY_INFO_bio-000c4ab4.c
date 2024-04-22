
PKCS8_PRIV_KEY_INFO * d2i_PKCS8_PRIV_KEY_INFO_bio(BIO *bp,PKCS8_PRIV_KEY_INFO **p8inf)

{
  PKCS8_PRIV_KEY_INFO *pPVar1;
  
  pPVar1 = (PKCS8_PRIV_KEY_INFO *)
           ASN1_d2i_bio(PKCS8_PRIV_KEY_INFO_new + 1,d2i_PKCS8_PRIV_KEY_INFO + 1,bp,p8inf);
  return pPVar1;
}

