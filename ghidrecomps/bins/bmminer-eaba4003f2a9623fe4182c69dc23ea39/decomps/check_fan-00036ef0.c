
/* WARNING: Unknown calling convention */

void check_fan(void)

{
  all_parameters *paVar1;
  int iVar2;
  byte bVar3;
  uint *puVar4;
  bool bVar5;
  uint fan_speed;
  uchar fan_id;
  int j;
  int i;
  
  paVar1 = dev;
  fan_id = '\0';
  *(uint *)&dev->temp_num = *(uint *)&dev->temp_num & 0xff;
  *(undefined *)((int)&paVar1->fan_speed_top1 + 3) = 0;
  paVar1 = dev;
  puVar4 = (uint *)((int)&dev->fan_speed_top1 + 3);
  *puVar4 = *puVar4 & 0xff;
  *(undefined *)((int)&paVar1->fan_speed_low1 + 3) = 0;
  for (j = 0; j < 2; j = j + 1) {
    for (i = 0; i < 8; i = i + 1) {
      iVar2 = get_fan_speed(&fan_id,&fan_speed);
      if (iVar2 != -1) {
        dev->fan_speed_value[fan_id] = fan_speed * 0x78;
        if ((fan_speed == 0) || (dev->fan_exist[fan_id] != '\0')) {
          if ((fan_speed == 0) && (dev->fan_exist[fan_id] == '\x01')) {
            dev->fan_exist[fan_id] = '\0';
            dev->fan_num = dev->fan_num + 0xff;
            iVar2 = 1 << fan_id;
            bVar5 = iVar2 != 0;
            if (bVar5) {
              iVar2 = 0;
            }
            bVar3 = (byte)iVar2;
            if (!bVar5) {
              bVar3 = 1;
            }
            dev->fan_exist_map = (uint)bVar3 & dev->fan_exist_map;
          }
        }
        else {
          dev->fan_exist[fan_id] = '\x01';
          dev->fan_num = dev->fan_num + '\x01';
          dev->fan_exist_map = 1 << fan_id | dev->fan_exist_map;
        }
        if (dev->fan_speed_top1 < dev->fan_speed_value[fan_id]) {
          dev->fan_speed_top1 = dev->fan_speed_value[fan_id];
        }
        if (((dev->fan_speed_value[fan_id] < dev->fan_speed_low1) &&
            (dev->fan_speed_value[fan_id] != 0)) || (dev->fan_speed_low1 == 0)) {
          dev->fan_speed_low1 = dev->fan_speed_value[fan_id];
        }
      }
    }
  }
  return;
}

