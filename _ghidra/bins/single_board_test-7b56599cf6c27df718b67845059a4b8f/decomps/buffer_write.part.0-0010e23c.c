
int buffer_write_part_0(BIO *param_1,void *param_2,size_t param_3)

{
  int iVar1;
  int iVar2;
  int len;
  _func_745 *p_Var3;
  size_t __n;
  bio_st *pbVar4;
  void *pvVar5;
  int iVar6;
  
  pbVar4 = param_1->next_bio;
  if (pbVar4 == (bio_st *)0x0) {
    return 0;
  }
  if (param_1->prev_bio == (bio_st *)0x0) {
    return 0;
  }
  iVar6 = 0;
  BIO_clear_flags(param_1,0xf);
  p_Var3 = pbVar4->callback;
  do {
    len = pbVar4->retry_reason;
    iVar2 = pbVar4->num;
    iVar1 = len + iVar2;
    __n = (int)p_Var3 - iVar1;
    if ((int)param_3 <= (int)__n) {
      memcpy((void *)(iVar1 + pbVar4->flags),param_2,param_3);
      pbVar4->retry_reason = param_3 + pbVar4->retry_reason;
      return param_3 + iVar6;
    }
    if (len != 0) {
      pvVar5 = param_2;
      if (0 < (int)__n) {
        param_3 = param_3 - __n;
        iVar6 = iVar6 + __n;
        pvVar5 = (void *)((int)param_2 + __n);
        memcpy((void *)(iVar1 + pbVar4->flags),param_2,__n);
        iVar2 = pbVar4->num;
        len = pbVar4->retry_reason + __n;
        pbVar4->retry_reason = len;
      }
      do {
        iVar2 = BIO_write(param_1->prev_bio,(void *)(iVar2 + pbVar4->flags),len);
        if (iVar2 < 1) {
          BIO_copy_next_retry(param_1);
          if (0 < iVar6 || iVar2 == 0) {
            iVar2 = iVar6;
          }
          return iVar2;
        }
        len = pbVar4->retry_reason - iVar2;
        iVar2 = pbVar4->num + iVar2;
        pbVar4->retry_reason = len;
        pbVar4->num = iVar2;
      } while (len != 0);
      p_Var3 = pbVar4->callback;
      param_2 = pvVar5;
    }
    pbVar4->num = 0;
    while ((int)p_Var3 <= (int)param_3) {
      iVar2 = BIO_write(param_1->prev_bio,param_2,param_3);
      param_2 = (void *)((int)param_2 + iVar2);
      if (iVar2 < 1) {
        BIO_copy_next_retry(param_1);
        if (iVar2 == 0 || 0 < iVar6) {
          iVar2 = iVar6;
        }
        return iVar2;
      }
      param_3 = param_3 - iVar2;
      iVar6 = iVar6 + iVar2;
      if (param_3 == 0) {
        return iVar6;
      }
      p_Var3 = pbVar4->callback;
    }
  } while( true );
}

