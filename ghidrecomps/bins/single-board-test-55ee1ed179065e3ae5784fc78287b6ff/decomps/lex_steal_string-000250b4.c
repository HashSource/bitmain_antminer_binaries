
undefined4 lex_steal_string(int param_1)

{
  undefined4 local_c;
  
  local_c = 0;
  if (*(int *)(param_1 + 0x34) == 0x100) {
    local_c = *(undefined4 *)(param_1 + 0x38);
    *(undefined4 *)(param_1 + 0x38) = 0;
  }
  return local_c;
}

