
void set_hcnt(uint param_1)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  int iVar7;
  undefined4 local_40;
  int local_3c;
  byte local_38;
  undefined4 local_34;
  uint local_30;
  int local_2c;
  
  uVar5 = (param_1 << 8) >> 0x18;
  uVar6 = (param_1 << 0x10) >> 0x18;
  uVar1 = uVar5 << 0x10;
  local_34 = 0;
  uVar2 = uVar6 << 8;
  local_30 = 0;
  iVar7 = 0;
  local_2c = 0;
  local_38 = 0;
  do {
    while ((*(int *)(dev + (iVar7 + 2) * 4) == 1 && (opt_multi_version != 0))) {
      local_3c = (uVar5 & 0xff) << 8;
      local_3c._0_3_ = CONCAT12((char)uVar6,(undefined2)local_3c);
      local_40 = 0x14000958;
      local_3c = CONCAT13((char)param_1,(int3)CONCAT31((uint3)local_3c >> 8,(char)(param_1 >> 0x18))
                         );
      local_38 = CRC5(&local_40,0x40,uVar5,uVar6,uVar6,uVar5);
      local_2c = (uint)local_38 << 0x18;
      local_34 = 0x58090014;
      local_30 = param_1 & 0xff0000ff | uVar1 | uVar2;
      set_BC_command_buffer(&local_34);
      uVar4 = get_BC_write_command();
      uVar3 = iVar7 << 0x10;
      iVar7 = iVar7 + 1;
      set_BC_write_command(uVar4 & 0xfff0ffff | uVar3 | 0x80800000);
      if (iVar7 == 0x10) {
        return;
      }
    }
    iVar7 = iVar7 + 1;
  } while (iVar7 != 0x10);
  return;
}

