
bool ossl_statem_export_early_allowed(int param_1)

{
  if (*(int *)(param_1 + 0x5ac) != 2) {
    return *(int *)(param_1 + 0x5ac) != 0 && *(int *)(param_1 + 0x1c) == 0;
  }
  return true;
}

