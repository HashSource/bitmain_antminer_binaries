
/* WARNING: Unknown calling convention */

void write_lcd_no_memset(uint line,char *buf,uint size)

{
  int iVar1;
  uint uVar2;
  undefined4 *puVar3;
  int iVar4;
  int iVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  bool bVar9;
  bool bVar10;
  
  iVar1 = lcd_fd;
  if (buf == (char *)0x0) {
    return;
  }
  if (lcd_fd < 1) {
    return;
  }
  bVar10 = 0x3f < size;
  bVar9 = size == 0x40;
  if (size < 0x41) {
    bVar10 = 2 < line;
    bVar9 = line == 3;
  }
  if (!bVar10 || bVar9) {
    iVar4 = 0;
    if (size != 0) {
      uVar2 = line;
      iVar5 = iVar4;
      if (0x10 < size) {
        do {
          puVar3 = (undefined4 *)(buf + iVar5);
          uVar7 = puVar3[1];
          size = size - 0x10;
          uVar8 = puVar3[2];
          uVar6 = puVar3[3];
          uVar2 = uVar2 + 1;
          iVar4 = iVar5 + 0x10;
          *(undefined4 *)(lcd_output[line] + iVar5) = *puVar3;
          *(undefined4 *)(lcd_output[line] + iVar5 + 4) = uVar7;
          *(undefined4 *)(lcd_output[line] + iVar5 + 8) = uVar8;
          *(undefined4 *)(lcd_output[line] + iVar5 + 0xc) = uVar6;
          iVar5 = iVar4;
        } while (0x10 < size);
      }
      memcpy(lcd_output + uVar2,buf + iVar4,size);
    }
    (*(code *)PTR_write_00030190)(iVar1,lcd_output,0x40);
    return;
  }
  (*(code *)PTR_printf_00030118)("%s: write_lcd\'s arg is overflow\n",DAT_00015ca4);
  return;
}

