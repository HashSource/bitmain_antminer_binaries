
undefined4 aes_ccm_ctrl(undefined4 param_1,undefined4 param_2,size_t param_3,int *param_4)

{
  undefined1 uVar1;
  int iVar2;
  int *piVar3;
  void *__dest;
  int iVar4;
  int iVar5;
  undefined4 uVar6;
  ushort uVar7;
  
  iVar2 = EVP_CIPHER_CTX_get_cipher_data();
  switch(param_2) {
  case 0:
    *(undefined4 *)(iVar2 + 0x10c) = 0xc;
    *(undefined4 *)(iVar2 + 0xf8) = 0;
    *(undefined4 *)(iVar2 + 0xfc) = 0;
    *(undefined4 *)(iVar2 + 0x100) = 0;
    *(undefined4 *)(iVar2 + 0x104) = 0;
    *(undefined4 *)(iVar2 + 0x108) = 8;
    *(undefined4 *)(iVar2 + 0x110) = 0xffffffff;
    return 1;
  default:
    uVar6 = 0xffffffff;
    break;
  case 8:
    iVar4 = EVP_CIPHER_CTX_get_cipher_data(param_4);
    if (*(int *)(iVar2 + 0x144) == 0) {
      uVar6 = 1;
    }
    else {
      if (*(int *)(iVar2 + 0x144) != iVar2) {
        return 0;
      }
      *(int *)(iVar4 + 0x144) = iVar4;
      uVar6 = 1;
    }
    break;
  case 9:
    param_3 = 0xf - param_3;
  case 0x14:
    if (6 < param_3 - 2) {
      return 0;
    }
    *(size_t *)(iVar2 + 0x108) = param_3;
    uVar6 = 1;
    break;
  case 0x10:
    iVar4 = EVP_CIPHER_CTX_encrypting(param_1);
    if (iVar4 == 0) {
      return 0;
    }
    if (*(int *)(iVar2 + 0x100) == 0) {
      return 0;
    }
    iVar4 = CRYPTO_ccm128_tag(iVar2 + 0x118,param_4,param_3);
    if (iVar4 == 0) {
      return 0;
    }
    uVar6 = 1;
    *(undefined4 *)(iVar2 + 0x100) = 0;
    *(undefined4 *)(iVar2 + 0xfc) = 0;
    *(undefined4 *)(iVar2 + 0x104) = 0;
    break;
  case 0x11:
    if ((int)(param_3 << 0x1f) < 0) {
      return 0;
    }
    if (0xc < param_3 - 4) {
      return 0;
    }
    iVar4 = EVP_CIPHER_CTX_encrypting(param_1);
    if (iVar4 == 0) {
      if (param_4 != (int *)0x0) {
        *(undefined4 *)(iVar2 + 0x100) = 1;
        __dest = (void *)EVP_CIPHER_CTX_buf_noconst(param_1);
        memcpy(__dest,param_4,param_3);
      }
    }
    else if (param_4 != (int *)0x0) {
      return 0;
    }
    *(size_t *)(iVar2 + 0x10c) = param_3;
    uVar6 = 1;
    break;
  case 0x12:
    if (param_3 != 4) {
      return 0;
    }
    piVar3 = (int *)EVP_CIPHER_CTX_iv_noconst(param_1);
    uVar6 = 1;
    *piVar3 = *param_4;
    break;
  case 0x16:
    if (param_3 != 0xd) {
      return 0;
    }
    piVar3 = (int *)EVP_CIPHER_CTX_buf_noconst(param_1);
    iVar4 = param_4[1];
    iVar5 = param_4[2];
    *piVar3 = *param_4;
    piVar3[1] = iVar4;
    piVar3[2] = iVar5;
    *(char *)(piVar3 + 3) = (char)param_4[3];
    *(undefined4 *)(iVar2 + 0x110) = 0xd;
    iVar4 = EVP_CIPHER_CTX_buf_noconst(param_1);
    uVar1 = *(undefined1 *)(iVar4 + 0xb);
    iVar4 = EVP_CIPHER_CTX_buf_noconst(param_1);
    uVar7 = CONCAT11(uVar1,*(undefined1 *)(iVar4 + 0xc));
    if (uVar7 < 8) {
      return 0;
    }
    uVar7 = uVar7 - 8;
    iVar4 = EVP_CIPHER_CTX_encrypting(param_1);
    if (iVar4 == 0) {
      if ((int)(uint)uVar7 < *(int *)(iVar2 + 0x10c)) {
        return 0;
      }
      uVar7 = uVar7 - (short)*(int *)(iVar2 + 0x10c);
    }
    iVar4 = EVP_CIPHER_CTX_buf_noconst(param_1);
    *(char *)(iVar4 + 0xb) = (char)(uVar7 >> 8);
    iVar4 = EVP_CIPHER_CTX_buf_noconst(param_1);
    *(char *)(iVar4 + 0xc) = (char)uVar7;
    return *(undefined4 *)(iVar2 + 0x10c);
  case 0x25:
    *param_4 = 0xf - *(int *)(iVar2 + 0x108);
    return 1;
  }
  return uVar6;
}

