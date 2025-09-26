
undefined4 ssl_session_hash(int param_1)

{
  undefined4 *puVar1;
  undefined4 local_c;
  
  if (3 < *(size_t *)(param_1 + 0x148)) {
    return *(undefined4 *)(param_1 + 0x14c);
  }
  local_c = 0;
  puVar1 = (undefined4 *)
           memcpy(&local_c,(undefined4 *)(param_1 + 0x14c),*(size_t *)(param_1 + 0x148));
  return *puVar1;
}

