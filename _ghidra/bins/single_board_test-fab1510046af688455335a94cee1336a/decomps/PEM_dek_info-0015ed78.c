
void PEM_dek_info(char *buf,char *type,int len,char *str)

{
  size_t sVar1;
  char *pcVar2;
  byte *pbVar3;
  byte *pbVar4;
  size_t sVar5;
  
  BUF_strlcat(buf,"DEK-Info: ",0x400);
  BUF_strlcat(buf,type,0x400);
  BUF_strlcat(buf,",",0x400);
  sVar1 = strlen(buf);
  sVar5 = sVar1 + len * 2;
  if ((int)sVar5 < 0x400) {
    if (0 < len) {
      pcVar2 = buf + sVar1;
      pbVar3 = (byte *)str;
      do {
        *pcVar2 = "0123456789ABCDEF"[*pbVar3 >> 4];
        pbVar4 = pbVar3 + 1;
        pcVar2[1] = "0123456789ABCDEF"[*pbVar3 & 0xf];
        pcVar2 = pcVar2 + 2;
        pbVar3 = pbVar4;
        sVar1 = sVar5;
      } while (pbVar4 != (byte *)(str + len));
    }
    buf[sVar1] = '\n';
    buf[sVar1 + 1] = '\0';
  }
  return;
}

