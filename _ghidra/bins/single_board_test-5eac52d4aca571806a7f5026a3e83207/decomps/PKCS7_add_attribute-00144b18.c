
int PKCS7_add_attribute(PKCS7_SIGNER_INFO *p7si,int nid,int atrtype,void *value)

{
  int iVar1;
  
  iVar1 = add_attribute(&p7si->unauth_attr);
  return iVar1;
}

