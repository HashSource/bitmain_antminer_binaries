
/* WARNING: Unknown calling convention */
/* Local variable dest:uint32_t *[r0:4] conflicts with parameter, skipped.
   Local variable src:uint32_t *[r1:4] conflicts with parameter, skipped. */

void flip_swab(void *dest_p,void *src_p,uint length)

{
  uint *puVar1;
  uint *puVar2;
  uint uVar4;
  uint *puVar3;
  
  if (length >> 2 != 0) {
    puVar1 = (uint *)((int)dest_p + -4);
    puVar2 = (uint *)src_p;
    do {
      puVar3 = puVar2 + 1;
      uVar4 = *puVar2;
      puVar1 = puVar1 + 1;
      *puVar1 = uVar4 << 0x18 | (uVar4 >> 8 & 0xff) << 0x10 | (uVar4 >> 0x10 & 0xff) << 8 |
                uVar4 >> 0x18;
      puVar2 = puVar3;
    } while (puVar3 != (uint *)((int)src_p + (length & 0xfffffffc)));
  }
  return;
}

