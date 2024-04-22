
int EVP_PKEY_assign(EVP_PKEY *pkey,int type,void *key)

{
  void *pvVar1;
  
  pvVar1 = (void *)pkey_set_type(pkey,type,0,0xffffffff);
  if ((pvVar1 != (void *)0x0) && ((pkey->pkey).ptr = (char *)key, pvVar1 = key, key != (void *)0x0))
  {
    pvVar1 = (void *)0x1;
  }
  return (int)pvVar1;
}

