
void update512(int param_1,void *param_2,size_t param_3)

{
  SHA512_Update(*(SHA512_CTX **)(param_1 + 0xc),param_2,param_3);
  return;
}

