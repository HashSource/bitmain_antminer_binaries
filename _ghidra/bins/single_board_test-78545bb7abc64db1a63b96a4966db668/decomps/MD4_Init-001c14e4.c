
int MD4_Init(MD4_CTX *c)

{
  memset(c,0,0x5c);
  c->A = 0x67452301;
  c->B = 0xefcdab89;
  c->C = 0x98badcfe;
  c->D = 0x10325476;
  return 1;
}

