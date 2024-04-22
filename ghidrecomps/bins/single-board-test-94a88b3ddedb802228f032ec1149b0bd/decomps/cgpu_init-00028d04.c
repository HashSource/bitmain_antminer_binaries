
undefined4 cgpu_init(void)

{
  int iVar1;
  undefined4 uVar2;
  
  memset(cgpu,0,0x2719f4);
  iVar1 = bitmain_axi_init();
  if (iVar1 < 0) {
    puts("open axi driver error");
    uVar2 = 0xffffffff;
  }
  else {
    uVar2 = 0;
  }
  return uVar2;
}

