
uint BIO_closesocket(int param_1)

{
  uint uVar1;
  
  uVar1 = close(param_1);
  return ~uVar1 >> 0x1f;
}

