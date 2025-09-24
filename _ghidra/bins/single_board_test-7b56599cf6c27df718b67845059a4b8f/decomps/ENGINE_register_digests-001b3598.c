
int ENGINE_register_digests(ENGINE *e)

{
  int iVar1;
  undefined4 local_14 [2];
  
  if ((*(code **)(e + 0x20) != (code *)0x0) &&
     (iVar1 = (**(code **)(e + 0x20))(e,0,local_14), 0 < iVar1)) {
    iVar1 = engine_table_register(&digest_table,0x1b357d,e,local_14[0],iVar1,0);
    return iVar1;
  }
  return 1;
}

