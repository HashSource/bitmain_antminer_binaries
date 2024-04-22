
void update256(int param_1,void *param_2,size_t param_3)

{
  SHA256_Update(*(SHA256_CTX **)(param_1 + 0xc),param_2,param_3);
  return;
}

