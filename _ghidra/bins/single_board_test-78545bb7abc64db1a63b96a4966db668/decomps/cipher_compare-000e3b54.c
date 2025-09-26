
undefined4 cipher_compare(int param_1,int param_2)

{
  if (*(uint *)(param_1 + 0xc) == *(uint *)(param_2 + 0xc)) {
    return 0;
  }
  if (*(uint *)(param_2 + 0xc) <= *(uint *)(param_1 + 0xc)) {
    return 1;
  }
  return 0xffffffff;
}

