
undefined4 aes_ecb_cipher(EVP_CIPHER_CTX *param_1,int param_2,int param_3,uint param_4)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  
  uVar5 = param_4;
  uVar1 = EVP_CIPHER_CTX_block_size(param_1);
  iVar2 = EVP_CIPHER_CTX_get_cipher_data(param_1);
  if (uVar1 <= param_4) {
    iVar3 = param_3;
    do {
      iVar4 = iVar3 + uVar1;
      (**(code **)(iVar2 + 0xf8))(iVar3,param_2,iVar2,*(code **)(iVar2 + 0xf8),uVar5);
      iVar3 = iVar4;
      param_2 = param_2 + uVar1;
    } while ((uint)(iVar4 - param_3) <= param_4 - uVar1);
  }
  return 1;
}

