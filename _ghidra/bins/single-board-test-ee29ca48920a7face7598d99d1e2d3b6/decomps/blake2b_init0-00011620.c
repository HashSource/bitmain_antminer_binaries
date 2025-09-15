
undefined4 blake2b_init0(void *param_1)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  int local_14;
  
  memset(param_1,0,0x168);
  for (local_14 = 0; local_14 < 8; local_14 = local_14 + 1) {
    uVar2 = *(undefined4 *)(&DAT_000336bc + local_14 * 8);
    puVar1 = (undefined4 *)(local_14 * 8 + (int)param_1);
    *puVar1 = *(undefined4 *)(&blake2b_IV + local_14 * 8);
    puVar1[1] = uVar2;
  }
  return 0;
}

