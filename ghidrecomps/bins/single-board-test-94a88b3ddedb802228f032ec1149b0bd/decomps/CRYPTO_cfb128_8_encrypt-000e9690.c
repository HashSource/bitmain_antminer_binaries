
void CRYPTO_cfb128_8_encrypt
               (int param_1,int param_2,int param_3,undefined4 param_4,undefined4 param_5,
               undefined4 param_6,undefined4 param_7,undefined4 param_8)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  if (param_3 != 0) {
    iVar3 = 0;
    do {
      iVar1 = param_1 + iVar3;
      iVar2 = param_2 + iVar3;
      iVar3 = iVar3 + 1;
      cfbr_encrypt_block_part_0(iVar1,iVar2,8,param_4,param_5,param_7,param_8);
    } while (iVar3 != param_3);
  }
  return;
}

