
undefined4 aes_ocb_ctrl(undefined4 *param_1,undefined4 param_2,uint param_3,undefined4 *param_4)

{
  int iVar1;
  EVP_CIPHER *cipher;
  undefined4 uVar2;
  int iVar3;
  
  iVar1 = EVP_CIPHER_CTX_get_cipher_data();
  switch(param_2) {
  case 0:
    cipher = (EVP_CIPHER *)*param_1;
    *(undefined4 *)(iVar1 + 0x1f0) = 0;
    *(undefined4 *)(iVar1 + 500) = 0;
    iVar3 = EVP_CIPHER_iv_length(cipher);
    *(int *)(iVar1 + 0x2cc) = iVar3;
    uVar2 = EVP_CIPHER_CTX_iv_noconst(param_1);
    *(undefined4 *)(iVar1 + 0x290) = uVar2;
    *(undefined4 *)(iVar1 + 0x2c4) = 0;
    *(undefined4 *)(iVar1 + 0x2c8) = 0;
    *(undefined4 *)(iVar1 + 0x2d0) = 0x10;
    return 1;
  default:
    return 0xffffffff;
  case 8:
    iVar3 = EVP_CIPHER_CTX_get_cipher_data(param_4);
    uVar2 = CRYPTO_ocb128_copy_ctx(iVar3 + 0x1f8,iVar1 + 0x1f8,iVar3,iVar3 + 0xf8);
    return uVar2;
  case 9:
    if (param_3 - 1 < 0xf) {
      *(uint *)(iVar1 + 0x2cc) = param_3;
      return 1;
    }
    break;
  case 0x10:
    if ((param_3 == *(uint *)(iVar1 + 0x2d0)) &&
       (iVar3 = EVP_CIPHER_CTX_encrypting(param_1), iVar3 != 0)) {
      memcpy(param_4,(void *)(iVar1 + 0x294),param_3);
      return 1;
    }
    break;
  case 0x11:
    if (param_4 == (undefined4 *)0x0) {
      if (param_3 < 0x11) {
        *(uint *)(iVar1 + 0x2d0) = param_3;
        return 1;
      }
    }
    else if ((param_3 == *(uint *)(iVar1 + 0x2d0)) &&
            (iVar3 = EVP_CIPHER_CTX_encrypting(param_1), iVar3 == 0)) {
      memcpy((void *)(iVar1 + 0x294),param_4,param_3);
      return 1;
    }
    break;
  case 0x25:
    *param_4 = *(undefined4 *)(iVar1 + 0x2cc);
    return 1;
  }
  return 0;
}

