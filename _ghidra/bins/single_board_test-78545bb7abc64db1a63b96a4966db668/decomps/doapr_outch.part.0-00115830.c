
undefined4
doapr_outch_part_0(int *param_1,int *param_2,uint *param_3,uint *param_4,undefined1 param_5)

{
  void *pvVar1;
  int *piVar2;
  int iVar3;
  uint __n;
  uint uVar4;
  
  __n = *param_3;
  uVar4 = *param_4;
  if (uVar4 < __n) {
    return 0;
  }
  piVar2 = param_2;
  if (param_2 != (int *)0x0) {
    piVar2 = (int *)0x1;
  }
  if (__n != uVar4) {
    piVar2 = (int *)0x0;
  }
  if (piVar2 != (int *)0x0) {
    if (0x7ffffbff < uVar4) {
      return 0;
    }
    pvVar1 = (void *)*param_2;
    uVar4 = uVar4 + 0x400;
    *param_4 = uVar4;
    if (pvVar1 == (void *)0x0) {
      pvVar1 = CRYPTO_malloc(uVar4,"crypto/bio/b_print.c",0x33a);
      *param_2 = (int)pvVar1;
      if (pvVar1 == (void *)0x0) {
        ERR_put_error(0x20,0x96,0x41,"crypto/bio/b_print.c",0x33b);
        return 0;
      }
      __n = *param_3;
      if (__n != 0) {
        if ((void *)*param_1 == (void *)0x0) {
          return 0;
        }
        memcpy(pvVar1,(void *)*param_1,__n);
        __n = *param_3;
      }
      uVar4 = *param_4;
      *param_1 = 0;
      if (uVar4 <= __n) {
        return 1;
      }
      goto LAB_001158ec;
    }
    pvVar1 = CRYPTO_realloc(pvVar1,uVar4,"crypto/bio/b_print.c",0x346);
    if (pvVar1 == (void *)0x0) {
      return 0;
    }
    uVar4 = *param_4;
    __n = *param_3;
    *param_2 = (int)pvVar1;
  }
  if (uVar4 <= __n) {
    return 1;
  }
  iVar3 = *param_1;
  if (iVar3 != 0) {
    *param_3 = __n + 1;
    *(undefined1 *)(iVar3 + __n) = param_5;
    return 1;
  }
LAB_001158ec:
  iVar3 = *param_2;
  *param_3 = __n + 1;
  *(undefined1 *)(iVar3 + __n) = param_5;
  return 1;
}

