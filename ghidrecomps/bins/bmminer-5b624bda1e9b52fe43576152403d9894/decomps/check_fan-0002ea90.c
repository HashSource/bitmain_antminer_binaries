
/* WARNING: Unknown calling convention */

void check_fan(void)

{
  char cVar1;
  int *piVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  uint uVar8;
  byte local_2d;
  uint fan_speed;
  
  piVar2 = DAT_0002eb5c;
  iVar7 = 2;
  local_2d = 0;
  do {
    iVar6 = 8;
    do {
      iVar3 = get_fan_speed(&local_2d,&fan_speed);
      if (iVar3 != -1) {
        uVar8 = (uint)local_2d;
        iVar3 = *piVar2;
        uVar4 = fan_speed * 0x78;
        *(uint *)(iVar3 + (uVar8 + 0xbd2) * 4 + 2) = uVar4;
        if (fan_speed == 0) {
          if (*(char *)(iVar3 + uVar8 + 0x2f42) == '\x01') {
            uVar5 = *(uint *)(iVar3 + 0x4c);
            cVar1 = *(char *)(iVar3 + 0x2fbd);
            *(undefined *)(iVar3 + uVar8 + 0x2f42) = 0;
            if (1 << uVar8 == 0) {
              uVar5 = uVar5 & 1;
            }
            else {
              uVar5 = 0;
            }
            *(uint *)(iVar3 + 0x4c) = uVar5;
            *(char *)(iVar3 + 0x2fbd) = cVar1 + -1;
          }
        }
        else if (*(char *)(iVar3 + uVar8 + 0x2f42) == '\0') {
          uVar5 = *(uint *)(iVar3 + 0x4c);
          cVar1 = *(char *)(iVar3 + 0x2fbd);
          *(undefined *)(iVar3 + uVar8 + 0x2f42) = 1;
          *(uint *)(iVar3 + 0x4c) = uVar5 | 1 << uVar8;
          *(char *)(iVar3 + 0x2fbd) = cVar1 + '\x01';
        }
        if (*(uint *)(iVar3 + 0x2fbf) < uVar4) {
          *(uint *)(iVar3 + 0x2fbf) = uVar4;
        }
      }
      iVar6 = iVar6 + -1;
    } while (iVar6 != 0);
    iVar7 = iVar7 + -1;
  } while (iVar7 != 0);
  return;
}

