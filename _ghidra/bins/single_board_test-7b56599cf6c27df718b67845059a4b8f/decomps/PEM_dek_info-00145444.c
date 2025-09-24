
void PEM_dek_info(char *buf,char *type,int len,char *str)

{
  size_t sVar1;
  int iVar2;
  size_t n;
  char *buf_00;
  byte *pbVar3;
  byte *pbVar4;
  
  sVar1 = strlen(buf);
  iVar2 = BIO_snprintf(buf + sVar1,0x400 - sVar1,"DEK-Info: %s,",type);
  if (0 < iVar2) {
    n = (0x400 - sVar1) - iVar2;
    buf_00 = buf + sVar1 + iVar2;
    if (0 < len) {
      pbVar3 = (byte *)str;
      do {
        pbVar4 = pbVar3 + 1;
        iVar2 = BIO_snprintf(buf_00,n,"%02X",(uint)*pbVar3);
        n = n - iVar2;
        buf_00 = buf_00 + iVar2;
        if (iVar2 < 1) {
          return;
        }
        pbVar3 = pbVar4;
      } while (pbVar4 != (byte *)(str + len));
    }
    if (1 < (int)n) {
      buf_00[0] = '\n';
      buf_00[1] = '\0';
      return;
    }
  }
  return;
}

