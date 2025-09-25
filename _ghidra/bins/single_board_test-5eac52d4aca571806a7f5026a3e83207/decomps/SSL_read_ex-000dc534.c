
uint SSL_read_ex(void)

{
  uint uVar1;
  
  uVar1 = ssl_read_internal();
  return uVar1 & ~((int)uVar1 >> 0x1f);
}

