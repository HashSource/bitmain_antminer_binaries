
int UI_ctrl(UI *ui,int cmd,long i,void *p,f *f)

{
  uint uVar1;
  uint uVar2;
  
  if (ui == (UI *)0x0) {
    ERR_put_error(0x28,0x6f,0x43,DAT_000d4c48,0x20d);
    uVar1 = 0xffffffff;
  }
  else if (cmd == 1) {
    uVar2 = *(uint *)(ui + 0x14);
    uVar1 = (uVar2 << 0x17) >> 0x1f;
    if (i == 0) {
      *(uint *)(ui + 0x14) = uVar2 & 0xfffffeff;
    }
    else {
      *(uint *)(ui + 0x14) = uVar2 | 0x100;
    }
  }
  else if (cmd == 2) {
    uVar1 = *(uint *)(ui + 0x14) & 1;
  }
  else {
    ERR_put_error(0x28,0x6f,0x6a,DAT_000d4c48,0x21f);
    uVar1 = 0xffffffff;
  }
  return uVar1;
}

