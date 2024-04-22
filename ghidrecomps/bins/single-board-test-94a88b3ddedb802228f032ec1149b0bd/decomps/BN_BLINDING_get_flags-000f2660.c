
ulong BN_BLINDING_get_flags(BN_BLINDING *param_1)

{
  return *(ulong *)(param_1 + 0x20);
}

