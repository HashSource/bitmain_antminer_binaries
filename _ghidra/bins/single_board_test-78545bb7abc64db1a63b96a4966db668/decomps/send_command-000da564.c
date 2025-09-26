
/* WARNING: Unknown calling convention */

int32_t send_command(uint8_t which_chain,uint8_t *command,int32_t length)

{
  int iVar1;
  byte *pbVar2;
  uint32_t *puVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  uint32_t bc_command [3];
  
  uVar7 = 0;
  bc_command[0] = 0;
  bc_command[1] = 0;
  bc_command[2] = 0;
  puVar3 = bc_command;
  if (length != 0) {
LAB_000da57c:
    do {
      iVar1 = 0;
      pbVar2 = command + uVar7;
      iVar5 = 1;
      uVar4 = uVar7;
      while (uVar4 < (uint)length) {
        uVar6 = (uint)*pbVar2;
        uVar4 = *puVar3;
        if (iVar1 == 0) {
          *puVar3 = uVar4 | uVar6 << 0x18;
        }
        else if (iVar1 == 1) {
          *puVar3 = uVar4 | uVar6 << 0x10;
        }
        else if (iVar1 == 2) {
          *puVar3 = uVar4 | uVar6 << 8;
        }
        else {
          *puVar3 = uVar4 | uVar6;
          if (iVar5 == 4) {
            uVar7 = uVar7 + 4;
            puVar3 = puVar3 + 1;
            if ((uint)length <= uVar7) goto LAB_000da5b2;
            goto LAB_000da57c;
          }
        }
        iVar1 = iVar1 + 1;
        iVar5 = iVar5 + 1;
        pbVar2 = pbVar2 + 1;
        uVar4 = iVar1 + uVar7;
      }
      uVar7 = uVar7 + 4;
      puVar3 = puVar3 + 1;
    } while (uVar7 < (uint)length);
  }
LAB_000da5b2:
  send_BC_command(bc_command,(uint)which_chain);
  return 0;
}

