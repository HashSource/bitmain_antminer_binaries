
int ssl_get_server_send_pkey(int param_1)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  
  iVar3 = *(int *)(param_1 + 0x98);
  if ((*(int *)(param_1 + 0x58) != 0) && (*(int *)(*(int *)(param_1 + 0x58) + 0x344) != 0)) {
    ssl_set_cert_masks(iVar3);
    iVar1 = ssl_cipher_get_cert_index(*(undefined4 *)(*(int *)(param_1 + 0x58) + 0x344));
    if (iVar1 == 0) {
      uVar2 = *(uint *)(*(int *)(param_1 + 0x98) + 0x3c);
      iVar1 = 1 - uVar2;
      if (1 < uVar2) {
        iVar1 = 0;
      }
LAB_0007bc2a:
      return iVar3 + iVar1 * 0x1c + 0x3c;
    }
    if (iVar1 == -1) {
      ERR_put_error(0x14,0x142,0x44,DAT_0007bc64,0x9d1);
    }
    else if (-1 < iVar1) goto LAB_0007bc2a;
  }
  return 0;
}

