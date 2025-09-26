
int ENGINE_register_digests(ENGINE *e)

{
  int iVar1;
  undefined4 local_14 [2];
  
  if ((*(code **)(e + 0x28) == (code *)0x0) ||
     (iVar1 = (**(code **)(e + 0x28))(e,0,local_14,0), iVar1 < 1)) {
    iVar1 = 1;
  }
  else {
    iVar1 = engine_table_register(&digest_table,0x19e241,e,local_14[0],iVar1,0);
  }
  return iVar1;
}

