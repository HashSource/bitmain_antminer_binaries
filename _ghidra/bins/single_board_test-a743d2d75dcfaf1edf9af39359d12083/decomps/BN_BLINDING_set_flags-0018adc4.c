
void BN_BLINDING_set_flags(BN_BLINDING *param_1,ulong param_2)

{
  *(ulong *)(param_1 + 0x20) = param_2;
  return;
}

