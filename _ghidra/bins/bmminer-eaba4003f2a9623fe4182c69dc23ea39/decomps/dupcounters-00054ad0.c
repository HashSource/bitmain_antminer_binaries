
void dupcounters(cgpu_info *cgpu,uint64_t *checked,uint64_t *dups)

{
  void *pvVar1;
  undefined4 uVar2;
  uint64_t *dups_local;
  uint64_t *checked_local;
  cgpu_info *cgpu_local;
  dupdata *dup;
  
  pvVar1 = cgpu->dup_data;
  if (pvVar1 == (void *)0x0) {
    *(undefined4 *)checked = 0;
    *(undefined4 *)((int)checked + 4) = 0;
    *(undefined4 *)dups = 0;
    *(undefined4 *)((int)dups + 4) = 0;
  }
  else {
    uVar2 = *(undefined4 *)((int)pvVar1 + 0x14);
    *(undefined4 *)checked = *(undefined4 *)((int)pvVar1 + 0x10);
    *(undefined4 *)((int)checked + 4) = uVar2;
    uVar2 = *(undefined4 *)((int)pvVar1 + 0x1c);
    *(undefined4 *)dups = *(undefined4 *)((int)pvVar1 + 0x18);
    *(undefined4 *)((int)dups + 4) = uVar2;
  }
  return;
}

