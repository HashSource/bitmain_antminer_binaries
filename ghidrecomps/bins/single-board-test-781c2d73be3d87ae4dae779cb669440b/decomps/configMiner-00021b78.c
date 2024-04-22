
/* WARNING: Unknown calling convention */

int configMiner(void)

{
  int iVar1;
  int ret;
  
  read_config();
  iVar1 = get_works();
  if (iVar1 == 0) {
    malloc_register_buf();
  }
  return iVar1;
}

