
int EVP_PKEY_set_type(EVP_PKEY *pkey,int type)

{
  int iVar1;
  
  iVar1 = pkey_set_type(pkey,type,0,0xffffffff);
  return iVar1;
}

