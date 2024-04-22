
int WHIRLPOOL_Update(WHIRLPOOL_CTX *c,void *inp,size_t bytes)

{
  uint uVar1;
  void *inp_00;
  
  uVar1 = bytes;
  inp_00 = inp;
  if (0xfffffff < bytes) {
    do {
      uVar1 = uVar1 + 0xf0000000;
      WHIRLPOOL_BitUpdate(c,inp_00,0x80000000);
      inp_00 = (void *)((int)inp_00 + 0x10000000);
    } while (0xfffffff < uVar1);
    uVar1 = bytes + 0xf0000000;
    bytes = bytes & 0xfffffff;
    inp = (void *)((uVar1 & 0xf0000000) + 0x10000000 + (int)inp);
  }
  if (bytes != 0) {
    WHIRLPOOL_BitUpdate(c,inp,bytes << 3);
  }
  return 1;
}

