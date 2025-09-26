
char * LZ4_slideInputBuffer(void *state)

{
  void *state_local;
  
  return *(char **)((int)state + 0x4000);
}

