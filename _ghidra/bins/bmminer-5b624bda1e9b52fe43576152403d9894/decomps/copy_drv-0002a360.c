
/* WARNING: Unknown calling convention */

device_drv * copy_drv(device_drv *drv)

{
  device_drv *dest;
  
  dest = (device_drv *)_cgmalloc(0x78,"cgminer.c","copy_drv",0x2ba4);
  _cg_memcpy(dest,drv,0x78,"cgminer.c","copy_drv",0x2ba5);
  dest->copy = true;
  return dest;
}

