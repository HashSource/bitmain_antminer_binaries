
int CMS_add_smimecap(CMS_SignerInfo *si,stack_st_X509_ALGOR *algs)

{
  int len;
  int iVar1;
  uchar *local_14 [2];
  
  iVar1 = 0;
  local_14[0] = (uchar *)0x0;
  len = i2d_X509_ALGORS(algs,local_14);
  if (0 < len) {
    iVar1 = CMS_signed_add1_attr_by_NID(si,0xa7,0x10,local_14[0],len);
    CRYPTO_free(local_14[0]);
  }
  return iVar1;
}

