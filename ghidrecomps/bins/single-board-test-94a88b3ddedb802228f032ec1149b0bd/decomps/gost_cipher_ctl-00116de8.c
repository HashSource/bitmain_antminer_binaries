
undefined4 gost_cipher_ctl(int param_1,int param_2,undefined4 param_3,uchar *param_4)

{
  int iVar1;
  
  if (param_2 == 6) {
    iVar1 = RAND_bytes(param_4,*(int *)(param_1 + 0x58));
    if (0 < iVar1) {
      return 1;
    }
    ERR_GOST_error(0x6f,0x7b,"gost_crypt.c",0x195,param_4);
    return 0xffffffff;
  }
  if (param_2 != 7) {
    ERR_GOST_error(0x6f,0x81,"gost_crypt.c",0x1a4,param_4);
    return 0xffffffff;
  }
  if (param_4 != (uchar *)0x0) {
    param_4[0] = '*';
    param_4[1] = '\x03';
    param_4[2] = '\0';
    param_4[3] = '\0';
    return 1;
  }
  return 0;
}

