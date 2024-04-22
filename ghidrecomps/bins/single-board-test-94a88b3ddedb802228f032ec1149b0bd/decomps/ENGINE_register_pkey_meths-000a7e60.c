
int ENGINE_register_pkey_meths(ENGINE *e)

{
  int iVar1;
  undefined4 local_14 [2];
  
  if ((*(code **)(e + 0x2c) == (code *)0x0) ||
     (iVar1 = (**(code **)(e + 0x2c))(e,0,local_14,0), iVar1 < 1)) {
    iVar1 = 1;
  }
  else {
    iVar1 = engine_table_register(DAT_000a7e94,DAT_000a7e90,e,local_14[0],iVar1,0);
  }
  return iVar1;
}

