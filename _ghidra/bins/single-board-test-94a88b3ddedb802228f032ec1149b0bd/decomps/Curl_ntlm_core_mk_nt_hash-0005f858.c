
undefined4 Curl_ntlm_core_mk_nt_hash(undefined4 param_1,char *param_2,uchar *param_3)

{
  char cVar1;
  size_t sVar2;
  char *data;
  undefined4 uVar3;
  char *pcVar4;
  size_t len;
  MD4_CTX MStack_7c;
  
  sVar2 = strlen(param_2);
  len = sVar2 * 2;
  data = (char *)(*Curl_cmalloc)(len);
  uVar3 = 0x1b;
  if (data != (char *)0x0) {
    if (sVar2 != 0) {
      param_2 = param_2 + -1;
      pcVar4 = data;
      do {
        param_2 = param_2 + 1;
        cVar1 = *param_2;
        pcVar4[1] = '\0';
        *pcVar4 = cVar1;
        pcVar4 = pcVar4 + 2;
      } while (pcVar4 != data + len);
    }
    MD4_Init(&MStack_7c);
    MD4_Update(&MStack_7c,data,len);
    MD4_Final(param_3,&MStack_7c);
    param_3[0x10] = '\0';
    param_3[0x11] = '\0';
    param_3[0x12] = '\0';
    param_3[0x13] = '\0';
    param_3[0x14] = '\0';
    (*Curl_cfree)(data);
    uVar3 = 0;
  }
  return uVar3;
}

