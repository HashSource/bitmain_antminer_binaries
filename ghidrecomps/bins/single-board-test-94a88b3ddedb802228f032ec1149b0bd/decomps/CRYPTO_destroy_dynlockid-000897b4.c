
void CRYPTO_destroy_dynlockid(int i)

{
  int iVar1;
  int *ptr;
  
  if (i != 0) {
    i = ~i;
  }
  if (dynlock_destroy_callback != (code *)0x0) {
    if (locking_callback != (code *)0x0) {
      (*locking_callback)(9,0x1d,"cryptlib.c",0x133);
    }
    if ((dyn_locks == (_STACK *)0x0) || (iVar1 = sk_num(dyn_locks), iVar1 <= i)) {
      if (locking_callback != (code *)0x0) {
        (*locking_callback)(10,0x1d,"cryptlib.c",0x136);
        return;
      }
      return;
    }
    ptr = (int *)sk_value(dyn_locks,i);
    if ((ptr == (int *)0x0) || (iVar1 = *ptr, *ptr = iVar1 + -1, 0 < iVar1 + -1)) {
      ptr = (int *)0x0;
    }
    else {
      sk_set(dyn_locks,i,(void *)0x0);
    }
    if (locking_callback != (code *)0x0) {
      (*locking_callback)(10,0x1d,"cryptlib.c",0x148);
    }
    if (ptr != (int *)0x0) {
      (*dynlock_destroy_callback)(ptr[1],"cryptlib.c",0x14b);
      CRYPTO_free(ptr);
      return;
    }
  }
  return;
}

