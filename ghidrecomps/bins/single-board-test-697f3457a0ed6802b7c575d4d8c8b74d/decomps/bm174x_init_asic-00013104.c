
int bm174x_init_asic(void *args)

{
  void *args_local;
  runtime_base_t *runtime;
  
  *(undefined4 *)((int)args + 0x90) = 0x10;
  *(undefined4 *)((int)args + 0x94) = 0x5d;
  *(undefined4 *)((int)args + 0x98) = 9;
  *(undefined4 *)((int)args + 0x9c) = 9;
  *(undefined4 *)((int)args + 0xa0) = 0x406;
  *(undefined4 *)((int)args + 0xa4) = 0x406;
  *(undefined4 *)((int)args + 0xa8) = 0x92;
  *(undefined4 *)((int)args + 0xb30) = 0x11bdd;
  *(undefined4 *)((int)args + 0xb34) = 0x11c1d;
  *(undefined4 *)((int)args + 0xb38) = 0x122a5;
  *(undefined4 *)((int)args + 0xb3c) = 0x11c5d;
  *(undefined4 *)((int)args + 0xb40) = 0x11e89;
  *(undefined4 *)((int)args + 0xb44) = 0x12019;
  *(undefined4 *)((int)args + 0xb48) = 0x1207d;
  *(undefined4 *)((int)args + 0xb4c) = 0x11f29;
  *(undefined4 *)((int)args + 0xb50) = 0x11ded;
  *(undefined4 *)((int)args + 0xb54) = 0x11e4d;
  *(undefined4 *)((int)args + 0xb58) = 0x11e69;
  *(undefined4 *)((int)args + 0xb5c) = 0x11cfd;
  *(undefined4 *)((int)args + 0xb60) = 0x11f65;
  *(undefined4 *)((int)args + 0xb64) = 0x11fbd;
  *(undefined4 *)((int)args + 0xb70) = 0x120d5;
  *(undefined4 *)((int)args + 0xb74) = 0x12125;
  *(undefined4 *)((int)args + 0xb6c) = 0x12159;
  *(undefined4 *)((int)args + 0xb68) = 0x12215;
  *(undefined4 *)((int)args + 0xb8c) = 0x125a5;
  *(undefined4 *)((int)args + 0xb90) = 0x12f95;
  *(undefined4 *)((int)args + 0xb88) = 0x12409;
  *(undefined4 *)((int)args + 0xb84) = 0x122c1;
  return 0;
}

