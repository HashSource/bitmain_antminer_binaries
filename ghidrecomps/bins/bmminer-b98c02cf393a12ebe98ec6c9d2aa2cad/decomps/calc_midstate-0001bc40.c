
void calc_midstate(int param_1)

{
  uint *puVar1;
  uint *puVar2;
  uint uVar3;
  uint local_f4;
  uint local_f0 [16];
  undefined auStack_b0 [136];
  undefined auStack_28 [32];
  
  puVar1 = (uint *)(param_1 + -4);
  puVar2 = &local_f4;
  do {
    puVar1 = puVar1 + 1;
    uVar3 = *puVar1;
    puVar2 = puVar2 + 1;
    *puVar2 = uVar3 << 0x18 | (uVar3 >> 8 & 0xff) << 0x10 | (uVar3 >> 0x10 & 0xff) << 8 |
              uVar3 >> 0x18;
  } while (puVar2 != local_f0 + 0xf);
  sha256_init(auStack_b0);
  sha256_update(auStack_b0,local_f0,0x40);
  local_f4 = 0x894;
  _cg_memcpy(param_1 + 0x80,auStack_28,0x20,"cgminer.c",DAT_0001bc8c);
  return;
}

