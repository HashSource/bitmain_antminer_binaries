
void clean_work(int param_1)

{
  free(*(void **)(param_1 + 0x120));
  free(*(void **)(param_1 + 0x134));
  free(*(void **)(param_1 + 0x148));
  free(*(void **)(param_1 + 0x140));
  (*(code *)PTR_memset_0007cfb4)(param_1,0,0x1c0);
  return;
}

