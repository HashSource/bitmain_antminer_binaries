
/* WARNING: Unknown calling convention */

void set_TW_write_command(uint *value)

{
  undefined4 *puVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  iVar3 = 0;
  iVar4 = *(int *)(DAT_0002e8dc + 0x8d4);
  do {
    puVar1 = (undefined4 *)((int)value + iVar3);
    iVar2 = iVar4 + iVar3;
    iVar3 = iVar3 + 4;
    *(undefined4 *)(iVar2 + 0x40) = *puVar1;
  } while (iVar3 != 0x34);
  return;
}

