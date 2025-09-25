
int PKCS7_add_signed_attribute(PKCS7_SIGNER_INFO *p7si,int nid,int type,void *data)

{
  int iVar1;
  
  iVar1 = add_attribute(&p7si->auth_attr);
  return iVar1;
}

