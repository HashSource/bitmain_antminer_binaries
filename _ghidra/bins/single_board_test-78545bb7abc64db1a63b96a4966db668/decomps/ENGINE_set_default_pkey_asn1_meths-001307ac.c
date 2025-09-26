
int ENGINE_set_default_pkey_asn1_meths(ENGINE *e)

{
  int iVar1;
  undefined4 local_14 [2];
  
  if ((*(code **)(e + 0x28) != (code *)0x0) &&
     (iVar1 = (**(code **)(e + 0x28))(e,0,local_14), 0 < iVar1)) {
    iVar1 = engine_table_register(&pkey_asn1_meth_table,0x1306c1,e,local_14[0],iVar1,1);
    return iVar1;
  }
  return 1;
}

