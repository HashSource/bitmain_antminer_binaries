
int X25519(void *param_1)

{
  int iVar1;
  
  x25519_scalar_mult_generic();
  iVar1 = CRYPTO_memcmp(kZeros_12885,param_1,0x20);
  if (iVar1 != 0) {
    iVar1 = 1;
  }
  return iVar1;
}

