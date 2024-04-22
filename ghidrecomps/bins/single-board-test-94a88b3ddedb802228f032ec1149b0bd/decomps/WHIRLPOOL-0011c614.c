
uchar * WHIRLPOOL(void *inp,size_t bytes,uchar *md)

{
  void *inp_00;
  uint uVar1;
  WHIRLPOOL_CTX WStack_c8;
  
  if (md == (uchar *)0x0) {
    md = DAT_0011c688;
  }
  memset(&WStack_c8,0,0xa8);
  inp_00 = inp;
  uVar1 = bytes;
  if (0xfffffff < bytes) {
    do {
      uVar1 = uVar1 + 0xf0000000;
      WHIRLPOOL_BitUpdate(&WStack_c8,inp_00,0x80000000);
      inp_00 = (void *)((int)inp_00 + 0x10000000);
    } while (0xfffffff < uVar1);
    uVar1 = bytes + 0xf0000000;
    bytes = bytes & 0xfffffff;
    inp = (void *)((int)inp + (uVar1 & 0xf0000000) + 0x10000000);
  }
  if (bytes != 0) {
    WHIRLPOOL_BitUpdate(&WStack_c8,inp,bytes << 3);
  }
  WHIRLPOOL_Final(md,&WStack_c8);
  return md;
}

