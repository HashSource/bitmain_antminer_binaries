
void write_lcd(uint param_1,int param_2,uint param_3)

{
  undefined4 uVar1;
  undefined4 uVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined4 uVar5;
  uint local_24;
  uint local_1c;
  int local_14;
  
  local_14 = 0;
  if ((param_2 != 0) && (0 < lcd_fd)) {
    if ((param_1 < 4) && (param_3 < 0x41)) {
      lseek(lcd_fd,0,0);
      memset(lcd_buffer + 0x20,0x20,0x40);
      local_1c = param_1;
      for (local_24 = param_3; local_24 != 0; local_24 = local_24 - 0x10) {
        if (local_24 < 0x11) {
          memcpy(lcd_buffer + local_1c * 0x10 + 0x20,(void *)(param_2 + local_14),local_24);
          break;
        }
        iVar3 = local_1c * 0x10;
        puVar4 = (undefined4 *)(param_2 + local_14);
        uVar1 = puVar4[1];
        uVar2 = puVar4[2];
        uVar5 = puVar4[3];
        *(undefined4 *)(lcd_buffer + iVar3 + 0x20) = *puVar4;
        *(undefined4 *)(&DAT_00031094 + iVar3) = uVar1;
        *(undefined4 *)(&DAT_00031098 + iVar3) = uVar2;
        *(undefined4 *)(&DAT_0003109c + iVar3) = uVar5;
        local_1c = local_1c + 1;
        local_14 = local_14 + 0x10;
      }
      write(lcd_fd,lcd_buffer + 0x20,0x40);
    }
    else {
      printf("%s: write_lcd\'s arg is overflow\n","write_lcd");
    }
  }
  return;
}

