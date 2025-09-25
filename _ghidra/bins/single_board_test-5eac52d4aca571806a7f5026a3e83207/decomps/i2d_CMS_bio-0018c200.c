
int i2d_CMS_bio(BIO *bp,CMS_ContentInfo *cms)

{
  int iVar1;
  
  iVar1 = ASN1_item_i2d_bio((ASN1_ITEM *)CMS_ContentInfo_it,bp,cms);
  return iVar1;
}

