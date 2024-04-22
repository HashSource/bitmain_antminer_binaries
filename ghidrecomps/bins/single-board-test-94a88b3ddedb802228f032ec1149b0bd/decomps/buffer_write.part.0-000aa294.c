
int buffer_write_part_0(BIO *param_1,void *param_2,size_t param_3)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  void *pvVar5;
  void *pvVar6;
  int iVar7;
  size_t __n;
  
  pvVar5 = param_1->ptr;
  if (pvVar5 == (void *)0x0) {
    return 0;
  }
  if (param_1->next_bio == (bio_st *)0x0) {
    return 0;
  }
  iVar7 = 0;
  BIO_clear_flags(param_1,0xf);
  iVar4 = *(int *)((int)pvVar5 + 4);
  do {
    iVar3 = *(int *)((int)pvVar5 + 0x18);
    iVar2 = *(int *)((int)pvVar5 + 0x1c);
    iVar1 = iVar3 + iVar2;
    __n = iVar4 - iVar1;
    if ((int)param_3 <= (int)__n) {
      memcpy((void *)(*(int *)((int)pvVar5 + 0x14) + iVar1),param_2,param_3);
      *(size_t *)((int)pvVar5 + 0x18) = *(int *)((int)pvVar5 + 0x18) + param_3;
      return iVar7 + param_3;
    }
    if (iVar3 != 0) {
      pvVar6 = param_2;
      if (0 < (int)__n) {
        param_3 = param_3 - __n;
        iVar7 = iVar7 + __n;
        pvVar6 = (void *)((int)param_2 + __n);
        memcpy((void *)(*(int *)((int)pvVar5 + 0x14) + iVar1),param_2,__n);
        iVar2 = *(int *)((int)pvVar5 + 0x1c);
        iVar3 = *(int *)((int)pvVar5 + 0x18) + __n;
        *(int *)((int)pvVar5 + 0x18) = iVar3;
      }
      do {
        iVar3 = BIO_write(param_1->next_bio,(void *)(*(int *)((int)pvVar5 + 0x14) + iVar2),iVar3);
        if (iVar3 < 1) goto LAB_000aa336;
        iVar2 = iVar3 + *(int *)((int)pvVar5 + 0x1c);
        iVar3 = *(int *)((int)pvVar5 + 0x18) - iVar3;
        *(int *)((int)pvVar5 + 0x1c) = iVar2;
        *(int *)((int)pvVar5 + 0x18) = iVar3;
      } while (iVar3 != 0);
      iVar4 = *(int *)((int)pvVar5 + 4);
      param_2 = pvVar6;
    }
    *(undefined4 *)((int)pvVar5 + 0x1c) = 0;
    while (iVar4 <= (int)param_3) {
      iVar3 = BIO_write(param_1->next_bio,param_2,param_3);
      param_2 = (void *)((int)param_2 + iVar3);
      if (iVar3 < 1) {
LAB_000aa336:
        BIO_copy_next_retry(param_1);
        if (iVar3 == 0) {
          return iVar7;
        }
        if (iVar7 == 0) {
          iVar7 = iVar3;
        }
        return iVar7;
      }
      param_3 = param_3 - iVar3;
      iVar7 = iVar3 + iVar7;
      if (param_3 == 0) {
        return iVar7;
      }
      iVar4 = *(int *)((int)pvVar5 + 4);
    }
  } while( true );
}

