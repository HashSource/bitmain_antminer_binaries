
void array_move(int param_1,int param_2,int param_3,int param_4)

{
  memmove((void *)(*(int *)(param_1 + 0x10) + param_2 * 4),
          (void *)(*(int *)(param_1 + 0x10) + param_3 * 4),param_4 << 2);
  return;
}

