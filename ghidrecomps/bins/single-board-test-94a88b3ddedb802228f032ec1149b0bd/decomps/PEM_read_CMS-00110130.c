
CMS_ContentInfo * PEM_read_CMS(FILE *fp,CMS_ContentInfo **x,undefined1 *cb,void *u)

{
  CMS_ContentInfo *pCVar1;
  
  pCVar1 = (CMS_ContentInfo *)PEM_ASN1_read(d2i_CMS_ContentInfo + 1,"CMS",fp,x,cb,u);
  return pCVar1;
}

