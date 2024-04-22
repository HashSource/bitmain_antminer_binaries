
int ENGINE_register_pkey_asn1_meths(ENGINE *e)

{
  int iVar1;
  undefined4 local_14 [2];
  
  if ((*(code **)(e + 0x30) == (code *)0x0) ||
     (iVar1 = (**(code **)(e + 0x30))(e,0,local_14,0), iVar1 < 1)) {
    iVar1 = 1;
  }
  else {
    iVar1 = engine_table_register(DAT_000a805c,DAT_000a8058,e,local_14[0],iVar1,0);
  }
  return iVar1;
}

