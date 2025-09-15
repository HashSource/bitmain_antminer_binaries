
undefined4 configMiner(void)

{
  int iVar1;
  undefined4 uVar2;
  
  read_config();
  iVar1 = get_works();
  if (iVar1 < 0) {
    uVar2 = 0xfffffff2;
  }
  else {
    malloc_register_buf();
    uVar2 = 0;
  }
  return uVar2;
}

