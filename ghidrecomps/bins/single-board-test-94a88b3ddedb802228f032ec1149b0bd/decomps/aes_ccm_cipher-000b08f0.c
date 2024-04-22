
size_t aes_ccm_cipher(int param_1,void *param_2,int param_3,size_t param_4)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  undefined auStack_30 [16];
  
  iVar3 = *(int *)(param_1 + 0x60);
  iVar5 = iVar3 + 0x110;
  if (((*(int *)(iVar3 + 0xfc) != 0) || (*(int *)(iVar3 + 0xf8) != 0)) &&
     ((iVar4 = *(int *)(param_1 + 8), iVar4 != 0 || (*(int *)(iVar3 + 0x100) != 0)))) {
    if (param_2 == (void *)0x0) {
      if (param_3 == 0) {
        iVar5 = CRYPTO_ccm128_setiv(iVar5,param_1 + 0x20,0xf - *(int *)(iVar3 + 0x108),param_4);
        if (iVar5 == 0) {
          *(undefined4 *)(iVar3 + 0x104) = 1;
          return param_4;
        }
      }
      else if ((*(int *)(iVar3 + 0x104) != 0) || (param_4 == 0)) {
        CRYPTO_ccm128_aad(iVar5,param_3,param_4);
        return param_4;
      }
    }
    else {
      if (param_3 == 0) {
        return 0;
      }
      if (*(int *)(iVar3 + 0x104) == 0) {
        iVar4 = CRYPTO_ccm128_setiv(iVar5,param_1 + 0x20,0xf - *(int *)(iVar3 + 0x108),param_4);
        if (iVar4 != 0) {
          return 0xffffffff;
        }
        iVar4 = *(int *)(param_1 + 8);
        *(undefined4 *)(iVar3 + 0x104) = 1;
      }
      iVar2 = *(int *)(iVar3 + 0x140);
      if (iVar4 == 0) {
        if (iVar2 == 0) {
          uVar1 = CRYPTO_ccm128_decrypt(iVar5,param_3,param_2,param_4);
          iVar4 = 1 - uVar1;
          if (1 < uVar1) {
            iVar4 = 0;
          }
        }
        else {
          uVar1 = CRYPTO_ccm128_decrypt_ccm64(iVar5,param_3,param_2,param_4,iVar2);
          iVar4 = 1 - uVar1;
          if (1 < uVar1) {
            iVar4 = 0;
          }
        }
        if ((((iVar4 == 0) ||
             (iVar5 = CRYPTO_ccm128_tag(iVar5,auStack_30,*(undefined4 *)(iVar3 + 0x10c)), iVar5 == 0
             )) || (iVar5 = CRYPTO_memcmp(auStack_30,(void *)(param_1 + 0x30),
                                          *(size_t *)(iVar3 + 0x10c)), iVar5 != 0)) ||
           (param_4 == 0xffffffff)) {
          OPENSSL_cleanse(param_2,param_4);
          param_4 = 0xffffffff;
        }
        *(undefined4 *)(iVar3 + 0xfc) = 0;
        *(undefined4 *)(iVar3 + 0x100) = 0;
        *(undefined4 *)(iVar3 + 0x104) = 0;
        return param_4;
      }
      if (iVar2 == 0) {
        iVar5 = CRYPTO_ccm128_encrypt(iVar5,param_3,param_2,param_4);
        if (iVar5 != 0) {
          iVar5 = 1;
        }
      }
      else {
        iVar5 = CRYPTO_ccm128_encrypt_ccm64(iVar5,param_3,param_2,param_4,iVar2);
        if (iVar5 != 0) {
          iVar5 = 1;
        }
      }
      if (iVar5 == 0) {
        *(undefined4 *)(iVar3 + 0x100) = 1;
        return param_4;
      }
    }
  }
  return 0xffffffff;
}

