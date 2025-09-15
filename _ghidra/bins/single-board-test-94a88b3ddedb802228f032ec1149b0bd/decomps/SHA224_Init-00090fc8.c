
int SHA224_Init(SHA256_CTX *c)

{
  memset(c,0,0x70);
  c->h[1] = 0x367cd507;
  c->h[0] = 0xc1059ed8;
  c->h[2] = 0x3070dd17;
  c->h[3] = 0xf70e5939;
  c->h[4] = 0xffc00b31;
  c->h[5] = 0x68581511;
  c->h[6] = 0x64f98fa7;
  c->h[7] = 0xbefa4fa4;
  c->md_len = 0x1c;
  return 1;
}

