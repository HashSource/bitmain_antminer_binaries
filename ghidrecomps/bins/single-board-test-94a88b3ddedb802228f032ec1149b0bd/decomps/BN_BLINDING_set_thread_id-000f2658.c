
void BN_BLINDING_set_thread_id(BN_BLINDING *param_1,ulong param_2)

{
  *(ulong *)(param_1 + 0x10) = param_2;
  return;
}

