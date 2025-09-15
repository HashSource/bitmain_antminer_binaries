
undefined4 configMiner(void)

{
  int iVar1;
  undefined4 uVar2;
  
  read_config();
  print_config();
  iVar1 = process_config();
  if (iVar1 < 0) {
    uVar2 = 0xfffffff2;
  }
  else {
    print_CONFIG();
    iVar1 = get_works();
    if (iVar1 < 0) {
      uVar2 = 0xfffffff2;
    }
    else {
      uVar2 = 0;
    }
  }
  return uVar2;
}

