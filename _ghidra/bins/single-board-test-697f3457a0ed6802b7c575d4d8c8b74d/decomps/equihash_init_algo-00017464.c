
void equihash_init_algo(void *args)

{
  void *args_local;
  runtime_base_t *runtime;
  
  *(undefined4 *)((int)args + 0x69c) = 0x8c;
  *(undefined4 *)((int)args + 0x6a0) = 4;
  *(undefined4 *)((int)args + 0x6a4) = 0x540;
  *(undefined4 *)((int)args + 0x6a8) = 0x20;
  *(undefined4 *)((int)args + 0xb7c) = 0x17229;
  *(undefined4 *)((int)args + 0xb78) = 0x1737d;
  return;
}

