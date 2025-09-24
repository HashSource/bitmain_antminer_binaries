
int ssl3_read_n(int param_1,uint param_2,uint param_3,int param_4,int param_5,uint *param_6)

{
  int *piVar1;
  void *__src;
  BIO *b;
  uint __n;
  uint uVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  void *__dest;
  int local_2c;
  
  if (param_2 == 0) {
    return 0;
  }
  iVar3 = *(int *)(param_1 + 0x664);
  if (iVar3 == 0) {
    iVar3 = ssl3_setup_read_buffer();
    if (iVar3 == 0) {
      return -1;
    }
    iVar3 = *(int *)(param_1 + 0x664);
  }
  __n = *(uint *)(param_1 + 0x674);
  uVar2 = 3U - iVar3 & 7;
  if (param_4 == 0) {
    iVar4 = 0;
    if (__n == 0) {
      __src = (void *)(iVar3 + uVar2);
      *(uint *)(param_1 + 0x670) = uVar2;
      __dest = __src;
    }
    else if ((uVar2 == 0 || 3 < __n) && (uVar2 != 0 && __n != 4)) {
      __src = (void *)(*(int *)(param_1 + 0x670) + iVar3);
      if ((*(char *)(iVar3 + *(int *)(param_1 + 0x670)) == '\x17') &&
         (0x7f < CONCAT11(*(undefined1 *)((int)__src + 3),*(undefined1 *)((int)__src + 4)))) {
        memmove((void *)(iVar3 + uVar2),__src,__n);
        *(uint *)(param_1 + 0x670) = uVar2;
        __src = (void *)(*(int *)(param_1 + 0x664) + uVar2);
        __dest = __src;
      }
      else {
        __dest = (void *)(iVar3 + uVar2);
        iVar4 = (int)__src - (int)__dest;
        if (iVar4 != 0) {
          iVar4 = 1;
        }
        if (param_5 != 1) {
          iVar4 = 0;
        }
      }
    }
    else {
      __dest = (void *)(iVar3 + uVar2);
      __src = (void *)(*(int *)(param_1 + 0x670) + iVar3);
      iVar4 = (int)__src - (int)__dest;
      if (iVar4 != 0) {
        iVar4 = 1;
      }
      if (param_5 != 1) {
        iVar4 = 0;
      }
    }
    *(void **)(param_1 + 0xef8) = __src;
    local_2c = 0;
    *(undefined4 *)(param_1 + 0xefc) = 0;
  }
  else {
    local_2c = *(int *)(param_1 + 0xefc);
    __dest = (void *)(iVar3 + uVar2);
    __src = *(void **)(param_1 + 0xef8);
    iVar4 = (int)__src - (int)__dest;
    if (iVar4 != 0) {
      iVar4 = 1;
    }
    if (param_5 != 1) {
      iVar4 = 0;
    }
  }
  if (iVar4 != 0) {
    memmove(__dest,__src,__n + local_2c);
    *(void **)(param_1 + 0xef8) = __dest;
    *(uint *)(param_1 + 0x670) = uVar2 + local_2c;
  }
  uVar2 = *(uint *)(*(int *)(*(int *)(param_1 + 4) + 100) + 0x30) & 8;
  if (uVar2 != 0) {
    if (param_4 != 0 && __n == 0) {
      return 0;
    }
    iVar3 = 0;
    if (__n != 0 && __n < param_2) goto LAB_000d5454;
  }
  if (__n < param_2) {
    uVar5 = *(int *)(param_1 + 0x66c) - *(int *)(param_1 + 0x670);
    if (uVar5 < param_2) {
      ossl_statem_fatal(param_1,0x50,0x95,0x44,"ssl/record/rec_layer_s3.c",0x117);
      return -1;
    }
    uVar6 = param_2;
    if (*(int *)(param_1 + 0x654) != 0 || uVar2 != 0) {
      if (param_3 < param_2) {
        param_3 = param_2;
      }
      uVar6 = uVar5;
      if (param_3 <= uVar5) {
        uVar6 = param_3;
      }
    }
    piVar1 = __errno_location();
    do {
      b = *(BIO **)(param_1 + 8);
      *piVar1 = 0;
      if (b == (BIO *)0x0) {
        iVar3 = -1;
        ossl_statem_fatal(param_1,0x50,0x95,0xd3,"ssl/record/rec_layer_s3.c",0x139);
LAB_000d555a:
        *(uint *)(param_1 + 0x674) = __n;
        if ((*(int *)(param_1 + 0x4f0) << 0x1b < 0) &&
           ((-1 < *(int *)(*(int *)(*(int *)(param_1 + 4) + 100) + 0x30) << 0x1c &&
            (__n + local_2c == 0)))) {
          ssl3_release_read_buffer(param_1);
          return iVar3;
        }
        return iVar3;
      }
      *(undefined4 *)(param_1 + 0x14) = 3;
      iVar3 = BIO_read(b,(void *)(__n + local_2c + (int)__dest),uVar6 - __n);
      if ((iVar3 < 0) || (iVar3 == 0)) goto LAB_000d555a;
      __n = __n + iVar3;
      if (((uint)(__n < param_2) & *(uint *)(*(int *)(*(int *)(param_1 + 4) + 100) + 0x30) >> 3) !=
          0) {
        iVar3 = 0;
        goto LAB_000d5516;
      }
      if (param_2 <= __n) {
        iVar3 = __n - param_2;
        __n = param_2;
LAB_000d5516:
        *(int *)(param_1 + 0x674) = iVar3;
        *(undefined4 *)(param_1 + 0x14) = 1;
        *(uint *)(param_1 + 0x670) = *(int *)(param_1 + 0x670) + __n;
        *(uint *)(param_1 + 0xefc) = *(int *)(param_1 + 0xefc) + __n;
        *param_6 = __n;
        return 1;
      }
    } while( true );
  }
  iVar3 = __n - param_2;
  __n = param_2;
LAB_000d5454:
  *(int *)(param_1 + 0x674) = iVar3;
  *(uint *)(param_1 + 0x670) = *(int *)(param_1 + 0x670) + __n;
  *(uint *)(param_1 + 0xefc) = *(int *)(param_1 + 0xefc) + __n;
  *param_6 = __n;
  return 1;
}

