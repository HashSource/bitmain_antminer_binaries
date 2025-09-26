
bool CTLOG_new_from_base64(int *param_1,uchar *param_2,undefined4 param_3)

{
  uchar *puVar1;
  EVP_PKEY *pkey;
  uchar *t;
  uchar *length;
  int iVar2;
  uchar *local_24 [2];
  
  if (param_1 == (int *)0x0) {
    ERR_put_error(0x32,0x76,7,"crypto/ct/ct_b64.c",0x8f);
    return false;
  }
  puVar1 = (uchar *)strlen((char *)param_2);
  length = puVar1;
  t = puVar1;
  if (puVar1 == (uchar *)0x0) goto LAB_0019d372;
  t = (uchar *)CRYPTO_malloc(((uint)puVar1 >> 2) * 3,"crypto/ct/ct_b64.c",0x24);
  if (t == (uchar *)0x0) {
    ERR_put_error(0x32,0x7c,0x41,"crypto/ct/ct_b64.c",0x26);
LAB_0019d3f0:
    CRYPTO_free(t);
  }
  else {
    length = (uchar *)EVP_DecodeBlock(t,param_2,(int)puVar1);
    if ((int)length < 0) {
      ERR_put_error(0x32,0x7c,0x6c,"crypto/ct/ct_b64.c",0x2c);
      goto LAB_0019d3f0;
    }
    puVar1 = puVar1 + (int)param_2;
    if (puVar1[-1] != '=') {
LAB_0019d372:
      local_24[0] = t;
      pkey = d2i_PUBKEY((EVP_PKEY **)0x0,local_24,(long)length);
      CRYPTO_free(t);
      iVar2 = 0x9d;
      if (pkey != (EVP_PKEY *)0x0) {
        iVar2 = CTLOG_new(pkey,param_3);
        *param_1 = iVar2;
        if (iVar2 == 0) {
          EVP_PKEY_free(pkey);
        }
        return iVar2 != 0;
      }
      goto LAB_0019d402;
    }
    iVar2 = -1;
    if ((puVar1[-2] == '=') && (iVar2 = -2, puVar1[-3] == '=')) goto LAB_0019d3f0;
    length = length + iVar2;
    if (-1 < (int)length) goto LAB_0019d372;
  }
  iVar2 = 0x95;
LAB_0019d402:
  ERR_put_error(0x32,0x76,0x6e,"crypto/ct/ct_b64.c",iVar2);
  return false;
}

