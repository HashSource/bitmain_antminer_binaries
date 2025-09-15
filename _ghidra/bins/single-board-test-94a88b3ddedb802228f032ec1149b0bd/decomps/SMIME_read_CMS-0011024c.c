
CMS_ContentInfo * SMIME_read_CMS(BIO *bio,BIO **bcont)

{
  ASN1_VALUE *pAVar1;
  
  pAVar1 = SMIME_read_ASN1(bio,bcont,(ASN1_ITEM *)CMS_ContentInfo_it);
  return (CMS_ContentInfo *)pAVar1;
}

