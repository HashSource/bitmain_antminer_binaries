
void update(int param_1,void *param_2,size_t param_3)

{
  RIPEMD160_Update(*(RIPEMD160_CTX **)(param_1 + 0xc),param_2,param_3);
  return;
}

