
void regen_hash(int param_1)

{
  uint *puVar1;
  uint *puVar2;
  uint uVar3;
  undefined auStack_78 [28];
  uint uStack_5c;
  uint local_58 [20];
  
  puVar1 = (uint *)(param_1 + -4);
  puVar2 = &uStack_5c;
  do {
    puVar1 = puVar1 + 1;
    uVar3 = *puVar1;
    puVar2 = puVar2 + 1;
    *puVar2 = uVar3 << 0x18 | (uVar3 >> 8 & 0xff) << 0x10 | (uVar3 >> 0x10 & 0xff) << 8 |
              uVar3 >> 0x18;
  } while (puVar2 != local_58 + 0x13);
  sha256(local_58,0x50,auStack_78);
  sha256(auStack_78,0x20,param_1 + 0xc0);
  return;
}

