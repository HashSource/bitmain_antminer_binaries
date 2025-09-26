
undefined4 init_certificate_authorities(int param_1)

{
  OPENSSL_sk_pop_free(*(undefined4 *)(*(int *)(param_1 + 0x7c) + 0x224),0x177669);
  *(undefined4 *)(*(int *)(param_1 + 0x7c) + 0x224) = 0;
  return 1;
}

