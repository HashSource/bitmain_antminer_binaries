
size_t buffer_read(BIO *param_1,void *param_2,size_t param_3)

{
  size_t sVar1;
  int *piVar2;
  void *data;
  size_t sVar3;
  size_t __n;
  bool bVar4;
  
  if (param_2 == (void *)0x0) {
    return 0;
  }
  piVar2 = (int *)param_1->ptr;
  if (piVar2 == (int *)0x0) {
    return 0;
  }
  if (param_1->next_bio == (bio_st *)0x0) {
    return 0;
  }
  sVar3 = 0;
  BIO_clear_flags(param_1,0xf);
  sVar1 = piVar2[3];
  while( true ) {
    __n = sVar1;
    if ((int)param_3 <= (int)sVar1) {
      __n = param_3;
    }
    data = param_2;
    if (sVar1 != 0) {
      sVar3 = __n + sVar3;
      data = (void *)((int)param_2 + __n);
      memcpy(param_2,(void *)(piVar2[2] + piVar2[4]),__n);
      bVar4 = param_3 == __n;
      param_3 = param_3 - __n;
      piVar2[4] = __n + piVar2[4];
      piVar2[3] = piVar2[3] - __n;
      if (bVar4) {
        return sVar3;
      }
    }
    if (*piVar2 < (int)param_3) {
      while( true ) {
        sVar1 = BIO_read(param_1->next_bio,data,param_3);
        data = (void *)((int)data + sVar1);
        if ((int)sVar1 < 1) break;
        bVar4 = param_3 == sVar1;
        sVar3 = sVar1 + sVar3;
        param_3 = param_3 - sVar1;
        if (bVar4) {
          return sVar3;
        }
      }
      BIO_copy_next_retry(param_1);
      if (sVar1 == 0) {
        return sVar3;
      }
      if (0 < (int)sVar3) {
        return sVar3;
      }
      return sVar1;
    }
    sVar1 = BIO_read(param_1->next_bio,(void *)piVar2[2],*piVar2);
    if ((int)sVar1 < 1) break;
    piVar2[4] = 0;
    piVar2[3] = sVar1;
    param_2 = data;
  }
  BIO_copy_next_retry(param_1);
  if (sVar1 == 0) {
    return sVar3;
  }
  if (0 < (int)sVar3) {
    return sVar3;
  }
  return sVar1;
}

