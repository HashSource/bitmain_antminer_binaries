
char * EC_POINT_point2hex(EC_GROUP *param_1,EC_POINT *param_2,point_conversion_form_t form,
                         BN_CTX *param_4)

{
  char cVar1;
  char *pcVar2;
  size_t len;
  byte *buf;
  size_t sVar3;
  char *pcVar4;
  byte *pbVar5;
  byte *pbVar6;
  
  len = EC_POINT_point2oct(param_1,param_2,form,(uchar *)0x0,0,param_4);
  if ((len == 0) || (buf = (byte *)CRYPTO_malloc(len,"ec_print.c",0x8a), buf == (byte *)0x0)) {
    pcVar4 = (char *)0x0;
  }
  else {
    sVar3 = EC_POINT_point2oct(param_1,param_2,form,buf,len,param_4);
    if (sVar3 == 0) {
      CRYPTO_free(buf);
      pcVar4 = (char *)0x0;
    }
    else {
      pcVar4 = (char *)CRYPTO_malloc((len + 1) * 2,"ec_print.c",0x92);
      if (pcVar4 == (char *)0x0) {
        CRYPTO_free(buf);
      }
      else {
        pbVar6 = buf;
        pcVar2 = pcVar4;
        do {
          pbVar5 = pbVar6 + 1;
          cVar1 = "0123456789ABCDEF"[(int)(uint)*pbVar6 >> 4];
          pcVar2[1] = "0123456789ABCDEF"[*pbVar6 & 0xf];
          *pcVar2 = cVar1;
          pbVar6 = pbVar5;
          pcVar2 = pcVar2 + 2;
        } while (pbVar5 != buf + len);
        pcVar4[len * 2] = '\0';
        CRYPTO_free(buf);
      }
    }
  }
  return pcVar4;
}

