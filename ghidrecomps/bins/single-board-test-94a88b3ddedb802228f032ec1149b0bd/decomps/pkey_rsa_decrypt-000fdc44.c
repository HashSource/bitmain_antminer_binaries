
int pkey_rsa_decrypt(int param_1,uchar *param_2,int *param_3,uchar *param_4,int param_5)

{
  int iVar1;
  uchar *to;
  int iVar2;
  char *pcVar3;
  int iVar4;
  
  iVar4 = *(int *)(param_1 + 0x14);
  if (*(int *)(iVar4 + 0x10) == 4) {
    to = *(uchar **)(iVar4 + 0x20);
    if (to == (uchar *)0x0) {
      iVar1 = EVP_PKEY_size(*(EVP_PKEY **)(param_1 + 8));
      to = (uchar *)CRYPTO_malloc(iVar1,DAT_000fdce8,0x9c);
      *(uchar **)(iVar4 + 0x20) = to;
      if (to == (uchar *)0x0) {
        return -1;
      }
    }
    iVar1 = RSA_private_decrypt(param_5,param_4,to,*(RSA **)(*(int *)(param_1 + 8) + 0x14),3);
    if (iVar1 < 1) {
      return iVar1;
    }
    iVar2 = 0;
    pcVar3 = *(char **)(iVar4 + 0x20);
    do {
      if (*pcVar3 != '\0') goto LAB_000fdca6;
      iVar2 = iVar2 + 1;
      pcVar3 = pcVar3 + 1;
    } while (iVar2 != iVar1);
    pcVar3 = *(char **)(iVar4 + 0x20) + iVar2;
LAB_000fdca6:
    iVar4 = RSA_padding_check_PKCS1_OAEP_mgf1
                      (param_2,iVar1,pcVar3,iVar1 - iVar2,iVar1,*(undefined4 *)(iVar4 + 0x24),
                       *(undefined4 *)(iVar4 + 0x28),*(undefined4 *)(iVar4 + 0x14),
                       *(undefined4 *)(iVar4 + 0x18));
  }
  else {
    iVar4 = RSA_private_decrypt(param_5,param_4,param_2,*(RSA **)(*(int *)(param_1 + 8) + 0x14),
                                *(int *)(iVar4 + 0x10));
  }
  if (-1 < iVar4) {
    *param_3 = iVar4;
    iVar4 = 1;
  }
  return iVar4;
}

