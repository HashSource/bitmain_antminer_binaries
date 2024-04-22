
/* WARNING: Unknown calling convention */

int numascs(void)

{
  int i;
  int count;
  
  count = 0;
  _rd_lock(&devices_lock,"api-btm.c","numascs",0x564);
  for (i = 0; i < total_devices; i = i + 1) {
    if (devices[i]->drv->drv_id == DRIVER_bitmain) {
      count = count + 1;
    }
    if (devices[i]->drv->drv_id == DRIVER_bitmain_soc) {
      count = count + 1;
    }
  }
  _rd_unlock(&devices_lock,"api-btm.c","numascs",0x569);
  return count;
}

