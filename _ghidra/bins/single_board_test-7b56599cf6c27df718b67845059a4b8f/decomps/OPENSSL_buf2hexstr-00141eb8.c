
char * OPENSSL_buf2hexstr(byte *param_1,int param_2)

{
  byte bVar1;
  char *pcVar2;
  byte *pbVar3;
  byte *pbVar4;
  char *pcVar5;
  
  if (param_2 != 0) {
    pcVar2 = (char *)CRYPTO_malloc(param_2 * 3,"crypto/o_str.c",0xcb);
    if (pcVar2 == (char *)0x0) {
      ERR_put_error(0xf,0x75,0x41,"crypto/o_str.c",0xcc);
    }
    else {
      pcVar5 = pcVar2;
      if (0 < param_2) {
        pbVar3 = param_1;
        do {
          *pcVar5 = "0123456789ABCDEF"[*pbVar3 >> 4];
          pbVar4 = pbVar3 + 1;
          bVar1 = *pbVar3;
          pcVar5[2] = ':';
          pcVar5[1] = "0123456789ABCDEF"[bVar1 & 0xf];
          pbVar3 = pbVar4;
          pcVar5 = pcVar5 + 3;
        } while (param_1 + param_2 != pbVar4);
        pcVar5 = pcVar2 + param_2 * 3;
      }
      pcVar5[-1] = '\0';
    }
    return pcVar2;
  }
  pcVar2 = (char *)CRYPTO_zalloc(1,"crypto/o_str.c",200);
  return pcVar2;
}

