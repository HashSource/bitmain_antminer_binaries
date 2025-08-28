
int SSL_CTX_get0_certificate(int param_1)

{
  undefined4 *puVar1;
  
  puVar1 = *(undefined4 **)(param_1 + 0xb0);
  if (puVar1 != (undefined4 *)0x0) {
    puVar1 = *(undefined4 **)*puVar1;
  }
  return (int)puVar1;
}

