
BIO * BIO_new_CMS(BIO *out,CMS_ContentInfo *cms)

{
  BIO *pBVar1;
  
  pBVar1 = BIO_new_NDEF(out,(ASN1_VALUE *)cms,(ASN1_ITEM *)CMS_ContentInfo_it);
  return pBVar1;
}

