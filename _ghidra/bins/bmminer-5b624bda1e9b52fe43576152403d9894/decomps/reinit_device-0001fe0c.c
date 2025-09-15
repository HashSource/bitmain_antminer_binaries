
/* WARNING: Unknown calling convention */

void reinit_device(cgpu_info *cgpu)

{
  if (cgpu->deven != DEV_DISABLED) {
    (*cgpu->drv->reinit_device)(cgpu);
  }
  return;
}

