
void init384(int param_1)

{
  SHA384_Init(*(SHA512_CTX **)(param_1 + 0xc));
  return;
}

