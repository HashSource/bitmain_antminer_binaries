
int pkey_hmac_ctrl(int param_1,int param_2,int param_3,void *param_4)

{
  int iVar1;
  int *piVar2;
  undefined4 *puVar3;
  
  puVar3 = *(undefined4 **)(param_1 + 0x14);
  if (param_2 == 6) {
    iVar1 = 0;
    if ((-2 < param_3 && (param_3 < 1 || param_4 != (void *)0x0)) &&
       (iVar1 = ASN1_OCTET_STRING_set((ASN1_STRING *)(puVar3 + 1),param_4,param_3), iVar1 != 0)) {
      iVar1 = 1;
    }
  }
  else {
    if (param_2 == 7) {
      piVar2 = *(int **)(*(int *)(param_1 + 8) + 0x18);
      iVar1 = HMAC_Init_ex((HMAC_CTX *)puVar3[5],(void *)piVar2[2],*piVar2,(EVP_MD *)*puVar3,
                           *(ENGINE **)(param_1 + 4));
      if (iVar1 != 0) {
        iVar1 = 1;
      }
      return iVar1;
    }
    if (param_2 == 1) {
      *puVar3 = param_4;
      return 1;
    }
    iVar1 = -2;
  }
  return iVar1;
}

