
int DES_set_key_checked(const_DES_cblock *key,DES_key_schedule *schedule)

{
  int iVar1;
  
  iVar1 = DES_check_key_parity(key);
  if (iVar1 == 0) {
    iVar1 = -1;
  }
  else {
    iVar1 = DES_is_weak_key(key);
    if (iVar1 == 0) {
      DES_set_key_unchecked(key,schedule);
      iVar1 = 0;
    }
    else {
      iVar1 = -2;
    }
  }
  return iVar1;
}

