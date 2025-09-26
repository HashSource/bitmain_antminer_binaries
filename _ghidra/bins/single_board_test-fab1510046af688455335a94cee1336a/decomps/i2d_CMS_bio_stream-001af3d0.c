
int i2d_CMS_bio_stream(BIO *out,CMS_ContentInfo *cms,BIO *in,int flags)

{
  int iVar1;
  
  iVar1 = i2d_ASN1_bio_stream(out,(ASN1_VALUE *)cms,in,flags,(ASN1_ITEM *)CMS_ContentInfo_it);
  return iVar1;
}

