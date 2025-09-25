
int EVP_PKEY_save_parameters(EVP_PKEY *pkey,int mode)

{
  stack_st_X509_ATTRIBUTE *psVar1;
  
  if ((pkey->type != 0x74) && (pkey->type != 0x198)) {
    return 0;
  }
  psVar1 = pkey->attributes;
  if (-1 < mode) {
    pkey->attributes = (stack_st_X509_ATTRIBUTE *)mode;
    return (int)psVar1;
  }
  return (int)psVar1;
}

