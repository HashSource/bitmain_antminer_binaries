
void Sha256_WriteByteBlock(int param_1)

{
  int aiStack_4c [16];
  uint local_c;
  
  for (local_c = 0; local_c < 0x10; local_c = local_c + 1) {
    aiStack_4c[local_c] =
         (uint)*(byte *)(param_1 + local_c * 4 + 0x28) * 0x1000000 +
         (uint)*(byte *)(param_1 + local_c * 4 + 0x29) * 0x10000 +
         (uint)*(byte *)(param_1 + local_c * 4 + 0x2a) * 0x100 +
         (uint)*(byte *)(param_1 + local_c * 4 + 0x2b);
  }
  Sha256_Transform(param_1,aiStack_4c);
  return;
}

