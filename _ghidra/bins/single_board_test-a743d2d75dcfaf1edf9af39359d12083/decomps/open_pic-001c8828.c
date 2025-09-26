
/* WARNING: Unknown calling convention */

int32_t open_pic(uint8_t which_chain)

{
  char tmp42 [2048];
  
  snprintf(tmp42,0x800,"%s: Bad pic param, input chain is %d\n","open_pic",(uint)which_chain);
  _applog(0,tmp42,false);
  return -0x7ffffdff;
}

