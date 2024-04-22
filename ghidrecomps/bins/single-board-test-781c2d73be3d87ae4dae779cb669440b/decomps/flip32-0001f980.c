
/* WARNING: Unknown calling convention */
/* Local variable dest:uint32_t *[r0:4] conflicts with parameter, skipped.
   Local variable src:uint32_t *[r1:4] conflicts with parameter, skipped. */

void flip32(void *dest_p,void *src_p)

{
  uint *puVar1;
  uint *puVar2;
  uint uVar3;
  
  puVar2 = (uint *)((int)src_p + -4);
  puVar1 = (uint *)((int)dest_p + -4);
  do {
    puVar2 = puVar2 + 1;
    uVar3 = *puVar2;
    puVar1 = puVar1 + 1;
    *puVar1 = uVar3 << 0x18 | (uVar3 >> 8 & 0xff) << 0x10 | (uVar3 >> 0x10 & 0xff) << 8 |
              uVar3 >> 0x18;
  } while (puVar2 != (uint *)((int)src_p + 0x1c));
  return;
}

