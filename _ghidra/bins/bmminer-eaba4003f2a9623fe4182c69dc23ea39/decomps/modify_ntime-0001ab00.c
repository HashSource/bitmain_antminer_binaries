
void modify_ntime(char *ntime,int noffset)

{
  uint uVar1;
  uint __bsx;
  int noffset_local;
  char *ntime_local;
  uchar bin [4];
  uint h32;
  uint *be32;
  
  hex2bin(bin,ntime,4);
  uVar1 = ((uint)bin >> 0x18 | ((uint)bin & 0xff0000) >> 8 | ((uint)bin & 0xff00) << 8 |
          (int)bin << 0x18) + noffset;
  bin = (uchar  [4])
        (uVar1 >> 0x18 | (uVar1 & 0xff0000) >> 8 | (uVar1 & 0xff00) << 8 | uVar1 * 0x1000000);
  __bin2hex(ntime,bin,4);
  return;
}

