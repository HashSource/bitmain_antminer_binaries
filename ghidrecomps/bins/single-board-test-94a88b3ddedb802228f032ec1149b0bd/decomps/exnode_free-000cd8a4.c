
void exnode_free(int **param_1)

{
  if ((*param_1 != (int *)0x0) && (**param_1 << 0x1c < 0)) {
    CRYPTO_free(param_1);
    return;
  }
  return;
}

