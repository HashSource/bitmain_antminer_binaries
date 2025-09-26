
undefined4 EC_KEY_decoded_from_explicit_params(int param_1)

{
  if ((param_1 != 0) && (*(int *)(param_1 + 0xc) != 0)) {
    return *(undefined4 *)(*(int *)(param_1 + 0xc) + 0x18);
  }
  return 0xffffffff;
}

