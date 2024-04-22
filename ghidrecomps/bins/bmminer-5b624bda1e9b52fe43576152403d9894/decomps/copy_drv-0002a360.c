
/* WARNING: Unknown calling convention */

device_drv * copy_drv(device_drv *drv)

{
  char *func;
  device_drv *dest;
  device_drv *copy;
  
  func = DAT_0002a3a0;
  dest = (device_drv *)_cgmalloc(0x78,"cgminer.c",DAT_0002a3a0,0x2ba4);
  _cg_memcpy(dest,drv,0x78,"cgminer.c",func,0x2ba5);
  dest->copy = true;
  return dest;
}

