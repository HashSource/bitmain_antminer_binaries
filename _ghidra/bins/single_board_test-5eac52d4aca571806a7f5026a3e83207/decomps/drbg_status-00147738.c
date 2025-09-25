
bool drbg_status(void)

{
  int iVar1;
  int iVar2;
  
  iVar1 = RAND_DRBG_get0_master();
  if (iVar1 != 0) {
    rand_drbg_lock();
    iVar2 = *(int *)(iVar1 + 0x5c);
    rand_drbg_unlock(iVar1);
    return iVar2 == 1;
  }
  return false;
}

