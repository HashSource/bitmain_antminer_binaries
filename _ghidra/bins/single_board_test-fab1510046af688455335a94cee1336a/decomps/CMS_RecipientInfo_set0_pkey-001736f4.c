
int CMS_RecipientInfo_set0_pkey(CMS_RecipientInfo *ri,EVP_PKEY *pkey)

{
  int iVar1;
  
  iVar1 = *(int *)ri;
  if (iVar1 != 0) {
    ERR_put_error(0x2e,0x91,0x7c,"cms_env.c",0x153);
  }
  else {
    *(EVP_PKEY **)(*(int *)(ri + 4) + 0x14) = pkey;
  }
  return (uint)(iVar1 == 0);
}

