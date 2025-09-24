
uint RSA_get_multi_prime_extra_count(int param_1)

{
  uint uVar1;
  
  uVar1 = OPENSSL_sk_num(*(undefined4 *)(param_1 + 0x30));
  return uVar1 & ~((int)uVar1 >> 0x1f);
}

