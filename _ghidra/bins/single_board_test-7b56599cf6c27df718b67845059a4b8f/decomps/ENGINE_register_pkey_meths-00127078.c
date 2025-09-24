
int ENGINE_register_pkey_meths(ENGINE *e)

{
  int iVar1;
  undefined4 local_14 [2];
  
  if ((*(code **)(e + 0x24) != (code *)0x0) &&
     (iVar1 = (**(code **)(e + 0x24))(e,0,local_14), 0 < iVar1)) {
    iVar1 = engine_table_register(&pkey_meth_table,0x12705d,e,local_14[0],iVar1,0);
    return iVar1;
  }
  return 1;
}

