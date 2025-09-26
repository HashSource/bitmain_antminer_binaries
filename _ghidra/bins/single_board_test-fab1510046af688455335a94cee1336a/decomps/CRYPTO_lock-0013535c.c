
void CRYPTO_lock(int mode,int type,char *file,int line)

{
  code *pcVar1;
  CRYPTO_dynlock_value *pCVar2;
  int iVar3;
  undefined4 *ptr;
  
  if (type < 0) {
    if (dynlock_lock_callback != (code *)0x0) {
      pCVar2 = CRYPTO_get_dynlock_value(type);
      if (pCVar2 != (CRYPTO_dynlock_value *)0x0) {
        (*dynlock_lock_callback)(mode,pCVar2,file,line);
        CRYPTO_destroy_dynlockid(type);
        return;
      }
      iVar3 = CRYPTO_lock_part_0(0,0);
      *(int *)(iVar3 + 0x5c) = iVar3;
      if (dynlock_create_callback == (code *)0x0) {
        ERR_put_error(0xf,0x67,100,"cryptlib.c",0xf8);
      }
      else {
        if (locking_callback != (code *)0x0) {
          (*locking_callback)(9,0x1d,"cryptlib.c",0xfb);
        }
        if ((dyn_locks == (_STACK *)0x0) && (dyn_locks = sk_new_null(), dyn_locks == (_STACK *)0x0))
        {
          if (locking_callback != (code *)0x0) {
            (*locking_callback)(10,0x1d,"cryptlib.c",0xfe);
          }
          iVar3 = 0xff;
        }
        else {
          if (locking_callback != (code *)0x0) {
            (*locking_callback)(10,0x1d,"cryptlib.c",0x102);
          }
          ptr = (undefined4 *)CRYPTO_malloc(8,"cryptlib.c",0x104);
          pcVar1 = dynlock_create_callback;
          iVar3 = 0x106;
          if (ptr != (undefined4 *)0x0) {
            *ptr = 1;
            iVar3 = (*pcVar1)("cryptlib.c",0x10a);
            ptr[1] = iVar3;
            if (iVar3 != 0) {
              if (locking_callback != (code *)0x0) {
                (*locking_callback)(9,0x1d,"cryptlib.c",0x111);
              }
              iVar3 = sk_find(dyn_locks,(void *)0x0);
              if (iVar3 == -1) {
                iVar3 = sk_push(dyn_locks,ptr);
                iVar3 = iVar3 + -1;
              }
              else {
                sk_set(dyn_locks,iVar3,ptr);
              }
              if (locking_callback != (code *)0x0) {
                (*locking_callback)(10,0x1d,"cryptlib.c",0x121);
              }
              if (iVar3 != -1) {
                return;
              }
              (*dynlock_destroy_callback)(ptr[1],"cryptlib.c",0x124);
              CRYPTO_free(ptr);
              return;
            }
            CRYPTO_free(ptr);
            iVar3 = 0x10d;
          }
        }
        ERR_put_error(0xf,0x67,0x41,"cryptlib.c",iVar3);
      }
      return;
    }
  }
  else if (locking_callback != (code *)0x0) {
    (*locking_callback)();
  }
  return;
}

