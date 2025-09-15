
/* WARNING: Unknown calling convention */

int __total_staged(void)

{
  uint uVar1;
  
  if (staged_work == (work *)0x0) {
    uVar1 = 0;
  }
  else {
    uVar1 = ((staged_work->hh).tbl)->num_items;
  }
  return uVar1;
}

