
undefined4 init_session_ticket(int param_1)

{
  if (*(int *)(param_1 + 0x1c) == 0) {
    *(undefined4 *)(param_1 + 0x55c) = 0;
  }
  return 1;
}

