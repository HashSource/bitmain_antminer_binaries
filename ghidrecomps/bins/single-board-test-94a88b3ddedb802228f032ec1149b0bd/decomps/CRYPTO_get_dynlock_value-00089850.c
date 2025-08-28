
CRYPTO_dynlock_value * CRYPTO_get_dynlock_value(int i)

{
  int iVar1;
  int *piVar2;
  
  if (i != 0) {
    i = ~i;
  }
  if (locking_callback != (code *)0x0) {
    (*locking_callback)(9,0x1d,"cryptlib.c",0x156);
  }
  if ((dyn_locks == (_STACK *)0x0) || (iVar1 = sk_num(dyn_locks), iVar1 <= i)) {
    piVar2 = (int *)0x0;
  }
  else {
    piVar2 = (int *)sk_value(dyn_locks,i);
    if (piVar2 != (int *)0x0) {
      *piVar2 = *piVar2 + 1;
    }
  }
  if (locking_callback != (code *)0x0) {
    (*locking_callback)(10,0x1d,"cryptlib.c",0x15d);
  }
  if (piVar2 != (int *)0x0) {
    return (CRYPTO_dynlock_value *)piVar2[1];
  }
  return (CRYPTO_dynlock_value *)0x0;
}

