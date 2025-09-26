
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

CMS_ContentInfo * CMS_ContentInfo_new(void)

{
  ASN1_VALUE *pAVar1;
  
  pAVar1 = ASN1_item_new((ASN1_ITEM *)CMS_ContentInfo_it);
  return (CMS_ContentInfo *)pAVar1;
}

