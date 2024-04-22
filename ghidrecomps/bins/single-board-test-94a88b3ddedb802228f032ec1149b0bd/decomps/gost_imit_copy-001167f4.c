
undefined4 gost_imit_copy(int param_1,int param_2)

{
  memcpy(*(void **)(param_1 + 0xc),*(void **)(param_2 + 0xc),0x1040);
  return 1;
}

