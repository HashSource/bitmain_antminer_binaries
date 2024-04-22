
void malloc_register_buf(void)

{
  reg_value_buf = malloc(0x1008);
  if (reg_value_buf == (void *)0x0) {
    printf("%s: malloc reg_value_buf failed\n","malloc_register_buf");
  }
  else {
    memset(reg_value_buf,0,0x1008);
  }
  return;
}

