
uint32_t get_register_value(uint32_t which_asic,uint32_t which_function,_Bool mode,char *asic_type)

{
  uint32_t uVar1;
  char *asic_type_local;
  _Bool mode_local;
  uint32_t which_function_local;
  uint32_t which_asic_local;
  
  uVar1 = get_register_value_with_ext_data(which_asic,which_function,mode,asic_type,(void *)0x0);
  return uVar1;
}

