
void * mem_gets(BIO *param_1,undefined1 *param_2,int param_3)

{
  char *pcVar1;
  void *pvVar2;
  BIO_METHOD *pBVar3;
  void *__n;
  BIO_METHOD *pBVar4;
  bool bVar5;
  
  pBVar4 = (BIO_METHOD *)param_1->next_bio->callback;
  if (param_1->retry_reason << 0x16 < 0) {
    pBVar4 = param_1->next_bio->method;
  }
  BIO_clear_flags(param_1,0xf);
  __n = (void *)pBVar4->type;
  if (param_3 <= (int)__n) {
    __n = (void *)(param_3 + -1);
  }
  if ((int)__n < 1) {
    *param_2 = 0;
    return (void *)0x0;
  }
  pvVar2 = (void *)0x0;
  pcVar1 = pBVar4->name + -1;
  do {
    pcVar1 = pcVar1 + 1;
    if (*pcVar1 == '\n') {
      __n = (void *)((int)pvVar2 + 1);
      break;
    }
    pvVar2 = (void *)((int)pvVar2 + 1);
  } while (__n != pvVar2);
  pBVar4 = param_1->next_bio->method;
  pBVar3 = (BIO_METHOD *)param_1->next_bio->callback;
  if (param_1->retry_reason << 0x16 < 0) {
    BIO_clear_flags(param_1,0xf);
  }
  else {
    BIO_clear_flags(param_1,0xf);
    pBVar4 = pBVar3;
  }
  pvVar2 = (void *)pBVar4->type;
  if (pvVar2 <= __n) {
    __n = pvVar2;
  }
  bVar5 = (int)param_2 < 0;
  if (param_2 != (undefined1 *)0x0) {
    bVar5 = (int)__n < 0;
  }
  if ((param_2 != (undefined1 *)0x0 && __n != (void *)0x0) && !bVar5) {
    memcpy(param_2,pBVar4->name,(size_t)__n);
    pBVar4->name = pBVar4->name + (int)__n;
    pBVar4->type = pBVar4->type - (int)__n;
    pBVar4->bwrite = pBVar4->bwrite + -(int)__n;
    param_2[(int)__n] = 0;
    return __n;
  }
  if (pvVar2 == (void *)0x0) {
    __n = param_1->ptr;
    if (__n == (void *)0x0) {
      return (void *)0x0;
    }
    BIO_set_flags(param_1,9);
  }
  if ((int)__n < 1) {
    return __n;
  }
  param_2[(int)__n] = 0;
  return __n;
}

