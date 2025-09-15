
ASN1_OBJECT * CMS_get0_type(CMS_ContentInfo *cms)

{
  return *(ASN1_OBJECT **)cms;
}

