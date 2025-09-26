
int EVP_PKEY_get_attr_by_NID(EVP_PKEY *key,int nid,int lastpos)

{
  int iVar1;
  
  iVar1 = X509at_get_attr_by_NID(key->attributes,nid,lastpos);
  return iVar1;
}

