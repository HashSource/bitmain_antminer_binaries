
void pkey_free_gost94(int param_1)

{
  if (*(DSA **)(param_1 + 0x14) != (DSA *)0x0) {
    DSA_free(*(DSA **)(param_1 + 0x14));
    return;
  }
  return;
}

