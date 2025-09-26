
CMS_ContentInfo * d2i_CMS_ContentInfo(CMS_ContentInfo **a,uchar **in,long len)

{
  ASN1_VALUE *pAVar1;
  
  pAVar1 = ASN1_item_d2i((ASN1_VALUE **)a,in,len,(ASN1_ITEM *)CMS_ContentInfo_it);
  return (CMS_ContentInfo *)pAVar1;
}

