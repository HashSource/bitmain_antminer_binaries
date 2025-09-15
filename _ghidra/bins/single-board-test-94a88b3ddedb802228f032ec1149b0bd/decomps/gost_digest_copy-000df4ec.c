
undefined4 gost_digest_copy(int param_1,int param_2)

{
  void *__dest;
  
  __dest = *(void **)(param_1 + 0xc);
  if ((__dest != (void *)0x0) && (*(void **)(param_2 + 0xc) != (void *)0x0)) {
    memcpy(__dest,*(void **)(param_2 + 0xc),0x1090);
    *(int *)((int)__dest + 8) = (int)__dest + 0x70;
  }
  return 1;
}

