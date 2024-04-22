
int ec_pre_comp_dup(int param_1)

{
  CRYPTO_add_lock((int *)(param_1 + 0x18),1,0x24,"ec_mult.c",0x7c);
  return param_1;
}

