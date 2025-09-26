
undefined4 aes_wrap_init_key(int param_1,uchar *param_2,undefined4 *param_3)

{
  undefined4 uVar1;
  AES_KEY *key;
  int iVar2;
  
  iVar2 = 1 - (int)param_3;
  if ((undefined4 *)0x1 < param_3) {
    iVar2 = 0;
  }
  key = *(AES_KEY **)(param_1 + 0x60);
  if (param_2 != (uchar *)0x0 || param_3 != (undefined4 *)0x0) {
    if (param_2 == (uchar *)0x0) {
      if (param_3 == (undefined4 *)0x0) {
        return 1;
      }
    }
    else {
      if (*(int *)(param_1 + 8) == 0) {
        AES_set_decrypt_key(param_2,*(int *)(param_1 + 0x58) << 3,key);
      }
      else {
        AES_set_encrypt_key(param_2,*(int *)(param_1 + 0x58) << 3,key);
      }
      if (iVar2 != 0) {
        key[1].rd_key[1] = 0;
        return 1;
      }
    }
    uVar1 = param_3[1];
    *(undefined4 *)(param_1 + 0x20) = *param_3;
    *(undefined4 *)(param_1 + 0x24) = uVar1;
    key[1].rd_key[1] = param_1 + 0x20;
  }
  return 1;
}

