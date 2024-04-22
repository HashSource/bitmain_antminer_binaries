
int CRYPTO_add_lock(int *pointer,int amount,int type,char *file,int line)

{
  int iVar1;
  CRYPTO_dynlock_value *pCVar2;
  int iVar3;
  int iVar4;
  code *pcVar5;
  
  iVar1 = DAT_00089ad0;
  if (*(code **)(DAT_00089ad0 + 0x14) == (code *)0x0) {
    if (type < 0) {
      if (*(int *)(DAT_00089ad0 + 8) != 0) {
        pCVar2 = CRYPTO_get_dynlock_value(type);
        if (pCVar2 != (CRYPTO_dynlock_value *)0x0) {
          (**(code **)(iVar1 + 8))(9,pCVar2,file,line);
          CRYPTO_destroy_dynlockid(type);
          iVar3 = *(int *)(iVar1 + 8);
          iVar4 = amount + *pointer;
          *pointer = iVar4;
          if (iVar3 == 0) {
            return iVar4;
          }
          pCVar2 = CRYPTO_get_dynlock_value(type);
          if (pCVar2 != (CRYPTO_dynlock_value *)0x0) {
            (**(code **)(iVar1 + 8))(10,pCVar2,file,line);
            CRYPTO_destroy_dynlockid(type);
            return iVar4;
          }
        }
        CRYPTO_lock_part_0(pCVar2,pCVar2);
        return stderr;
      }
    }
    else if (*(code **)(DAT_00089ad0 + 0x10) != (code *)0x0) {
      (**(code **)(DAT_00089ad0 + 0x10))(9,type,file,line);
      pcVar5 = *(code **)(iVar1 + 0x10);
      iVar1 = amount + *pointer;
      *pointer = iVar1;
      if (pcVar5 == (code *)0x0) {
        return iVar1;
      }
      (*pcVar5)(10,type,file,line);
      return iVar1;
    }
    iVar1 = amount + *pointer;
    *pointer = iVar1;
  }
  else {
    iVar1 = (**(code **)(DAT_00089ad0 + 0x14))();
  }
  return iVar1;
}

