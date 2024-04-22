
void cg_logwork_uint32(undefined4 param_1,undefined4 param_2)

{
  undefined4 local_10;
  undefined local_c;
  
  if (opt_logwork_path != 0) {
    local_c = 0;
    local_10 = param_2;
    cg_logwork(param_1,&local_10);
    return;
  }
  return;
}

