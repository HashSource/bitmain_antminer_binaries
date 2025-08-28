
void engine_list_cleanup(void)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  if (engine_list_head != 0) {
    do {
      iVar1 = engine_list_head;
      CRYPTO_lock(9,0x1e,"eng_list.c",0x119);
      iVar2 = engine_list_head;
      iVar4 = engine_list_head;
      if (engine_list_head != iVar1 && engine_list_head != 0) {
        do {
          iVar4 = *(int *)(iVar4 + 0x6c);
        } while (iVar4 != iVar1 && iVar4 != 0);
      }
      if (iVar4 == 0) {
        ERR_put_error(0x26,0x79,0x69,"eng_list.c",0xa6);
        ERR_put_error(0x26,0x7b,0x6e,"eng_list.c",0x11b);
      }
      else {
        iVar4 = *(int *)(iVar1 + 0x6c);
        if (iVar4 != 0) {
          *(undefined4 *)(iVar4 + 0x68) = *(undefined4 *)(iVar1 + 0x68);
        }
        iVar3 = *(int *)(iVar1 + 0x68);
        if (iVar3 != 0) {
          *(int *)(iVar3 + 0x6c) = iVar4;
        }
        if (iVar1 == iVar2) {
          engine_list_head = *(int *)(iVar1 + 0x6c);
        }
        if (iVar1 == engine_list_tail) {
          engine_list_tail = iVar3;
        }
        engine_free_util(iVar1,0);
      }
      CRYPTO_lock(10,0x1e,"eng_list.c",0x11e);
    } while (engine_list_head != 0);
  }
  return;
}

