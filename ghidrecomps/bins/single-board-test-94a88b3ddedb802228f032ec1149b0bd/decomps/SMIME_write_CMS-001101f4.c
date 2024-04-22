
int SMIME_write_CMS(BIO *bio,CMS_ContentInfo *cms,BIO *data,int flags)

{
  int iVar1;
  ASN1_OBJECT *o;
  int econt_nid;
  stack_st_X509_ALGOR *mdalgs;
  
  iVar1 = OBJ_obj2nid(*(ASN1_OBJECT **)cms);
  o = CMS_get0_eContentType(cms);
  econt_nid = OBJ_obj2nid(o);
  if (iVar1 == 0x16) {
    mdalgs = *(stack_st_X509_ALGOR **)(*(int *)(cms + 4) + 4);
  }
  else {
    mdalgs = (stack_st_X509_ALGOR *)0x0;
  }
  iVar1 = SMIME_write_ASN1(bio,(ASN1_VALUE *)cms,data,flags,iVar1,econt_nid,mdalgs,DAT_00110248);
  return iVar1;
}

