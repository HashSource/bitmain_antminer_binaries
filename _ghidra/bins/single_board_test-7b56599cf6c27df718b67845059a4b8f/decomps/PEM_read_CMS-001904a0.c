
CMS_ContentInfo * PEM_read_CMS(FILE *fp,CMS_ContentInfo **x,undefined1 *cb,void *u)

{
  CMS_ContentInfo *pCVar1;
  
  pCVar1 = (CMS_ContentInfo *)PEM_ASN1_read((undefined1 *)0x190c7d,"CMS",fp,x,cb,u);
  return pCVar1;
}

