
uint SSL_write_ex(void)

{
  uint uVar1;
  
  uVar1 = ssl_write_internal();
  return uVar1 & ~((int)uVar1 >> 0x1f);
}

