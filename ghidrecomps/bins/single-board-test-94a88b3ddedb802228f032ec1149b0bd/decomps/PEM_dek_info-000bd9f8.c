
void PEM_dek_info(char *buf,char *type,int len,char *str)

{
  int iVar1;
  size_t sVar2;
  char *pcVar3;
  byte *pbVar4;
  byte *pbVar5;
  size_t sVar6;
  
  BUF_strlcat(buf,DAT_000bda74,0x400);
  BUF_strlcat(buf,type,0x400);
  BUF_strlcat(buf,DAT_000bda78,0x400);
  sVar2 = strlen(buf);
  iVar1 = DAT_000bda7c;
  sVar6 = sVar2 + len * 2;
  if ((int)sVar6 < 0x400) {
    if (0 < len) {
      pcVar3 = buf + sVar2;
      pbVar4 = (byte *)str;
      do {
        *pcVar3 = *(char *)(iVar1 + (uint)(*pbVar4 >> 4));
        pbVar5 = pbVar4 + 1;
        pcVar3[1] = *(char *)(iVar1 + (*pbVar4 & 0xf));
        pcVar3 = pcVar3 + 2;
        pbVar4 = pbVar5;
        sVar2 = sVar6;
      } while (pbVar5 != (byte *)(str + len));
    }
    buf[sVar2] = '\n';
    buf[sVar2 + 1] = '\0';
  }
  return;
}

