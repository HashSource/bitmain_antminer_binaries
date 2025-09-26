
undefined4 pkey_ecx_derive25519(int param_1,int param_2,undefined4 *param_3)

{
  int iVar1;
  
  if ((*(int *)(param_1 + 8) == 0) || (*(int *)(param_1 + 0xc) == 0)) {
    ERR_put_error(0x10,0x116,0x8c,"crypto/ec/ecx_meth.c",0x299);
  }
  else {
    iVar1 = *(int *)(*(int *)(param_1 + 8) + 0x18);
    if ((iVar1 == 0) || (*(int *)(iVar1 + 0x3c) == 0)) {
      ERR_put_error(0x10,0x116,0x7b,"crypto/ec/ecx_meth.c",0x29f);
    }
    else if (*(int *)(*(int *)(param_1 + 0xc) + 0x18) == 0) {
      ERR_put_error(0x10,0x116,0x85,"crypto/ec/ecx_meth.c",0x2a3);
    }
    else if ((param_2 == 0) || (iVar1 = X25519(param_2), iVar1 != 0)) {
      *param_3 = 0x20;
      return 1;
    }
  }
  return 0;
}

