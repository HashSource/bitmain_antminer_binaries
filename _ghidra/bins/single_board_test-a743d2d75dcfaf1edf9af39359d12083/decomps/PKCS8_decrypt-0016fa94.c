
PKCS8_PRIV_KEY_INFO * PKCS8_decrypt(X509_SIG *p8,char *pass,int passlen)

{
  PKCS8_PRIV_KEY_INFO *pPVar1;
  
  pPVar1 = (PKCS8_PRIV_KEY_INFO *)
           PKCS12_item_decrypt_d2i
                     (p8->algor,(ASN1_ITEM *)&PKCS8_PRIV_KEY_INFO_it,pass,passlen,p8->digest,1);
  return pPVar1;
}

