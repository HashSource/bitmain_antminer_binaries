
int EC_GROUP_get_degree(EC_GROUP *group)

{
  int iVar1;
  
  if (*(code **)(*(int *)group + 0x20) == (code *)0x0) {
    ERR_put_error(0x10,0xad,0x42,DAT_000a1254,0x1d3);
    iVar1 = 0;
  }
  else {
    iVar1 = (**(code **)(*(int *)group + 0x20))();
  }
  return iVar1;
}

