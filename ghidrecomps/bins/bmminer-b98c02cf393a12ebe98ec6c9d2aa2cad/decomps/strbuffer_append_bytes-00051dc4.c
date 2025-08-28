
undefined4 strbuffer_append_bytes(int *param_1,void *param_2,size_t param_3)

{
  int iVar1;
  void *__dest;
  uint uVar2;
  uint uVar3;
  
  uVar2 = param_1[1];
  iVar1 = param_1[2];
  if (param_3 < iVar1 - uVar2) {
    __dest = (void *)*param_1;
LAB_00051e28:
    memcpy((void *)((int)__dest + uVar2),param_2,param_3);
    iVar1 = param_1[1];
    param_1[1] = param_3 + iVar1;
    *(undefined1 *)(*param_1 + param_3 + iVar1) = 0;
    return 0;
  }
  if ((param_3 != 0xffffffff && -1 < iVar1) && (uVar2 <= -param_3 - 2)) {
    uVar2 = uVar2 + 1 + param_3;
    uVar3 = iVar1 << 1;
    if ((uint)(iVar1 << 1) < uVar2) {
      uVar3 = uVar2;
    }
    __dest = (void *)jsonp_malloc(uVar3);
    if (__dest != (void *)0x0) {
      memcpy(__dest,(void *)*param_1,param_1[1]);
      jsonp_free(*param_1);
      uVar2 = param_1[1];
      *param_1 = (int)__dest;
      param_1[2] = uVar3;
      goto LAB_00051e28;
    }
  }
  return 0xffffffff;
}

