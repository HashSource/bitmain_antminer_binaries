
int SHA256_Init(SHA256_CTX *c)

{
  memset(c,0,0x70);
  c->h[1] = 0xbb67ae85;
  c->h[0] = 0x6a09e667;
  c->h[2] = 0x3c6ef372;
  c->h[3] = 0xa54ff53a;
  c->h[4] = 0x510e527f;
  c->h[5] = 0x9b05688c;
  c->h[6] = 0x1f83d9ab;
  c->h[7] = 0x5be0cd19;
  c->md_len = 0x20;
  return 1;
}

