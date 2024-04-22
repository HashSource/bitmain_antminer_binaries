
CMS_ContentInfo * PEM_read_bio_CMS(BIO *bp,CMS_ContentInfo **x,undefined1 *cb,void *u)

{
  CMS_ContentInfo *pCVar1;
  
  pCVar1 = (CMS_ContentInfo *)PEM_ASN1_read_bio(d2i_CMS_ContentInfo + 1,"CMS",bp,x,cb,u);
  return pCVar1;
}

