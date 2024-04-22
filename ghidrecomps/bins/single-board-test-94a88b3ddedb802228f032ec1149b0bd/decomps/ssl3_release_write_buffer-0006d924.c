
undefined4 ssl3_release_write_buffer(int param_1)

{
  char *file;
  uint uVar1;
  uint *puVar2;
  uint *ptr;
  int iVar3;
  uint uVar4;
  
  ptr = *(uint **)(*(int *)(param_1 + 0x58) + 0xfc);
  if (ptr != (uint *)0x0) {
    iVar3 = *(int *)(param_1 + 0xe4);
    uVar4 = *(uint *)(*(int *)(param_1 + 0x58) + 0x100);
    CRYPTO_lock(9,0xc,DAT_0006d9a8,0x270);
    puVar2 = *(uint **)(iVar3 + 0x15c);
    if (((puVar2 == (uint *)0x0) ||
        (((uVar4 != *puVar2 && (*puVar2 != 0)) ||
         (uVar1 = puVar2[1], *(uint *)(iVar3 + 0x158) <= uVar1)))) || (uVar4 < 4)) {
      CRYPTO_lock(10,0xc,DAT_0006d9a8,0x27d);
      CRYPTO_free(ptr);
    }
    else {
      *puVar2 = uVar4;
      file = DAT_0006d9a8;
      *ptr = puVar2[2];
      puVar2[1] = uVar1 + 1;
      puVar2[2] = (uint)ptr;
      CRYPTO_lock(10,0xc,file,0x27d);
    }
    *(undefined4 *)(*(int *)(param_1 + 0x58) + 0xfc) = 0;
  }
  return 1;
}

