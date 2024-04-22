
int ssl23_num_ciphers(void)

{
  int iVar1;
  int iVar2;
  
  iVar1 = ssl3_num_ciphers();
  iVar2 = ssl2_num_ciphers();
  return iVar1 + iVar2;
}

