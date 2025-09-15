
char * offset_ntime(char *ntime,int noffset)

{
  char *pcVar1;
  uint uVar2;
  uint __bsx;
  int noffset_local;
  char *ntime_local;
  uchar bin [4];
  uint h32;
  uint *be32;
  
  hex2bin(bin,ntime,4);
  uVar2 = ((uint)bin >> 0x18 | ((uint)bin & 0xff0000) >> 8 | ((uint)bin & 0xff00) << 8 |
          (int)bin << 0x18) + noffset;
  bin = (uchar  [4])
        (uVar2 >> 0x18 | (uVar2 & 0xff0000) >> 8 | (uVar2 & 0xff00) << 8 | uVar2 * 0x1000000);
  pcVar1 = bin2hex(bin,4);
  return pcVar1;
}

