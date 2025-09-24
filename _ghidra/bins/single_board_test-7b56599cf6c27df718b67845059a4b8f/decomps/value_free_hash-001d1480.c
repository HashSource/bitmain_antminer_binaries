
void value_free_hash(int param_1,undefined4 param_2)

{
  if (*(int *)(param_1 + 4) != 0) {
    OPENSSL_LH_delete(param_2,param_1);
    return;
  }
  return;
}

