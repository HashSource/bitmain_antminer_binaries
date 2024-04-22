
int dsPIC33EP16GS202_update_pic_app_program(undefined4 param_1)

{
  FILE *__stream;
  ulong uVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  int iVar5;
  undefined4 local_3738;
  undefined4 uStack_3734;
  undefined4 local_3730;
  undefined4 local_372c;
  undefined4 local_3728;
  undefined4 local_3724;
  undefined4 local_3720;
  undefined4 auStack_371c [3520];
  
  memset(&local_3720,0,0x3700);
  local_3730 = 0;
  local_3738 = 0;
  uStack_3734 = (uint)uStack_3734._3_1_ << 0x18;
  local_372c = 0;
  local_3728 = 0;
  local_3724 = 0;
  __stream = fopen("/etc/config/dsPIC33EP16GS202_app.txt","r");
  if (__stream == (FILE *)0x0) {
    iVar2 = -1;
  }
  else {
    fseek(__stream,0,0);
    memset(&local_3720,0,0x3700);
    puVar3 = &local_3720;
    do {
      puVar4 = puVar3 + 1;
      fgets((char *)&local_3738,7,__stream);
      uVar1 = strtoul((char *)&local_3738,(char **)0x0,0x10);
      *(char *)((int)puVar3 + 3) = (char)uVar1;
      *(char *)puVar3 = (char)(uVar1 >> 0x18);
      *(char *)((int)puVar3 + 1) = (char)(uVar1 >> 0x10);
      *(char *)((int)puVar3 + 2) = (char)(uVar1 >> 8);
      puVar3 = puVar4;
    } while (puVar4 != auStack_371c + 0xdbf);
    fclose(__stream);
    iVar2 = dsPIC33EP16GS202_reset_pic_part_0(param_1);
    if ((iVar2 == 0) || (iVar2 = dsPIC33EP16GS202_erase_pic_app_program_part_1(param_1), iVar2 == 0)
       ) {
LAB_0003fe2e:
      iVar2 = 0;
    }
    else {
      iVar2 = 0;
      do {
        iVar5 = iVar2 + 0x10;
        local_3730 = *(undefined4 *)((int)&local_3720 + iVar2);
        local_372c = *(undefined4 *)((int)auStack_371c + iVar2);
        local_3728 = *(undefined4 *)((int)auStack_371c + iVar2 + 4);
        local_3724 = *(undefined4 *)((int)auStack_371c + iVar2 + 8);
        iVar2 = dsPIC33EP16GS202_send_data_to_pic(param_1,&local_3730);
        if (iVar2 == 0) goto LAB_0003fe2e;
        iVar2 = iVar5;
      } while (iVar5 != 0x3700);
      iVar2 = dsPIC33EP16GS202_reset_pic_part_0(param_1);
      if (iVar2 != 0) {
        iVar2 = 1;
      }
    }
  }
  return iVar2;
}

