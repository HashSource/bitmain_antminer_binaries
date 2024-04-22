
void sph_blake224_addbits_and_close
               (undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  blake32_close(param_1,param_2,param_3,param_4,7);
  sph_blake224_init(param_1);
  return;
}

