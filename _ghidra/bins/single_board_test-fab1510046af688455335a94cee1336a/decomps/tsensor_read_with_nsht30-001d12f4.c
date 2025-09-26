
/* WARNING: Unknown calling convention */

int32_t tsensor_read_with_nsht30
                  (uint32_t which_chain,uint8_t slave_addr,_Bool check_crc,double *temperature,
                  double *humidity)

{
  int32_t iVar1;
  int32_t iVar2;
  byte local_811;
  char tmp42 [2048];
  
  local_811 = slave_addr;
  if (which_chain < 0x10) {
    iVar1 = find_index(which_chain,slave_addr);
    if (iVar1 == -0x7ffffa00) {
      iVar1 = tsensor_open(which_chain,&local_811,'\x01');
      if ((iVar1 < 0) || (iVar2 = find_index(which_chain,local_811), iVar2 == -0x7ffffa00)) {
        snprintf(tmp42,0x800," auto exec tsensor_open, but chain %d,slave_addr %d open failed\n",
                 which_chain,(uint)local_811);
        _applog(0,tmp42,false);
        return iVar1;
      }
    }
    else {
      iVar1 = 0;
    }
    builtin_strncpy(tmp42,"7007 is not supported ye",0x18);
    tmp42[0x18] = 't';
    tmp42[0x19] = '\0';
    _applog(0,tmp42,false);
  }
  else {
    snprintf(tmp42,0x800," Bad T-sensor param, input chain is %d\n",which_chain);
    _applog(0,tmp42,false);
    iVar1 = -0x7ffff9ff;
  }
  return iVar1;
}

