
bool openssl_strerror_r(void)

{
  int iVar1;
  
  iVar1 = __xpg_strerror_r();
  return iVar1 == 0;
}

