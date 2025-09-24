
int CMS_RecipientInfo_set0_pkey(CMS_RecipientInfo *ri,EVP_PKEY *pkey)

{
  if (*(int *)ri == 0) {
    EVP_PKEY_free(*(EVP_PKEY **)(*(int *)(ri + 4) + 0x14));
    *(EVP_PKEY **)(*(int *)(ri + 4) + 0x14) = pkey;
    return 1;
  }
  ERR_put_error(0x2e,0x91,0x7c,"crypto/cms/cms_env.c",0x11a);
  return 0;
}

