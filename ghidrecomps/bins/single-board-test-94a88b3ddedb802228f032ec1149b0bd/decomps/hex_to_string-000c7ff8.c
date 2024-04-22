
char * hex_to_string(uchar *buffer,long len)

{
  byte bVar1;
  int iVar2;
  byte *pbVar3;
  byte *pbVar4;
  char *pcVar5;
  char *pcVar6;
  
  if (buffer == (uchar *)0x0 || len == 0) {
    pcVar6 = (char *)0x0;
  }
  else {
    pcVar6 = (char *)CRYPTO_malloc(len * 3 + 1,DAT_000c8080,0x19f);
    iVar2 = DAT_000c8084;
    if (pcVar6 == (char *)0x0) {
      ERR_put_error(0x22,0x6f,0x41,DAT_000c8080,0x1a0);
    }
    else {
      pcVar5 = pcVar6;
      if (0 < len) {
        pbVar3 = buffer;
        do {
          *pcVar5 = *(char *)(iVar2 + (uint)(*pbVar3 >> 4));
          pbVar4 = pbVar3 + 1;
          bVar1 = *pbVar3;
          pcVar5[2] = ':';
          pcVar5[1] = *(char *)(iVar2 + (bVar1 & 0xf));
          pcVar5 = pcVar5 + 3;
          pbVar3 = pbVar4;
        } while (pbVar4 != buffer + len);
        pcVar5 = pcVar6 + len * 3;
      }
      pcVar5[-1] = '\0';
    }
  }
  return pcVar6;
}

