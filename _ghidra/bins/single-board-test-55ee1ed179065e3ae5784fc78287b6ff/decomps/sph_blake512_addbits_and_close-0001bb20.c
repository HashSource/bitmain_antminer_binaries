
void sph_blake512_addbits_and_close
               (undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  blake64_close(param_1,param_2,param_3,param_4,8);
  sph_blake512_init(param_1);
  return;
}

