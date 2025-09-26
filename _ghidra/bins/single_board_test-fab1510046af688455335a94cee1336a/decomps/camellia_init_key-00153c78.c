
undefined4 camellia_init_key(int *param_1,uchar *param_2,undefined4 param_3,int param_4)

{
  int iVar1;
  undefined4 uVar2;
  uint uVar3;
  CAMELLIA_KEY *key;
  
  key = (CAMELLIA_KEY *)param_1[0x18];
  iVar1 = Camellia_set_key(param_2,param_1[0x16] << 3,key);
  if (iVar1 < 0) {
    ERR_put_error(6,0x9f,0x9d,"e_camellia.c",0x108);
    uVar2 = 0;
  }
  else {
    uVar2 = 1;
    uVar3 = *(uint *)(*param_1 + 0x10) & 0xf0007;
    if ((uVar3 - 1 < 2) && (param_4 == 0)) {
      if (uVar3 == 2) {
        uVar3 = 0x180c75;
      }
      else {
        uVar3 = 0;
      }
      key[1].u.rd_key[1] = uVar3;
      key[1].u.rd_key[0] = 0x180c69;
    }
    else {
      if (uVar3 == 2) {
        uVar3 = 0x180c75;
      }
      else {
        uVar3 = 0;
      }
      key[1].u.rd_key[1] = uVar3;
      key[1].u.rd_key[0] = 0x180c5d;
    }
  }
  return uVar2;
}

