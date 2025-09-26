
int aes_init_key(int *param_1,uchar *param_2,undefined4 param_3,int param_4)

{
  int iVar1;
  uint uVar2;
  AES_KEY *key;
  bool bVar3;
  
  key = (AES_KEY *)param_1[0x18];
  uVar2 = *(uint *)(*param_1 + 0x10) & 0xf0007;
  if ((uVar2 - 1 < 2) && (param_4 == 0)) {
    iVar1 = AES_set_decrypt_key(param_2,param_1[0x16] << 3,key);
    if (uVar2 == 2) {
      uVar2 = 0x17be61;
    }
    else {
      uVar2 = 0;
    }
    bVar3 = -1 < iVar1;
    key[1].rd_key[2] = uVar2;
    if (bVar3) {
      iVar1 = 1;
    }
    key[1].rd_key[1] = 0x17ba01;
  }
  else {
    iVar1 = AES_set_encrypt_key(param_2,param_1[0x16] << 3,key);
    if (uVar2 == 2) {
      uVar2 = 0x17be61;
    }
    else {
      uVar2 = 0;
    }
    bVar3 = -1 < iVar1;
    key[1].rd_key[2] = uVar2;
    if (bVar3) {
      iVar1 = 1;
    }
    key[1].rd_key[1] = 0x17b5a1;
  }
  if (!bVar3) {
    ERR_put_error(6,0x85,0x8f,"e_aes.c",0x3f1);
    iVar1 = 0;
  }
  return iVar1;
}

