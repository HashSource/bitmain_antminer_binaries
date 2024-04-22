
int pkey_hmac_ctrl(int param_1,int param_2,int param_3,EVP_MD *param_4)

{
  int iVar1;
  int *piVar2;
  EVP_MD **ppEVar3;
  
  ppEVar3 = *(EVP_MD ***)(param_1 + 0x14);
  if (param_2 == 6) {
    iVar1 = 1 - (int)param_4;
    if ((EVP_MD *)0x1 < param_4) {
      iVar1 = 0;
    }
    if (param_3 < 1) {
      iVar1 = 0;
    }
    if (iVar1 == 0) {
      iVar1 = 0;
      if ((param_3 + 1 < 0 == SCARRY4(param_3,1)) &&
         (iVar1 = ASN1_OCTET_STRING_set((ASN1_STRING *)(ppEVar3 + 1),param_4,param_3), iVar1 != 0))
      {
        iVar1 = 1;
      }
    }
    else {
      iVar1 = 0;
    }
  }
  else if (param_2 == 7) {
    piVar2 = *(int **)(*(int *)(param_1 + 8) + 0x14);
    iVar1 = HMAC_Init_ex((HMAC_CTX *)(ppEVar3 + 5),(void *)piVar2[2],*piVar2,*ppEVar3,
                         *(ENGINE **)(param_1 + 4));
    if (iVar1 != 0) {
      iVar1 = 1;
    }
  }
  else if (param_2 == 1) {
    *ppEVar3 = param_4;
    iVar1 = 1;
  }
  else {
    iVar1 = -2;
  }
  return iVar1;
}

