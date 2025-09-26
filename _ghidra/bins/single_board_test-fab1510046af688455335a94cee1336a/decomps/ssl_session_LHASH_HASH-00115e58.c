
uint ssl_session_LHASH_HASH(int param_1)

{
  return (uint)*(byte *)(param_1 + 0x4a) << 0x10 | (uint)*(byte *)(param_1 + 0x49) << 8 |
         (uint)*(byte *)(param_1 + 0x48) | (uint)*(byte *)(param_1 + 0x4b) << 0x18;
}

