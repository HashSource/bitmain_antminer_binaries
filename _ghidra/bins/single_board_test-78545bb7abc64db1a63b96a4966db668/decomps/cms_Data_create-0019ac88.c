
CMS_ContentInfo * cms_Data_create(void)

{
  CMS_ContentInfo *cms;
  ASN1_OBJECT *pAVar1;
  
  cms = CMS_ContentInfo_new();
  if (cms != (CMS_ContentInfo *)0x0) {
    pAVar1 = OBJ_nid2obj(0x15);
    *(ASN1_OBJECT **)cms = pAVar1;
    CMS_set_detached(cms,0);
  }
  return cms;
}

