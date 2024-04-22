
undefined4 gost_cipher_cleanup(int param_1)

{
  gost_destroy(*(int *)(param_1 + 0x60) + 0xc);
  *(undefined4 *)(param_1 + 0x54) = 0;
  return 1;
}

