
undefined4 gost_digest_cleanup(int param_1)

{
  if (*(void **)(param_1 + 0xc) != (void *)0x0) {
    memset(*(void **)(param_1 + 0xc),0,0x1090);
  }
  return 1;
}

