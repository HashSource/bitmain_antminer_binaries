
/* WARNING: Unknown calling convention */

void write_lcd(uint line,char *buf,uint size)

{
  int iVar1;
  undefined4 *puVar2;
  uint uVar3;
  int iVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  bool bVar8;
  bool bVar9;
  
  if (buf == (char *)0x0) {
    return;
  }
  if (lcd_fd < 1) {
    return;
  }
  bVar9 = 0x3f < size;
  bVar8 = size == 0x40;
  if (size < 0x41) {
    bVar9 = 2 < line;
    bVar8 = line == 3;
  }
  if (!bVar9 || bVar8) {
    iVar4 = 0;
    lseek(lcd_fd,0,0);
    memset(lcd_output,0x20,0x40);
    if (size != 0) {
      iVar1 = iVar4;
      uVar3 = line;
      if (0x10 < size) {
        do {
          puVar2 = (undefined4 *)(buf + iVar1);
          uVar5 = puVar2[1];
          size = size - 0x10;
          uVar6 = puVar2[2];
          uVar7 = puVar2[3];
          uVar3 = uVar3 + 1;
          iVar4 = iVar1 + 0x10;
          *(undefined4 *)(lcd_output[line] + iVar1) = *puVar2;
          *(undefined4 *)(lcd_output[line] + iVar1 + 4) = uVar5;
          *(undefined4 *)(lcd_output[line] + iVar1 + 8) = uVar6;
          *(undefined4 *)(lcd_output[line] + iVar1 + 0xc) = uVar7;
          iVar1 = iVar4;
        } while (0x10 < size);
      }
      memcpy(lcd_output + uVar3,buf + iVar4,size);
    }
    (*(code *)PTR_write_00030190)(lcd_fd,lcd_output,0x40);
    return;
  }
  (*(code *)PTR_printf_00030118)("%s: write_lcd\'s arg is overflow\n","write_lcd");
  return;
}

