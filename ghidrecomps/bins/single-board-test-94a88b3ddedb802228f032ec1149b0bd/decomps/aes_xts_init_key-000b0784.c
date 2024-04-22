
undefined4 aes_xts_init_key(int param_1,uchar *param_2,undefined4 *param_3,int param_4)

{
  uint uVar1;
  undefined4 uVar2;
  int iVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  AES_KEY *key;
  
  key = *(AES_KEY **)(param_1 + 0x60);
  if (param_3 != (undefined4 *)0x0 || param_2 != (uchar *)0x0) {
    if (param_2 != (uchar *)0x0) {
      iVar3 = *(int *)(param_1 + 0x58);
      key[2].rd_key[6] = (uint)(param_3 == (undefined4 *)0x0 && param_2 == (uchar *)0x0);
      uVar1 = DAT_000b0810;
      if (param_4 == 0) {
        AES_set_decrypt_key(param_2,iVar3 << 2,key);
        key[2].rd_key[4] = DAT_000b080c;
      }
      else {
        AES_set_encrypt_key(param_2,iVar3 << 2,key);
        key[2].rd_key[4] = uVar1;
      }
      AES_set_encrypt_key(param_2 + *(int *)(param_1 + 0x58) / 2,*(int *)(param_1 + 0x58) << 2,
                          (AES_KEY *)(key[1].rd_key + 1));
      key[2].rd_key[5] = uVar1;
      key[2].rd_key[2] = (uint)key;
    }
    if (param_3 != (undefined4 *)0x0) {
      key[2].rd_key[3] = (uint)(key[1].rd_key + 1);
      uVar2 = param_3[1];
      uVar4 = param_3[2];
      uVar5 = param_3[3];
      *(undefined4 *)(param_1 + 0x20) = *param_3;
      *(undefined4 *)(param_1 + 0x24) = uVar2;
      *(undefined4 *)(param_1 + 0x28) = uVar4;
      *(undefined4 *)(param_1 + 0x2c) = uVar5;
    }
  }
  return 1;
}

