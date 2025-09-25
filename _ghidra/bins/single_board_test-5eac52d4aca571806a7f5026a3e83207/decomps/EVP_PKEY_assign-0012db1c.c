
int EVP_PKEY_assign(EVP_PKEY *pkey,int type,void *key)

{
  int iVar1;
  
  if (pkey == (EVP_PKEY *)0x0) {
    return 0;
  }
  iVar1 = EVP_PKEY_set_type(pkey,type);
  if (iVar1 != 0) {
    pkey->save_parameters = (int)key;
    if (key != (void *)0x0) {
      key = (void *)0x1;
    }
    return (int)key;
  }
  return 0;
}

