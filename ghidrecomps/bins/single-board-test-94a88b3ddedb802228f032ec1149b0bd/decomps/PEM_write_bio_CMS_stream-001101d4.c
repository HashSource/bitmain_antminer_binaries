
int PEM_write_bio_CMS_stream(BIO *out,CMS_ContentInfo *cms,BIO *in,int flags)

{
  int iVar1;
  
  iVar1 = PEM_write_bio_ASN1_stream
                    (out,(ASN1_VALUE *)cms,in,flags,"CMS",(ASN1_ITEM *)CMS_ContentInfo_it);
  return iVar1;
}

