
/* WARNING: Unknown calling convention */

int32_t send_command(uint8_t which_chain,uint8_t *command,int32_t length)

{
  int iVar1;
  byte *pbVar2;
  uint32_t *puVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  int iVar7;
  uint32_t bc_command [3];
  
  uVar4 = 0;
  bc_command[0] = 0;
  bc_command[1] = 0;
  bc_command[2] = 0;
  puVar3 = bc_command;
  if (length != 0) {
LAB_001d2e4a:
    do {
      iVar1 = 0;
      pbVar2 = command + uVar4;
      iVar7 = 1;
      uVar5 = uVar4;
      while (uVar5 < (uint)length) {
        uVar6 = (uint)*pbVar2;
        uVar5 = *puVar3;
        if (iVar1 == 0) {
          *puVar3 = uVar5 | uVar6 << 0x18;
        }
        else if (iVar1 == 1) {
          *puVar3 = uVar5 | uVar6 << 0x10;
        }
        else if (iVar1 == 2) {
          *puVar3 = uVar5 | uVar6 << 8;
        }
        else {
          *puVar3 = uVar5 | uVar6;
          if (iVar7 == 4) {
            uVar4 = uVar4 + 4;
            puVar3 = puVar3 + 1;
            if ((uint)length <= uVar4) goto LAB_001d2e7c;
            goto LAB_001d2e4a;
          }
        }
        iVar1 = iVar1 + 1;
        iVar7 = iVar7 + 1;
        pbVar2 = pbVar2 + 1;
        uVar5 = uVar4 + iVar1;
      }
      uVar4 = uVar4 + 4;
      puVar3 = puVar3 + 1;
    } while (uVar4 < (uint)length);
  }
LAB_001d2e7c:
  send_BC_command(bc_command,(uint)which_chain);
  return 0;
}

