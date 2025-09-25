
byte * OPENSSL_hexstr2buf(char *param_1,int *param_2)

{
  char cVar1;
  size_t sVar2;
  byte *ptr;
  uint uVar3;
  uint uVar4;
  char *pcVar5;
  byte *pbVar6;
  
  sVar2 = strlen(param_1);
  ptr = (byte *)CRYPTO_malloc(sVar2 >> 1,"crypto/o_str.c",0x9c);
  pbVar6 = ptr;
  if (ptr == (byte *)0x0) {
    ERR_put_error(0xf,0x76,0x41,"crypto/o_str.c",0x9d);
  }
  else {
    while( true ) {
      pcVar5 = param_1;
      cVar1 = *pcVar5;
      if (cVar1 == '\0') break;
      param_1 = pcVar5 + 1;
      if (cVar1 != ':') {
        if (pcVar5[1] == '\0') {
          ERR_put_error(0xf,0x76,0x67,"crypto/o_str.c",0xa7);
          CRYPTO_free(ptr);
          return (byte *)0x0;
        }
        uVar3 = OPENSSL_hexchar2int(pcVar5[1]);
        uVar4 = OPENSSL_hexchar2int(cVar1);
        if ((int)(uVar3 | uVar4) < 0) {
          CRYPTO_free(ptr);
          ERR_put_error(0xf,0x76,0x66,"crypto/o_str.c",0xaf);
          return (byte *)0x0;
        }
        *pbVar6 = (byte)uVar3 | (byte)(uVar4 << 4);
        param_1 = pcVar5 + 2;
        pbVar6 = pbVar6 + 1;
      }
    }
    if (param_2 != (int *)0x0) {
      *param_2 = (int)pbVar6 - (int)ptr;
    }
  }
  return ptr;
}

