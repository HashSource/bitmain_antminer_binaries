
/* WARNING: Unknown calling convention */

void dupcounters(cgpu_info *cgpu,uint64_t *checked,uint64_t *dups)

{
  dupdata *dup;
  undefined4 uVar1;
  
  dup = (dupdata *)cgpu->dup_data;
  if (dup == (dupdata *)0x0) {
    *(undefined4 *)checked = 0;
    *(undefined4 *)((int)checked + 4) = 0;
    *(undefined4 *)dups = 0;
    *(undefined4 *)((int)dups + 4) = 0;
  }
  else {
    uVar1 = *(undefined4 *)((int)&dup->checked + 4);
    *(undefined4 *)checked = *(undefined4 *)&dup->checked;
    *(undefined4 *)((int)checked + 4) = uVar1;
    uVar1 = *(undefined4 *)((int)&dup->dups + 4);
    *(undefined4 *)dups = *(undefined4 *)&dup->dups;
    *(undefined4 *)((int)dups + 4) = uVar1;
  }
  return;
}

