
char * hex_to_string(uchar *buffer,long len)

{
  byte bVar1;
  byte *pbVar2;
  byte *pbVar3;
  char *pcVar4;
  char *pcVar5;
  
  if (buffer == (uchar *)0x0 || len == 0) {
    pcVar5 = (char *)0x0;
  }
  else {
    pcVar5 = (char *)CRYPTO_malloc(len * 3 + 1,"v3_utl.c",0x19f);
    if (pcVar5 == (char *)0x0) {
      ERR_put_error(0x22,0x6f,0x41,"v3_utl.c",0x1a0);
    }
    else {
      pcVar4 = pcVar5;
      if (0 < len) {
        pbVar2 = buffer;
        do {
          *pcVar4 = "0123456789ABCDEF"[*pbVar2 >> 4];
          pbVar3 = pbVar2 + 1;
          bVar1 = *pbVar2;
          pcVar4[2] = ':';
          pcVar4[1] = "0123456789ABCDEF"[bVar1 & 0xf];
          pcVar4 = pcVar4 + 3;
          pbVar2 = pbVar3;
        } while (pbVar3 != buffer + len);
        pcVar4 = pcVar5 + len * 3;
      }
      pcVar4[-1] = '\0';
    }
  }
  return pcVar5;
}

