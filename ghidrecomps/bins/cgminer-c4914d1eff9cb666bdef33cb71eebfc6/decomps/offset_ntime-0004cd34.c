
char * offset_ntime(char *ntime,int noffset)

{
  uint uVar1;
  char *pcVar2;
  int noffset_local;
  char *ntime_local;
  uchar bin [4];
  uint32_t h32;
  uint32_t *be32;
  
  hex2bin(bin,ntime,4);
  uVar1 = __bswap_32((uint)bin);
  bin = (uchar  [4])__bswap_32(noffset + uVar1);
  pcVar2 = bin2hex(bin,4);
  return pcVar2;
}

