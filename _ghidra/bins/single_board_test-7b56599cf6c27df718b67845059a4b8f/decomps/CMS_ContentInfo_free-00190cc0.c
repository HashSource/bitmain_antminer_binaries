
void CMS_ContentInfo_free(CMS_ContentInfo *a)

{
  ASN1_item_free((ASN1_VALUE *)a,(ASN1_ITEM *)CMS_ContentInfo_it);
  return;
}

