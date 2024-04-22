
device_drv * copy_drv(device_drv *drv)

{
  device_drv *dest;
  device_drv *drv_local;
  device_drv *copy;
  
  dest = (device_drv *)_cgmalloc(0x78,"cgminer.c","copy_drv",0x2bab);
  _cg_memcpy(dest,drv,0x78,"cgminer.c","copy_drv",0x2bac);
  dest->copy = true;
  return dest;
}

