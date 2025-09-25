
void * mem_read(BIO *param_1,void *param_2,void *param_3)

{
  void *pvVar1;
  BIO_METHOD *pBVar2;
  bool bVar3;
  
  pBVar2 = (BIO_METHOD *)param_1->next_bio->callback;
  if (param_1->retry_reason << 0x16 < 0) {
    pBVar2 = param_1->next_bio->method;
  }
  BIO_clear_flags(param_1,0xf);
  pvVar1 = (void *)pBVar2->type;
  if (-1 < (int)param_3) {
    if (pvVar1 <= param_3) {
      param_3 = pvVar1;
    }
    bVar3 = (int)param_2 < 0;
    if (param_2 != (void *)0x0) {
      bVar3 = (int)param_3 < 0;
    }
    if ((param_2 != (void *)0x0 && param_3 != (void *)0x0) && !bVar3) {
      memcpy(param_2,pBVar2->name,(size_t)param_3);
      pBVar2->type = pBVar2->type - (int)param_3;
      pBVar2->bwrite = pBVar2->bwrite + -(int)param_3;
      pBVar2->name = pBVar2->name + (int)param_3;
      return param_3;
    }
  }
  if ((pvVar1 == (void *)0x0) && (param_3 = param_1->ptr, param_3 != (void *)0x0)) {
    BIO_set_flags(param_1,9);
    return param_3;
  }
  return param_3;
}

