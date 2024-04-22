
size_t mem_read(BIO *param_1,void *param_2,uint param_3)

{
  size_t sVar1;
  int iVar2;
  size_t *psVar3;
  bool bVar4;
  
  psVar3 = (size_t *)param_1->ptr;
  BIO_clear_flags(param_1,0xf);
  if ((-1 < (int)param_3) && (*psVar3 < param_3)) {
    param_3 = *psVar3;
  }
  bVar4 = (int)param_2 < 0;
  if (param_2 != (void *)0x0) {
    bVar4 = (int)param_3 < 0;
  }
  if ((param_2 != (void *)0x0 && param_3 != 0) && !bVar4) {
    memcpy(param_2,(void *)psVar3[1],param_3);
    iVar2 = param_1->flags;
    sVar1 = *psVar3;
    *psVar3 = sVar1 - param_3;
    if (iVar2 << 0x16 < 0) {
      psVar3[1] = psVar3[1] + param_3;
      return param_3;
    }
    memmove((void *)psVar3[1],(void *)((int)(void *)psVar3[1] + param_3),sVar1 - param_3);
  }
  else if ((*psVar3 == 0) && (param_3 = param_1->num, param_3 != 0)) {
    BIO_set_flags(param_1,9);
    return param_3;
  }
  return param_3;
}

