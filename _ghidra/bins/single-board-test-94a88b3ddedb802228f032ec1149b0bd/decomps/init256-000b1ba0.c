
void init256(int param_1)

{
  SHA256_Init(*(SHA256_CTX **)(param_1 + 0xc));
  return;
}

