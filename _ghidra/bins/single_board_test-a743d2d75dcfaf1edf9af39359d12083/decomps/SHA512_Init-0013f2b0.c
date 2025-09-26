
int SHA512_Init(SHA512_CTX *c)

{
  *(undefined4 *)c->h = 0xf3bcc908;
  *(undefined4 *)((int)c->h + 4) = 0x6a09e667;
  *(undefined4 *)(c->h + 2) = 0xfe94f82b;
  *(undefined4 *)((int)c->h + 0x14) = 0x3c6ef372;
  *(undefined4 *)(c->h + 1) = 0x84caa73b;
  *(undefined4 *)((int)c->h + 0xc) = 0xbb67ae85;
  *(undefined4 *)(c->h + 3) = 0x5f1d36f1;
  *(undefined4 *)((int)c->h + 0x1c) = 0xa54ff53a;
  *(undefined4 *)(c->h + 7) = 0x137e2179;
  *(undefined4 *)((int)c->h + 0x3c) = 0x5be0cd19;
  *(undefined4 *)(c->h + 4) = 0xade682d1;
  *(undefined4 *)((int)c->h + 0x24) = 0x510e527f;
  *(undefined4 *)(c->h + 5) = 0x2b3e6c1f;
  *(undefined4 *)((int)c->h + 0x2c) = 0x9b05688c;
  *(undefined4 *)(c->h + 6) = 0xfb41bd6b;
  *(undefined4 *)((int)c->h + 0x34) = 0x1f83d9ab;
  c->num = 0;
  c->md_len = 0x40;
  *(undefined4 *)&c->Nl = 0;
  *(undefined4 *)((int)&c->Nl + 4) = 0;
  *(undefined4 *)&c->Nh = 0;
  *(undefined4 *)((int)&c->Nh + 4) = 0;
  return 1;
}

