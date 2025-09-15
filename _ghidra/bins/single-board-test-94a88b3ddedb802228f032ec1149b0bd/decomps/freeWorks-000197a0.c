
void freeWorks(void)

{
  int local_c;
  
  for (local_c = 0; local_c < 0x80; local_c = local_c + 1) {
    if (*(int *)(cgpu + (local_c + 0xa8) * 4) != 0) {
      free(*(void **)(cgpu + (local_c + 0xa8) * 4));
    }
    *(undefined4 *)(cgpu + (local_c + 0xa8) * 4) = 0;
  }
  return;
}

