
size_t mem_gets(BIO *param_1,undefined *param_2,int param_3)

{
  char *pcVar1;
  size_t sVar2;
  int iVar3;
  uint *puVar4;
  uint __n;
  uint uVar5;
  size_t *psVar6;
  bool bVar7;
  
  puVar4 = (uint *)param_1->ptr;
  BIO_clear_flags(param_1,0xf);
  uVar5 = *puVar4;
  if (param_3 <= (int)uVar5) {
    uVar5 = param_3 - 1;
  }
  if ((int)uVar5 < 1) {
    *param_2 = 0;
    return 0;
  }
  __n = 0;
  do {
    pcVar1 = (char *)(puVar4[1] + __n);
    __n = __n + 1;
    if (*pcVar1 == '\n') break;
  } while (__n != uVar5);
  psVar6 = (size_t *)param_1->ptr;
  BIO_clear_flags(param_1,0xf);
  uVar5 = *psVar6;
  if (uVar5 <= __n) {
    __n = uVar5;
  }
  bVar7 = (int)param_2 < 0;
  if (param_2 != (undefined *)0x0) {
    bVar7 = (int)__n < 0;
  }
  if ((param_2 != (undefined *)0x0 && __n != 0) && !bVar7) {
    memcpy(param_2,(void *)psVar6[1],__n);
    iVar3 = param_1->flags;
    sVar2 = *psVar6;
    *psVar6 = sVar2 - __n;
    if (iVar3 << 0x16 < 0) {
      psVar6[1] = psVar6[1] + __n;
    }
    else {
      memmove((void *)psVar6[1],(void *)((int)(void *)psVar6[1] + __n),sVar2 - __n);
    }
  }
  else {
    if (uVar5 == 0) {
      __n = param_1->num;
      if (__n == 0) {
        return 0;
      }
      BIO_set_flags(param_1,9);
    }
    if ((int)__n < 1) {
      return __n;
    }
  }
  param_2[__n] = 0;
  return __n;
}

