
void BN_CTX_secure_new(void)

{
  BN_CTX *pBVar1;
  
  pBVar1 = BN_CTX_new();
  if (pBVar1 != (BN_CTX *)0x0) {
    *(undefined4 *)(pBVar1 + 0x2c) = 8;
  }
  return;
}

