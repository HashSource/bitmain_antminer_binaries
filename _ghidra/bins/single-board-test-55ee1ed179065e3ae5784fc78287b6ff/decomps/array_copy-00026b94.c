
void array_copy(int param_1,int param_2,int param_3,int param_4,int param_5)

{
  memcpy((void *)(param_1 + param_2 * 4),(void *)(param_3 + param_4 * 4),param_5 << 2);
  return;
}

