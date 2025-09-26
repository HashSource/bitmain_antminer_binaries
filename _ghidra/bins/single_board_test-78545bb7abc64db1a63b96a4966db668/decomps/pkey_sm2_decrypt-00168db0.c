
undefined4
pkey_sm2_decrypt(int param_1,int param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = *(int *)(*(int *)(param_1 + 0x14) + 4);
  uVar2 = *(undefined4 *)(*(int *)(param_1 + 8) + 0x18);
  if (iVar1 == 0) {
    iVar1 = EVP_sm3();
  }
  if (param_2 == 0) {
    iVar1 = sm2_plaintext_size(param_4,param_5);
    if (iVar1 == 0) {
      uVar2 = 0xffffffff;
    }
    else {
      uVar2 = 1;
    }
    return uVar2;
  }
  uVar2 = sm2_decrypt(uVar2,iVar1,param_4,param_5,param_2,param_3);
  return uVar2;
}

