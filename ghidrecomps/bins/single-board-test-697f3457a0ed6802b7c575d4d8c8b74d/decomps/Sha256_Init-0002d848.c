
void Sha256_Init(CSha256 *p)

{
  CSha256 *p_local;
  
  p->state[0] = 0x6a09e667;
  p->state[1] = 0xbb67ae85;
  p->state[2] = 0x3c6ef372;
  p->state[3] = 0xa54ff53a;
  p->state[4] = 0x510e527f;
  p->state[5] = 0x9b05688c;
  p->state[6] = 0x1f83d9ab;
  p->state[7] = 0x5be0cd19;
  *(undefined4 *)&p->count = 0;
  *(undefined4 *)((int)&p->count + 4) = 0;
  return;
}

