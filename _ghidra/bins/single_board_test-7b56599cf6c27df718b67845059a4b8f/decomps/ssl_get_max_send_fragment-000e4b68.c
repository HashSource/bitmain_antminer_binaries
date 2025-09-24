
int ssl_get_max_send_fragment(int param_1)

{
  char cVar1;
  
  if ((*(int *)(param_1 + 0x474) != 0) &&
     (cVar1 = *(char *)(*(int *)(param_1 + 0x474) + 0x1ec), (byte)(cVar1 - 1U) < 4)) {
    return 0x200 << (uint)(byte)(cVar1 - 1);
  }
  return *(int *)(param_1 + 0x50c);
}

