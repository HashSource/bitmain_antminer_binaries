
undefined4 rsa_ossl_init(int param_1)

{
  *(uint *)(param_1 + 0x40) = *(uint *)(param_1 + 0x40) | 6;
  return 1;
}

