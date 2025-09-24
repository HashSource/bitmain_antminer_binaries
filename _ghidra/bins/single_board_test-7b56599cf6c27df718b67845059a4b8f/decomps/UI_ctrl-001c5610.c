
int UI_ctrl(UI *ui,int cmd,long i,void *p,f *f)

{
  uint uVar1;
  uint uVar2;
  
  if (ui == (UI *)0x0) {
    ERR_put_error(0x28,0x6f,0x43,"crypto/ui/ui_lib.c",0x22a);
  }
  else {
    if (cmd == 1) {
      uVar1 = *(uint *)(ui + 0x10);
      uVar2 = (uVar1 << 0x17) >> 0x1f;
      if (i != 0) {
        *(uint *)(ui + 0x10) = uVar1 | 0x100;
        return uVar2;
      }
      *(uint *)(ui + 0x10) = uVar1 & 0xfffffeff;
      return uVar2;
    }
    if (cmd == 2) {
      return *(uint *)(ui + 0x10) & 1;
    }
    ERR_put_error(0x28,0x6f,0x6a,"crypto/ui/ui_lib.c",0x23c);
  }
  return -1;
}

