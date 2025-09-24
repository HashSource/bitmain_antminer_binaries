
undefined4 SSL_CIPHER_get_kx_nid(int param_1)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 0x10);
  if (iVar1 == 1) {
    iVar1 = 0;
  }
  else if (iVar1 == 4) {
    iVar1 = 1;
  }
  else if (iVar1 != 2) {
    if (iVar1 == 0x80) {
      iVar1 = 3;
    }
    else if (iVar1 == 0x100) {
      iVar1 = 4;
    }
    else if (iVar1 == 0x40) {
      iVar1 = 5;
    }
    else if (iVar1 == 8) {
      iVar1 = 6;
    }
    else if (iVar1 == 0x20) {
      iVar1 = 7;
    }
    else if (iVar1 == 0x10) {
      iVar1 = 8;
    }
    else {
      if (iVar1 != 0) {
        return 0;
      }
      iVar1 = 9;
    }
  }
  return *(undefined4 *)(ssl_cipher_table_kx + iVar1 * 8 + 4);
}

