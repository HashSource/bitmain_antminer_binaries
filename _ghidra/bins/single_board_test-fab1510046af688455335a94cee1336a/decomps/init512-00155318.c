
void init512(int param_1)

{
  SHA512_Init(*(SHA512_CTX **)(param_1 + 0xc));
  return;
}

