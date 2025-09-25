
undefined4 ENGINE_register_EC(int param_1)

{
  undefined4 uVar1;
  
  if (*(int *)(param_1 + 0x14) != 0) {
    uVar1 = engine_table_register(&dh_table,0x122d45,param_1,&dummy_nid,1,0);
    return uVar1;
  }
  return 1;
}

