
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void check_fan(void)

{
  uchar uVar1;
  all_parameters *paVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  uint uVar8;
  byte local_2d;
  uint fan_speed;
  
  iVar7 = 2;
  local_2d = 0;
  do {
    iVar6 = 8;
    do {
      iVar3 = get_fan_speed(&local_2d,&fan_speed);
      paVar2 = dev;
      if (iVar3 != -1) {
        uVar8 = (uint)local_2d;
        uVar4 = fan_speed * 0x78;
        dev->fan_speed_value[uVar8] = uVar4;
        if (fan_speed == 0) {
          if (paVar2->fan_exist[uVar8] == '\x01') {
            uVar5 = paVar2->fan_exist_map;
            uVar1 = paVar2->fan_num;
            paVar2->fan_exist[uVar8] = '\0';
            if (1 << uVar8 == 0) {
              uVar5 = uVar5 & 1;
            }
            else {
              uVar5 = 0;
            }
            paVar2->fan_exist_map = uVar5;
            paVar2->fan_num = uVar1 + 0xff;
          }
        }
        else if (paVar2->fan_exist[uVar8] == '\0') {
          uVar5 = paVar2->fan_exist_map;
          uVar1 = paVar2->fan_num;
          paVar2->fan_exist[uVar8] = '\x01';
          paVar2->fan_exist_map = uVar5 | 1 << uVar8;
          paVar2->fan_num = uVar1 + '\x01';
        }
        if (paVar2->fan_speed_top1 < uVar4) {
          paVar2->fan_speed_top1 = uVar4;
        }
      }
      iVar6 = iVar6 + -1;
    } while (iVar6 != 0);
    iVar7 = iVar7 + -1;
  } while (iVar7 != 0);
  return;
}

