
ushort def_is_number(int param_1,int param_2)

{
  return *(ushort *)(*(int *)(param_1 + 4) + param_2 * 2) & 1;
}

