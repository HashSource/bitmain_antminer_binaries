
void ssl23_get_cipher_by_char(undefined4 param_1)

{
  int iVar1;
  
  iVar1 = ssl3_get_cipher_by_char();
  if (iVar1 != 0) {
    return;
  }
  ssl2_get_cipher_by_char(param_1);
  return;
}

