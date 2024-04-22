
void * json_array_grow(int param_1,int param_2,int param_3)

{
  void *__dest;
  uint uVar1;
  uint uVar2;
  void *__src;
  
  uVar1 = *(uint *)(param_1 + 8);
  if ((uint)(*(int *)(param_1 + 0xc) + param_2) <= uVar1) {
    return *(void **)(param_1 + 0x10);
  }
  __src = *(void **)(param_1 + 0x10);
  uVar2 = param_2 + uVar1;
  if (param_2 + uVar1 < uVar1 << 1) {
    uVar2 = uVar1 << 1;
  }
  __dest = (void *)jsonp_malloc(uVar2 << 2);
  if (__dest != (void *)0x0) {
    *(uint *)(param_1 + 8) = uVar2;
    *(void **)(param_1 + 0x10) = __dest;
    if (param_3 == 0) {
      return __src;
    }
    memcpy(__dest,__src,*(int *)(param_1 + 0xc) << 2);
    jsonp_free(__src);
    return *(void **)(param_1 + 0x10);
  }
  return (void *)0x0;
}

