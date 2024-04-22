
int aes_init_key(int *param_1,uchar *param_2,undefined4 param_3,int param_4)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  AES_KEY *key;
  bool bVar5;
  
  key = (AES_KEY *)param_1[0x18];
  uVar3 = *(uint *)(*param_1 + 0x10) & 0xf0007;
  if ((uVar3 - 1 < 2) && (param_4 == 0)) {
    iVar2 = AES_set_decrypt_key(param_2,param_1[0x16] << 3,key);
    uVar1 = DAT_000b1358;
    uVar4 = DAT_000b1350;
    if (uVar3 != 2) {
      uVar4 = 0;
    }
    bVar5 = -1 < iVar2;
    key[1].rd_key[2] = uVar4;
    if (bVar5) {
      iVar2 = 1;
    }
    key[1].rd_key[1] = uVar1;
  }
  else {
    iVar2 = AES_set_encrypt_key(param_2,param_1[0x16] << 3,key);
    uVar1 = DAT_000b1354;
    uVar4 = DAT_000b1350;
    if (uVar3 != 2) {
      uVar4 = 0;
    }
    bVar5 = -1 < iVar2;
    key[1].rd_key[2] = uVar4;
    if (bVar5) {
      iVar2 = 1;
    }
    key[1].rd_key[1] = uVar1;
  }
  if (!bVar5) {
    ERR_put_error(6,0x85,0x8f,DAT_000b135c,0x3f1);
    iVar2 = 0;
  }
  return iVar2;
}

