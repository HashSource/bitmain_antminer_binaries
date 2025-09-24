
int DES_set_key(const_DES_cblock *key,DES_key_schedule *schedule)

{
  int iVar1;
  
  if (_shadow_DES_check_key == 0) {
    DES_set_key_unchecked(key,schedule);
    return 0;
  }
  iVar1 = DES_set_key_checked(key,schedule);
  return iVar1;
}

