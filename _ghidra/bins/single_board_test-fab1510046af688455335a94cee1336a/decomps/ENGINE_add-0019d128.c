
int ENGINE_add(ENGINE *e)

{
  uint uVar1;
  int iVar2;
  ENGINE *pEVar3;
  char *__s2;
  
  if (e == (ENGINE *)0x0) {
    ERR_put_error(0x26,0x69,0x43,"eng_list.c",0x102);
    return 0;
  }
  if ((*(int *)e == 0) || (*(int *)(e + 4) == 0)) {
    ERR_put_error(0x26,0x69,0x6c,"eng_list.c",0x106);
  }
  CRYPTO_lock(9,0x1e,"eng_list.c",0x108);
  if (engine_list_head == (ENGINE *)0x0) {
    if (engine_list_tail == (ENGINE *)0x0) {
      *(undefined4 *)(e + 0x68) = 0;
      engine_list_head = e;
      engine_cleanup_add_last(0x19cf81);
LAB_0019d1b8:
      iVar2 = 1;
      engine_list_tail = e;
      *(undefined4 *)(e + 0x6c) = 0;
      *(int *)(e + 0x58) = *(int *)(e + 0x58) + 1;
      goto LAB_0019d1a0;
    }
    iVar2 = 0x7b;
LAB_0019d17e:
    ERR_put_error(0x26,0x78,0x6e,"eng_list.c",iVar2);
  }
  else {
    __s2 = *(char **)e;
    pEVar3 = engine_list_head;
    do {
      uVar1 = strcmp(*(char **)pEVar3,__s2);
      pEVar3 = *(ENGINE **)(pEVar3 + 0x6c);
      iVar2 = 1 - uVar1;
      if (1 < uVar1) {
        iVar2 = 0;
      }
    } while (uVar1 != 0 && pEVar3 != (ENGINE *)0x0);
    if (iVar2 == 0) {
      if ((engine_list_tail != (ENGINE *)0x0) && (*(int *)(engine_list_tail + 0x6c) == 0)) {
        *(ENGINE **)(engine_list_tail + 0x6c) = e;
        *(ENGINE **)(e + 0x68) = engine_list_tail;
        goto LAB_0019d1b8;
      }
      iVar2 = 0x87;
      goto LAB_0019d17e;
    }
    ERR_put_error(0x26,0x78,0x67,"eng_list.c",0x75);
  }
  iVar2 = 0;
  ERR_put_error(0x26,0x69,0x6e,"eng_list.c",0x10a);
LAB_0019d1a0:
  CRYPTO_lock(10,0x1e,"eng_list.c",0x10d);
  return iVar2;
}

