
undefined4 blake2b_init0(void *param_1)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  int local_c;
  
  memset(param_1,0,0x168);
  for (local_c = 0; local_c < 8; local_c = local_c + 1) {
    uVar2 = (&DAT_0002ba9c)[local_c * 2];
    puVar1 = (undefined4 *)((int)param_1 + local_c * 8);
    *puVar1 = (&blake2b_IV)[local_c * 2];
    puVar1[1] = uVar2;
  }
  return 0;
}

