
int ENGINE_set_default_pkey_meths(ENGINE *e)

{
  int iVar1;
  undefined4 local_14 [2];
  
  if ((*(code **)(e + 0x2c) == (code *)0x0) ||
     (iVar1 = (**(code **)(e + 0x2c))(e,0,local_14,0), iVar1 < 1)) {
    iVar1 = 1;
  }
  else {
    iVar1 = engine_table_register(DAT_000a7f14,DAT_000a7f10,e,local_14[0],iVar1,1);
  }
  return iVar1;
}

