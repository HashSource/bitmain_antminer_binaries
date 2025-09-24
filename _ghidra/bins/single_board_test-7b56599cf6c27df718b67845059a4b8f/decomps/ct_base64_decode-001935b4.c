
int ct_base64_decode(uchar *param_1,undefined4 *param_2)

{
  size_t n;
  uchar *t;
  int iVar1;
  int iVar2;
  
  n = strlen((char *)param_1);
  if (n == 0) {
    *param_2 = 0;
    return 0;
  }
  t = (uchar *)CRYPTO_malloc((n >> 2) * 3,"crypto/ct/ct_b64.c",0x24);
  if (t == (uchar *)0x0) {
    ERR_put_error(0x32,0x7c,0x41,"crypto/ct/ct_b64.c",0x26);
  }
  else {
    iVar1 = EVP_DecodeBlock(t,param_1,n);
    if (iVar1 < 0) {
      ERR_put_error(0x32,0x7c,0x6c,"crypto/ct/ct_b64.c",0x2c);
    }
    else {
      iVar2 = iVar1;
      if (((param_1[n - 1] != '=') || (iVar2 = iVar1 + -1, param_1[n - 2] != '=')) ||
         (iVar2 = iVar1 + -2, param_1[n - 3] != '=')) {
        *param_2 = t;
        return iVar2;
      }
    }
  }
  CRYPTO_free(t);
  return -1;
}

