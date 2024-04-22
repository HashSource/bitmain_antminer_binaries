
undefined4 Curl_ntlm_core_mk_nt_hash(undefined4 param_1,char *param_2,uchar *param_3)

{
  char cVar1;
  code **ppcVar2;
  size_t sVar3;
  char *data;
  undefined4 uVar4;
  char *pcVar5;
  size_t len;
  MD4_CTX MStack_7c;
  
  sVar3 = strlen(param_2);
  len = sVar3 * 2;
  data = (char *)(**DAT_0005f8d8)(len);
  uVar4 = 0x1b;
  if (data != (char *)0x0) {
    if (sVar3 != 0) {
      param_2 = param_2 + -1;
      pcVar5 = data;
      do {
        param_2 = param_2 + 1;
        cVar1 = *param_2;
        pcVar5[1] = '\0';
        *pcVar5 = cVar1;
        pcVar5 = pcVar5 + 2;
      } while (pcVar5 != data + len);
    }
    MD4_Init(&MStack_7c);
    MD4_Update(&MStack_7c,data,len);
    MD4_Final(param_3,&MStack_7c);
    ppcVar2 = DAT_0005f8dc;
    param_3[0x10] = '\0';
    param_3[0x11] = '\0';
    param_3[0x12] = '\0';
    param_3[0x13] = '\0';
    param_3[0x14] = '\0';
    (**ppcVar2)(data);
    uVar4 = 0;
  }
  return uVar4;
}

