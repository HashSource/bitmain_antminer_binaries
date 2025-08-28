
int CRYPTO_add_lock(int *pointer,int amount,int type,char *file,int line)

{
  code *pcVar1;
  int iVar2;
  CRYPTO_dynlock_value *pCVar3;
  
  if (add_lock_callback == (code *)0x0) {
    if (type < 0) {
      if (dynlock_lock_callback != (code *)0x0) {
        pCVar3 = CRYPTO_get_dynlock_value(type);
        if (pCVar3 != (CRYPTO_dynlock_value *)0x0) {
          (*dynlock_lock_callback)(9,pCVar3,file,line);
          CRYPTO_destroy_dynlockid(type);
          pcVar1 = dynlock_lock_callback;
          iVar2 = amount + *pointer;
          *pointer = iVar2;
          if (pcVar1 == (code *)0x0) {
            return iVar2;
          }
          pCVar3 = CRYPTO_get_dynlock_value(type);
          if (pCVar3 != (CRYPTO_dynlock_value *)0x0) {
            (*dynlock_lock_callback)(10,pCVar3,file,line);
            CRYPTO_destroy_dynlockid(type);
            return iVar2;
          }
        }
        CRYPTO_lock_part_0(pCVar3,pCVar3);
        return stderr;
      }
    }
    else if (locking_callback != (code *)0x0) {
      (*locking_callback)(9,type,file,line);
      pcVar1 = locking_callback;
      iVar2 = amount + *pointer;
      *pointer = iVar2;
      if (pcVar1 == (code *)0x0) {
        return iVar2;
      }
      (*pcVar1)(10,type,file,line);
      return iVar2;
    }
    iVar2 = amount + *pointer;
    *pointer = iVar2;
  }
  else {
    iVar2 = (*add_lock_callback)();
  }
  return iVar2;
}

