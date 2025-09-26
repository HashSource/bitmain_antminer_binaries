
int i2d_CMS_ContentInfo(CMS_ContentInfo *a,uchar **out)

{
  int iVar1;
  
  iVar1 = ASN1_item_i2d((ASN1_VALUE *)a,out,(ASN1_ITEM *)CMS_ContentInfo_it);
  return iVar1;
}

