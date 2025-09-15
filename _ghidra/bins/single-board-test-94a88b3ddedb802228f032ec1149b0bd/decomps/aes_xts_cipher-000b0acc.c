
int aes_xts_cipher(int param_1,int param_2,int param_3,uint param_4)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  
  iVar3 = *(int *)(param_1 + 0x60);
  if (*(int *)(iVar3 + 0x1f0) == 0) {
    iVar4 = 0;
  }
  else {
    iVar1 = *(int *)(iVar3 + 500);
    iVar4 = iVar1;
    if (iVar1 != 0) {
      if (param_2 == 0 || param_3 == 0) {
        iVar4 = 0;
      }
      else {
        iVar4 = 0;
        if (0xf < param_4) {
          if (*(code **)(iVar3 + 0x200) == (code *)0x0) {
            uVar2 = CRYPTO_xts128_encrypt
                              (iVar3 + 0x1f0,param_1 + 0x20,param_3,param_2,param_4,
                               *(undefined4 *)(param_1 + 8));
            iVar4 = 1 - uVar2;
            if (1 < uVar2) {
              iVar4 = 0;
            }
          }
          else {
            (**(code **)(iVar3 + 0x200))
                      (param_3,param_2,param_4,*(int *)(iVar3 + 0x1f0),iVar1,param_1 + 0x20);
            iVar4 = 1;
          }
        }
      }
    }
  }
  return iVar4;
}

