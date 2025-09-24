
bool aes_xts_cipher(undefined4 param_1,int param_2,int param_3,uint param_4)

{
  bool bVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  int iVar5;
  int iVar6;
  code *pcVar7;
  
  iVar2 = EVP_CIPHER_CTX_get_cipher_data();
  iVar5 = *(int *)(iVar2 + 0x1f0);
  if (iVar5 == 0) {
    return false;
  }
  iVar6 = *(int *)(iVar2 + 500);
  if (iVar6 == 0) {
    bVar1 = false;
  }
  else {
    bVar1 = false;
    if (0xf < param_4 && (param_3 != 0 && param_2 != 0)) {
      pcVar7 = *(code **)(iVar2 + 0x200);
      if (pcVar7 == (code *)0x0) {
        uVar3 = EVP_CIPHER_CTX_iv_noconst(param_1);
        uVar4 = EVP_CIPHER_CTX_encrypting(param_1);
        iVar2 = CRYPTO_xts128_encrypt(iVar2 + 0x1f0,uVar3,param_3,param_2,param_4,uVar4);
        bVar1 = iVar2 == 0;
      }
      else {
        uVar3 = EVP_CIPHER_CTX_iv_noconst(param_1);
        (*pcVar7)(param_3,param_2,param_4,iVar5,iVar6,uVar3);
        bVar1 = true;
      }
    }
  }
  return bVar1;
}

