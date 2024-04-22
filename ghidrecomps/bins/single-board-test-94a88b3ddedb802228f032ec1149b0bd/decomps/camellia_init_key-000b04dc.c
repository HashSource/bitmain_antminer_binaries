
undefined4 camellia_init_key(int *param_1,uchar *param_2,undefined4 param_3,int param_4)

{
  int iVar1;
  undefined4 uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  CAMELLIA_KEY *key;
  
  key = (CAMELLIA_KEY *)param_1[0x18];
  iVar1 = Camellia_set_key(param_2,param_1[0x16] << 3,key);
  uVar4 = DAT_000b0558;
  uVar5 = DAT_000b0554;
  if (iVar1 < 0) {
    ERR_put_error(6,0x9f,0x9d,DAT_000b055c,0x108);
    uVar2 = 0;
  }
  else {
    uVar2 = 1;
    uVar3 = *(uint *)(*param_1 + 0x10) & 0xf0007;
    if ((uVar3 - 1 < 2) && (param_4 == 0)) {
      uVar5 = DAT_000b0550;
      if (uVar3 != 2) {
        uVar5 = 0;
      }
      key[1].u.rd_key[1] = uVar5;
      key[1].u.rd_key[0] = uVar4;
    }
    else {
      uVar4 = DAT_000b0550;
      if (uVar3 != 2) {
        uVar4 = 0;
      }
      key[1].u.rd_key[1] = uVar4;
      key[1].u.rd_key[0] = uVar5;
    }
  }
  return uVar2;
}

