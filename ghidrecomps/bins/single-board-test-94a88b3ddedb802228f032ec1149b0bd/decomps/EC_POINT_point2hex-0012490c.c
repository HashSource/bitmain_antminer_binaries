
char * EC_POINT_point2hex(EC_GROUP *param_1,EC_POINT *param_2,point_conversion_form_t form,
                         BN_CTX *param_4)

{
  char cVar1;
  char *pcVar2;
  int iVar3;
  size_t len;
  byte *buf;
  size_t sVar4;
  char *pcVar5;
  byte *pbVar6;
  byte *pbVar7;
  
  len = EC_POINT_point2oct(param_1,param_2,form,(uchar *)0x0,0,param_4);
  if ((len == 0) || (buf = (byte *)CRYPTO_malloc(len,DAT_001249b8,0x8a), buf == (byte *)0x0)) {
    pcVar5 = (char *)0x0;
  }
  else {
    sVar4 = EC_POINT_point2oct(param_1,param_2,form,buf,len,param_4);
    if (sVar4 == 0) {
      CRYPTO_free(buf);
      pcVar5 = (char *)0x0;
    }
    else {
      pcVar5 = (char *)CRYPTO_malloc((len + 1) * 2,DAT_001249b8,0x92);
      iVar3 = DAT_001249bc;
      if (pcVar5 == (char *)0x0) {
        CRYPTO_free(buf);
      }
      else {
        pbVar7 = buf;
        pcVar2 = pcVar5;
        do {
          pbVar6 = pbVar7 + 1;
          cVar1 = *(char *)(((int)(uint)*pbVar7 >> 4) + iVar3);
          pcVar2[1] = *(char *)((*pbVar7 & 0xf) + iVar3);
          *pcVar2 = cVar1;
          pbVar7 = pbVar6;
          pcVar2 = pcVar2 + 2;
        } while (pbVar6 != buf + len);
        pcVar5[len * 2] = '\0';
        CRYPTO_free(buf);
      }
    }
  }
  return pcVar5;
}

