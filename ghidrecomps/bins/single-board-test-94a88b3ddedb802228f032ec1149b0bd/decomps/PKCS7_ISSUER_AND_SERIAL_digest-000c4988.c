
int PKCS7_ISSUER_AND_SERIAL_digest(PKCS7_ISSUER_AND_SERIAL *data,EVP_MD *type,uchar *md,uint *len)

{
  int iVar1;
  
  iVar1 = ASN1_item_digest((ASN1_ITEM *)PKCS7_ISSUER_AND_SERIAL_it,type,data,md,len);
  return iVar1;
}

