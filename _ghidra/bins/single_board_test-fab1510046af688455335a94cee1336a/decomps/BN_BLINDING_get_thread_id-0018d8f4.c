
ulong BN_BLINDING_get_thread_id(BN_BLINDING *param_1)

{
  return *(ulong *)(param_1 + 0x10);
}

