
int CRYPTO_set_mem_debug(void)

{
  int iVar1;
  
  iVar1 = allow_customize;
  if (allow_customize != 0) {
    iVar1 = 1;
  }
  return iVar1;
}

