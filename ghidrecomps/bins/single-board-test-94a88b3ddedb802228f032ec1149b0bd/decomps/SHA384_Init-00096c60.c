
int SHA384_Init(SHA512_CTX *c)

{
  *(undefined4 *)c->h = 0xc1059ed8;
  *(undefined4 *)((int)c->h + 4) = 0xcbbb9d5d;
  *(undefined4 *)(c->h + 2) = 0x3070dd17;
  *(undefined4 *)((int)c->h + 0x14) = 0x9159015a;
  *(undefined4 *)(c->h + 1) = 0x367cd507;
  *(undefined4 *)((int)c->h + 0xc) = 0x629a292a;
  *(undefined4 *)(c->h + 3) = 0xf70e5939;
  *(undefined4 *)((int)c->h + 0x1c) = 0x152fecd8;
  *(undefined4 *)(c->h + 7) = 0xbefa4fa4;
  *(undefined4 *)((int)c->h + 0x3c) = 0x47b5481d;
  *(undefined4 *)(c->h + 4) = 0xffc00b31;
  *(undefined4 *)((int)c->h + 0x24) = 0x67332667;
  *(undefined4 *)(c->h + 5) = 0x68581511;
  *(undefined4 *)((int)c->h + 0x2c) = 0x8eb44a87;
  *(undefined4 *)(c->h + 6) = 0x64f98fa7;
  *(undefined4 *)((int)c->h + 0x34) = 0xdb0c2e0d;
  c->num = 0;
  c->md_len = 0x30;
  *(undefined4 *)&c->Nl = 0;
  *(undefined4 *)((int)&c->Nl + 4) = 0;
  *(undefined4 *)&c->Nh = 0;
  *(undefined4 *)((int)&c->Nh + 4) = 0;
  return 1;
}

