
size_t buffer_read(BIO *param_1,void *param_2,size_t param_3)

{
  size_t sVar1;
  bio_st *pbVar2;
  void *data;
  size_t sVar3;
  size_t __n;
  bool bVar4;
  
  if (param_2 == (void *)0x0) {
    return 0;
  }
  pbVar2 = param_1->next_bio;
  if (pbVar2 != (bio_st *)0x0) {
    if (param_1->prev_bio == (bio_st *)0x0) {
      return 0;
    }
    sVar3 = 0;
    BIO_clear_flags(param_1,0xf);
    sVar1 = pbVar2->init;
    while( true ) {
      __n = param_3;
      if ((int)sVar1 <= (int)param_3) {
        __n = sVar1;
      }
      data = param_2;
      if (sVar1 != 0) {
        sVar3 = __n + sVar3;
        data = (void *)((int)param_2 + __n);
        memcpy(param_2,pbVar2->cb_arg + pbVar2->shutdown,__n);
        bVar4 = param_3 == __n;
        param_3 = param_3 - __n;
        pbVar2->shutdown = __n + pbVar2->shutdown;
        pbVar2->init = pbVar2->init - __n;
        if (bVar4) {
          return sVar3;
        }
      }
      if ((int)pbVar2->method < (int)param_3) break;
      sVar1 = BIO_read(param_1->prev_bio,pbVar2->cb_arg,(int)pbVar2->method);
      if ((int)sVar1 < 1) {
        BIO_copy_next_retry(param_1);
        if (0 < (int)sVar3 || sVar1 == 0) {
          sVar1 = sVar3;
        }
        return sVar1;
      }
      pbVar2->shutdown = 0;
      pbVar2->init = sVar1;
      param_2 = data;
    }
    do {
      sVar1 = BIO_read(param_1->prev_bio,data,param_3);
      data = (void *)((int)data + sVar1);
      if ((int)sVar1 < 1) {
        BIO_copy_next_retry(param_1);
        if (0 < (int)sVar3 || sVar1 == 0) {
          sVar1 = sVar3;
        }
        return sVar1;
      }
      bVar4 = param_3 != sVar1;
      sVar3 = sVar1 + sVar3;
      param_3 = param_3 - sVar1;
    } while (bVar4);
    return sVar3;
  }
  return 0;
}

