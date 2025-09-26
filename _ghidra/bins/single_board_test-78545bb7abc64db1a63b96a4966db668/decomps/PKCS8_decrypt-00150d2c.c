
PKCS8_PRIV_KEY_INFO * PKCS8_decrypt(X509_SIG *p8,char *pass,int passlen)

{
  PKCS8_PRIV_KEY_INFO *pPVar1;
  X509_ALGOR *local_20;
  ASN1_OCTET_STRING *local_1c [2];
  
  X509_SIG_get0(p8,&local_20,local_1c);
  pPVar1 = (PKCS8_PRIV_KEY_INFO *)
           PKCS12_item_decrypt_d2i
                     (local_20,(ASN1_ITEM *)&PKCS8_PRIV_KEY_INFO_it,pass,passlen,local_1c[0],1);
  return pPVar1;
}

