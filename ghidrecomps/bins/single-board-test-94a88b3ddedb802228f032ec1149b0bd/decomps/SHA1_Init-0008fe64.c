
int SHA1_Init(SHA_CTX *c)

{
  memset(c,0,0x60);
  c->h0 = 0x67452301;
  c->h1 = 0xefcdab89;
  c->h2 = 0x98badcfe;
  c->h3 = 0x10325476;
  c->h4 = 0xc3d2e1f0;
  return 1;
}

