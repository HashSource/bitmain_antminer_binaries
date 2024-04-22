
int __get_queued(int param_1)

{
  int iVar1;
  int local_c;
  
  local_c = *(int *)(param_1 + 0x164);
  if (local_c != 0) {
    iVar1 = stale_work(local_c,0);
    if (iVar1 == 0) {
      __add_queued(param_1,local_c);
    }
    else {
      _discard_work(&local_c,"cgminer.c",DAT_00023d6c,0x2463);
      wake_gws();
    }
    *(undefined4 *)(param_1 + 0x164) = 0;
    return local_c;
  }
  return 0;
}

