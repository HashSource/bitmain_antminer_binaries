
int dtls1_get_cipher(void)

{
  int iVar1;
  
  iVar1 = ssl3_get_cipher();
  if ((iVar1 != 0) && (*(int *)(iVar1 + 0x14) == 4)) {
    iVar1 = 0;
  }
  return iVar1;
}

