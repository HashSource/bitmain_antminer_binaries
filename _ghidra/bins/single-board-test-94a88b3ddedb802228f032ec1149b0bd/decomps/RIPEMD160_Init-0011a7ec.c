
int RIPEMD160_Init(RIPEMD160_CTX *c)

{
  memset(c,0,0x60);
  c->A = 0x67452301;
  c->B = 0xefcdab89;
  c->C = 0x98badcfe;
  c->D = 0x10325476;
  c->E = 0xc3d2e1f0;
  return 1;
}

