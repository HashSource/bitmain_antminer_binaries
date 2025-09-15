
int EVP_PKEY_set_type_str(EVP_PKEY *pkey,char *str,int len)

{
  int iVar1;
  
  iVar1 = pkey_set_type(pkey,0,str,len);
  return iVar1;
}

