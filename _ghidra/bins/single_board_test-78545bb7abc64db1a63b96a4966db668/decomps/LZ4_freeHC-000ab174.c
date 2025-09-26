
int LZ4_freeHC(void *LZ4HC_Data)

{
  void *LZ4HC_Data_local;
  
  if (LZ4HC_Data != (void *)0x0) {
    free(LZ4HC_Data);
  }
  return 0;
}

