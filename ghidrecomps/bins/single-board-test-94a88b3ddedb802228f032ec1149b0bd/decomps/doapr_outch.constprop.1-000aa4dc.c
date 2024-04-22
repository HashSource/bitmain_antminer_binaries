
void doapr_outch_constprop_1(void **param_1,void **param_2,size_t *param_3,size_t *param_4)

{
  void *pvVar1;
  size_t sVar2;
  uint uVar3;
  
  if (param_2 != (void **)0x0) {
    sVar2 = *param_3;
    uVar3 = *param_4;
    if (sVar2 != uVar3) goto LAB_000aa4f2;
    pvVar1 = *param_2;
    sVar2 = sVar2 + 0x400;
    *param_4 = sVar2;
    if (pvVar1 == (void *)0x0) {
      pvVar1 = CRYPTO_malloc(sVar2,DAT_000aa568,0x2c9);
      *param_2 = pvVar1;
      if (pvVar1 == (void *)0x0) {
        return;
      }
      sVar2 = *param_3;
      if (sVar2 != 0) {
        memcpy(pvVar1,*param_1,sVar2);
        sVar2 = *param_3;
      }
      uVar3 = *param_4;
      *param_1 = (void *)0x0;
      goto LAB_000aa4f2;
    }
    pvVar1 = CRYPTO_realloc(pvVar1,sVar2,DAT_000aa568,0x2d4);
    *param_2 = pvVar1;
    if (pvVar1 == (void *)0x0) {
      return;
    }
  }
  uVar3 = *param_4;
  sVar2 = *param_3;
LAB_000aa4f2:
  if (sVar2 < uVar3) {
    if (*param_1 != (void *)0x0) {
      *(undefined *)((int)*param_1 + sVar2) = 0x20;
      *param_3 = sVar2 + 1;
      return;
    }
    *(undefined *)((int)*param_2 + sVar2) = 0x20;
    *param_3 = sVar2 + 1;
  }
  return;
}

