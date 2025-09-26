
undefined4 HMAC_CTX_reset(undefined4 *param_1)

{
  int iVar1;
  
  EVP_MD_CTX_reset(param_1[2]);
  EVP_MD_CTX_reset(param_1[3]);
  EVP_MD_CTX_reset(param_1[1]);
  *param_1 = 0;
  if (param_1[2] == 0) {
    iVar1 = EVP_MD_CTX_new();
    param_1[2] = iVar1;
    if (iVar1 == 0) goto LAB_0013e504;
  }
  if (param_1[3] == 0) {
    iVar1 = EVP_MD_CTX_new();
    param_1[3] = iVar1;
    if (iVar1 != 0) goto LAB_0013e4f2;
  }
  else {
LAB_0013e4f2:
    if (param_1[1] != 0) {
      return 1;
    }
    iVar1 = EVP_MD_CTX_new();
    param_1[1] = iVar1;
    if (iVar1 != 0) {
      return 1;
    }
  }
  iVar1 = param_1[2];
LAB_0013e504:
  EVP_MD_CTX_reset(iVar1);
  EVP_MD_CTX_reset(param_1[3]);
  EVP_MD_CTX_reset(param_1[1]);
  *param_1 = 0;
  return 0;
}

