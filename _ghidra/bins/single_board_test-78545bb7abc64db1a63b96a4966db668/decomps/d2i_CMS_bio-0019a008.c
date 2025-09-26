
CMS_ContentInfo * d2i_CMS_bio(BIO *bp,CMS_ContentInfo **cms)

{
  CMS_ContentInfo *pCVar1;
  
  pCVar1 = (CMS_ContentInfo *)ASN1_item_d2i_bio((ASN1_ITEM *)CMS_ContentInfo_it,bp,cms);
  return pCVar1;
}

