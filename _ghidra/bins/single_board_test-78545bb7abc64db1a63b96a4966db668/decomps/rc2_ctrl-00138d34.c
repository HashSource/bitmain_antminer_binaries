
undefined4 rc2_ctrl(EVP_CIPHER_CTX *param_1,int param_2,int param_3,undefined4 *param_4)

{
  int *piVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 uVar4;
  
  if (param_2 == 2) {
    puVar3 = (undefined4 *)EVP_CIPHER_CTX_get_cipher_data();
    *param_4 = *puVar3;
    return 1;
  }
  if (param_2 == 3) {
    if (0 < param_3) {
      piVar1 = (int *)EVP_CIPHER_CTX_get_cipher_data();
      *piVar1 = param_3;
      return 1;
    }
    uVar4 = 0;
  }
  else {
    if (param_2 == 0) {
      piVar1 = (int *)EVP_CIPHER_CTX_get_cipher_data();
      iVar2 = EVP_CIPHER_CTX_key_length(param_1);
      *piVar1 = iVar2 << 3;
      return 1;
    }
    uVar4 = 0xffffffff;
  }
  return uVar4;
}

