
undefined4 dev_from_id(void)

{
  int iVar1;
  
  iVar1 = get_thread();
  return *(undefined4 *)(*(int *)(iVar1 + 0x24) + 8);
}

