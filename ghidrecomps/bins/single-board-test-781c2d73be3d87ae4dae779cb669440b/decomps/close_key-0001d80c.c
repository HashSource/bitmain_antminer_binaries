
/* WARNING: Unknown calling convention */

void close_key(void)

{
  undefined4 extraout_r1;
  undefined4 in_r2;
  undefined4 in_r3;
  
  close(key_fd);
  (*(code *)PTR_puts_0003015c)("key closed!!!",extraout_r1,in_r2,in_r3);
  return;
}

