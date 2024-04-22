
/* WARNING: Unknown calling convention */

void malloc_register_buf(void)

{
  undefined4 in_r2;
  undefined4 in_r3;
  
  reg_value_buf = (reg_buf *)calloc(0x1008,1);
  if (reg_value_buf == (reg_buf *)0x0) {
    (*(code *)PTR_printf_00030118)("%s: malloc reg_value_buf failed\n",DAT_00021af0,in_r2,in_r3);
    return;
  }
  return;
}

