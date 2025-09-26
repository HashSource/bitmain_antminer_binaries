
undefined4 SSL_CIPHER_get_digest_nid(int param_1)

{
  int iVar1;
  int iVar2;
  
  iVar2 = *(int *)(param_1 + 0x1c);
  if (iVar2 == 1) {
    iVar1 = 0;
  }
  else if (iVar2 == 2) {
    iVar1 = 1;
  }
  else if (iVar2 == 4) {
    iVar1 = 2;
  }
  else if (iVar2 == 8) {
    iVar1 = 3;
  }
  else if (iVar2 == 0x10) {
    iVar1 = 4;
  }
  else if (iVar2 == 0x20) {
    iVar1 = 5;
  }
  else if (iVar2 == 0x80) {
    iVar1 = 6;
  }
  else if (iVar2 == 0x100) {
    iVar1 = 7;
  }
  else if (iVar2 == 0x200) {
    iVar1 = 8;
  }
  else {
    iVar1 = 9;
    if (iVar2 != 0) {
      return 0;
    }
  }
  return *(undefined4 *)(ssl_cipher_table_mac + iVar1 * 8 + 4);
}

