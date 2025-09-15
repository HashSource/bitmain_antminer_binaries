
int ascdevice(int ascid)

{
  int ascid_local;
  int i;
  int count;
  
  count = 0;
  _rd_lock(&devices_lock,"api-btm.c","ascdevice",0x572);
  i = 0;
  while( true ) {
    if (total_devices <= i) {
      _rd_unlock(&devices_lock,"api-btm.c","ascdevice",0x57a);
      return -1;
    }
    if (devices[i]->drv->drv_id == DRIVER_bitmain) {
      count = count + 1;
    }
    if (devices[i]->drv->drv_id == DRIVER_bitmain_soc) {
      count = count + 1;
    }
    if (ascid + 1 == count) break;
    i = i + 1;
  }
  _rd_unlock(&devices_lock,"api-btm.c","ascdevice",0x57f);
  return i;
}

